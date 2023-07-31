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
        [$.verbatim, $._attached_modifier_conflict_open],
        [$.null_modifier, $._attached_modifier_conflict_open],

        [$.bold_inline, $._attached_modifier_conflict_open],
        [$.italic_inline, $._attached_modifier_conflict_open],
        [$.strikethrough_inline, $._attached_modifier_conflict_open],
        [$.underline_inline, $._attached_modifier_conflict_open],
        [$.spoiler_inline, $._attached_modifier_conflict_open],
        [$.superscript_inline, $._attached_modifier_conflict_open],
        [$.subscript_inline, $._attached_modifier_conflict_open],
        [$.verbatim_inline, $._attached_modifier_conflict_open],
        [$.null_modifier_inline, $._attached_modifier_conflict_open],

        // TODO: Is it possible to remove this conflict?
        [$._paragraph_segment],

        [$._title_inline],
        [$._bold_paragraph_segment],
        [$._italic_paragraph_segment],
        [$._strikethrough_paragraph_segment],
        [$._underline_paragraph_segment],
        [$._spoiler_paragraph_segment],
        [$._superscript_paragraph_segment],
        [$._subscript_paragraph_segment],
        [$._subscript_paragraph_segment],
        [$._null_modifier_paragraph_segment],
        [$._bold_inline_paragraph_segment],
        [$._italic_inline_paragraph_segment],
        [$._strikethrough_inline_paragraph_segment],
        [$._underline_inline_paragraph_segment],
        [$._spoiler_inline_paragraph_segment],
        [$._superscript_inline_paragraph_segment],
        [$._subscript_inline_paragraph_segment],
        [$._subscript_inline_paragraph_segment],
        [$._null_modifier_inline_paragraph_segment],
        [$._verbatim_paragraph_segment],
    ],

    precedences: ($) => [
        [$.heading, $.delimiting_modifier],
        [$.horizontal_line, $.underline_open],
        [$.footnote_list_single, $.superscript_open],
    ],

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

        _character: (_) => token(/[\p{L}\p{N}]/u),
        // TODO: Is there a way of shortening this regex? If there were set intersection, we could
        // do: \p{P}&&[^\n\r]. Apparently \p{P} includes newlines, which causes problems.
        _punctuation: (_) => token(/[^\n\r\p{Z}\p{L}\p{N}]/u),
        _word: ($) => prec.right(-1, repeat1($._character)),
        _whitespace: (_) => token(prec(1, /\p{Zs}+/u)),

        bold_open: (_) => "*",
        italic_open: (_) => "/",
        strikethrough_open: (_) => "-",
        underline_open: (_) => "_",
        spoiler_open: (_) => "!",
        superscript_open: (_) => "^",
        subscript_open: (_) => ",",
        verbatim_open: (_) => "`",
        null_modifier_open: (_) => "%",
        inline_math_open: (_) => "$",
        inline_macro_open: (_) => "&",

        escape_sequence: ($) => seq("\\", alias(prec(10, /./), $.escape_char)),

        _paragraph_inner: ($) =>
            choice($._word, $.escape_sequence, $._punctuation),

        // TODO: Make the choices a little more explicit. Make the part after $._whitespace optional,
        // see if the attached modifier edge cases still function.
        _paragraph_segment: ($) =>
            prec.right(
                seq(
                    choice(
                        repeat1($._paragraph_inner),
                        seq(
                            repeat1(
                                choice(
                                    $._attached_modifier_conflict_open,
                                    $.attached_modifier,
                                ),
                            ),
                            optional($._paragraph_segment),
                        ),
                    ),
                    repeat(
                        prec.right(
                            1,
                            seq(
                                choice($._whitespace, $._punctuation),
                                optional(
                                    choice(
                                        repeat1($._paragraph_inner),
                                        seq(
                                            repeat1(
                                                choice(
                                                    $._attached_modifier_conflict_open,
                                                    $.attached_modifier,
                                                ),
                                            ),
                                            optional($._paragraph_segment),
                                        ),
                                    ),
                                ),
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
                            repeat1(
                                choice(
                                    $._attached_modifier_conflict_open,
                                    $.attached_modifier_inline,
                                ),
                            ),
                            optional($._title_inline),
                        ),
                    ),
                    repeat(
                        seq(
                            $._whitespace,
                            optional(
                                choice(
                                    repeat1($._paragraph_inner),
                                    seq(
                                        repeat1(
                                            choice(
                                                $._attached_modifier_conflict_open,
                                                $.attached_modifier_inline,
                                            ),
                                        ),
                                        optional($._title_inline),
                                    ),
                                ),
                            ),
                        ),
                    ),
                ),
            ),

        title: ($) => $._title_inline,

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
                                alias(repeat1(choice($._word, $._punctuation)), $.parameter),
                                repeat(
                                    seq(
                                        $._whitespace,
                                        optional(alias(repeat1(choice($._word, $._punctuation)), $.parameter)),
                                    ),
                                ),
                            ),
                        ),
                    ),
                ),
                newline,
                alias(
                    repeat(choice($._word, $._whitespace, $._punctuation, newline)),
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
                                alias(repeat1(choice($._word, $._punctuation)), $.parameter),
                                repeat(
                                    seq(
                                        $._whitespace,
                                        optional(alias(repeat1(choice($._word, $._punctuation)), $.parameter)),
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
                                alias(repeat1(choice($._word, $._punctuation)), $.parameter),
                                repeat(
                                    seq(
                                        $._whitespace,
                                        optional(alias(repeat1(choice($._word, $._punctuation)), $.parameter)),
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
                                alias(repeat1(choice($._word, $._punctuation)), $.parameter),
                                repeat(
                                    seq(
                                        $._whitespace,
                                        optional(alias(repeat1(choice($._word, $._punctuation)), $.parameter)),
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
                                alias(repeat1(choice($._word, $._punctuation)), $.parameter),
                                repeat(
                                    seq(
                                        $._whitespace,
                                        optional(alias(repeat1(choice($._word, $._punctuation)), $.parameter)),
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
                                alias(repeat1(choice($._word, $._punctuation)), $.parameter),
                                repeat(
                                    seq(
                                        $._whitespace,
                                        optional(alias(repeat1(choice($._word, $._punctuation)), $.parameter)),
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
                $.verbatim,
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
                $.verbatim_inline,
                $.null_modifier_inline,
            ),

        _attached_modifier_conflict_open: ($) =>
            alias(
                choice(
                    $.bold_open,
                    $.italic_open,
                    $.strikethrough_open,
                    $.underline_open,
                    $.spoiler_open,
                    $.superscript_open,
                    $.subscript_open,
                    $.null_modifier_open,
                    $.verbatim_open,
                ),
                "_word",
            ),

        _bold_paragraph_segment: ($) => attached_modifier_para_seg($, "bold"),
        _italic_paragraph_segment: ($) =>
            attached_modifier_para_seg($, "italic"),
        _strikethrough_paragraph_segment: ($) =>
            attached_modifier_para_seg($, "strikethrough"),
        _underline_paragraph_segment: ($) =>
            attached_modifier_para_seg($, "underline"),
        _spoiler_paragraph_segment: ($) =>
            attached_modifier_para_seg($, "spoiler"),
        _superscript_paragraph_segment: ($) =>
            attached_modifier_para_seg($, "superscript"),
        _subscript_paragraph_segment: ($) =>
            attached_modifier_para_seg($, "subscript"),
        _null_modifier_paragraph_segment: ($) =>
            attached_modifier_para_seg($, "null_modifier"),
        _verbatim_paragraph_segment: ($) =>
            seq(
                repeat1(
                    choice(
                        $._paragraph_inner,
                        $._attached_modifier_conflict_open,
                    ),
                ),
                repeat(
                    seq(
                        $._whitespace,
                        repeat1(
                            choice(
                                $._paragraph_inner,
                                $._attached_modifier_conflict_open,
                            ),
                        ),
                    ),
                ),
            ),

        _bold_inline_paragraph_segment: ($) =>
            attached_modifier_para_seg($, "bold", true),
        _italic_inline_paragraph_segment: ($) =>
            attached_modifier_para_seg($, "italic", true),
        _strikethrough_inline_paragraph_segment: ($) =>
            attached_modifier_para_seg($, "strikethrough", true),
        _underline_inline_paragraph_segment: ($) =>
            attached_modifier_para_seg($, "underline", true),
        _spoiler_inline_paragraph_segment: ($) =>
            attached_modifier_para_seg($, "spoiler", true),
        _superscript_inline_paragraph_segment: ($) =>
            attached_modifier_para_seg($, "superscript", true),
        _subscript_inline_paragraph_segment: ($) =>
            attached_modifier_para_seg($, "subscript", true),
        _null_modifier_inline_paragraph_segment: ($) =>
            attached_modifier_para_seg($, "null_modifier", true),

        bold: ($) => attached_modifier($, "bold"),
        italic: ($) => attached_modifier($, "italic"),
        strikethrough: ($) => attached_modifier($, "strikethrough"),
        underline: ($) => attached_modifier($, "underline"),
        spoiler: ($) => attached_modifier($, "spoiler"),
        superscript: ($) => attached_modifier($, "superscript"),
        subscript: ($) => attached_modifier($, "subscript"),
        verbatim: ($) => attached_modifier_verbatim($, "verbatim"),
        null_modifier: ($) => attached_modifier($, "null_modifier"),

        bold_inline: ($) => attached_modifier_inline($, "bold"),
        italic_inline: ($) => attached_modifier_inline($, "italic"),
        strikethrough_inline: ($) =>
            attached_modifier_inline($, "strikethrough"),
        underline_inline: ($) => attached_modifier_inline($, "underline"),
        spoiler_inline: ($) => attached_modifier_inline($, "spoiler"),
        superscript_inline: ($) => attached_modifier_inline($, "superscript"),
        subscript_inline: ($) => attached_modifier_inline($, "subscript"),
        verbatim_inline: ($) =>
            attached_modifier_verbatim_inline($, "verbatim"),
        null_modifier_inline: ($) =>
            attached_modifier_inline($, "null_modifier"),
    },
});

function attached_modifier_para_seg($, type, inline) {
    const other_attached_modifiers = [
        "bold",
        "italic",
        "strikethrough",
        "underline",
        "spoiler",
        "superscript",
        "subscript",
        "null_modifier",
        "verbatim",
        // "inline_math",
        // "inline_macro",
    ]
        .filter((x) => x != type)
        .map((x) => $[inline ? x + "_inline" : x]);
    type = inline ? type + "_inline" : type;
    const paragraph_segment = $["_" + type + "_paragraph_segment"];
    return seq(
        choice(
            repeat1($._paragraph_inner),
            seq(
                repeat1(
                    choice(
                        $._attached_modifier_conflict_open,
                        ...other_attached_modifiers,
                    ),
                ),
                optional(paragraph_segment),
            ),
        ),
        repeat(
            prec.right(
                1,
                seq(
                    choice($._whitespace, $._punctuation),
                    choice(
                        repeat1($._paragraph_inner),
                        seq(
                            repeat1(
                                choice(
                                    $._attached_modifier_conflict_open,
                                    ...other_attached_modifiers,
                                ),
                            ),
                            optional(paragraph_segment),
                        ),
                    ),
                ),
            ),
        ),
    );
}

function attached_modifier($, type) {
    const paragraph_segment = $["_" + type + "_paragraph_segment"];
    return prec.dynamic(
        1,
        seq(
            $[type + "_open"],
            paragraph_segment,
            repeat(
                seq(
                    optional($._whitespace),
                    newline,
                    choice(
                        paragraph_segment,
                        seq($.weak_carryover_tag, paragraph_segment),
                    ),
                ),
            ),
            $[type + "_close"],
        ),
    );
}

function attached_modifier_verbatim($, type) {
    return prec.dynamic(
        2,
        seq(
            $[type + "_open"],
            $._verbatim_paragraph_segment,
            repeat(
                seq(
                    optional($._whitespace),
                    newline,
                    $._verbatim_paragraph_segment,
                ),
            ),
            $[type + "_close"],
        ),
    );
}

function attached_modifier_verbatim_inline($, type) {
    return prec.dynamic(
        2,
        seq(
            $[type + "_open"],
            $._verbatim_paragraph_segment,
            $[type + "_close"],
        ),
    );
}

function attached_modifier_inline($, type) {
    return prec.dynamic(
        1,
        seq(
            $[type + "_open"],
            $["_" + type + "_inline_paragraph_segment"],
            $[type + "_close"],
        ),
    );
}
