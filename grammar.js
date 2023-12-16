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

        $.paragraph_break,

        $.punctuation,

        $.non_open,
        $.non_close,

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

        $.verbatim_open,
        $.verbatim_close,

        $.math_open,
        $.math_close,

        $.inline_macro_open,
        $.inline_macro_close,

        $.heading_prefix,
    ],

    conflicts: ($) => [
        [$.open_conflict, $.verbatim],
        [$.open_conflict, $.math],
        [$.open_conflict, $.inline_macro],
    ],

    precedences: ($) => [],

    inline: ($) => [$.paragraph, $.verbatim_paragraph],

    supertypes: ($) => [],

    rules: {
        document: ($) => repeat(choice($.paragraph, $.paragraph_break)),

        _character: (_) => token(/[\p{L}\p{N}]/u),

        punctuation: ($) => token(/[^\n\r\p{Z}\p{L}\p{N}]/u),

        word: ($) => prec.right(repeat1($._character)),
        whitespace: (_) => token(prec(1, /\p{Zs}+/u)),
        soft_break: (_) => newline,

        escape_sequence: ($) => token(seq("\\", choice(/./, newline))),

        paragraph: ($) =>
            prec.right(
                repeat1(
                    choice(
                        seq($.whitespace, alias($.non_close, $.punctuation)),
                        seq($.word, alias($.non_open, $.punctuation)),
                        $.whitespace,
                        $.word,
                        $.punctuation,
                        $.bold,
                        $.italic,
                        $.underline,
                        $.strikethrough,
                        $.spoiler,
                        $.superscript,
                        $.subscript,
                        $.verbatim,
                        $.inline_macro,
                        $.math,
                        $.open_conflict,
                        $.escape_sequence,
                        seq($.soft_break, $.paragraph),
                    ),
                ),
            ),

        verbatim_paragraph: ($) =>
            prec.right(
                repeat1(
                    choice(
                        seq($.whitespace, alias($.non_close, $.punctuation)),
                        seq($.word, alias($.non_open, $.punctuation)),
                        $.whitespace,
                        $.word,
                        $.punctuation,
                        $.verbatim_open,
                        $.math_open,
                        $.inline_macro_open,
                        alias($.escape_sequence, $.word),
                        seq($.soft_break, $.verbatim_paragraph),
                    ),
                ),
            ),

        open_conflict: ($) =>
            prec.dynamic(
                -1,
                seq(
                    choice(
                        $.bold_open,
                        $.italic_open,
                        $.underline_open,
                        $.strikethrough_open,
                        $.spoiler_open,
                        $.superscript_open,
                        $.subscript_open,
                        $.verbatim_open,
                        $.math_open,
                        $.inline_macro_open,
                    ),
                    $.paragraph,
                ),
            ),

        // paragraph_break: (_) => token(prec(1, seq(newline, newline_or_eof))),

        bold: ($) => seq($.bold_open, $.paragraph, $.bold_close),
        italic: ($) => seq($.italic_open, $.paragraph, $.italic_close),
        underline: ($) => seq($.underline_open, $.paragraph, $.underline_close),
        strikethrough: ($) =>
            seq($.strikethrough_open, $.paragraph, $.strikethrough_close),
        spoiler: ($) => seq($.spoiler_open, $.paragraph, $.spoiler_close),
        superscript: ($) =>
            seq($.superscript_open, $.paragraph, $.superscript_close),
        subscript: ($) => seq($.subscript_open, $.paragraph, $.subscript_close),

        verbatim: ($) =>
            prec.right(
                -1,
                seq($.verbatim_open, $.verbatim_paragraph, $.verbatim_close),
            ),

        math: ($) =>
            prec.right(
                -1,
                seq($.math_open, $.verbatim_paragraph, $.math_close),
            ),

        inline_macro: ($) =>
            prec.right(
                -1,
                seq(
                    $.inline_macro_open,
                    $.verbatim_paragraph,
                    $.inline_macro_close,
                ),
            ),

        heading: ($) =>
            seq(
                $.heading_prefix,
                $.whitespace,
                // TODO: This should be a sequence of chars terminated by a `soft_break`.
                $.paragraph,
            ),
    },
});
