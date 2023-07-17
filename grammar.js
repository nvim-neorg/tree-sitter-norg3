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
        $._dedent,
    ],

    conflicts: ($) => [],

    precedences: ($) => [],

    inlines: ($) => [],

    supertypes: ($) => [$.non_structural, $.nestable_modifiers],

    rules: {
        document: ($) =>
            repeat(choice($.non_structural, $.heading, $.nestable_modifiers)),

        non_structural: ($) => choice($.paragraph, newline),

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
                    repeat(
                        choice(
                            $.heading,
                            $.non_structural,
                            $.nestable_modifiers,
                        ),
                    ),
                    optional($._dedent),
                ),
            ),

        nestable_modifiers: ($) => choice($.unordered_list, $.ordered_list),

        unordered_list: ($) => prec.right(repeat1($.unordered_list_item)),
        ordered_list: ($) => prec.right(repeat1($.ordered_list_item)),

        unordered_list_item: ($) =>
            prec.right(
                seq(
                    $.unordered_list_prefix,
                    $._whitespace,
                    $.paragraph,
                    repeat($.unordered_list),
                    optional($._dedent),
                ),
            ),

        ordered_list_item: ($) =>
            prec.right(
                seq(
                    $.ordered_list_prefix,
                    $._whitespace,
                    $.paragraph,
                    repeat($.ordered_list),
                    optional($._dedent),
                ),
            ),
    },
});

function nestable_detached_modifier($, prefix_type, chr) {}
