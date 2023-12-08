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

        $.punctuation,

        $.maybe_opening_modifier,

        $.bold_open,
        $.bold_close,

        $.italic_open,
        $.italic_close,

        $.underline_open,
        $.underline_close,

        $.strikethrough_open,
        $.strikethrough_close,

        $.spoiler_open,
        $.spoiler_close,

        $.superscript_open,
        $.superscript_close,

        $.subscript_open,
        $.subscript_close,
    ],

    conflicts: ($) => [],

    precedences: ($) => [],

    inline: ($) => [$.paragraph],

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
                        $.bold,
                        $.italic,
                        $.underline,
                        $.strikethrough,
                        $.spoiler,
                        $.superscript,
                        $.subscript,
                        $.punctuation,
                        $.open_conflict,
                    ),
                    repeat(
                        choice(
                            $.word,
                            $.punctuation,
                            $.whitespace,
                            seq(
                                choice($.maybe_opening_modifier, $.punctuation),
                                choice(
                                    $.bold,
                                    $.italic,
                                    $.underline,
                                    $.strikethrough,
                                    $.spoiler,
                                    $.superscript,
                                    $.subscript,
                                    $.punctuation,
                                    $.open_conflict,
                                ),
                            ),
                            seq(newline, $.paragraph),
                        ),
                    ),
                ),
            ),

        open_conflict: ($) =>
            seq(
                choice(
                    $.bold_open,
                    $.italic_open,
                    $.underline_open,
                    $.strikethrough_open,
                    $.spoiler_open,
                    $.superscript_open,
                    $.subscript_open,
                ),
                $.paragraph,
            ),

        paragraph_break: (_) => token(prec(1, seq(newline, newline_or_eof))),

        bold: ($) => seq($.bold_open, $.paragraph, $.bold_close),
        italic: ($) => seq($.italic_open, $.paragraph, $.italic_close),
        underline: ($) => seq($.underline_open, $.paragraph, $.underline_close),
        strikethrough: ($) =>
            seq($.strikethrough_open, $.paragraph, $.strikethrough_close),
        spoiler: ($) => seq($.spoiler_open, $.paragraph, $.spoiler_close),
        superscript: ($) =>
            seq($.superscript_open, $.paragraph, $.superscript_close),
        subscript: ($) => seq($.subscript_open, $.paragraph, $.subscript_close),
    },
});
