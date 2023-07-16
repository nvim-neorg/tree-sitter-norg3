let newline = choice("\n", "\r", "\r\n");
let newline_or_eof = choice("\n", "\r", "\r\n", "\0");

module.exports = grammar({
    name: "norg",

    // Tell treesitter we want to handle whitespace ourselves
    extras: ($) => [$._preceding_whitespace],
    externals: ($) => [$._preceding_whitespace, $.heading_stars, $._dedent],

    conflicts: ($) => [],

    precedences: ($) => [],

    inlines: ($) => [],

    supertypes: ($) => [$.non_structural],

    rules: {
        document: ($) => repeat(choice($.heading)),

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
                    newline_or_eof
                )
            ),

        heading: ($) =>
            prec.right(
                seq(
                    $.heading_stars,
                    alias(repeat1($._paragraph_inner), $.title),
                    newline_or_eof,
                    repeat(choice($.heading, $.non_structural)),
                    optional($._dedent)
                )
            ),
    },
});
