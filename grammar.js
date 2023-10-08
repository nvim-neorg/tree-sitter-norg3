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
    ],

    // TODO: Minimize conflict count
    conflicts: ($) => [
        [$.punctuation, $._bold_open],
        [$.punctuation, $.italic_open],
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
        _bold_open: (_) => "*",
        _bold_close: ($) => choice(
            // avoid breaking paragraph to match the bold_close
            prec(2, seq("*", $._bold_word_segment)),
            alias(prec(1, "*"), $.close),
        ),
        bold_free_open: ($) => seq($._bold_open, $._free_open),
        _bold_free_close: ($) => choice(
            prec(2, seq("|*", $._bold_free_word_segment)),
            alias("|*", $.free_close),
        ),
        italic_open: (_) => "/",
        italic_close: (_) => prec(1, "/"),
        _bold_word_segment: ($) => seq(
            $._word,
            choice(
                $._bold_ws_segment,
                $._bold_punc_segment,
                $._bold_newline_segment,
                seq($.link_modifier, $._bold_free_att_mod_segment),
                $._bold_close,
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
                $._bold_close,
            )
        ),
        _bold_att_mod_segment: ($) => seq(
            choice(
                $.italic,
            ),
            choice(
                $._bold_ws_segment,
                $._bold_punc_segment,
                $._bold_att_mod_segment,
                seq($.link_modifier, $._bold_word_segment),
                $._bold_newline_segment,
                $._bold_close,
            ),
        ),
        _bold_newline_segment: ($) => seq(
            newline,
            choice(
                $._bold_word_segment,
                $._bold_punc_segment,
                $._bold_att_mod_segment,
            )
        ),
        _bold_paragraph_segment: ($) => choice(
            $._bold_word_segment,
            $._bold_ws_segment,
            $._bold_punc_segment,
            $._bold_att_mod_segment,
            $._bold_newline_segment,
        ),
        _bold_free_word_segment: ($) => seq(
            $._word,
            choice(
                $._bold_free_ws_punc_segment,
                seq($.link_modifier, $._bold_free_att_mod_segment),
                $._bold_free_close,
            )
        ),
        _bold_free_ws_punc_segment: ($) => seq(
            choice(
                $._whitespace,
                $.punctuation,
            ),
            $._bold_free_paragraph_segment,
        ),
        _bold_free_att_mod_segment: ($) => seq(
            choice(
                $.italic,
            ),
            choice(
                $._bold_free_ws_punc_segment,
                $._bold_free_att_mod_segment,
                seq($.link_modifier, $._bold_free_word_segment),
                $._bold_free_newline_segment,
                $._bold_free_close,
            )
        ),
        _bold_free_newline_segment: ($) => seq(
            newline,
            choice(
                $._bold_free_word_segment,
                $._bold_free_ws_punc_segment,
                $._bold_free_att_mod_segment,
                $._bold_free_close,
            )
        ),
        _bold_free_paragraph_segment: ($) => choice(
            $._bold_free_word_segment,
            $._bold_free_ws_punc_segment,
            $._bold_free_att_mod_segment,
            $._bold_free_newline_segment,
            $._bold_free_close,
        ),
        bold: ($) => choice(
            prec.dynamic(1, seq(
                alias($._bold_open, $.open),
                choice(
                    $._bold_word_segment,
                    $._bold_punc_segment,
                    $._bold_att_mod_segment,
                )
            )),
            prec.dynamic(2, seq(
                alias($.bold_free_open, $.free_open),
                $._bold_free_paragraph_segment,
            )),
        ),
        _italic_word_segment: ($) => seq(
            $._word,
            choice(
                $._italic_ws_segment,
                $._italic_punc_segment,
                // this avoids parser breaks paragraph to match the italic_close
                prec(2, seq("/", $._italic_word_segment)),
                alias($.italic_close, $.close),
            )
        ),
        _italic_ws_segment: ($) => seq(
            $._whitespace,
            $._italic_paragraph_segment,
        ),
        _italic_punc_segment: ($) => seq(
            $.punctuation,
            choice(
                $._italic_paragraph_segment,
                prec(2, seq("/", $._italic_word_segment)),
                alias($.italic_close, $.close),
            )
        ),
        _italic_att_mod_segment: ($) => seq(
            choice(
                $.bold,
            ),
            choice(
                $._italic_ws_segment,
                $._italic_punc_segment,
                $._italic_att_mod_segment,
                prec(2, seq("/", $._italic_word_segment)),
                alias($.italic_close, $.close),
            ),
        ),
        _italic_paragraph_segment: ($) => choice(
            $._italic_word_segment,
            $._italic_ws_segment,
            $._italic_punc_segment,
            $._italic_att_mod_segment,
            seq(
                newline,
                repeat($._whitespace),
                choice(
                    $._italic_word_segment,
                    $._italic_punc_segment,
                    $._italic_att_mod_segment,
                )
            ),
        ),
        italic: ($) => prec.dynamic(1, seq(
            alias($.italic_open, $.open),
            choice(
                $._italic_word_segment,
                $._italic_punc_segment,
                $._italic_att_mod_segment,
                // TODO: free-form
                // seq("|", $._italic_free_para_seg)
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
