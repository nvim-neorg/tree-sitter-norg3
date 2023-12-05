let newline = choice("\n", "\r", "\r\n");
let newline_or_eof = choice("\n", "\r", "\r\n", "\0");

/// General TODOS:
//  - Abstract repeating patterns (e.g. nestable detached modifiers) into Javascript functions.
//  - Add tests for link modifiers, then everything else.
//  - Make every node have an alias($.node, $.node_prefix). Only some currently do.

// KNOWN ISSUES:
// - *./text/* fails (issue with $.paragraph grammar disallowing such an order)

module.exports = grammar({
    name: "norg",

    // Tell treesitter we want to handle whitespace ourselves
    extras: ($) => [$._preceding_whitespace],
    externals: ($) => [
        $._preceding_whitespace,

        $.bold_open,
        $.bold_close,

        $.italic_open,
        $.italic_close,

        $.maybe_opening_modifier,
    ],

    conflicts: ($) => [
        [$.open_conflict, $.bold],
        [$.open_conflict, $.italic],
    ],

    precedences: ($) => [],

    inlines: ($) => [],

    supertypes: ($) => [],

    rules: {
        document: ($) => repeat(choice($.paragraph, $.paragraph_break)),

        _character: (_) => token(/[\p{L}\p{N}]/u),

        punctuation: ($) => token(/[^\n\r\p{Z}\p{L}\p{N}]/u),

        word: ($) => prec.right(repeat1($._character)),
        whitespace: (_) => token(prec(1, /\p{Zs}+/u)),

        paragraph: ($) =>
            prec.right(
                seq(
                    choice(
                        $.word,
                        $.punctuation,
                        $.whitespace,
                        $.open_conflict,
                        $.bold,
                        $.italic,
                    ),
                    optional(
                        seq(
                            repeat1(
                                choice(
                                    $.word,
                                    $.punctuation,
                                    $.whitespace,
                                    seq(
                                        $.maybe_opening_modifier,
                                        choice(
                                            $.open_conflict,
                                            $.bold,
                                            $.italic,
                                            $.punctuation,
                                        ),
                                    ),
                                ),
                            ),
                            repeat(
                                prec.right(
                                    seq(
                                        newline,
                                        repeat1(
                                            choice(
                                                $.word,
                                                $.punctuation,
                                                $.whitespace,
                                                seq(
                                                    $.maybe_opening_modifier,
                                                    choice(
                                                        $.open_conflict,
                                                        $.bold,
                                                        $.italic,
                                                        $.punctuation,
                                                    ),
                                                ),
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        ),
                    ),
                ),
            ),

        open_conflict: ($) =>
            prec.dynamic(
                -1,
                seq(repeat1(choice($.bold_open, $.italic_open)), $.word),
            ),

        paragraph_break: (_) => token(prec(1, seq(newline, newline_or_eof))),

        bold: ($) => seq($.bold_open, $.paragraph, $.bold_close),
        italic: ($) => seq($.italic_open, $.paragraph, $.italic_close),
    },
});
