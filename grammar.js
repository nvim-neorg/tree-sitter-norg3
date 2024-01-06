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
    extras: ($) => [
        $._preceding_whitespace,
        // NOTE: someone who thought about this is genious
        // $._failed_close,
    ],
    externals: ($) => [
        $._preceding_whitespace,

        $.paragraph_break,
        $._failed_close,
        $._newline,
        $.desc_close,
        $.link_close,
        $.inside_verbatim,

        $.punctuation,

        $.not_open,
        $.not_close,

        $.free_form_open,
        $.free_form_close,

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

        $.inline_comment_open,
        $.inline_comment_close,

        $.verbatim_open,
        $.verbatim_close,

        $.math_open,
        $.math_close,

        $.inline_macro_open,
        $.inline_macro_close,

        $.heading_prefix,
        $.unordered_list_prefix,

        $.weak_delimiting_modifier,
        $._dedent,
        $._indent_seg_end,

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

    supertypes: ($) => [
        $.att_mod,
        $.non_structural,
    ],

    rules: {
        document: ($) => repeat(
            choice(
                $.paragraph,
                $.heading,
                $._newline,
                $.strong_delimiting_modifier,
                // fake weak delimiting modifier
                alias(
                    token(seq("--", repeat("-"), newline)),
                    $.weak_delimiting_modifier
                ),
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
                        $._general,

                        $.att_mod,
                        $.open_conflict,

                        $.anchor,
                        $.link,
                    ),
                ),
            ),
        att_mod: ($) =>
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
            ),
        _general: ($) =>
            choice(
                seq($.whitespace, optional(alias($.not_close, $.punctuation))),
                prec.right(seq($.word, optional(alias($.not_open, $.punctuation)))),
                $.punctuation,
                $.escape_sequence,
                seq($.soft_break, optional(alias($.not_close, $.punctuation))),
            ),

        desc_open: (_) => "[",

        verbatim_paragraph_inner: ($) =>
            prec.right(
                repeat1(
                    choice(
                        $._general,
                        alias(
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
                                // prec(1, $.not_open),
                                prec(1, '['),
                                // "[",
                                // FIXME: need verbatim_conflict to solve these
                                // $.desc_open,
                                $.inside_verbatim,
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
                    ),
                ),
            ),

        open_conflict: ($) =>
            // prec.right(
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
                    optional($.paragraph_inner),
                    $._failed_close,
                    // prec.right(
                    //     repeat(
                    //         seq(
                    //             $.paragraph_inner,
                    //             $._failed_close,
                    //         )
                    //     )
                    // )
                ),
            // ),

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
        _free_form: ($) =>
            seq(
                $.free_form_open,
                repeat(
                    choice(
                        $.paragraph_inner,
                        alias(token(prec(1, "\\")), $.punctuation),
                        // alias("|", $.punctuation),
                    )
                ),
                $.free_form_close,
            ),
        bold: ($) =>
            seq(
                $.bold_open,
                choice(
                    $._free_form,
                    // seq(
                    //     $.free_bold_open,
                    //     // alias("|", $.free_form_open),
                    //     // $.free_form_open,
                    //     // TODO: replace repeat1 in all free-form to just repeat
                    //     // this change makes parser about 28KiB bigger
                    //     repeat(
                    //         choice(
                    //             $.paragraph_inner,
                    //             alias(token(prec(1, "\\")), $.punctuation),
                    //             alias("|", $.punctuation),
                    //         ),
                    //     ),
                    //     $.free_form_close,
                    //     // alias("|", $.free_form_close),
                    // ),
                    $.paragraph_inner,
                ),
                $.bold_close,
                optional($.attached_modifier_extension),
            ),

        italic: ($) =>
            seq(
                $.italic_open,
                choice(
                    // seq(
                    //     alias("|", $.free_form_open),
                    //     // $.free_form_open,
                    //     repeat(
                    //         choice(
                    //             $.paragraph_inner,
                    //             alias(token(prec(1, "\\")), $.punctuation),
                    //             alias("|", $.punctuation),
                    //         ),
                    //     ),
                    //     $.free_form_close,
                    //     // alias("|", $.free_form_close),
                    // ),
                    $._free_form,
                    $.paragraph_inner,
                ),
                $.italic_close,
                optional($.attached_modifier_extension),
            ),

        underline: ($) =>
            seq(
                $.underline_open,
                choice(
                    // seq(
                    //     alias("|", $.free_form_open),
                    //     repeat(
                    //         choice(
                    //             $.paragraph_inner,
                    //             alias(token(prec(1, "\\")), $.punctuation),
                    //             alias("|", $.punctuation),
                    //         ),
                    //     ),
                    //     alias("|", $.free_form_close),
                    // ),
                    $._free_form,
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
                        repeat(
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
                    // seq(
                    //     alias("|", $.free_form_open),
                    //     repeat(
                    //         choice(
                    //             $.paragraph_inner,
                    //             alias(token(prec(1, "\\")), $.punctuation),
                    //             alias("|", $.punctuation),
                    //         ),
                    //     ),
                    //     alias("|", $.free_form_close),
                    // ),
                    $._free_form,
                    $.paragraph_inner,
                ),
                $.spoiler_close,
                optional($.attached_modifier_extension),
            ),

        superscript: ($) =>
            seq(
                $.superscript_open,
                choice(
                    // seq(
                    //     alias("|", $.free_form_open),
                    //     repeat(
                    //         choice(
                    //             $.paragraph_inner,
                    //             alias(token(prec(1, "\\")), $.punctuation),
                    //             alias("|", $.punctuation),
                    //         ),
                    //     ),
                    //     alias("|", $.free_form_close),
                    // ),
                    $._free_form,
                    $.paragraph_inner,
                ),
                $.superscript_close,
                optional($.attached_modifier_extension),
            ),

        subscript: ($) =>
            seq(
                $.subscript_open,
                choice(
                    // seq(
                    //     alias("|", $.free_form_open),
                    //     repeat(
                    //         choice(
                    //             $.paragraph_inner,
                    //             alias(token(prec(1, "\\")), $.punctuation),
                    //             alias("|", $.punctuation),
                    //         ),
                    //     ),
                    //     alias("|", $.free_form_close),
                    // ),
                    $._free_form,
                    $.paragraph_inner,
                ),
                $.subscript_close,
                optional($.attached_modifier_extension),
            ),

        inline_comment: ($) =>
            seq(
                $.inline_comment_open,
                choice(
                    // seq(
                    //     alias("|", $.free_form_open),
                    //     repeat(
                    //         choice(
                    //             $.paragraph_inner,
                    //             alias(token(prec(1, "\\")), $.punctuation),
                    //             alias("|", $.punctuation),
                    //         ),
                    //     ),
                    //     alias("|", $.free_form_close),
                    // ),
                    $._free_form,
                    $.paragraph_inner,
                ),
                $.inline_comment_close,
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
                            repeat(
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
                            repeat(
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
                            repeat(
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
            seq(
                "[",
                // alias($.desc_open, "["),
                field("description", $.description),
                alias($.desc_close, "]"),
                // "]"
            ),
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
                alias($.link_close, "}"),
            ),
        uri: (_) => token(prec(-1, /[^\}]+/)),
        path: (_) => /[^:\}]+/,
        norg_file: ($) =>
            seq(
                ":",
                optional(
                    choice(
                        seq(
                            token(prec(1, "$")),
                            choice(
                                field("root", alias("/", $.current_workspace)),
                                seq(field("root", alias(/[^\$\/:\}]+/, $.workspace)), "/"),
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

        strong_delimiting_modifier: ($) => seq(token(seq("==", repeat("="))), $._newline),
        horizontal_rule: ($) => seq(token(prec(1, seq("__", repeat("_")))), $._newline),
        heading: ($) =>
            prec.right(
                seq(
                    $.heading_prefix,
                    whitespace,
                    field(
                        "title",
                        choice(
                            alias($.paragraph, $.inline),
                            $.slide,
                            $.indent_segment,
                        ),
                    ),
                    repeat(choice($.heading, $.non_structural, $._newline)),
                    optional(choice($._dedent, $.weak_delimiting_modifier))
                ),
            ),
        non_structural: ($) =>
            choice(
                $.paragraph,
                // TODO: tag
                $.horizontal_rule,
            ),
        slide: ($) =>
            seq(
                prec(1, ":"),
                $._newline,
                prec.right(repeat1($.non_structural)),
            ),
        indent_segment: ($) =>
            prec.right(
                seq(
                    prec(1, "::"),
                    $._newline,
                    repeat1(
                        choice(
                            $.non_structural,
                            $._newline,
                        ),
                    ),
                    optional(
                        choice($._indent_seg_end, $.weak_delimiting_modifier)
                    )
                ),
            ),
    },
});
