let newline = choice("\n", "\r", "\r\n");
let newline_or_eof = choice("\n", "\r", "\r\n", "\0");

/// General TODOS:
//  - Abstract repeating patterns (e.g. nestable detached modifiers) into Javascript functions.

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

    conflicts: ($) => [],

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

        _character: (_) => token(/[^\s]/),
        _word: ($) => prec.right(repeat1($._character)),
        _whitespace: (_) => token(prec(1, /[\t                　]+/)),

        escape_sequence: ($) => seq("\\", alias(prec(10, /./), $.escape_char)),

        _paragraph_inner: ($) =>
            choice($._word, $._whitespace, $.escape_sequence),

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
    },
});
