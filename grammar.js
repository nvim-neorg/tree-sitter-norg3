/// <reference types="tree-sitter-cli/dsl" />
// @ts-check
const newline = choice("\n", "\r", "\r\n");
const whitespace = token(prec(1, /\p{Zs}+/u));

const ATTACHED_MODIFIERS = [
    "bold",
    "italic",
    "underline",
    "strikethrough",
    "spoiler",
    "superscript",
    "subscript",
    "inline_comment",
];
const VERBATIM_ATTACHED_MODIFIERS = [
    "verbatim",
    "math",
    "inline_macro",
];

/// General TODOS:
//  - Abstract repeating patterns (e.g. nestable detached modifiers) into Javascript functions.
//  - Make every node have an alias($.node, $.node_prefix). Only some currently do.

/**
 * @param {RuleOrLiteral} rule
 */
function repeat2(rule) {
    return seq(rule, rule, repeat(rule));
}

module.exports = grammar({
    name: "norg",

    // Tell treesitter we want to handle whitespace ourselves
    extras: ($) => [
        $._preceding_whitespace,
    ],
    externals: ($) => [
        $._preceding_whitespace,

        $.paragraph_break,
        $._newline,
        $._failed_close,
        $.__inside_verbatim,

        $._punctuation,

        $.desc_open,
        $.desc_close,
        $.target_open,
        $.target_close,

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
        $.__indent_seg_end,

        $._error_sentinel,
    ],

    conflicts: ($) => [
        [$.open_conflict, $.verbatim],
        [$.open_conflict, $.math],
        [$.open_conflict, $.inline_macro],
        ...ATTACHED_MODIFIERS.map((kind) => [
            [$.open_conflict, $[kind], $.verbatim],
            [$.open_conflict, $[kind], $.math],
            [$.open_conflict, $[kind], $.inline_macro],
        ]).flat(),
        [$._link_description, $.verbatim],
        [$._link_description, $.math],
        [$._link_description, $.inline_macro],
        [$._link_target, $.verbatim],
        [$._link_target, $.math],
        [$._link_target, $.inline_macro],
    ],

    precedences: () => [],

    inline: ($) => [$.paragraph_inner, $.verbatim_paragraph_inner],

    supertypes: ($) => [
        $.attached_modifiers,
        $.non_structural,
        // $.tag,
    ],

    rules: {
        document: ($) => repeat(
            choice(
                $.heading,
                $.non_structural,
                $._newline,
                $.strong_delimiting_modifier,
                // fake weak delimiting modifier
                alias(
                    token(seq(repeat2("-"), newline)),
                    $.weak_delimiting_modifier
                ),
            )
        ),
        paragraph: ($) => seq($.paragraph_inner, $.paragraph_break),

        punctuation: ($) => choice(
            token(repeat1('*')),
            token(repeat1('/')),
            token(repeat1('_')),
            token(repeat1('-')),
            token(repeat1('!')),
            token(repeat1('`')),
            token(repeat1('&')),
            token(repeat1('$')),
            /[^\n\r\p{Z}\p{L}\p{N}]/u,
            $._punctuation
        ),

        _word: (_) => /[\p{L}\p{N}]+/,
        word: ($) => $._word,
        whitespace: (_) => token(prec(1, whitespace)),
        soft_break: (_) => token(prec(1, seq(optional(whitespace), newline))),

        escape_sequence: (_) => token(seq("\\", choice(/./, newline))),

        paragraph_inner: ($) =>
            prec.right(
                repeat1(
                    choice(
                        $._general,

                        $.attached_modifiers,
                        $.open_conflict,

                        $.anchor,
                        $.link,
                    ),
                ),
            ),
        attached_modifiers: ($) =>
            choice(
                ...ATTACHED_MODIFIERS.map((kind) => $[kind]),
                ...VERBATIM_ATTACHED_MODIFIERS.map((kind) => $[kind]),
            ),
        _general: ($) =>
            choice(
                seq($.whitespace, optional(alias($.not_close, $.punctuation))),
                prec.right(seq($.word, optional(alias($.not_open, $.punctuation)))),
                $.punctuation,
                $.escape_sequence,
                seq($.soft_break, optional(alias($.not_close, $.punctuation))),
            ),

        verbatim_paragraph_inner: ($) =>
            prec.right(
                repeat1(
                    choice(
                        $.__inside_verbatim,
                        $._general,
                        alias(
                            choice(
                                ...ATTACHED_MODIFIERS.map((kind) => $[kind + "_open"]),
                                ...VERBATIM_ATTACHED_MODIFIERS.map((kind) => $[kind + "_open"]),
                                $.target_open,
                                $.desc_open,
                                // list of link target prefixes to make conflict
                                // see link-11 ~ link-17
                                ":",
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
            // dynamic precedence to solve cases like link-09
            prec.dynamic(-1,
                seq(
                    choice(
                        ...ATTACHED_MODIFIERS.map((kind) => $[kind + "_open"]),
                        ...VERBATIM_ATTACHED_MODIFIERS.map((kind) => $[kind + "_open"]),
                    ),
                    optional($.paragraph_inner),
                    $._failed_close,
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
        _free_form: ($) =>
            seq(
                $.free_form_open,
                repeat(
                    choice(
                        $.paragraph_inner,
                        alias(token(prec(1, "\\")), $.punctuation),
                    )
                ),
                $.free_form_close,
            ),
        _verbatim_free_form: ($) =>
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

        bold: gen_attached_modifier("bold"),
        italic: gen_attached_modifier("italic"),
        underline: gen_attached_modifier("underline"),
        strikethrough: gen_attached_modifier("strikethrough"),
        spoiler: gen_attached_modifier("spoiler"),
        superscript: gen_attached_modifier("superscript"),
        subscript: gen_attached_modifier("subscript"),
        inline_comment: gen_attached_modifier("inline_comment"),

        verbatim: gen_verbatim_attached_modifier("verbatim"),
        math: gen_verbatim_attached_modifier("math"),
        inline_macro: gen_verbatim_attached_modifier("inline_macro"),

        _link_description: ($) =>
            seq(
                alias($.desc_open, "["),
                field("description", $.description),
                alias($.desc_close, "]"),
            ),
        description: ($) => $.paragraph_inner,

        _link_target: ($) =>
            seq(
                alias($.target_open, "{"),
                field("target", choice(
                    $.scope,
                    $.norg_file,
                    $.uri,
                    $.link_target_file,
                    $.link_target_wiki,
                    $.link_target_magic,
                    $.link_target_timestamp,
                )),
                alias($.target_close, "}"),
            ),
        uri: ($) => repeat1(
            choice(
                $._word,
                alias($.punctuation, "punctuation"),
            )
        ),
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
                alias(token(prec(1, seq("^", optional("^")))), $.footnote_prefix),
                whitespace,
                alias($.description, $.title)
            ),
        link_scope_definition: ($) =>
            seq(
                alias(token(prec(1, seq("$", optional("$")))), $.definition_prefix),
                whitespace,
                alias($.description, $.title)
            ),
        anchor: ($) =>
            prec.right(
                seq(
                    $._link_description,
                    optional($._link_target),
                )
            ),
        link: ($) =>
            prec.right(
                seq(
                    $._link_target,
                    optional($._link_description),
                )
            ),

        strong_delimiting_modifier: (_) => token(seq(repeat2("="), newline)),
        horizontal_rule: (_) => token(prec(1, seq(repeat2("_"), newline))),
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
                // $.tag,
                $.horizontal_rule,
            ),
        // tag: ($) =>
        //     choice(
        //     ),
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
                        choice($.weak_delimiting_modifier, $.__indent_seg_end)
                    )
                ),
            ),
    },
});

/**
 * @param {string} kind
 */
function gen_attached_modifier(kind) {
    return (/** @type GrammarSymbols<any> */ $) =>
        seq(
            $[kind + "_open"],
            choice(
                $._free_form,
                $.paragraph_inner,
            ),
            $[kind + "_close"],
            optional($.attached_modifier_extension),
        )
}

/**
 * @param {string} kind
 */
function gen_verbatim_attached_modifier(kind) {
    return (/** @type GrammarSymbols<any> */ $) =>
        prec.right(
            -1,
            seq(
                $[kind + "_open"],
                choice(
                    $._verbatim_free_form,
                    $.verbatim_paragraph_inner,
                ),
                $[kind + "_close"],
                optional($.attached_modifier_extension),
            ),
        )
}
