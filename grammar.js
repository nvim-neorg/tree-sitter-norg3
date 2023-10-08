let newline = choice("\n", "\r", "\r\n");
let newline_or_eof = choice("\n", "\r", "\r\n", "\0");

const ATTACHED_MODIFIER_TYPES = [
    "bold",
    "italic",
    "strikethrough",
    "underline",
    "spoiler",
    "superscript",
    "subscript",
]

/// General TODOS:
//  - Abstract repeating patterns (e.g. nestable detached modifiers) into Javascript functions.
//  - Support link modifiers within inline paragraph segments (titles)
//  - Add tests for link modifiers, then everything else.
//  - Make every node have an alias($.node, $.node_prefix). Only some currently do.

module.exports = grammar({
    name: "norg",

    // Tell treesitter we want to handle whitespace ourselves
    extras: ($) => [$._precedingwhitespace],
    externals: ($) => [
        $._precedingwhitespace,
    ],

    // TODO: Minimize conflict count
    conflicts: ($) => [
        [$.punctuation, $._bold_open],
        [$.punctuation, $._italic_open],
        [$.punctuation, $._strikethrough_open],
        [$.punctuation, $._underline_open],
        [$.punctuation, $._spoiler_open],
        [$.punctuation, $._superscript_open],
        [$.punctuation, $._subscript_open],
        [$.punctuation, $.link_modifier],
        [$.punctuation, $._free_open],
    ],

    precedences: ($) => [],

    inlines: ($) => [],

    supertypes: ($) => [
        $.non_structural,
        $.punctuation,
    ],

    rules: {
        document: ($) =>
            repeat(
                choice(
                    $.non_structural,
                    // $.heading,
                    // $.strong_delimiting_modifier,
                ),
            ),

        non_structural: ($) =>
            choice(
                $.paragraph,
                newline_or_eof,
            ),

        _character: (_) => token(/[\p{L}\p{N}]/u),
        punctuation: ($) => choice(
            // to make conflict with attached modifier openers
            // & repeated attached modifiers
            // the following code makes tokens like * and /\*\*+/
            ...[
                "*",
                "/",
                "-",
                "_",
                "!",
                "^",
                ",",
                "`",
                "%",
                "$",
                "&",
            ].map(m => [m, prec(1, token(seq(m, repeat1(m))))]).flat(),
            // conflict with link modifier is also needed
            ":",
            "|",
            token(/[^\n\r\p{Z}\p{L}\p{N}]/u),
        ),
        _word: ($) => prec.right(-1, repeat1($._character)),
        _whitespace: (_) => token(prec(1, /\p{Zs}+/u)),

        escape_sequence: ($) => seq("\\", alias(prec(10, /./), $.escape_char)),

        paragraph: ($) => prec.right(seq(
            $._paragraph_segment,
            repeat(seq(newline, $._paragraph_segment)),
            optional(newline_or_eof),
        )),

        _word_segment: ($) => prec.right(seq(
            $._word,
            optional(
                choice(
                    $._ws_punc_segment,
                    seq($.link_modifier, $._att_mod_seg),
                ),
            )
        )),
        _ws_punc_segment: ($) => prec.right(seq(
            choice(
                $._whitespace,
                $.punctuation,
            ),
            optional($._paragraph_segment)
        )),
        _att_mod_seg: ($) => prec.right(seq(
            choice(
                $.bold,
                $.italic,
            ),
            optional(
                choice(
                    $._ws_punc_segment,
                    $._att_mod_seg,
                    seq($.link_modifier, $._word_segment),
                )
            )
        )),
        _paragraph_segment: ($) => choice(
            $._word_segment,
            $._ws_punc_segment,
            $._att_mod_seg,
        ),
        link_modifier: (_) => prec.dynamic(1, ":"),
        _free_open: (_) => "|",
        ...gen_attached_modifiers("bold", "*"),
        ...gen_attached_modifiers("italic", "/"),
        ...gen_attached_modifiers("strikethrough", "-"),
        ...gen_attached_modifiers("underline", "_"),
        ...gen_attached_modifiers("spoiler", "!"),
        ...gen_attached_modifiers("superscript", "^"),
        ...gen_attached_modifiers("subscript", ","),
    }
})

// TODO: automate
function gen_attached_modifiers(type, mod) {
    const rules = {};
    const other_modifiers = ATTACHED_MODIFIER_TYPES.filter((t) => t != type);
    const open = `_${type}_open`;
    const close = `_${type}_close`;
    const word_segment = `_${type}_word_segment`;
    const ws_segment = `_${type}_ws_segment`;
    const punc_segment = `_${type}_punc_segment`;
    const att_mod_seg = `_${type}_attached_modifier_segment`;
    const newline_segment = `_${type}_newline_segment`;

    const free_open = `_${type}_free_open`;
    const free_close = `_${type}_free_close`;
    const free_word_segment = `_${type}_free_word_segment`;
    const free_ws_punc_segment = `_${type}_free_ws_punc_segment`;
    const free_att_mod_seg = `_${type}_free_attached_modifier_segment`;
    const free_newline_segment = `_${type}_free_newline_segment`;
    rules[open] = (_) => mod;
    rules[close] = ($) => choice(
        prec(2, seq(mod, $[word_segment])),
        alias(prec(1, mod), $.close),
    );
    rules[free_open] = ($) => seq($[open], $._free_open);
    rules[free_close] = ($) => choice(
        prec(2, seq(mod, $[free_word_segment])),
        alias(prec(1, mod), $.close),
    );
    rules[word_segment] = ($) => seq(
        $._word,
        choice(
            $[ws_segment],
            $[punc_segment],
            $[newline_segment],
            $[close],
            seq($.link_modifier, $[att_mod_seg]),
        )
    );
    rules[ws_segment] = ($) => seq(
        $._whitespace,
        choice(
            $[word_segment],
            $[ws_segment],
            $[punc_segment],
            $[att_mod_seg],
            $[newline_segment],
        )
    )
    rules[punc_segment] = ($) => seq(
        $.punctuation,
        choice(
            $[word_segment],
            $[ws_segment],
            $[punc_segment],
            $[att_mod_seg],
            $[newline_segment],
            $[close],
        )
    );
    rules[att_mod_seg] = ($) => seq(
        choice(
            ...other_modifiers.map(m => $[m])
        ),
        choice(
            $[ws_segment],
            $[punc_segment],
            $[att_mod_seg],
            $[newline_segment],
            $[close],
            seq($.link_modifier, $[word_segment]),
        )
    );
    rules[newline_segment] = ($) => seq(
        newline,
        choice(
            $[word_segment],
            $[punc_segment],
            $[att_mod_seg],
        )
    );
    rules[free_word_segment] = ($) => seq(
        $._word,
        choice(
            $[free_ws_punc_segment],
            $[free_close],
            seq($.link_modifier, $[free_att_mod_seg])
        )
    );
    rules[free_ws_punc_segment] = ($) => seq(
        choice(
            $._whitespace,
            $.punctuation,
        ),
        $[free_word_segment],
        $[free_ws_punc_segment],
        $[free_att_mod_seg],
        $[free_newline_segment],
        $[free_close],
    )
    rules[free_att_mod_seg] = ($) => seq(
        choice(
            ...other_modifiers.map(m => $[m])
        ),
        choice(
            $[free_ws_punc_segment],
            $[free_att_mod_seg],
            $[free_newline_segment],
            $[free_close],
            seq($.link_modifier, $[free_word_segment]),
        )
    )
    rules[free_newline_segment] = ($) => seq(
        newline,
        choice(
            $[free_word_segment],
            $[free_ws_punc_segment],
            $[free_att_mod_seg],
            $[free_close],
        )
    )
    rules[type] = ($) => choice(
        prec.dynamic(1, seq(
            alias($[open], $.open),
            choice(
                $[word_segment],
                $[punc_segment],
                $[att_mod_seg],
            )
        )),
        prec.dynamic(2, seq(
            alias($[free_open], $.free_open),
            $[free_word_segment],
            $[free_ws_punc_segment],
            $[free_att_mod_seg],
            $[free_newline_segment],
        ))
    )
    return rules
}
