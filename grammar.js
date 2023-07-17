let newline = choice("\n", "\r", "\r\n");
let newline_or_eof = choice("\n", "\r", "\r\n", "\0");

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

        $._dedent,
    ],

    conflicts: ($) => [],

    precedences: ($) => [],

    inlines: ($) => [],

    supertypes: ($) => [
        $.non_structural,
        $.nestable_modifiers,
        $.rangeable_detached_modifiers,
    ],

    rules: {
        document: ($) => repeat(choice($.non_structural, $.heading)),

        non_structural: ($) =>
            choice(
                $.paragraph,
                newline,
                $.nestable_modifiers,
                $.rangeable_detached_modifiers,
            ),

        _character: (_) => token(/[^\s]/),
        _word: ($) => prec.right(repeat1($._character)),
        _whitespace: (_) => token(/[\t                　]+/),

        escape_sequence: ($) => seq("\\", alias(prec(10, /./), $.escape_char)),

        _paragraph_inner: ($) =>
            choice($._word, $._whitespace, $.escape_sequence),

        paragraph: ($) =>
            prec.right(
                seq(
                    repeat1($._paragraph_inner),
                    repeat(seq(newline, repeat1($._paragraph_inner))),
                    newline_or_eof,
                ),
            ),

        heading: ($) =>
            prec.right(
                seq(
                    $.heading_stars,
                    alias(repeat1($._paragraph_inner), $.title),
                    newline_or_eof,
                    repeat(choice($.heading, $.non_structural)),
                    optional($._dedent),
                ),
            ),

        nestable_modifiers: ($) => choice($.unordered_list, $.ordered_list, $.quote),

        unordered_list: ($) => prec.right(repeat1($.unordered_list_item)),

        unordered_list_item: ($) =>
            prec.right(
                seq(
                    $.unordered_list_prefix,
                    $._whitespace,
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
                    $.paragraph,
                    repeat($.quote_item),
                    optional($._dedent),
                ),
            ),

        rangeable_detached_modifiers: ($) =>
            choice($.definition_list, $.footnote_list, $.table),

        definition_list: ($) =>
            choice($.definition_list_single, $.definition_list_multi),

        definition_list_single: ($) =>
            seq(
                "$",
                $._whitespace,
                alias($._paragraph_inner, $.title),
                repeat1(newline),
                $.paragraph,
            ),

        definition_list_multi: ($) =>
            prec.right(
                seq(
                    "$$",
                    $._whitespace,
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
                alias($._paragraph_inner, $.title),
                repeat1(newline),
                $.paragraph,
            ),

        footnote_list_multi: ($) =>
            prec.right(
                seq(
                    "^^",
                    $._whitespace,
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
                alias($._paragraph_inner, $.title),
                repeat1(newline),
                $.paragraph,
            ),

        table_cell_multi: ($) =>
            prec.right(
                seq(
                    "::",
                    $._whitespace,
                    alias($._paragraph_inner, $.title),
                    repeat($.non_structural),
                    "::",
                ),
            ),
    },
});

function nestable_detached_modifier($, prefix_type, chr) {}
