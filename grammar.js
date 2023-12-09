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

        $.verbatim_open,
        $.verbatim_close,

        $.math_open,
        $.math_close,

        $.inline_macro_open,
        $.inline_macro_close,
    ],

    conflicts: ($) => [
        [$.open_conflict, $.bold, $.verbatim],
        [$.open_conflict, $.italic, $.verbatim],
        [$.open_conflict, $.underline, $.verbatim],
        [$.open_conflict, $.strikethrough, $.verbatim],
        [$.open_conflict, $.spoiler, $.verbatim],
        [$.open_conflict, $.superscript, $.verbatim],
        [$.open_conflict, $.subscript, $.verbatim],

        [$.open_conflict, $.bold, $.math],
        [$.open_conflict, $.italic, $.math],
        [$.open_conflict, $.underline, $.math],
        [$.open_conflict, $.strikethrough, $.math],
        [$.open_conflict, $.spoiler, $.math],
        [$.open_conflict, $.superscript, $.math],
        [$.open_conflict, $.subscript, $.math],

        [$.open_conflict, $.bold, $.inline_macro],
        [$.open_conflict, $.italic, $.inline_macro],
        [$.open_conflict, $.underline, $.inline_macro],
        [$.open_conflict, $.strikethrough, $.inline_macro],
        [$.open_conflict, $.spoiler, $.inline_macro],
        [$.open_conflict, $.superscript, $.inline_macro],
        [$.open_conflict, $.subscript, $.inline_macro],

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
                        $.verbatim,
                        $.inline_macro,
                        $.math,
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
                                    $.verbatim,
                                    $.inline_macro,
                                    $.math,
                                    $.punctuation,
                                    $.open_conflict,
                                ),
                            ),
                            seq(newline, $.paragraph),
                        ),
                    ),
                ),
            ),

        verbatim_paragraph: ($) =>
            prec.right(
                repeat1(
                    choice(
                        $.word,
                        $.punctuation,
                        $.whitespace,
                        $.maybe_opening_modifier,
                        seq(newline, $.verbatim_paragraph),
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

        verbatim: ($) =>
            seq($.verbatim_open, $.verbatim_paragraph, $.verbatim_close),

        math: ($) => seq($.math_open, $.verbatim_paragraph, $.math_close),

        inline_macro: ($) =>
            seq(
                $.inline_macro_open,
                $.verbatim_paragraph,
                $.inline_macro_close,
            ),
    },
});
