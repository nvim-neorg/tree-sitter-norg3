let newline = choice("\n", "\r", "\r\n");
let newline_or_eof = choice("\n", "\r", "\r\n", "\0");

/// General TODOS:
//  - Abstract repeating patterns (e.g. nestable detached modifiers) into Javascript functions.
//  - Add tests for link modifiers, then everything else.
//  - Make every node have an alias($.node, $.node_prefix). Only some currently do.

module.exports = grammar({
    name: "norg",

    // Tell treesitter we want to handle whitespace ourselves
    extras: ($) => [$._preceding_whitespace],
    externals: ($) => [$._preceding_whitespace, $.bold_open, $.bold_close],

    conflicts: ($) => [[$.paragraph, $.open_conflict]],

    precedences: ($) => [],

    inlines: ($) => [],

    supertypes: ($) => [],

    rules: {
        document: ($) => repeat(choice($.paragraph, $.paragraph_break)),

        _character: (_) => token(/[\p{L}\p{N}]/u),

        punctuation: ($) => choice("*", token(/[^\n\r\p{Z}\p{L}\p{N}]/u)),

        word: ($) => prec.right(repeat1($._character)),
        whitespace: (_) => token(prec(1, /\p{Zs}+/u)),

        paragraph: ($) =>
            prec.right(
                repeat1(
                    choice(
                        $.word,
                        newline,
                        $.open_conflict,
                        $.punctuation,
                        $.whitespace,
                        $.bold,
                    ),
                ),
            ),

        open_conflict: ($) => prec.right(seq(choice($.bold_open), $.word)),

        paragraph_break: (_) => token(seq(newline, newline_or_eof)),

        bold: ($) =>
            prec.dynamic(1, seq($.bold_open, $.paragraph, $.bold_close)),
    },
});
