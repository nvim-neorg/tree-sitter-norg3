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

        $.bold_open,
        $.italic_open,
        $.strikethrough_open,
        $.underline_open,
        $.spoiler_open,
        $.superscript_open,
        $.subscript_open,
        $.verbatim_open,
        $.null_modifier_open,
        $.inline_math_open,
        $.inline_macro_open,

        $.bold_close,
        $.italic_close,
        $.strikethrough_close,
        $.underline_close,
        $.spoiler_close,
        $.superscript_close,
        $.subscript_close,
        $.verbatim_close,
        $.null_modifier_close,
        $.inline_math_close,
        $.inline_macro_close,

        $._dedent,
    ],

    conflicts: ($) => [
        [$.bold, $._attached_modifier_conflict_open],
        [$.italic, $._attached_modifier_conflict_open],
        [$.strikethrough, $._attached_modifier_conflict_open],
        [$.underline, $._attached_modifier_conflict_open],
        [$.spoiler, $._attached_modifier_conflict_open],
        [$.superscript, $._attached_modifier_conflict_open],
        [$.subscript, $._attached_modifier_conflict_open],
        [$.null_modifier, $._attached_modifier_conflict_open],

        [$.bold_inline, $._attached_modifier_conflict_open],
        [$.italic_inline, $._attached_modifier_conflict_open],
        [$.strikethrough_inline, $._attached_modifier_conflict_open],
        [$.underline_inline, $._attached_modifier_conflict_open],
        [$.spoiler_inline, $._attached_modifier_conflict_open],
        [$.superscript_inline, $._attached_modifier_conflict_open],
        [$.subscript_inline, $._attached_modifier_conflict_open],
        [$.null_modifier_inline, $._attached_modifier_conflict_open],
    ],

    precedences: ($) => [[$.heading, $.delimiting_modifier]],

    inlines: ($) => [$._title_inline],

    supertypes: ($) => [
        $.non_structural,
        $.nestable_modifier,
        $.rangeable_detached_modifier,
        $.tag,
        $.todo_item,
        $.delimiting_modifier,
        $.attached_modifier,
        $.attached_modifier_inline,
        $._attached_modifier_conflict_open,
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

        // TODO: Make those use another construct
        // like a "paragraph_segment" that uses "bold_single_line" (don't allow the bold to overflow across
        // lines!!).
        _paragraph_inner: ($) => choice($._word, $.escape_sequence),

        _paragraph_segment: ($) =>
            prec.right(
                seq(
                    choice(
                        repeat1($._paragraph_inner),
                        seq(
                            $.attached_modifier,
                            repeat(
                                prec.right($._attached_modifier_conflict_open),
                            ),
                            optional($._paragraph_segment),
                        ),
                        seq(
                            $._attached_modifier_conflict_open,
                            $._paragraph_segment,
                        ),
                    ),
                    repeat(
                        seq(
                            $._whitespace,
                            choice(
                                seq(
                                    $.attached_modifier,
                                    repeat(
                                        prec.right(
                                            $._attached_modifier_conflict_open,
                                        ),
                                    ),
                                    optional($._paragraph_segment),
                                ),
                                seq(
                                    $._attached_modifier_conflict_open,
                                    $._paragraph_segment,
                                ),
                                repeat1($._paragraph_inner),
                            ),
                        ),
                    ),
                ),
            ),

        paragraph: ($) =>
            prec.right(
                seq(
                    $._paragraph_segment,
                    repeat(
                        seq(
                            newline,
                            choice(
                                $._paragraph_segment,
                                seq($.weak_carryover_tag, $._paragraph_segment),
                            ),
                        ),
                    ),
                    newline_or_eof,
                ),
            ),

        // This is a meta-node to make treesitter do what we want it to.
        // If you make `$.title` self-reference with a hidden alias (e.g. `alias($.title, "_title")`,
        // then the content is still marked "nested". As a result when you do `*hello* /world/`, `*hello*`
        // self-references `title`, which then makes `/world/` a subchild of `*hello*`, even though it absolutely
        // shouldn't. This node is marked inline in the AST, preventing
        _title_inline: ($) =>
            prec.right(
                seq(
                    choice(
                        repeat1($._paragraph_inner),
                        seq(
                            $.attached_modifier_inline,
                            repeat(
                                prec.right($._attached_modifier_conflict_open),
                            ),
                            optional($._title_inline),
                        ),
                        seq(
                            $._attached_modifier_conflict_open,
                            $._title_inline,
                        ),
                    ),
                    repeat(
                        seq(
                            $._whitespace,
                            choice(
                                seq(
                                    $.attached_modifier_inline,
                                    repeat(
                                        prec.right(
                                            $._attached_modifier_conflict_open,
                                        ),
                                    ),
                                    optional($._title_inline),
                                ),
                                seq(
                                    $._attached_modifier_conflict_open,
                                    $._title_inline,
                                ),
                                repeat1($._paragraph_inner),
                            ),
                        ),
                    ),
                ),
            ),

        title: ($) =>
            prec.right(
                seq(
                    choice(
                        repeat1($._paragraph_inner),
                        seq(
                            $.attached_modifier_inline,
                            repeat(
                                prec.right($._attached_modifier_conflict_open),
                            ),
                            optional($._title_inline),
                        ),
                        seq(
                            $._attached_modifier_conflict_open,
                            $._title_inline,
                        ),
                    ),
                    repeat(
                        seq(
                            $._whitespace,
                            choice(
                                seq(
                                    $.attached_modifier_inline,
                                    repeat(
                                        prec.right(
                                            $._attached_modifier_conflict_open,
                                        ),
                                    ),
                                    optional($._title_inline),
                                ),
                                seq(
                                    $._attached_modifier_conflict_open,
                                    $._title_inline,
                                ),
                                repeat1($._paragraph_inner),
                            ),
                        ),
                    ),
                ),
            ),

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
                "$",
                $._whitespace,
                optional(seq($.detached_modifier_extension, $._whitespace)),
                $.title,
                repeat1(newline),
                $.paragraph,
            ),

        definition_list_multi: ($) =>
            prec.right(
                seq(
                    "$$",
                    $._whitespace,
                    optional(seq($.detached_modifier_extension, $._whitespace)),
                    $.title,
                    newline_or_eof,
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
                $.title,
                repeat1(newline),
                $.paragraph,
            ),

        footnote_list_multi: ($) =>
            prec.right(
                seq(
                    "^^",
                    $._whitespace,
                    optional(seq($.detached_modifier_extension, $._whitespace)),
                    $.title,
                    newline_or_eof,
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
                $.title,
                repeat1(newline),
                $.paragraph,
            ),

        table_cell_multi: ($) =>
            prec.right(
                seq(
                    "::",
                    $._whitespace,
                    optional(seq($.detached_modifier_extension, $._whitespace)),
                    $.title,
                    newline_or_eof,
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

        attached_modifier: ($) =>
            choice(
                $.bold,
                $.italic,
                $.strikethrough,
                $.underline,
                $.spoiler,
                $.superscript,
                $.subscript,
                $.null_modifier,
            ),
        attached_modifier_inline: ($) =>
            choice(
                $.bold_inline,
                $.italic_inline,
                $.strikethrough_inline,
                $.underline_inline,
                $.spoiler_inline,
                $.superscript_inline,
                $.subscript_inline,
                $.null_modifier_inline,
            ),

        _attached_modifier_conflict_open: ($) =>
            choice(
                $.bold_open,
                $.italic_open,
                $.strikethrough_open,
                $.underline_open,
                $.spoiler_open,
                $.superscript_open,
                $.subscript_open,
                $.null_modifier_open,
            ),

        bold: ($) => attached_modifier($, "bold"),
        italic: ($) => attached_modifier($, "italic"),
        strikethrough: ($) => attached_modifier($, "strikethrough"),
        underline: ($) => attached_modifier($, "underline"),
        spoiler: ($) => attached_modifier($, "spoiler"),
        superscript: ($) => attached_modifier($, "superscript"),
        subscript: ($) => attached_modifier($, "subscript"),
        // TODO: Verbatim stuff
        null_modifier: ($) => attached_modifier($, "null_modifier"),

        bold_inline: ($) => attached_modifier_inline($, "bold"),
        italic_inline: ($) => attached_modifier_inline($, "italic"),
        strikethrough_inline: ($) =>
            attached_modifier_inline($, "strikethrough"),
        underline_inline: ($) => attached_modifier_inline($, "underline"),
        spoiler_inline: ($) => attached_modifier_inline($, "spoiler"),
        superscript_inline: ($) => attached_modifier_inline($, "superscript"),
        subscript_inline: ($) => attached_modifier_inline($, "subscript"),
        // TODO: Verbatim stuff
        null_modifier_inline: ($) =>
            attached_modifier_inline($, "null_modifier"),
    },
});

function attached_modifier($, type) {
    const other_attached_modifiers = [
        "bold",
        "italic",
        "strikethrough",
        "underline",
        "spoiler",
        "superscript",
        "subscript",
        // "verbatim",
        "null_modifier",
        // "inline_math",
        // "inline_macro",
    ]
        .filter((x) => x != type)
        .map((x) => $[x]);

    return prec.dynamic(
        1,
        seq(
            $[type + "_open"],
            seq(
                repeat1(
                    choice(
                        $._paragraph_inner,
                        ...other_attached_modifiers,
                        $._whitespace,
                        $._attached_modifier_conflict_open,
                    ),
                ),
                repeat(
                    seq(
                        newline,
                        repeat1(
                            choice(
                                $._paragraph_inner,
                                ...other_attached_modifiers,
                                $._whitespace,
                                $._attached_modifier_conflict_open,
                            ),
                        ),
                    ),
                ),
            ),
            $[type + "_close"],
        ),
    );
}

function attached_modifier_inline($, type) {
    const other_attached_modifiers = [
        "bold",
        "italic",
        "strikethrough",
        "underline",
        "spoiler",
        "superscript",
        "subscript",
        // "verbatim",
        "null_modifier",
        // "inline_math",
        // "inline_macro",
    ]
        .filter((x) => x != type)
        .map((x) => $[x + "_inline"]);

    return prec.dynamic(
        1,
        seq(
            $[type + "_open"],
            repeat1(
                choice(
                    $._paragraph_inner,
                    ...other_attached_modifiers,
                    $._whitespace,
                    $._attached_modifier_conflict_open,
                ),
            ),
            $[type + "_close"],
        ),
    );
}
