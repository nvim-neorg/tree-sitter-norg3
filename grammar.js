let newline = choice("\n", "\r", "\r\n");
let newline_or_eof = choice("\n", "\r", "\r\n", "\0");

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
        // $.bold_close,
    ],

    // TODO: Minimize conflict count
    conflicts: ($) => [
        [$.punctuation, $.bold_open],
        [$.punctuation, $.italic_open],
        [$.punctuation, $.link_modifier],
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
            // conflict with link modifier is also needed
            ":",
            // TODO: add more repeated modifier cases
            prec(1, /\*+/),
            prec(1, /\/+/),
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
                    $._ws_segment,
                    $._punc_segment,
                    seq($.link_modifier, $._att_mod_seg),
                ),
            )
        )),
        _ws_segment: ($) => prec.right(seq(
            $._whitespace,
            optional(
                choice(
                    $._paragraph_segment,
                )
            )
        )),
        _punc_segment: ($) => prec.right(seq(
            $.punctuation,
            optional(
                choice(
                    $._paragraph_segment,
                )
            )
        )),
        _att_mod_seg: ($) => prec.right(seq(
            choice(
                $.bold,
            ),
            optional(
                choice(
                    $._ws_segment,
                    $._punc_segment,
                    $._att_mod_seg,
                    seq($.link_modifier, $._word_segment),
                )
            )
        )),
        _paragraph_segment: ($) => choice(
            $._word_segment,
            $._ws_segment,
            $._punc_segment,
            $._att_mod_seg,
        ),
        link_modifier: (_) => prec.dynamic(1, ":"),
        bold_open: (_) => "*",
        bold_close: (_) => prec(1, "*"),
        italic_open: (_) => "/",
        italic_close: (_) => prec(1, "/"),
        _bold_word_segment: ($) => seq(
            $._word,
            choice(
                $._bold_paragraph_segment,
                prec(2, seq("*", $._bold_word_segment)),
                alias($.bold_close, $.close),
            )
        ),
        _bold_ws_segment: ($) => seq(
            $._whitespace,
            $._bold_paragraph_segment,
        ),
        _bold_punc_segment: ($) => seq(
            $.punctuation,
            choice(
                $._bold_paragraph_segment,
                alias($.bold_close, $.close),
                prec(2, seq("*", $._bold_word_segment)),
            )
        ),
        _bold_paragraph_segment: ($) => choice(
            $._bold_word_segment,
            $._bold_ws_segment,
            $._bold_punc_segment,
            seq(
                alias(newline, $.newline),
                repeat($._whitespace),
                choice(
                    $._bold_word_segment,
                    $._bold_punc_segment,
                )
            ),
        ),
        bold: ($) => prec.dynamic(1, seq(
            alias($.bold_open, $.open),
            choice(
                $._bold_word_segment,
                $._bold_punc_segment,
                // TODO: free-form
                // seq("|", $._bold_free_para_seg)
            )
        )),
    }
})

const ATTACHED_MODIFIER_TYPES = [
    "bold",
    "italic",
]

// TODO: automate
function gen_attached_modifiers() {
    const rules = {};
    ATTACHED_MODIFIER_TYPES.forEach((type) => {
        const other_modifiers = ATTACHED_MODIFIER_TYPES.filter((t) => t != type);
        rules["_" + type + "_word_segment"] = ($) => seq(
            $._word,
            choice(
                $["_" + type + "_paragraph_segment"],
                $[type + "close"],
            )
        );
        rules["_" + type + "_ws_segment"] = ($) => seq(
            $._whitespace,
            $["_" + type + "_paragraph_segment"],
        );
        rules["_" + type + "_punc_segment"] = ($) => seq(
            $.punctuation,
            choice(
                $["_" + type + "_paragraph_segment"],
                $[type + "close"],
            )
        );
        rules["_" + type + "_att_mod_seg"] = ($) => seq(
            choice(...(other_modifiers.map(t => $[t]))),
            choice(
                $["_" + type + "_paragraph_segment"],
                $[type + "close"],
            )
        ),
        rules["_" + type + "_paragraph_segment"] = ($) => choice(
            $["_" + type + "_word_segment"],
            $["_" + type + "_ws_segment"],
            $["_" + type + "_punc_segment"],
            seq(
                newline,
                repeat($._whitespace),
                choice(
                    $["_" + type + "_word_segment"],
                    $["_" + type + "_punc_segment"],
                )
            )
        )
        rules[type] = ($) => prec.dynamic(1, seq(
            $[type + "_open"],
            choice(
                $["_" + type + "_word_segment"],
                $["_" + type + "_punc_segment"],
            )
        ));
    })
}
