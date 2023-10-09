let newline = choice("\n", "\r", "\r\n");
let newline_or_eof = choice("\n", "\r", "\r\n", "\0");

const ATTACHED_MODIFIER_TYPES = [
    "bold",
    "italic",
    "strikethrough",
    "underline",
    "spoiler",
    "superscript",
    "subscript",

    "verbatim",
    "null_modifier",
    "inline_math",
    "inline_macro",
]

/// General TODOS:
//  - Abstract repeating patterns (e.g. nestable detached modifiers) into Javascript functions.
//  - Add tests for link modifiers, then everything else.
//  - Make every node have an alias($.node, $.node_prefix). Only some currently do.

module.exports = grammar({
    name: "norg",

    // Tell treesitter we want to handle whitespace ourselves
    extras: ($) => [$._preceding_whitespace],
    externals: ($) => [
        $._preceding_whitespace,

        $.heading_stars,
        $.unordered_list_prefix,
        $.ordered_list_prefix,
        $.quote_prefix,

        $.weak_delimiting_modifier,

        $._dedent,
    ],

    conflicts: ($) => [
        [$.punctuation, $._bold_open],
        [$._heading_conflict, $._bold_open],
        [$._punctuation, $._italic_open],
        [$._ul_conflict, $._strikethrough_open],
        [$._punctuation, $._underline_open],
        [$._punctuation, $._spoiler_open],
        [$._punctuation, $._superscript_open],
        [$._punctuation, $._subscript_open],
        [$._punctuation, $._verbatim_open],
        [$._punctuation, $._null_modifier_open],
        [$._punctuation, $._inline_math_open],
        [$._punctuation, $._inline_macro_open],
        [$._punctuation, $.link_modifier],
        [$._punctuation, $._free_open],

        [$.table_cell_single, $.punctuation],
    ],

    precedences: ($) => [
        [$.heading, $.delimiting_modifier],
        [$.horizontal_line, $._punctuation],
        [$.footnote_list_single, $._punctuation],
        [$.definition_list_single, $._punctuation],
        [$.footnote_list_multi, $._punctuation],
        [$.definition_list_multi, $._punctuation],
        [$.table_cell_single, $._punctuation],
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
                newline,
                $.nestable_modifier,
                $.rangeable_detached_modifier,
                $.tag,
                $.delimiting_modifier,
            ),

        _character: (_) => token(/[\p{L}\p{N}]/u),
        punctuation: ($) => choice(
            $._punctuation,
            $._heading_conflict,
            $._ul_conflict,
            $._ol_conflict,
        ),
        _punctuation: ($) => choice(
            // to make conflict with attached modifier openers
            // & repeated attached modifiers
            // the following code makes tokens like * and /\*\*+/
            ...[
                // "*",
                "/",
                // "-",
                "_",
                "!",
                "^",
                ",",
                "`",
                "%",
                "$",
                "&",
                // make seperate twice-repeated tokens (e.g. "$$") to make conflict with rangeable_detached_modifiers
            ].map(m => [m, m + m, prec(1, token(seq(m + m, repeat1(m))))]).flat(),
            // conflict with link modifier is also needed
            ":",
            "|",
            token(/[^\n\r\p{Z}\p{L}\p{N}]/u),
        ),
        // these are for breaking attached modifier when structural modifiers come after eol
        _heading_conflict: (_) => choice(
            "*", prec(1, token(seq("*", repeat1("*"))))
        ),
        _ul_conflict: (_) => choice(
            "-", prec(1, token(seq("-", repeat1("-"))))
        ),
        _ol_conflict: (_) => choice(
            "~", prec(1, token(seq("~", repeat1("~"))))
        ),

        _word: ($) => prec.right(-1, repeat1($._character)),
        _whitespace: (_) => token(prec(1, /\p{Zs}+/u)),

        escape_sequence: ($) => seq(
            "\\",
            alias(
                choice(
                    prec(10, /(\r\n|[\s\S])/),
                    $.punctuation,
                ),
                $.escape_char
            )
        ),

        link_modifier: (_) => prec.dynamic(1, ":"),
        _free_open: (_) => "|",

        ...gen_non_verbatim_attached_modifier("bold", "*"),
        ...gen_non_verbatim_attached_modifier("italic", "/"),
        ...gen_non_verbatim_attached_modifier("strikethrough", "-"),
        ...gen_non_verbatim_attached_modifier("underline", "_"),
        ...gen_non_verbatim_attached_modifier("spoiler", "!"),
        ...gen_non_verbatim_attached_modifier("superscript", "^"),
        ...gen_non_verbatim_attached_modifier("subscript", ","),
        ...gen_verbatim_attached_modifier("verbatim", "`"),
        ...gen_verbatim_attached_modifier("null_modifier", "%"),
        ...gen_verbatim_attached_modifier("inline_math", "$"),
        ...gen_verbatim_attached_modifier("inline_macro", "&"),

        paragraph: ($) => prec.right(repeat1(
            // "" is for end-of-string (e.g. test)
            seq($._paragraph_segment, choice(newline_or_eof, "")),
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
                $.escape_sequence,
            ),
            optional($._paragraph_segment)
        )),
        _att_mod_seg: ($) => prec.right(seq(
            choice(
                ...ATTACHED_MODIFIER_TYPES.map(n => $[n])
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
        _inline_word_segment: ($) => prec.right(seq(
            $._word,
            optional(
                choice(
                    $._inline_ws_punc_segment,
                    seq($.link_modifier, $._inline_att_mod_seg),
                ),
            )
        )),
        _inline_ws_punc_segment: ($) => prec.right(seq(
            choice(
                $._whitespace,
                $.punctuation,
                $.escape_sequence,
            ),
            optional($._inline_paragraph_segment)
        )),
        _inline_att_mod_seg: ($) => prec.right(seq(
            choice(
                ...ATTACHED_MODIFIER_TYPES.map(n => alias($["inline_" + n], $[n]))
            ),
            optional(
                choice(
                    $._inline_ws_punc_segment,
                    $._inline_att_mod_seg,
                    seq($.link_modifier, $._inline_word_segment),
                )
            )
        )),
        _inline_paragraph_segment: ($) => choice(
            $._inline_word_segment,
            $._inline_ws_punc_segment,
            $._inline_att_mod_seg,
        ),

        title: ($) => $._inline_paragraph_segment,

        heading: ($) =>
            prec.right(
                seq(
                    $.heading_stars,
                    $._whitespace,
                    optional(seq($.detached_modifier_extension, $._whitespace)),
                    $.title,
                    newline_or_eof,
                    repeat(choice($.heading, $.non_structural)),
                    optional(choice($._dedent, $.weak_delimiting_modifier)),
                ),
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
            choice($.definition_list, $.footnote_list, $.table),

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
                choice(newline_or_eof, ""),
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

        link: ($) =>
            prec.right(seq($.link_location, optional($.link_description))),

        anchor: ($) =>
            prec.right(
                seq(
                    $.link_description,
                    optional(choice($.link_location, $.link_description)),
                ),
            ),

        url: ($) => repeat1(choice($._word, $.punctuation)),

        link_to_detached_modifier: ($) =>
            choice(
                // TODO: Add the rest
                alias(repeat1("*"), $.heading_link),
                alias("$", $.definition_link),
                alias("^", $.footnote_link),
            ),

        // FIXME: double newlines are permitted within links here.
        // FIXME: Allow attached modifiers to contain links
        // TODO: Give the paragraph segments a node name
        // TODO: Give field names to the description and location
        link_location: ($) =>
            seq(
                "{",
                choice(
                    $.url,
                    seq(
                        $.link_to_detached_modifier,
                        $._whitespace,
                        $._paragraph_segment,
                        repeat(seq(newline, $._paragraph_segment)),
                    ),
                ),
                "}",
            ),

        link_description: ($) =>
            seq(
                "[",
                $._paragraph_segment,
                repeat(seq(newline, $._paragraph_segment)),
                "]",
            ),

        link_location_inline: ($) =>
            seq(
                "{",
                choice(
                    $.url,
                    seq($.link_to_detached_modifier, $._whitespace, $.title),
                ),
                "}",
            ),

        link_description_inline: ($) => seq("[", $.title, "]"),

        link_inline: ($) =>
            prec.right(
                2,
                seq(
                    $.link_location_inline,
                    optional($.link_description_inline),
                ),
            ),

        anchor_inline: ($) =>
            prec.right(
                2,
                seq(
                    $.link_description_inline,
                    optional(
                        choice(
                            $.link_location_inline,
                            $.link_description_inline,
                        ),
                    ),
                ),
            ),

        // TODO: slide
    },
});

function gen_attached_modifier(type, mod, verbatim, not_inline) {
    const rules = {};
    const other_modifiers = ATTACHED_MODIFIER_TYPES.filter((t) => t != type);
    const prefix = not_inline ? "" : "inline_"

    const open = `_${type}_open`;
    const close = `_${prefix + type}_close`;
    const word_segment = `_${prefix + type}_word_segment`;
    const ws_segment = `_${prefix + type}_ws_segment`;
    const punc_segment = `_${prefix + type}_punc_segment`;
    const safe_punc_segment = `_${prefix + type}_safe_punc_segment`;
    const att_mod_segment = `_${prefix + type}_attached_modifier_segment`;
    const newline_segment = `_${type}_newline_segment`;

    const free_open = `_${type}_free_open`;
    const free_close = `_${prefix + type}_free_close`;
    const free_word_segment = `_${prefix + type}_free_word_segment`;
    const free_ws_punc_segment = `_${prefix + type}_free_ws_punc_segment`;
    const free_safe_punc_segment = `_${prefix + type}_free_safe_punc_segment`;
    const free_att_mod_segment = `_${prefix + type}_free_attached_modifier_segment`;
    const free_newline_segment = `_${type}_free_newline_segment`;

    rules[open] = (_) => mod;
    rules[close] = ($) => choice(
        prec(2, seq(mod, $[word_segment])),
        alias(prec(1, mod), $.close),
    );
    rules[free_open] = ($) => seq($[open], $._free_open);
    rules[free_close] = ($) => choice(
        prec(2, seq(mod, $[free_word_segment])),
        alias(prec(1, "|" + mod), $.free_close),
    );
    rules[word_segment] = ($) => seq(
        $._word,
        choice(
            ...[
                $[ws_segment],
                $[punc_segment],
                not_inline ? $[newline_segment] : null,
                $[close],
                verbatim ? null : seq($.link_modifier, $[att_mod_segment]),
            ].filter(n => n !== null)
        )
    );
    rules[ws_segment] = ($) => seq(
        $._whitespace,
        choice(
            ...[
                $[word_segment],
                $[ws_segment],
                $[punc_segment],
                verbatim ? null : $[att_mod_segment],
                not_inline ? $[newline_segment] : null,
            ].filter(n => n !== null)
        )
    )
    rules[punc_segment] = ($) => seq(
        choice(
            $.punctuation,
            $.escape_sequence,
        ),
        choice(
            ...[
                $[word_segment],
                $[ws_segment],
                $[punc_segment],
                verbatim ? null : $[att_mod_segment],
                not_inline ? $[newline_segment] : null,
                $[close],
            ].filter(n => n !== null)
        )
    );
    if (!verbatim) {
        rules[att_mod_segment] = ($) => seq(
            choice(
                ...other_modifiers.map(m => not_inline ? $[m] : alias($[prefix + m], $[m]))
            ),
            choice(
                ...[
                    $[ws_segment],
                    $[punc_segment],
                    $[att_mod_segment],
                    not_inline ? $[newline_segment] : null,
                    $[close],
                    seq($.link_modifier, $[word_segment]),
                ].filter(n => n !== null)
            )
        );
    }
    if (not_inline) {
        rules[safe_punc_segment] = ($) => choice(
            seq(
                choice(
                    $._heading_conflict,
                    $._ul_conflict,
                    $._ol_conflict,
                ),
                choice(
                    ...[
                        $[word_segment],
                        $[punc_segment],
                        verbatim ? null : $[att_mod_segment],
                        not_inline ? $[newline_segment] : null,
                        $[close],
                    ].filter(n => n !== null)
                )
            ),
            seq(
                choice(
                    $._punctuation,
                    $.escape_sequence,
                ),
                choice(
                    ...[
                        $[word_segment],
                        $[ws_segment],
                        $[punc_segment],
                        verbatim ? null : $[att_mod_segment],
                        not_inline ? $[newline_segment] : null,
                        $[close],
                    ].filter(n => n !== null)
                )
            )
        );
        rules[newline_segment] = ($) => seq(
            newline,
            choice(
                ...[
                    $[word_segment],
                    // FIXME: `- ` is allowed, but have smaller prec
                    $[safe_punc_segment],
                    verbatim ? null : $[att_mod_segment],
                ].filter(n => n !== null)
            )
        );
    }

    rules[free_word_segment] = ($) => seq(
        $._word,
        choice(
            ...[
                $[free_ws_punc_segment],
                $[free_close],
                not_inline ? $[free_newline_segment] : null,
                verbatim ? null : seq($.link_modifier, $[free_att_mod_segment])
            ].filter(n => n !== null)
        )
    );
    rules[free_ws_punc_segment] = ($) => seq(
        choice(
            $._whitespace,
            $.punctuation,
        ),
        choice(
            ...[
                $[free_word_segment],
                $[free_ws_punc_segment],
                verbatim ? null : $[free_att_mod_segment],
                not_inline ? $[free_newline_segment] : null,
                $[free_close],
            ].filter(n => n !== null)
        )
    )
    if (!verbatim) {
        rules[free_att_mod_segment] = ($) => seq(
            choice(
                ...other_modifiers.map(m => $[m])
            ),
            choice(
                ...[
                    $[free_ws_punc_segment],
                    $[free_att_mod_segment],
                    not_inline ? $[free_newline_segment] : null,
                    $[free_close],
                    seq($.link_modifier, $[free_word_segment]),
                ].filter(n => n !== null)
            )
        )
    }
    if (not_inline) {
        rules[free_safe_punc_segment] = ($) => choice(
            seq(
                choice(
                    $._heading_conflict,
                    $._ul_conflict,
                    $._ol_conflict,
                ),
                choice(
                    ...[
                        $[free_word_segment],
                        seq(
                            $.punctuation,
                            choice(
                                ...[
                                    $[free_word_segment],
                                    $[free_ws_punc_segment],
                                    verbatim ? null : $[free_att_mod_segment],
                                    $[free_newline_segment],
                                    $[free_close],
                                ].filter(n => n !== null)
                            )
                        ),
                        verbatim ? null : $[free_att_mod_segment],
                        $[free_newline_segment],
                        $[free_close],
                    ].filter(n => n !== null)
                )
            ),
            seq(
                choice(
                    $._punctuation,
                    $.escape_sequence,
                ),
                choice(
                    ...[
                        $[free_word_segment],
                        $[free_ws_punc_segment],
                        verbatim ? null : $[free_att_mod_segment],
                        $[free_newline_segment],
                        $[free_close],
                    ].filter(n => n !== null)
                )
            )
        );
        rules[free_newline_segment] = ($) => seq(
            newline,
            choice(
                ...[
                    $[free_word_segment],
                    $[free_safe_punc_segment],
                    verbatim ? null : $[free_att_mod_segment],
                    $[free_close],
                ].filter(n => n !== null)
            )
        )
    }
    rules[prefix + type] = ($) => choice(
        prec.dynamic(1, seq(
            alias($[open], $.open),
            choice(
                ...[
                    $[word_segment],
                    $[punc_segment],
                    verbatim ? null : $[att_mod_segment],
                ].filter(n => n !== null)
            )
        )),
        prec.dynamic(2, seq(
            alias($[free_open], $.free_open),
            choice(
                ...[
                    $[free_word_segment],
                    $[free_ws_punc_segment],
                    verbatim ? null : $[free_att_mod_segment],
                ].filter(n => n !== null)
            )
        ))
    )
    return rules
}

function gen_non_verbatim_attached_modifier(type, mod) {
    return {
        ...gen_attached_modifier(type, mod, false, true),
        ...gen_attached_modifier(type, mod, false, false),
    }
}

function gen_verbatim_attached_modifier(type, mod) {
    return {
        ...gen_attached_modifier(type, mod, true, true),
        ...gen_attached_modifier(type, mod, true, false),
    }
}
