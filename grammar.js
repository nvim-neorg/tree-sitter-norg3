let newline = choice("\n", "\r", "\r\n");
let newline_or_eof = choice("\n", "\r", "\r\n", "\0");

/// General TODOS:
//  - Abstract repeating patterns (e.g. nestable detached modifiers) into Javascript functions.

module.exports = grammar({
    name: "norg",

    // Tell treesitter we want to handle whitespace ourselves
    extras: ($) => [],
    externals: ($) => [
        $._whitespace,
        $._word,

        $.bold_open,
        $.bold_close,
        $.free_bold_open,
        $.free_bold_close,
        $.italic_open,
        $.italic_close,
        $.free_italic_open,
        $.free_italic_close,
        $.strikethrough_open,
        $.strikethrough_close,
        $.free_strikethrough_open,
        $.free_strikethrough_close,
        $.underline_open,
        $.underline_close,
        $.free_underline_open,
        $.free_underline_close,
        $.spoiler_open,
        $.spoiler_close,
        $.free_spoiler_open,
        $.free_spoiler_close,
        $.superscript_open,
        $.superscript_close,
        $.free_superscript_open,
        $.free_superscript_close,
        $.subscript_open,
        $.subscript_close,
        $.free_subscript_open,
        $.free_subscript_close,
        $.inline_comment_open,
        $.inline_comment_close,
        $.free_inline_comment_open,
        $.free_inline_comment_close,
        $.verbatim_open,
        $.verbatim_close,
        $.free_verbatim_open,
        $.free_verbatim_close,
        $.inline_math_open,
        $.inline_math_close,
        $.free_inline_math_open,
        $.free_inline_math_close,
        $.inline_macro_open,
        $.inline_macro_close,
        $.free_inline_macro_open,
        $.free_inline_macro_close,

        $.link_modifier,
        $.escape_sequence_prefix,
        $._punc_end,

        $.heading_stars,
        $.unordered_list_prefix,
        $.ordered_list_prefix,
        $.quote_prefix,

        $.weak_delimiting_modifier,

        $._dedent,
    ],

    conflicts: ($) => [
        [$.bold, $._mod_conflict],
        [$.italic, $._mod_conflict],
        [$.strikethrough, $._mod_conflict],
        [$.underline, $._mod_conflict],
        [$.spoiler, $._mod_conflict],
        [$.superscript, $._mod_conflict],
        [$.subscript, $._mod_conflict],
        [$.inline_comment, $._mod_conflict],
        [$.verbatim, $._mod_conflict],
        [$.inline_math, $._mod_conflict],
        [$.inline_macro, $._mod_conflict],
        [$._attached_modifier, $._mod_conflict],
        [$._attached_modifier],
        [$.table_cell_single, $._punc],
        [$.detached_modifier_extension, $._punc],
    ],

    precedences: ($) => [[$.heading, $.delimiting_modifier]],

    inlines: ($) => [],

    supertypes: ($) => [
        $.non_structural,
        $.nestable_modifier,
        $.rangeable_detached_modifier,
        $.tag,
        $.todo_item,
        $.delimiting_modifier,
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

        escape_sequence: ($) => seq($.escape_sequence_prefix, alias(prec(10, choice(/./, newline)), $.escape_char)),

        _paragraph_inner: ($) =>
            choice(
                $.escape_sequence,
                $._word,
                $._whitespace,
                $._punc,
                $._mod_conflict,
                $._attached_modifier,
            ),

        paragraph: ($) =>
            prec.right(
                seq(
                    repeat1($._paragraph_inner),
                    repeat(
                        seq(
                            newline,
                            repeat1(
                                choice(
                                    $._paragraph_inner,
                                    seq(
                                        $.weak_carryover_tag,
                                        $._paragraph_inner,
                                    ),
                                ),
                            ),
                        ),
                    ),
                    newline_or_eof,
                ),
            ),

        heading: ($) =>
            prec.right(
                seq(
                    $.heading_stars,
                    $._whitespace,
                    optional(seq($.detached_modifier_extension, $._whitespace)),
                    alias(repeat1($._paragraph_inner), $.title),
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
                "$",
                $._whitespace,
                optional(seq($.detached_modifier_extension, $._whitespace)),
                alias($._paragraph_inner, $.title),
                repeat1(newline),
                $.paragraph,
            ),

        definition_list_multi: ($) =>
            prec.right(
                seq(
                    "$$",
                    $._whitespace,
                    optional(seq($.detached_modifier_extension, $._whitespace)),
                    alias($._paragraph_inner, $.title),
                    repeat($.non_structural),
                    "$$",
                ),
            ),

        footnote_list: ($) =>
            choice($.footnote_list_single, $.footnote_list_multi),

        footnote_list_single: ($) =>
            seq(
                "^",
                $._whitespace,
                optional(seq($.detached_modifier_extension, $._whitespace)),
                alias($._paragraph_inner, $.title),
                repeat1(newline),
                $.paragraph,
            ),

        footnote_list_multi: ($) =>
            prec.right(
                seq(
                    "^^",
                    $._whitespace,
                    optional(seq($.detached_modifier_extension, $._whitespace)),
                    alias($._paragraph_inner, $.title),
                    repeat($.non_structural),
                    "^^",
                ),
            ),

        table: ($) => choice($.table_cell_single, $.table_cell_multi),

        table_cell_single: ($) =>
            seq(
                ":",
                $._whitespace,
                optional(seq($.detached_modifier_extension, $._whitespace)),
                alias($._paragraph_inner, $.title),
                repeat1(newline),
                $.paragraph,
            ),

        table_cell_multi: ($) =>
            prec.right(
                seq(
                    "::",
                    $._whitespace,
                    optional(seq($.detached_modifier_extension, $._whitespace)),
                    alias($._paragraph_inner, $.title),
                    repeat($.non_structural),
                    "::",
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
                alias(repeat1(token(prec(1, /[a-zA-Z]/))), $.identifier),
                repeat(
                    seq(
                        ".",
                        alias(
                            repeat1(token(prec(1, /[a-zA-Z]/))),
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
                                repeat1(alias($._word, $.parameter)),
                                repeat(
                                    seq(
                                        $._whitespace,
                                        optional(alias($._word, $.parameter)),
                                    ),
                                ),
                            ),
                        ),
                    ),
                ),
                newline,
                alias(
                    repeat(choice($._word, $._whitespace, newline)),
                    $.verbatim_content,
                ),
                newline,
                "@end",
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
                                repeat1(alias($._word, $.parameter)),
                                repeat(
                                    seq(
                                        $._whitespace,
                                        optional(alias($._word, $.parameter)),
                                    ),
                                ),
                            ),
                        ),
                    ),
                ),
                newline,
                alias(repeat(choice($.non_structural, $.heading)), $.content),
                "|end",
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
                                repeat1(alias($._word, $.parameter)),
                                repeat(
                                    seq(
                                        $._whitespace,
                                        optional(alias($._word, $.parameter)),
                                    ),
                                ),
                            ),
                        ),
                    ),
                ),
                newline,
                alias(repeat(choice($.non_structural, $.heading)), $.content),
                "=end",
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
                                repeat1(alias($._word, $.parameter)),
                                repeat(
                                    seq(
                                        $._whitespace,
                                        optional(alias($._word, $.parameter)),
                                    ),
                                ),
                            ),
                        ),
                    ),
                ),
                newline,
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
                                repeat1(alias($._word, $.parameter)),
                                repeat(
                                    seq(
                                        $._whitespace,
                                        optional(alias($._word, $.parameter)),
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
                                repeat1(alias($._word, $.parameter)),
                                repeat(
                                    seq(
                                        $._whitespace,
                                        optional(alias($._word, $.parameter)),
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
        _punc: $ => seq(
            choice(
                // combine all repeated token to ignore repeated attached modifiers
                token(prec.right(repeat1("*"))),
                token(prec.right(repeat1("/"))),
                token(prec.right(repeat1("-"))),
                token(prec.right(repeat1("_"))),
                token(prec.right(repeat1("!"))),
                token(prec.right(repeat1("`"))),
                token(prec.right(repeat1("^"))),
                token(prec.right(repeat1(","))),
                token(prec.right(repeat1("%"))),
                token(prec.right(repeat1("$"))),
                token(prec.right(repeat1("&"))),
                ".",
                "<",
                ">",
                "(",
                ")",
                "\\",
                ":",
                "|"
            ),
            optional($._punc_end)
        ),
        _attached_mod_content: $ =>
            prec.right(seq(
                repeat1($._paragraph_inner),
                repeat(
                    seq(
                        newline,
                        repeat1($._paragraph_inner),
                    )
                ),
            )),
        _verbatim_paragraph_element: $ =>
            choice(
                $.escape_sequence,
                $._word,
                $._whitespace,
                $._punc,
                $._mod_conflict,
            ),
        _verbatim_paragraph_content: $ =>
            prec.right(seq(
                repeat1($._verbatim_paragraph_element),
                repeat(
                    seq(
                        newline,
                        repeat1($._verbatim_paragraph_element),
                    )
                )
            )),
        _free_form_verbatim_mod_content: $ =>
            prec.right(
                repeat1(
                    choice(
                        choice(
                            // $.escape_sequence,
                            $._word,
                            $._whitespace,
                            $._punc,
                            $._mod_conflict,
                        ),
                        newline,
                    )
                )
            ),
        _attached_modifier: $ =>
            seq(
                optional($.link_modifier),
                choice(
                    $.bold,
                    $.italic,
                    $.strikethrough,
                    $.underline,
                    $.spoiler,
                    $.superscript,
                    $.subscript,
                    $.inline_comment,
                    $.verbatim,
                    $.inline_math,
                    $.inline_macro,
                ),
                optional($.link_modifier),
            ),
        _mod_conflict: $ =>
            alias(
                choice(
                    $.bold_open,
                    $.italic_open,
                    $.strikethrough_open,
                    $.underline_open,
                    $.spoiler_open,
                    $.superscript_open,
                    $.subscript_open,
                    $.inline_comment_open,
                    $.verbatim_open,
                    $.inline_math_open,
                    $.inline_macro_open,
                    $.free_bold_open,
                    $.free_italic_open,
                    $.free_strikethrough_open,
                    $.free_underline_open,
                    $.free_spoiler_open,
                    $.free_superscript_open,
                    $.free_subscript_open,
                    $.free_inline_comment_open,
                    $.free_verbatim_open,
                    $.free_inline_math_open,
                    $.free_inline_macro_open,
                    $.link_modifier,
                ),
            "_punc"),
        bold: $ => gen_attached_modifier($, "bold", false),
        italic: $ => gen_attached_modifier($, "italic", false),
        strikethrough: $ => gen_attached_modifier($, "strikethrough", false),
        underline: $ => gen_attached_modifier($, "underline", false),
        spoiler: $ => gen_attached_modifier($, "spoiler", false),
        superscript: $ => gen_attached_modifier($, "superscript", false),
        subscript: $ => gen_attached_modifier($, "subscript", false),
        inline_comment: $ => gen_attached_modifier($, "inline_comment", false),
        verbatim: $ => gen_attached_modifier($, "verbatim", true),
        inline_math: $ => gen_attached_modifier($, "inline_math", true),
        inline_macro: $ => gen_attached_modifier($, "inline_macro", true),
    },
});

function gen_attached_modifier($, kind, verbatim) {
    let open = alias($[kind + "_open"], "_open");
    let close = alias($[kind + "_close"], "_close");
    let free_open = alias($["free_" + kind + "_open"], $.free_form_open);
    let free_close = alias($["free_" + kind + "_close"], $.free_form_close);
    let content = $._attached_mod_content;
    let free_form_content = $._attached_mod_content;
    let precedence = 2;

    if (verbatim) {
        content = $._verbatim_paragraph_content;
        free_form_content = $._free_form_verbatim_mod_content;
        precedence = 5;
    }
    return choice(
        prec.dynamic(precedence + 1, seq(
            free_open,
            free_form_content,
            free_close,
        )),
        prec.dynamic(precedence, seq(
            open,
            content,
            close,
        ))
    )
}
