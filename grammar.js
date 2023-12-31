/// <reference types="tree-sitter-cli/dsl" />
// @ts-check
let newline = choice("\n", "\r", "\r\n");
const whitespace = token(prec(1, /\p{Zs}+/u));

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
        $._newline,

        $.punctuation,

        $.non_open,
        $.non_close,
        $.non_linkable,

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

        $._link_end_flag,

        $.heading_prefix,

        $._error_sentinel,
    ],

    conflicts: ($) => [
        [$.open_conflict, $.verbatim],
        [$.open_conflict, $.math],
        [$.open_conflict, $.inline_macro],
        [$.open_conflict, $.bold, $.verbatim],
        [$.open_conflict, $.bold, $.math],
        [$.open_conflict, $.bold, $.inline_macro],
        [$.open_conflict, $.italic, $.verbatim],
        [$.open_conflict, $.italic, $.math],
        [$.open_conflict, $.italic, $.inline_macro],
        [$.open_conflict, $.underline, $.verbatim],
        [$.open_conflict, $.underline, $.math],
        [$.open_conflict, $.underline, $.inline_macro],
        [$.open_conflict, $.strikethrough, $.verbatim],
        [$.open_conflict, $.strikethrough, $.math],
        [$.open_conflict, $.strikethrough, $.inline_macro],
        [$.open_conflict, $.spoiler, $.verbatim],
        [$.open_conflict, $.spoiler, $.math],
        [$.open_conflict, $.spoiler, $.inline_macro],
        [$.open_conflict, $.superscript, $.verbatim],
        [$.open_conflict, $.superscript, $.math],
        [$.open_conflict, $.superscript, $.inline_macro],
        [$.open_conflict, $.subscript, $.verbatim],
        [$.open_conflict, $.subscript, $.math],
        [$.open_conflict, $.subscript, $.inline_macro],
    ],

    precedences: ($) => [],

    inline: ($) => [$.paragraph, $.verbatim_paragraph],

    supertypes: ($) => [],

    rules: {
        document: ($) => repeat(
            choice(
                alias($.para, $.paragraph),
                $.heading,
                $._newline,
            )
        ),
        para: ($) => seq($.paragraph, $.paragraph_break),

        punctuation: (_) => token(choice(
            repeat1('*'),
            /[^\n\r\p{Z}\p{L}\p{N}]/u
        )),

        word: (_) => /[\p{L}\p{N}]+/,
        whitespace: (_) => token(prec(1, /\p{Zs}+/u)),
        soft_break: (_) => token(prec(1, seq(optional(/\p{Zs}+/u), newline))),

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
                        // $.superscript,
                        // $.subscript,
                        $.verbatim,
                        $.inline_macro,
                        $.math,
                        $.open_conflict,
                        $.anchor,
                        $.link,
                        $.escape_sequence,
                        $.soft_break,
                        seq($.soft_break, alias($.non_close, $.punctuation)),
                    ),
                ),
            ),

        verbatim_paragraph: ($) =>
            prec.right(
                repeat1(
                    choice(
                        seq($.whitespace, alias($.non_close, $.punctuation)),
                        seq($.word, alias($.non_open, $.punctuation)),
                        $.non_linkable,
                        $.escape_sequence,
                        $.whitespace,
                        $.word,
                        $.punctuation,
                        $.verbatim_open,
                        $.math_open,
                        $.inline_macro_open,
                        alias(
                            choice(
                                $.bold_open,
                                $.italic_open,
                                $.underline_open,
                                $.strikethrough_open,
                                $.spoiler_open,
                                $.superscript_open,
                                $.subscript_open,
                            ),
                            $.punctuation,
                        ),
                        alias("{", $.punctuation),
                        $.soft_break,
                        seq($.soft_break, alias($.non_close, $.punctuation)),
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

        identifier: (_) => /[A-Za-z][A-Za-z\-]+/,
        attached_modifier_extension: ($) =>
            seq(
                "(",
                $.kv_pair,
                repeat(
                    seq(",", $.kv_pair),
                ),
                ")",
            ),
        kv_pair: ($) =>
            seq(
                alias($.identifier, $.param),
                ":",
                alias($.identifier, $.value),
            ),
        bold: ($) =>
            seq(
                $.bold_open,
                choice(
                    seq(
                        alias("|", $.free_form_open),
                        repeat1(
                            choice(
                                $.paragraph,
                                alias(token(prec(1, "\\")), $.punctuation),
                                alias("|", $.punctuation),
                            ),
                        ),
                        alias("|", $.free_form_close),
                    ),
                    $.paragraph,
                ),
                $.bold_close,
                optional($.attached_modifier_extension),
            ),

        italic: ($) =>
            seq(
                $.italic_open,
                choice(
                    seq(
                        alias("|", $.free_form_open),
                        repeat1(
                            choice(
                                $.paragraph,
                                alias(token(prec(1, "\\")), $.punctuation),
                                alias("|", $.punctuation),
                            ),
                        ),
                        alias("|", $.free_form_close),
                    ),
                    $.paragraph,
                ),
                $.italic_close,
                optional($.attached_modifier_extension),
            ),

        underline: ($) =>
            seq(
                $.underline_open,
                choice(
                    seq(
                        alias("|", $.free_form_open),
                        repeat1(
                            choice(
                                $.paragraph,
                                alias(token(prec(1, "\\")), $.punctuation),
                                alias("|", $.punctuation),
                            ),
                        ),
                        alias("|", $.free_form_close),
                    ),
                    $.paragraph,
                ),
                $.underline_close,
                optional($.attached_modifier_extension),
            ),

        strikethrough: ($) =>
            seq(
                $.strikethrough_open,
                choice(
                    seq(
                        alias("|", $.free_form_open),
                        repeat1(
                            choice(
                                $.paragraph,
                                alias(token(prec(1, "\\")), $.punctuation),
                                alias("|", $.punctuation),
                            ),
                        ),
                        alias("|", $.free_form_close),
                    ),
                    $.paragraph,
                ),
                $.strikethrough_close,
                optional($.attached_modifier_extension),
            ),

        spoiler: ($) =>
            seq(
                $.spoiler_open,
                choice(
                    seq(
                        alias("|", $.free_form_open),
                        repeat1(
                            choice(
                                $.paragraph,
                                alias(token(prec(1, "\\")), $.punctuation),
                                alias("|", $.punctuation),
                            ),
                        ),
                        alias("|", $.free_form_close),
                    ),
                    $.paragraph,
                ),
                $.spoiler_close,
                optional($.attached_modifier_extension),
            ),

        superscript: ($) =>
            seq(
                $.superscript_open,
                choice(
                    seq(
                        alias("|", $.free_form_open),
                        repeat1(
                            choice(
                                $.paragraph,
                                alias(token(prec(1, "\\")), $.punctuation),
                                alias("|", $.punctuation),
                            ),
                        ),
                        alias("|", $.free_form_close),
                    ),
                    $.paragraph,
                ),
                $.superscript_close,
                optional($.attached_modifier_extension),
            ),

        subscript: ($) =>
            seq(
                $.subscript_open,
                choice(
                    seq(
                        alias("|", $.free_form_open),
                        repeat1(
                            choice(
                                $.paragraph,
                                alias(token(prec(1, "\\")), $.punctuation),
                                alias("|", $.punctuation),
                            ),
                        ),
                        alias("|", $.free_form_close),
                    ),
                    $.paragraph,
                ),
                $.subscript_close,
                optional($.attached_modifier_extension),
            ),

        verbatim: ($) =>
            prec.right(
                -1,
                seq(
                    $.verbatim_open,
                    choice(
                        seq(
                            alias("|", $.free_form_open),
                            repeat1(
                                choice(
                                    $.verbatim_paragraph,
                                    alias(token(prec(1, "\\")), $.punctuation),
                                    alias("|", $.punctuation),
                                ),
                            ),
                            alias("|", $.free_form_close),
                        ),
                        $.verbatim_paragraph,
                    ),
                    $.verbatim_close,
                    optional($.attached_modifier_extension),
                ),
            ),

        math: ($) =>
            prec.right(
                -1,
                seq(
                    $.math_open,
                    choice(
                        seq(
                            alias("|", $.free_form_open),
                            repeat1(
                                choice(
                                    $.verbatim_paragraph,
                                    alias(token(prec(1, "\\")), $.punctuation),
                                    alias("|", $.punctuation),
                                ),
                            ),
                            alias("|", $.free_form_close),
                        ),
                        $.verbatim_paragraph,
                    ),
                    $.math_close,
                    optional($.attached_modifier_extension),
                ),
            ),

        inline_macro: ($) =>
            prec.right(
                -1,
                seq(
                    $.inline_macro_open,
                    choice(
                        seq(
                            alias("|", $.free_form_open),
                            repeat1(
                                choice(
                                    $.verbatim_paragraph,
                                    alias(token(prec(1, "\\")), $.punctuation),
                                    alias("|", $.punctuation),
                                ),
                            ),
                            alias("|", $.free_form_close),
                        ),
                        $.verbatim_paragraph,
                    ),
                    $.inline_macro_close,
                    optional($.attached_modifier_extension),
                ),
            ),

        _description: ($) =>
            seq(
                "[",
                field("description", $.description),
                "]",
                optional($._link_end_flag),
            ),
        description: ($) => $.paragraph,

        _location: ($) =>
            seq(
                "{",
                field("target", choice(
                    $.scope,
                    $.norg_file,
                    $.uri,
                )),
                "}",
                optional($._link_end_flag),
            ),
        uri: (_) => token(prec(-1, /[^\}]+/)),
        norg_file: ($) =>
            seq(
                ":",
                optional(
                    choice(
                        seq(
                            "$",
                            choice(
                                field("root", alias("/", $.current_workspace)),
                                seq(field("root", alias(/[^\$\/\:\}]+/, $.workspace)), "/"),
                            )
                        ),
                        field("root", alias(token(prec(1, "/")), $.file_root))
                    )
                ),
                field("path", alias(/[^\$\:\}]+/, $.norg_file_path)),
                ":",
                optional(field("scope", $.scope)),
            ),
        scope: ($) =>
            seq(
                $._scope_item,
                repeat(seq(token(prec(9, " : ")), $._scope_item)),
            ),
        _scope_item: ($) =>
            choice(
                $.link_scope_heading,
                $.link_scope_footnote,
                $.link_scope_definition,
            ),
        link_scope_heading: ($) =>
            seq(
                alias(token(repeat1("*")), $.heading_prefix),
                whitespace,
                alias($.description, $.title)
            ),
        link_scope_footnote: ($) =>
            seq(
                alias(token(seq("^", optional("^"))), $.footnote_prefix),
                whitespace,
                alias($.description, $.title)
            ),
        link_scope_definition: ($) =>
            seq(
                alias(token(seq("$", optional("$"))), $.definition_prefix),
                whitespace,
                alias($.description, $.title)
            ),
        anchor: ($) =>
            prec.right(
                seq(
                    $._description,
                    optional($._location),
                )
            ),
        link: ($) =>
            prec.right(
                seq(
                    $._location,
                    optional($._description),
                )
            ),

        heading: ($) =>
            prec.right(
                seq(
                    $.heading_prefix,
                    $.whitespace,
                    // TODO: This should be a sequence of chars terminated by a `soft_break`.
                    alias($.para, $.inline),
                    repeat(
                        choice(
                            $.heading,
                            alias($.para, $.paragraph),
                            $._newline,
                        )
                    )
                ),
            )
    },
});
