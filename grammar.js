let newline = choice("\n", "\r", "\r\n");
// "" is for end-of-string (e.g. test)
let newline_or_eof = choice("\n", "\r", "\r\n", "\0", "");

const ATTACHED_MODIFIER_TYPES = [
    "bold",
    "italic",
    "strikethrough",
    "underline",
    "spoiler",
    "superscript",
    "subscript",
]

/// General TODOS:
//  - Abstract repeating patterns (e.g. nestable detached modifiers) into Javascript functions.
//  - Support link modifiers within inline paragraph segments (titles)
//  - Add tests for link modifiers, then everything else.
//  - Make every node have an alias($.node, $.node_prefix). Only some currently do.

module.exports = grammar({
    name: "norg",

    // Tell treesitter we want to handle whitespace ourselves
    extras: ($) => [$._precedingwhitespace],
    externals: ($) => [
        $._precedingwhitespace,

        $.heading_stars,
        $.unordered_list_prefix,
        $.ordered_list_prefix,
        $.quote_prefix,

        $.weak_delimiting_modifier,

        $._dedent,
    ],

    // TODO: Minimize conflict count
    conflicts: ($) => [
        [$.punctuation, $._bold_open],
        [$.punctuation, $._italic_open],
        [$.punctuation, $._strikethrough_open],
        [$.punctuation, $._underline_open],
        [$.punctuation, $._spoiler_open],
        [$.punctuation, $._superscript_open],
        [$.punctuation, $._subscript_open],
        [$.punctuation, $.link_modifier],
        [$.punctuation, $._free_open],
    ],

    precedences: ($) => [
        [$.heading, $.delimiting_modifier],
        [$.horizontal_line, $.punctuation],
        [$.footnote_list_single, $.punctuation],
        [$.definition_list_single, $.punctuation],
    ],

    inlines: ($) => [],

    supertypes: ($) => [
        $.non_structural,
        $.nestable_modifier,
        $.rangeable_detached_modifier,
        $.tag,
        $.todo_item,
        $.delimiting_modifier,
        $.punctuation,
    ],

    rules: {
        document: ($) =>
            repeat(
                choice(
                    $.non_structural,
                    $.heading,
                    $.strong_delimiting_modifier,
                ),
            ),

        non_structural: ($) =>
            choice(
                $.paragraph,
                newline_or_eof,
                $.nestable_modifier,
                $.rangeable_detached_modifier,
                $.tag,
                $.delimiting_modifier,
            ),

        _character: (_) => token(/[\p{L}\p{N}]/u),
        punctuation: ($) => choice(
            // to make conflict with attached modifier openers
            // & repeated attached modifiers
            // the following code makes tokens like * and /\*\*+/
            ...[
                "*",
                "/",
                "-",
                "_",
                "!",
                "^",
                ",",
                "`",
                "%",
                "$",
                "&",
            ].map(m => [m, prec(1, token(seq(m, repeat1(m))))]).flat(),
            // conflict with link modifier is also needed
            ":",
            "|",
            token(/[^\n\r\p{Z}\p{L}\p{N}]/u),
        ),
        _word: ($) => prec.right(-1, repeat1($._character)),
        _whitespace: (_) => token(prec(1, /\p{Zs}+/u)),

        escape_sequence: ($) => seq("\\", alias(prec(10, /./), $.escape_char)),

        paragraph: ($) => prec.right(repeat1(
            seq($._paragraph_segment, choice(newline_or_eof)),
        )),

        _word_segment: ($) => prec.right(seq(
            $._word,
            optional(
                choice(
                    $._ws_punc_segment,
                    seq($.link_modifier, $._att_mod_seg),
                ),
            )
        )),
        _ws_punc_segment: ($) => prec.right(seq(
            choice(
                $._whitespace,
                $.punctuation,
            ),
            optional($._paragraph_segment)
        )),
        _att_mod_seg: ($) => prec.right(seq(
            choice(
                $.bold,
                $.italic,
            ),
            optional(
                choice(
                    $._ws_punc_segment,
                    $._att_mod_seg,
                    seq($.link_modifier, $._word_segment),
                )
            )
        )),
        _paragraph_segment: ($) => choice(
            $._word_segment,
            $._ws_punc_segment,
            $._att_mod_seg,
        ),
        link_modifier: (_) => prec.dynamic(1, ":"),
        _free_open: (_) => "|",
        ...gen_attached_modifiers("bold", "*"),
        ...gen_attached_modifiers("italic", "/"),
        ...gen_attached_modifiers("strikethrough", "-"),
        ...gen_attached_modifiers("underline", "_"),
        ...gen_attached_modifiers("spoiler", "!"),
        ...gen_attached_modifiers("superscript", "^"),
        ...gen_attached_modifiers("subscript", ","),

        // TODO: title should be one-line paragraph
        title: ($) => $._paragraph_segment,

        heading: ($) =>
            prec.right(
                seq(
                    $.heading_stars,
                    $._whitespace,
                    // optional(seq($.detached_modifier_extension, $._whitespace)),
                    $.title,
                    newline_or_eof,
                    repeat(choice($.heading, $.non_structural)),
                    optional(choice($._dedent, $.weak_delimiting_modifier)),
                )
            ),

        nestable_modifier: ($) =>
            choice($.unordered_list, $.ordered_list, $.quote),

        unordered_list: ($) => prec.right(repeat1($.unordered_list_item)),

        unordered_list_item: ($) =>
            prec.right(
                seq(
                    $.unordered_list_prefix,
                    $._whitespace,
                    optional(seq($.detached_modifier_extension, $._whitespace)),
                    $.paragraph,
                    repeat($.unordered_list_item),
                    optional($._dedent),
                ),
            ),

        ordered_list: ($) => prec.right(repeat1($.ordered_list_item)),

        ordered_list_item: ($) =>
            prec.right(
                seq(
                    $.ordered_list_prefix,
                    $._whitespace,
                    optional(seq($.detached_modifier_extension, $._whitespace)),
                    $.paragraph,
                    repeat($.ordered_list_item),
                    optional($._dedent),
                ),
            ),

        quote: ($) => prec.right(repeat1($.quote_item)),

        quote_item: ($) =>
            prec.right(
                seq(
                    $.quote_prefix,
                    $._whitespace,
                    optional(seq($.detached_modifier_extension, $._whitespace)),
                    $.paragraph,
                    repeat($.quote_item),
                    optional($._dedent),
                ),
            ),

        rangeable_detached_modifier: ($) =>
            choice(
                $.definition_list,
                $.footnote_list,
                // $.table
            ),

        definition_list: ($) =>
            choice($.definition_list_single, $.definition_list_multi),

        definition_list_single: ($) =>
            seq(
                alias("$", $.definition_single_prefix),
                $._whitespace,
                optional(seq($.detached_modifier_extension, $._whitespace)),
                $.title,
                repeat1(newline),
                $.paragraph,
            ),

        definition_list_multi: ($) =>
            prec.right(
                seq(
                    alias("$$", $.definition_multi_prefix),
                    $._whitespace,
                    optional(seq($.detached_modifier_extension, $._whitespace)),
                    $.title,
                    newline_or_eof,
                    repeat($.non_structural),
                    alias("$$", $.definition_multi_end),
                ),
            ),

        footnote_list: ($) =>
            choice($.footnote_list_single, $.footnote_list_multi),

        footnote_list_single: ($) =>
            seq(
                alias("^", $.footnote_single_prefix),
                $._whitespace,
                optional(seq($.detached_modifier_extension, $._whitespace)),
                $.title,
                repeat1(newline),
                $.paragraph,
            ),

        footnote_list_multi: ($) =>
            prec.right(
                seq(
                    alias("^^", $.footnote_multi_prefix),
                    $._whitespace,
                    optional(seq($.detached_modifier_extension, $._whitespace)),
                    $.title,
                    newline_or_eof,
                    repeat($.non_structural),
                    alias("^^", $.footnote_multi_end),
                ),
            ),

        table: ($) => choice($.table_cell_single, $.table_cell_multi),

        table_cell_single: ($) =>
            seq(
                alias(":", $.table_cell_single_prefix),
                $._whitespace,
                optional(seq($.detached_modifier_extension, $._whitespace)),
                $.title,
                repeat1(newline),
                $.paragraph,
            ),

        table_cell_multi: ($) =>
            prec.right(
                seq(
                    alias("::", $.table_cell_multi_prefix),
                    $._whitespace,
                    optional(seq($.detached_modifier_extension, $._whitespace)),
                    $.title,
                    newline_or_eof,
                    repeat($.non_structural),
                    alias("::", $.table_cell_multi_end),
                ),
            ),


        tag: ($) =>
            choice(
                $.verbatim_ranged_tag,
                $.ranged_tag,
                $.infirm_tag,
                $.strong_carryover_tag,
                $.weak_carryover_tag,
                $.macro_tag,
            ),

        tag_name: ($) =>
            seq(
                alias(repeat1(token(prec(1, /[a-z\-A-Z]/))), $.identifier),
                repeat(
                    seq(
                        ".",
                        alias(
                            repeat1(token(prec(1, /[a-z\-A-Z]/))),
                            $.identifier,
                        ),
                    ),
                ),
            ),

        verbatim_ranged_tag: ($) =>
            seq(
                "@",
                $.tag_name,
                optional(
                    seq(
                        $._whitespace,
                        optional(
                            seq(
                                alias(
                                    repeat1(choice($._word, $.punctuation, $.escape_sequence)),
                                    $.parameter,
                                ),
                                repeat(
                                    seq(
                                        $._whitespace,
                                        optional(
                                            alias(
                                                repeat1(
                                                    choice(
                                                        $._word,
                                                        $.punctuation,
                                                    ),
                                                ),
                                                $.parameter,
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        ),
                    ),
                ),
                newline,
                optional(
                    seq(
                        alias(
                            repeat(
                                choice($._word, $._whitespace, $.punctuation, newline),
                            ),
                            $.verbatim_content,
                        ),
                        newline,
                    ),
                ),
                alias(token(seq("@end", newline_or_eof)), $.end),
            ),

        ranged_tag: ($) =>
            seq(
                token("|"),
                $.tag_name,
                optional(
                    seq(
                        $._whitespace,
                        optional(
                            seq(
                                alias(
                                    repeat1(choice($._word, $.punctuation, $.escape_sequence)),
                                    $.parameter,
                                ),
                                repeat(
                                    seq(
                                        $._whitespace,
                                        optional(
                                            alias(
                                                repeat1(
                                                    choice(
                                                        $._word,
                                                        $.punctuation,
                                                    ),
                                                ),
                                                $.parameter,
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        ),
                    ),
                ),
                newline,
                alias(repeat(choice($.non_structural, $.heading)), $.content),
                alias(token(seq("|end", newline_or_eof)), $.end),
            ),

        macro_tag: ($) =>
            seq(
                token("="),
                $.tag_name,
                optional(
                    seq(
                        $._whitespace,
                        optional(
                            seq(
                                alias(
                                    repeat1(choice($._word, $.punctuation, $.escape_sequence)),
                                    $.parameter,
                                ),
                                repeat(
                                    seq(
                                        $._whitespace,
                                        optional(
                                            alias(
                                                repeat1(
                                                    choice(
                                                        $._word,
                                                        $.punctuation,
                                                    ),
                                                ),
                                                $.parameter,
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        ),
                    ),
                ),
                newline,
                alias(repeat(choice($.non_structural, $.heading)), $.content),
                alias(token(seq("=end", newline_or_eof)), $.end),
            ),

        infirm_tag: ($) =>
            seq(
                ".",
                $.tag_name,

                optional(
                    seq(
                        $._whitespace,
                        optional(
                            seq(
                                alias(
                                    repeat1(choice($._word, $.punctuation, $.escape_sequence)),
                                    $.parameter,
                                ),
                                repeat(
                                    seq(
                                        $._whitespace,
                                        optional(
                                            alias(
                                                repeat1(
                                                    choice(
                                                        $._word,
                                                        $.punctuation,
                                                    ),
                                                ),
                                                $.parameter,
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        ),
                    ),
                ),
                newline_or_eof,
            ),

        strong_carryover_tag: ($) =>
            seq(
                "#",
                $.tag_name,

                optional(
                    seq(
                        $._whitespace,
                        optional(
                            seq(
                                alias(
                                    repeat1(choice($._word, $.punctuation, $.escape_sequence)),
                                    $.parameter,
                                ),
                                repeat(
                                    seq(
                                        $._whitespace,
                                        optional(
                                            alias(
                                                repeat1(
                                                    choice(
                                                        $._word,
                                                        $.punctuation,
                                                    ),
                                                ),
                                                $.parameter,
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        ),
                    ),
                ),
                newline,
            ),

        weak_carryover_tag: ($) =>
            seq(
                "+",
                $.tag_name,

                optional(
                    seq(
                        $._whitespace,
                        optional(
                            seq(
                                alias(
                                    repeat1(choice($._word, $.punctuation, $.escape_sequence)),
                                    $.parameter,
                                ),
                                repeat(
                                    seq(
                                        $._whitespace,
                                        optional(
                                            alias(
                                                repeat1(
                                                    choice(
                                                        $._word,
                                                        $.punctuation,
                                                    ),
                                                ),
                                                $.parameter,
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        ),
                    ),
                ),
                newline,
            ),

        todo_item_done: ($) => "x",
        todo_item_undone: ($) => " ",
        todo_item_uncertain: ($) => "?",
        todo_item_urgent: ($) => "!",
        todo_item_pending: ($) => "-",
        todo_item_on_hold: ($) => "=",
        todo_item_cancelled: ($) => "_",
        todo_item_recurring: ($) =>
            seq(
                "+",
                optional(
                    seq(
                        $._whitespace,
                        alias(
                            repeat(choice($._word, $._whitespace)),
                            $.timestamp,
                        ),
                    ),
                ),
            ),
        todo_item_priority: ($) => seq("#", $._whitespace, $._word),
        todo_item_timestamp: ($) =>
            seq(
                "@",
                seq(
                    $._whitespace,
                    alias(repeat1(choice($._word, $._whitespace)), $.timestamp),
                ),
            ),
        todo_item_start_date: ($) =>
            seq(
                ">",
                seq(
                    $._whitespace,
                    alias(repeat1(choice($._word, $._whitespace)), $.timestamp),
                ),
            ),
        todo_item_due_date: ($) =>
            seq(
                "<",
                seq(
                    $._whitespace,
                    alias(repeat1(choice($._word, $._whitespace)), $.timestamp),
                ),
            ),

        todo_item: ($) =>
            choice(
                $.todo_item_done,
                $.todo_item_undone,
                $.todo_item_uncertain,
                $.todo_item_urgent,
                $.todo_item_pending,
                $.todo_item_on_hold,
                $.todo_item_cancelled,
                $.todo_item_recurring,
                $.todo_item_priority,
                $.todo_item_timestamp,
                $.todo_item_start_date,
                $.todo_item_due_date,
            ),

        detached_modifier_extension: ($) =>
            seq(
                "(",
                $.todo_item,
                repeat(seq(token(prec(1, "|")), $.todo_item)),
                ")",
            ),

        delimiting_modifier: ($) =>
            choice($.weak_delimiting_modifier, $.horizontal_line),

        strong_delimiting_modifier: ($) =>
            prec.right(seq("==", repeat("="), newline_or_eof)),

        horizontal_line: ($) =>
            prec.right(seq("_", repeat1("_"), newline_or_eof)),
    }
});

// TODO: automate
function gen_attached_modifiers(type, mod) {
    const rules = {};
    const other_modifiers = ATTACHED_MODIFIER_TYPES.filter((t) => t != type);
    const open = `_${type}_open`;
    const close = `_${type}_close`;
    const word_segment = `_${type}_word_segment`;
    const ws_segment = `_${type}_ws_segment`;
    const punc_segment = `_${type}_punc_segment`;
    const att_mod_segment = `_${type}_attached_modifier_segment`;
    const newline_segment = `_${type}_newline_segment`;

    const free_open = `_${type}_free_open`;
    const free_close = `_${type}_free_close`;
    const free_word_segment = `_${type}_free_word_segment`;
    const free_ws_punc_segment = `_${type}_free_ws_punc_segment`;
    const free_att_mod_segment = `_${type}_free_attached_modifier_segment`;
    const free_newline_segment = `_${type}_free_newline_segment`;
    rules[open] = (_) => mod;
    rules[close] = ($) => choice(
        prec(2, seq(mod, $[word_segment])),
        alias(prec(1, mod), $.close),
    );
    rules[free_open] = ($) => seq($[open], $._free_open);
    rules[free_close] = ($) => choice(
        prec(2, seq(mod, $[free_word_segment])),
        alias(prec(1, mod), $.close),
    );
    rules[word_segment] = ($) => seq(
        $._word,
        choice(
            $[ws_segment],
            $[punc_segment],
            $[newline_segment],
            $[close],
            seq($.link_modifier, $[att_mod_segment]),
        )
    );
    rules[ws_segment] = ($) => seq(
        $._whitespace,
        choice(
            $[word_segment],
            $[ws_segment],
            $[punc_segment],
            $[att_mod_segment],
            $[newline_segment],
        )
    )
    rules[punc_segment] = ($) => seq(
        $.punctuation,
        choice(
            $[word_segment],
            $[ws_segment],
            $[punc_segment],
            $[att_mod_segment],
            $[newline_segment],
            $[close],
        )
    );
    rules[att_mod_segment] = ($) => seq(
        choice(
            ...other_modifiers.map(m => $[m])
        ),
        choice(
            $[ws_segment],
            $[punc_segment],
            $[att_mod_segment],
            $[newline_segment],
            $[close],
            seq($.link_modifier, $[word_segment]),
        )
    );
    rules[newline_segment] = ($) => seq(
        newline,
        choice(
            $[word_segment],
            $[punc_segment],
            $[att_mod_segment],
        )
    );

    rules[free_word_segment] = ($) => seq(
        $._word,
        choice(
            $[free_ws_punc_segment],
            $[free_close],
            seq($.link_modifier, $[free_att_mod_segment])
        )
    );
    rules[free_ws_punc_segment] = ($) => seq(
        choice(
            $._whitespace,
            $.punctuation,
        ),
        $[free_word_segment],
        $[free_ws_punc_segment],
        $[free_att_mod_segment],
        $[free_newline_segment],
        $[free_close],
    )
    rules[free_att_mod_segment] = ($) => seq(
        choice(
            ...other_modifiers.map(m => $[m])
        ),
        choice(
            $[free_ws_punc_segment],
            $[free_att_mod_segment],
            $[free_newline_segment],
            $[free_close],
            seq($.link_modifier, $[free_word_segment]),
        )
    )
    rules[free_newline_segment] = ($) => seq(
        newline,
        choice(
            $[free_word_segment],
            $[free_ws_punc_segment],
            $[free_att_mod_segment],
            $[free_close],
        )
    )
    rules[type] = ($) => choice(
        prec.dynamic(1, seq(
            alias($[open], $.open),
            choice(
                $[word_segment],
                $[punc_segment],
                $[att_mod_segment],
            )
        )),
        prec.dynamic(2, seq(
            alias($[free_open], $.free_open),
            $[free_word_segment],
            $[free_ws_punc_segment],
            $[free_att_mod_segment],
            $[free_newline_segment],
        ))
    )
    return rules
}
