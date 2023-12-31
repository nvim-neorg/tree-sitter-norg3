/// <reference types="tree-sitter-cli/dsl" />
// @ts-check
const newline = choice("\n", "\r", "\r\n");
const whitespace = token(prec(1, /\p{Zs}+/u));

/// General TODOS:
//  - Abstract repeating patterns (e.g. nestable detached modifiers) into Javascript functions.
//  - Make every node have an alias($.node, $.node_prefix). Only some currently do.

module.exports = grammar({
    name: "norg",

    // Tell treesitter we want to handle whitespace ourselves
    extras: ($) => [$._preceding_whitespace],
    externals: ($) => [
        $._preceding_whitespace,

        $.paragraph_break,
        $._newline,

        $.punctuation,

        $.not_open,
        $.not_close,

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

        $._error_sentinel,
    ],

    conflicts: ($) => [
        [$._location, $.verbatim],
        [$._location, $.math],
        [$._location, $.inline_macro],
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

    precedences: () => [],

    inline: ($) => [$.paragraph_inner, $.verbatim_paragraph_inner],

    supertypes: (_) => [],

    rules: {
        document: ($) => repeat(
            choice(
                $.paragraph,
                $.heading,
                $._newline,
            )
        ),
        paragraph: ($) => seq($.paragraph_inner, $.paragraph_break),

        punctuation: (_) => token(choice(
            repeat1('*'),
            repeat1('/'),
            repeat1('_'),
            repeat1('-'),
            repeat1('!'),
            repeat1('`'),
            repeat1('&'),
            repeat1('$'),
            /[^\n\r\p{Z}\p{L}\p{N}]/u
        )),

        word: (_) => /[\p{L}\p{N}]+/,
        whitespace: (_) => token(prec(1, /\p{Zs}+/u)),
        soft_break: (_) => token(prec(1, seq(optional(/\p{Zs}+/u), newline))),

        escape_sequence: (_) => token(seq("\\", choice(/./, newline))),

        paragraph_inner: ($) =>
            prec.right(
                repeat1(
                    choice(
                        seq($.whitespace, alias($.not_close, $.punctuation)),
                        seq($.word, alias($.not_open, $.punctuation)),
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
                        seq($.soft_break, alias($.not_close, $.punctuation)),
                    ),
                ),
            ),

        verbatim_paragraph_inner: ($) =>
            prec.right(
                repeat1(
                    choice(
                        seq($.whitespace, alias($.not_close, $.punctuation)),
                        seq($.word, alias($.not_open, $.punctuation)),
                        // $.not_linkable,
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
                                prec(1, '['),
                                prec(1, ']'),
                                "{",
                                // list of link target prefixes to make conflict
                                // see link-11 ~ link-17
                                "/",
                                "#",
                                "?",
                                "=",
                            ),
                            $.punctuation,
                        ),
                        $.soft_break,
                        seq($.soft_break, alias($.not_close, $.punctuation)),
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
                    $.paragraph_inner,
                ),
            ),

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
                                $.paragraph_inner,
                                alias(token(prec(1, "\\")), $.punctuation),
                                alias("|", $.punctuation),
                            ),
                        ),
                        alias("|", $.free_form_close),
                    ),
                    $.paragraph_inner,
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
                                $.paragraph_inner,
                                alias(token(prec(1, "\\")), $.punctuation),
                                alias("|", $.punctuation),
                            ),
                        ),
                        alias("|", $.free_form_close),
                    ),
                    $.paragraph_inner,
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
                                $.paragraph_inner,
                                alias(token(prec(1, "\\")), $.punctuation),
                                alias("|", $.punctuation),
                            ),
                        ),
                        alias("|", $.free_form_close),
                    ),
                    $.paragraph_inner,
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
                                $.paragraph_inner,
                                alias(token(prec(1, "\\")), $.punctuation),
                                alias("|", $.punctuation),
                            ),
                        ),
                        alias("|", $.free_form_close),
                    ),
                    $.paragraph_inner,
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
                                $.paragraph_inner,
                                alias(token(prec(1, "\\")), $.punctuation),
                                alias("|", $.punctuation),
                            ),
                        ),
                        alias("|", $.free_form_close),
                    ),
                    $.paragraph_inner,
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
                                $.paragraph_inner,
                                alias(token(prec(1, "\\")), $.punctuation),
                                alias("|", $.punctuation),
                            ),
                        ),
                        alias("|", $.free_form_close),
                    ),
                    $.paragraph_inner,
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
                                $.paragraph_inner,
                                alias(token(prec(1, "\\")), $.punctuation),
                                alias("|", $.punctuation),
                            ),
                        ),
                        alias("|", $.free_form_close),
                    ),
                    $.paragraph_inner,
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
                                    $.verbatim_paragraph_inner,
                                    alias(token(prec(1, "\\")), $.punctuation),
                                    alias("|", $.punctuation),
                                ),
                            ),
                            alias("|", $.free_form_close),
                        ),
                        $.verbatim_paragraph_inner,
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
                                    $.verbatim_paragraph_inner,
                                    alias(token(prec(1, "\\")), $.punctuation),
                                    alias("|", $.punctuation),
                                ),
                            ),
                            alias("|", $.free_form_close),
                        ),
                        $.verbatim_paragraph_inner,
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
                                    $.verbatim_paragraph_inner,
                                    alias(token(prec(1, "\\")), $.punctuation),
                                    alias("|", $.punctuation),
                                ),
                            ),
                            alias("|", $.free_form_close),
                        ),
                        $.verbatim_paragraph_inner,
                    ),
                    $.inline_macro_close,
                    optional($.attached_modifier_extension),
                ),
            ),

        _description: ($) =>
            seq("[", field("description", $.description), "]"),
        description: ($) => $.paragraph_inner,

        _location: ($) =>
            seq(
                "{",
                field("target", choice(
                    $.scope,
                    $.norg_file,
                    $.uri,
                    $.link_target_file,
                    $.link_target_wiki,
                    $.link_target_magic,
                    $.link_target_timestamp,
                )),
                "}",
            ),
        uri: (_) => token(prec(-1, /[^\}]+/)),
        path: (_) => /[^\:\}]+/,
        norg_file: ($) =>
            seq(
                ":",
                optional(
                    choice(
                        seq(
                            token(prec(1, "$")),
                            choice(
                                field("root", alias("/", $.current_workspace)),
                                seq(field("root", alias(/[^\$\/\:\}]+/, $.workspace)), "/"),
                            )
                        ),
                        field("root", alias(token(prec(1, "/")), $.file_root))
                    )
                ),
                field("path", $.path),
                ":",
                optional(field("scope", $.scope)),
            ),
        link_target_file: ($) =>
            seq(
                alias(token("/"), $.file_prefix),
                whitespace,
                field("value", $.path),
            ),
        link_target_wiki: ($) =>
            seq(
                alias(token("?"), $.wiki_prefix),
                whitespace,
                field("value", $.path),
            ),
        link_target_magic: ($) =>
            seq(
                alias(token("#"), $.magic_prefix),
                whitespace,
                field("value", $.path),
            ),
        link_target_timestamp: ($) =>
            seq(
                alias(token("@"), $.timestamp_prefix),
                whitespace,
                field("value", $.path),
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
                    whitespace,
                    alias($.paragraph, $.inline),
                    repeat(
                        choice(
                            $.heading,
                            $.paragraph,
                            $._newline,
                        )
                    )
                ),
            )
    },
});
