#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 56
#define LARGE_STATE_COUNT 23
#define SYMBOL_COUNT 47
#define ALIAS_COUNT 1
#define TOKEN_COUNT 25
#define EXTERNAL_TOKEN_COUNT 1
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 2

enum {
  anon_sym_LF = 1,
  anon_sym_CR = 2,
  anon_sym_CR_LF = 3,
  anon_sym_ = 4,
  sym__character = 5,
  anon_sym_STAR = 6,
  anon_sym_SLASH = 7,
  anon_sym_DASH = 8,
  anon_sym__ = 9,
  anon_sym_BANG = 10,
  anon_sym_CARET = 11,
  anon_sym_COMMA = 12,
  anon_sym_BQUOTE = 13,
  anon_sym_PERCENT = 14,
  anon_sym_DOLLAR = 15,
  anon_sym_AMP = 16,
  anon_sym_COLON = 17,
  aux_sym_punctuation_token1 = 18,
  aux_sym_punctuation_token2 = 19,
  aux_sym_punctuation_token3 = 20,
  sym__whitespace = 21,
  anon_sym_BSLASH = 22,
  aux_sym_escape_sequence_token1 = 23,
  sym__precedingwhitespace = 24,
  sym_document = 25,
  sym_non_structural = 26,
  sym_punctuation = 27,
  sym__word = 28,
  sym_paragraph = 29,
  sym__word_segment = 30,
  sym__ws_segment = 31,
  sym__punc_segment = 32,
  sym__att_mod_seg = 33,
  sym__paragraph_segment = 34,
  sym_link_modifier = 35,
  sym_bold_open = 36,
  sym_bold_close = 37,
  sym__bold_word_segment = 38,
  sym__bold_ws_segment = 39,
  sym__bold_punc_segment = 40,
  sym__bold_paragraph_segment = 41,
  sym_bold = 42,
  aux_sym_document_repeat1 = 43,
  aux_sym__word_repeat1 = 44,
  aux_sym_paragraph_repeat1 = 45,
  aux_sym__bold_paragraph_segment_repeat1 = 46,
  alias_sym_newline = 47,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_LF] = "\n",
  [anon_sym_CR] = "\r",
  [anon_sym_CR_LF] = "\r\n",
  [anon_sym_] = " ",
  [sym__character] = "_character",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_DASH] = "-",
  [anon_sym__] = "_",
  [anon_sym_BANG] = "!",
  [anon_sym_CARET] = "^",
  [anon_sym_COMMA] = ",",
  [anon_sym_BQUOTE] = "`",
  [anon_sym_PERCENT] = "%",
  [anon_sym_DOLLAR] = "$",
  [anon_sym_AMP] = "&",
  [anon_sym_COLON] = ":",
  [aux_sym_punctuation_token1] = "punctuation_token1",
  [aux_sym_punctuation_token2] = "punctuation_token2",
  [aux_sym_punctuation_token3] = "punctuation_token3",
  [sym__whitespace] = "_whitespace",
  [anon_sym_BSLASH] = "\\",
  [aux_sym_escape_sequence_token1] = "escape_char",
  [sym__precedingwhitespace] = "_precedingwhitespace",
  [sym_document] = "document",
  [sym_non_structural] = "non_structural",
  [sym_punctuation] = "punctuation",
  [sym__word] = "_word",
  [sym_paragraph] = "paragraph",
  [sym__word_segment] = "_word_segment",
  [sym__ws_segment] = "_ws_segment",
  [sym__punc_segment] = "_punc_segment",
  [sym__att_mod_seg] = "_att_mod_seg",
  [sym__paragraph_segment] = "_paragraph_segment",
  [sym_link_modifier] = "link_modifier",
  [sym_bold_open] = "open",
  [sym_bold_close] = "close",
  [sym__bold_word_segment] = "_bold_word_segment",
  [sym__bold_ws_segment] = "_bold_ws_segment",
  [sym__bold_punc_segment] = "_bold_punc_segment",
  [sym__bold_paragraph_segment] = "_bold_paragraph_segment",
  [sym_bold] = "bold",
  [aux_sym_document_repeat1] = "document_repeat1",
  [aux_sym__word_repeat1] = "_word_repeat1",
  [aux_sym_paragraph_repeat1] = "paragraph_repeat1",
  [aux_sym__bold_paragraph_segment_repeat1] = "_bold_paragraph_segment_repeat1",
  [alias_sym_newline] = "newline",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_LF] = anon_sym_LF,
  [anon_sym_CR] = anon_sym_CR,
  [anon_sym_CR_LF] = anon_sym_CR_LF,
  [anon_sym_] = anon_sym_,
  [sym__character] = sym__character,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym__] = anon_sym__,
  [anon_sym_BANG] = anon_sym_BANG,
  [anon_sym_CARET] = anon_sym_CARET,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_BQUOTE] = anon_sym_BQUOTE,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_DOLLAR] = anon_sym_DOLLAR,
  [anon_sym_AMP] = anon_sym_AMP,
  [anon_sym_COLON] = anon_sym_COLON,
  [aux_sym_punctuation_token1] = aux_sym_punctuation_token1,
  [aux_sym_punctuation_token2] = aux_sym_punctuation_token2,
  [aux_sym_punctuation_token3] = aux_sym_punctuation_token3,
  [sym__whitespace] = sym__whitespace,
  [anon_sym_BSLASH] = anon_sym_BSLASH,
  [aux_sym_escape_sequence_token1] = aux_sym_escape_sequence_token1,
  [sym__precedingwhitespace] = sym__precedingwhitespace,
  [sym_document] = sym_document,
  [sym_non_structural] = sym_non_structural,
  [sym_punctuation] = sym_punctuation,
  [sym__word] = sym__word,
  [sym_paragraph] = sym_paragraph,
  [sym__word_segment] = sym__word_segment,
  [sym__ws_segment] = sym__ws_segment,
  [sym__punc_segment] = sym__punc_segment,
  [sym__att_mod_seg] = sym__att_mod_seg,
  [sym__paragraph_segment] = sym__paragraph_segment,
  [sym_link_modifier] = sym_link_modifier,
  [sym_bold_open] = sym_bold_open,
  [sym_bold_close] = sym_bold_close,
  [sym__bold_word_segment] = sym__bold_word_segment,
  [sym__bold_ws_segment] = sym__bold_ws_segment,
  [sym__bold_punc_segment] = sym__bold_punc_segment,
  [sym__bold_paragraph_segment] = sym__bold_paragraph_segment,
  [sym_bold] = sym_bold,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
  [aux_sym__word_repeat1] = aux_sym__word_repeat1,
  [aux_sym_paragraph_repeat1] = aux_sym_paragraph_repeat1,
  [aux_sym__bold_paragraph_segment_repeat1] = aux_sym__bold_paragraph_segment_repeat1,
  [alias_sym_newline] = alias_sym_newline,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CR_LF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_] = {
    .visible = true,
    .named = false,
  },
  [sym__character] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym__] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CARET] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOLLAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_punctuation_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_punctuation_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_punctuation_token3] = {
    .visible = false,
    .named = false,
  },
  [sym__whitespace] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_BSLASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_escape_sequence_token1] = {
    .visible = true,
    .named = true,
  },
  [sym__precedingwhitespace] = {
    .visible = false,
    .named = true,
  },
  [sym_document] = {
    .visible = true,
    .named = true,
  },
  [sym_non_structural] = {
    .visible = false,
    .named = true,
    .supertype = true,
  },
  [sym_punctuation] = {
    .visible = false,
    .named = true,
    .supertype = true,
  },
  [sym__word] = {
    .visible = false,
    .named = true,
  },
  [sym_paragraph] = {
    .visible = true,
    .named = true,
  },
  [sym__word_segment] = {
    .visible = false,
    .named = true,
  },
  [sym__ws_segment] = {
    .visible = false,
    .named = true,
  },
  [sym__punc_segment] = {
    .visible = false,
    .named = true,
  },
  [sym__att_mod_seg] = {
    .visible = false,
    .named = true,
  },
  [sym__paragraph_segment] = {
    .visible = false,
    .named = true,
  },
  [sym_link_modifier] = {
    .visible = true,
    .named = true,
  },
  [sym_bold_open] = {
    .visible = true,
    .named = true,
  },
  [sym_bold_close] = {
    .visible = true,
    .named = true,
  },
  [sym__bold_word_segment] = {
    .visible = false,
    .named = true,
  },
  [sym__bold_ws_segment] = {
    .visible = false,
    .named = true,
  },
  [sym__bold_punc_segment] = {
    .visible = false,
    .named = true,
  },
  [sym__bold_paragraph_segment] = {
    .visible = false,
    .named = true,
  },
  [sym_bold] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_document_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__word_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_paragraph_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__bold_paragraph_segment_repeat1] = {
    .visible = false,
    .named = false,
  },
  [alias_sym_newline] = {
    .visible = true,
    .named = true,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [1] = {
    [0] = alias_sym_newline,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 28,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 17,
  [48] = 16,
  [49] = 24,
  [50] = 38,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
};

static inline bool sym__character_character_set_1(int32_t c) {
  return (c < 6688
    ? (c < 3046
      ? (c < 2406
        ? (c < 1488
          ? (c < 750
            ? (c < 188
              ? (c < 170
                ? (c < 'A'
                  ? (c >= '0' && c <= '9')
                  : (c <= 'Z' || (c >= 'a' && c <= 'z')))
                : (c <= 170 || (c < 181
                  ? (c >= 178 && c <= 179)
                  : (c <= 181 || (c >= 185 && c <= 186)))))
              : (c <= 190 || (c < 710
                ? (c < 216
                  ? (c >= 192 && c <= 214)
                  : (c <= 246 || (c >= 248 && c <= 705)))
                : (c <= 721 || (c < 748
                  ? (c >= 736 && c <= 740)
                  : c <= 748)))))
            : (c <= 750 || (c < 910
              ? (c < 895
                ? (c < 886
                  ? (c >= 880 && c <= 884)
                  : (c <= 887 || (c >= 890 && c <= 893)))
                : (c <= 895 || (c < 904
                  ? c == 902
                  : (c <= 906 || c == 908))))
              : (c <= 929 || (c < 1329
                ? (c < 1015
                  ? (c >= 931 && c <= 1013)
                  : (c <= 1153 || (c >= 1162 && c <= 1327)))
                : (c <= 1366 || (c < 1376
                  ? c == 1369
                  : c <= 1416)))))))
          : (c <= 1514 || (c < 2036
            ? (c < 1774
              ? (c < 1646
                ? (c < 1568
                  ? (c >= 1519 && c <= 1522)
                  : (c <= 1610 || (c >= 1632 && c <= 1641)))
                : (c <= 1647 || (c < 1749
                  ? (c >= 1649 && c <= 1747)
                  : (c <= 1749 || (c >= 1765 && c <= 1766)))))
              : (c <= 1788 || (c < 1869
                ? (c < 1808
                  ? c == 1791
                  : (c <= 1808 || (c >= 1810 && c <= 1839)))
                : (c <= 1957 || (c < 1984
                  ? c == 1969
                  : c <= 2026)))))
            : (c <= 2037 || (c < 2160
              ? (c < 2084
                ? (c < 2048
                  ? c == 2042
                  : (c <= 2069 || c == 2074))
                : (c <= 2084 || (c < 2112
                  ? c == 2088
                  : (c <= 2136 || (c >= 2144 && c <= 2154)))))
              : (c <= 2183 || (c < 2365
                ? (c < 2208
                  ? (c >= 2185 && c <= 2190)
                  : (c <= 2249 || (c >= 2308 && c <= 2361)))
                : (c <= 2365 || (c < 2392
                  ? c == 2384
                  : c <= 2401)))))))))
        : (c <= 2415 || (c < 2738
          ? (c < 2565
            ? (c < 2493
              ? (c < 2451
                ? (c < 2437
                  ? (c >= 2417 && c <= 2432)
                  : (c <= 2444 || (c >= 2447 && c <= 2448)))
                : (c <= 2472 || (c < 2482
                  ? (c >= 2474 && c <= 2480)
                  : (c <= 2482 || (c >= 2486 && c <= 2489)))))
              : (c <= 2493 || (c < 2534
                ? (c < 2524
                  ? c == 2510
                  : (c <= 2525 || (c >= 2527 && c <= 2529)))
                : (c <= 2545 || (c < 2556
                  ? (c >= 2548 && c <= 2553)
                  : c <= 2556)))))
            : (c <= 2570 || (c < 2654
              ? (c < 2610
                ? (c < 2579
                  ? (c >= 2575 && c <= 2576)
                  : (c <= 2600 || (c >= 2602 && c <= 2608)))
                : (c <= 2611 || (c < 2616
                  ? (c >= 2613 && c <= 2614)
                  : (c <= 2617 || (c >= 2649 && c <= 2652)))))
              : (c <= 2654 || (c < 2703
                ? (c < 2674
                  ? (c >= 2662 && c <= 2671)
                  : (c <= 2676 || (c >= 2693 && c <= 2701)))
                : (c <= 2705 || (c < 2730
                  ? (c >= 2707 && c <= 2728)
                  : c <= 2736)))))))
          : (c <= 2739 || (c < 2911
            ? (c < 2831
              ? (c < 2784
                ? (c < 2749
                  ? (c >= 2741 && c <= 2745)
                  : (c <= 2749 || c == 2768))
                : (c <= 2785 || (c < 2809
                  ? (c >= 2790 && c <= 2799)
                  : (c <= 2809 || (c >= 2821 && c <= 2828)))))
              : (c <= 2832 || (c < 2869
                ? (c < 2858
                  ? (c >= 2835 && c <= 2856)
                  : (c <= 2864 || (c >= 2866 && c <= 2867)))
                : (c <= 2873 || (c < 2908
                  ? c == 2877
                  : c <= 2909)))))
            : (c <= 2913 || (c < 2969
              ? (c < 2949
                ? (c < 2929
                  ? (c >= 2918 && c <= 2927)
                  : (c <= 2935 || c == 2947))
                : (c <= 2954 || (c < 2962
                  ? (c >= 2958 && c <= 2960)
                  : c <= 2965)))
              : (c <= 2970 || (c < 2984
                ? (c < 2974
                  ? c == 2972
                  : (c <= 2975 || (c >= 2979 && c <= 2980)))
                : (c <= 2986 || (c < 3024
                  ? (c >= 2990 && c <= 3001)
                  : c <= 3024)))))))))))
      : (c <= 3058 || (c < 4176
        ? (c < 3450
          ? (c < 3242
            ? (c < 3168
              ? (c < 3114
                ? (c < 3086
                  ? (c >= 3077 && c <= 3084)
                  : (c <= 3088 || (c >= 3090 && c <= 3112)))
                : (c <= 3129 || (c < 3160
                  ? c == 3133
                  : (c <= 3162 || c == 3165))))
              : (c <= 3169 || (c < 3205
                ? (c < 3192
                  ? (c >= 3174 && c <= 3183)
                  : (c <= 3198 || c == 3200))
                : (c <= 3212 || (c < 3218
                  ? (c >= 3214 && c <= 3216)
                  : c <= 3240)))))
            : (c <= 3251 || (c < 3342
              ? (c < 3296
                ? (c < 3261
                  ? (c >= 3253 && c <= 3257)
                  : (c <= 3261 || (c >= 3293 && c <= 3294)))
                : (c <= 3297 || (c < 3313
                  ? (c >= 3302 && c <= 3311)
                  : (c <= 3314 || (c >= 3332 && c <= 3340)))))
              : (c <= 3344 || (c < 3412
                ? (c < 3389
                  ? (c >= 3346 && c <= 3386)
                  : (c <= 3389 || c == 3406))
                : (c <= 3414 || (c < 3430
                  ? (c >= 3416 && c <= 3425)
                  : c <= 3448)))))))
          : (c <= 3455 || (c < 3749
            ? (c < 3634
              ? (c < 3517
                ? (c < 3482
                  ? (c >= 3461 && c <= 3478)
                  : (c <= 3505 || (c >= 3507 && c <= 3515)))
                : (c <= 3517 || (c < 3558
                  ? (c >= 3520 && c <= 3526)
                  : (c <= 3567 || (c >= 3585 && c <= 3632)))))
              : (c <= 3635 || (c < 3716
                ? (c < 3664
                  ? (c >= 3648 && c <= 3654)
                  : (c <= 3673 || (c >= 3713 && c <= 3714)))
                : (c <= 3716 || (c < 3724
                  ? (c >= 3718 && c <= 3722)
                  : c <= 3747)))))
            : (c <= 3749 || (c < 3840
              ? (c < 3776
                ? (c < 3762
                  ? (c >= 3751 && c <= 3760)
                  : (c <= 3763 || c == 3773))
                : (c <= 3780 || (c < 3792
                  ? c == 3782
                  : (c <= 3801 || (c >= 3804 && c <= 3807)))))
              : (c <= 3840 || (c < 3976
                ? (c < 3904
                  ? (c >= 3872 && c <= 3891)
                  : (c <= 3911 || (c >= 3913 && c <= 3948)))
                : (c <= 3980 || (c < 4159
                  ? (c >= 4096 && c <= 4138)
                  : c <= 4169)))))))))
        : (c <= 4181 || (c < 5024
          ? (c < 4696
            ? (c < 4256
              ? (c < 4206
                ? (c < 4193
                  ? (c >= 4186 && c <= 4189)
                  : (c <= 4193 || (c >= 4197 && c <= 4198)))
                : (c <= 4208 || (c < 4238
                  ? (c >= 4213 && c <= 4225)
                  : (c <= 4238 || (c >= 4240 && c <= 4249)))))
              : (c <= 4293 || (c < 4348
                ? (c < 4301
                  ? c == 4295
                  : (c <= 4301 || (c >= 4304 && c <= 4346)))
                : (c <= 4680 || (c < 4688
                  ? (c >= 4682 && c <= 4685)
                  : c <= 4694)))))
            : (c <= 4696 || (c < 4802
              ? (c < 4752
                ? (c < 4704
                  ? (c >= 4698 && c <= 4701)
                  : (c <= 4744 || (c >= 4746 && c <= 4749)))
                : (c <= 4784 || (c < 4792
                  ? (c >= 4786 && c <= 4789)
                  : (c <= 4798 || c == 4800))))
              : (c <= 4805 || (c < 4888
                ? (c < 4824
                  ? (c >= 4808 && c <= 4822)
                  : (c <= 4880 || (c >= 4882 && c <= 4885)))
                : (c <= 4954 || (c < 4992
                  ? (c >= 4969 && c <= 4988)
                  : c <= 5007)))))))
          : (c <= 5109 || (c < 6128
            ? (c < 5952
              ? (c < 5792
                ? (c < 5121
                  ? (c >= 5112 && c <= 5117)
                  : (c <= 5740 || (c >= 5743 && c <= 5786)))
                : (c <= 5866 || (c < 5888
                  ? (c >= 5870 && c <= 5880)
                  : (c <= 5905 || (c >= 5919 && c <= 5937)))))
              : (c <= 5969 || (c < 6103
                ? (c < 5998
                  ? (c >= 5984 && c <= 5996)
                  : (c <= 6000 || (c >= 6016 && c <= 6067)))
                : (c <= 6103 || (c < 6112
                  ? c == 6108
                  : c <= 6121)))))
            : (c <= 6137 || (c < 6400
              ? (c < 6279
                ? (c < 6176
                  ? (c >= 6160 && c <= 6169)
                  : (c <= 6264 || (c >= 6272 && c <= 6276)))
                : (c <= 6312 || (c < 6320
                  ? c == 6314
                  : c <= 6389)))
              : (c <= 6430 || (c < 6576
                ? (c < 6512
                  ? (c >= 6470 && c <= 6509)
                  : (c <= 6516 || (c >= 6528 && c <= 6571)))
                : (c <= 6601 || (c < 6656
                  ? (c >= 6608 && c <= 6618)
                  : c <= 6678)))))))))))))
    : (c <= 6740 || (c < 43138
      ? (c < 11264
        ? (c < 8118
          ? (c < 7401
            ? (c < 7086
              ? (c < 6917
                ? (c < 6800
                  ? (c >= 6784 && c <= 6793)
                  : (c <= 6809 || c == 6823))
                : (c <= 6963 || (c < 6992
                  ? (c >= 6981 && c <= 6988)
                  : (c <= 7001 || (c >= 7043 && c <= 7072)))))
              : (c <= 7141 || (c < 7296
                ? (c < 7232
                  ? (c >= 7168 && c <= 7203)
                  : (c <= 7241 || (c >= 7245 && c <= 7293)))
                : (c <= 7304 || (c < 7357
                  ? (c >= 7312 && c <= 7354)
                  : c <= 7359)))))
            : (c <= 7404 || (c < 8008
              ? (c < 7424
                ? (c < 7413
                  ? (c >= 7406 && c <= 7411)
                  : (c <= 7414 || c == 7418))
                : (c <= 7615 || (c < 7960
                  ? (c >= 7680 && c <= 7957)
                  : (c <= 7965 || (c >= 7968 && c <= 8005)))))
              : (c <= 8013 || (c < 8029
                ? (c < 8025
                  ? (c >= 8016 && c <= 8023)
                  : (c <= 8025 || c == 8027))
                : (c <= 8029 || (c < 8064
                  ? (c >= 8031 && c <= 8061)
                  : c <= 8116)))))))
          : (c <= 8124 || (c < 8458
            ? (c < 8182
              ? (c < 8144
                ? (c < 8130
                  ? c == 8126
                  : (c <= 8132 || (c >= 8134 && c <= 8140)))
                : (c <= 8147 || (c < 8160
                  ? (c >= 8150 && c <= 8155)
                  : (c <= 8172 || (c >= 8178 && c <= 8180)))))
              : (c <= 8188 || (c < 8336
                ? (c < 8308
                  ? (c >= 8304 && c <= 8305)
                  : (c <= 8313 || (c >= 8319 && c <= 8329)))
                : (c <= 8348 || (c < 8455
                  ? c == 8450
                  : c <= 8455)))))
            : (c <= 8467 || (c < 8508
              ? (c < 8486
                ? (c < 8473
                  ? c == 8469
                  : (c <= 8477 || c == 8484))
                : (c <= 8486 || (c < 8490
                  ? c == 8488
                  : (c <= 8493 || (c >= 8495 && c <= 8505)))))
              : (c <= 8511 || (c < 9312
                ? (c < 8526
                  ? (c >= 8517 && c <= 8521)
                  : (c <= 8526 || (c >= 8528 && c <= 8585)))
                : (c <= 9371 || (c < 10102
                  ? (c >= 9450 && c <= 9471)
                  : c <= 10131)))))))))
        : (c <= 11492 || (c < 12704
          ? (c < 11720
            ? (c < 11631
              ? (c < 11520
                ? (c < 11506
                  ? (c >= 11499 && c <= 11502)
                  : (c <= 11507 || c == 11517))
                : (c <= 11557 || (c < 11565
                  ? c == 11559
                  : (c <= 11565 || (c >= 11568 && c <= 11623)))))
              : (c <= 11631 || (c < 11696
                ? (c < 11680
                  ? (c >= 11648 && c <= 11670)
                  : (c <= 11686 || (c >= 11688 && c <= 11694)))
                : (c <= 11702 || (c < 11712
                  ? (c >= 11704 && c <= 11710)
                  : c <= 11718)))))
            : (c <= 11726 || (c < 12353
              ? (c < 12293
                ? (c < 11736
                  ? (c >= 11728 && c <= 11734)
                  : (c <= 11742 || c == 11823))
                : (c <= 12295 || (c < 12337
                  ? (c >= 12321 && c <= 12329)
                  : (c <= 12341 || (c >= 12344 && c <= 12348)))))
              : (c <= 12438 || (c < 12549
                ? (c < 12449
                  ? (c >= 12445 && c <= 12447)
                  : (c <= 12538 || (c >= 12540 && c <= 12543)))
                : (c <= 12591 || (c < 12690
                  ? (c >= 12593 && c <= 12686)
                  : c <= 12693)))))))
          : (c <= 12735 || (c < 42623
            ? (c < 19903
              ? (c < 12881
                ? (c < 12832
                  ? (c >= 12784 && c <= 12799)
                  : (c <= 12841 || (c >= 12872 && c <= 12879)))
                : (c <= 12895 || (c < 12977
                  ? (c >= 12928 && c <= 12937)
                  : (c <= 12991 || c == 13312))))
              : (c <= 19903 || (c < 42240
                ? (c < 40959
                  ? c == 19968
                  : (c <= 42124 || (c >= 42192 && c <= 42237)))
                : (c <= 42508 || (c < 42560
                  ? (c >= 42512 && c <= 42539)
                  : c <= 42606)))))
            : (c <= 42653 || (c < 42965
              ? (c < 42891
                ? (c < 42775
                  ? (c >= 42656 && c <= 42735)
                  : (c <= 42783 || (c >= 42786 && c <= 42888)))
                : (c <= 42954 || (c < 42963
                  ? (c >= 42960 && c <= 42961)
                  : c <= 42963)))
              : (c <= 42969 || (c < 43020
                ? (c < 43011
                  ? (c >= 42994 && c <= 43009)
                  : (c <= 43013 || (c >= 43015 && c <= 43018)))
                : (c <= 43042 || (c < 43072
                  ? (c >= 43056 && c <= 43061)
                  : c <= 43123)))))))))))
      : (c <= 43187 || (c < 65345
        ? (c < 43808
          ? (c < 43600
            ? (c < 43396
              ? (c < 43261
                ? (c < 43250
                  ? (c >= 43216 && c <= 43225)
                  : (c <= 43255 || c == 43259))
                : (c <= 43262 || (c < 43312
                  ? (c >= 43264 && c <= 43301)
                  : (c <= 43334 || (c >= 43360 && c <= 43388)))))
              : (c <= 43442 || (c < 43520
                ? (c < 43488
                  ? (c >= 43471 && c <= 43481)
                  : (c <= 43492 || (c >= 43494 && c <= 43518)))
                : (c <= 43560 || (c < 43588
                  ? (c >= 43584 && c <= 43586)
                  : c <= 43595)))))
            : (c <= 43609 || (c < 43714
              ? (c < 43697
                ? (c < 43642
                  ? (c >= 43616 && c <= 43638)
                  : (c <= 43642 || (c >= 43646 && c <= 43695)))
                : (c <= 43697 || (c < 43705
                  ? (c >= 43701 && c <= 43702)
                  : (c <= 43709 || c == 43712))))
              : (c <= 43714 || (c < 43777
                ? (c < 43744
                  ? (c >= 43739 && c <= 43741)
                  : (c <= 43754 || (c >= 43762 && c <= 43764)))
                : (c <= 43782 || (c < 43793
                  ? (c >= 43785 && c <= 43790)
                  : c <= 43798)))))))
          : (c <= 43814 || (c < 64287
            ? (c < 55216
              ? (c < 43888
                ? (c < 43824
                  ? (c >= 43816 && c <= 43822)
                  : (c <= 43866 || (c >= 43868 && c <= 43881)))
                : (c <= 44002 || (c < 44032
                  ? (c >= 44016 && c <= 44025)
                  : (c <= 44032 || c == 55203))))
              : (c <= 55238 || (c < 64256
                ? (c < 63744
                  ? (c >= 55243 && c <= 55291)
                  : (c <= 64109 || (c >= 64112 && c <= 64217)))
                : (c <= 64262 || (c < 64285
                  ? (c >= 64275 && c <= 64279)
                  : c <= 64285)))))
            : (c <= 64296 || (c < 64848
              ? (c < 64320
                ? (c < 64312
                  ? (c >= 64298 && c <= 64310)
                  : (c <= 64316 || c == 64318))
                : (c <= 64321 || (c < 64326
                  ? (c >= 64323 && c <= 64324)
                  : (c <= 64433 || (c >= 64467 && c <= 64829)))))
              : (c <= 64911 || (c < 65142
                ? (c < 65008
                  ? (c >= 64914 && c <= 64967)
                  : (c <= 65019 || (c >= 65136 && c <= 65140)))
                : (c <= 65276 || (c < 65313
                  ? (c >= 65296 && c <= 65305)
                  : c <= 65338)))))))))
        : (c <= 65370 || (c < 66816
          ? (c < 65930
            ? (c < 65576
              ? (c < 65490
                ? (c < 65474
                  ? (c >= 65382 && c <= 65470)
                  : (c <= 65479 || (c >= 65482 && c <= 65487)))
                : (c <= 65495 || (c < 65536
                  ? (c >= 65498 && c <= 65500)
                  : (c <= 65547 || (c >= 65549 && c <= 65574)))))
              : (c <= 65594 || (c < 65664
                ? (c < 65599
                  ? (c >= 65596 && c <= 65597)
                  : (c <= 65613 || (c >= 65616 && c <= 65629)))
                : (c <= 65786 || (c < 65856
                  ? (c >= 65799 && c <= 65843)
                  : c <= 65912)))))
            : (c <= 65931 || (c < 66464
              ? (c < 66304
                ? (c < 66208
                  ? (c >= 66176 && c <= 66204)
                  : (c <= 66256 || (c >= 66273 && c <= 66299)))
                : (c <= 66339 || (c < 66384
                  ? (c >= 66349 && c <= 66378)
                  : (c <= 66421 || (c >= 66432 && c <= 66461)))))
              : (c <= 66499 || (c < 66720
                ? (c < 66513
                  ? (c >= 66504 && c <= 66511)
                  : (c <= 66517 || (c >= 66560 && c <= 66717)))
                : (c <= 66729 || (c < 66776
                  ? (c >= 66736 && c <= 66771)
                  : c <= 66811)))))))
          : (c <= 66855 || (c < 67506
            ? (c < 66995
              ? (c < 66956
                ? (c < 66928
                  ? (c >= 66864 && c <= 66915)
                  : (c <= 66938 || (c >= 66940 && c <= 66954)))
                : (c <= 66962 || (c < 66967
                  ? (c >= 66964 && c <= 66965)
                  : (c <= 66977 || (c >= 66979 && c <= 66993)))))
              : (c <= 67001 || (c < 67424
                ? (c < 67072
                  ? (c >= 67003 && c <= 67004)
                  : (c <= 67382 || (c >= 67392 && c <= 67413)))
                : (c <= 67431 || (c < 67463
                  ? (c >= 67456 && c <= 67461)
                  : c <= 67504)))))
            : (c <= 67514 || (c < 67672
              ? (c < 67639
                ? (c < 67592
                  ? (c >= 67584 && c <= 67589)
                  : (c <= 67592 || (c >= 67594 && c <= 67637)))
                : (c <= 67640 || (c < 67647
                  ? c == 67644
                  : c <= 67669)))
              : (c <= 67702 || (c < 67828
                ? (c < 67751
                  ? (c >= 67705 && c <= 67742)
                  : (c <= 67759 || (c >= 67808 && c <= 67826)))
                : (c <= 67829 || (c < 67872
                  ? (c >= 67835 && c <= 67867)
                  : c <= 67883)))))))))))))));
}

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(4);
      if (lookahead == 0) ADVANCE(8);
      if (lookahead == '\n') ADVANCE(5);
      if (lookahead == '\r') ADVANCE(6);
      if (lookahead == '!') ADVANCE(15);
      if (lookahead == '$') ADVANCE(20);
      if (lookahead == '%') ADVANCE(19);
      if (lookahead == '&') ADVANCE(21);
      if (lookahead == '*') ADVANCE(11);
      if (lookahead == ',') ADVANCE(17);
      if (lookahead == '-') ADVANCE(13);
      if (lookahead == '/') ADVANCE(12);
      if (lookahead == ':') ADVANCE(22);
      if (lookahead == '\\') ADVANCE(27);
      if (lookahead == '^') ADVANCE(16);
      if (lookahead == '_') ADVANCE(14);
      if (lookahead == '`') ADVANCE(18);
      if (lookahead == 8232 ||
          lookahead == 8233) ADVANCE(28);
      if (lookahead == ' ' ||
          lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(26);
      if (sym__character_character_set_1(lookahead)) ADVANCE(9);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(5);
      if (lookahead == '\r') ADVANCE(6);
      if (lookahead == '!') ADVANCE(15);
      if (lookahead == '$') ADVANCE(20);
      if (lookahead == '%') ADVANCE(19);
      if (lookahead == '&') ADVANCE(21);
      if (lookahead == '*') ADVANCE(11);
      if (lookahead == ',') ADVANCE(17);
      if (lookahead == '-') ADVANCE(13);
      if (lookahead == '/') ADVANCE(12);
      if (lookahead == ':') ADVANCE(22);
      if (lookahead == '^') ADVANCE(16);
      if (lookahead == '_') ADVANCE(14);
      if (lookahead == '`') ADVANCE(18);
      if (lookahead == ' ' ||
          lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(26);
      if (sym__character_character_set_1(lookahead)) ADVANCE(9);
      if (lookahead != 0 &&
          lookahead != 8232 &&
          lookahead != 8233) ADVANCE(25);
      END_STATE();
    case 2:
      if (lookahead == '*') ADVANCE(10);
      END_STATE();
    case 3:
      if (eof) ADVANCE(4);
      if (lookahead == 0) ADVANCE(8);
      if (lookahead == '\n') ADVANCE(5);
      if (lookahead == '\r') ADVANCE(6);
      if (lookahead == '!') ADVANCE(15);
      if (lookahead == '$') ADVANCE(20);
      if (lookahead == '%') ADVANCE(19);
      if (lookahead == '&') ADVANCE(21);
      if (lookahead == '*') ADVANCE(11);
      if (lookahead == ',') ADVANCE(17);
      if (lookahead == '-') ADVANCE(13);
      if (lookahead == '/') ADVANCE(12);
      if (lookahead == ':') ADVANCE(22);
      if (lookahead == '^') ADVANCE(16);
      if (lookahead == '_') ADVANCE(14);
      if (lookahead == '`') ADVANCE(18);
      if (lookahead == ' ' ||
          lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(26);
      if (sym__character_character_set_1(lookahead)) ADVANCE(9);
      if (lookahead != 0 &&
          lookahead != 8232 &&
          lookahead != 8233) ADVANCE(25);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_LF);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_CR);
      if (lookahead == '\n') ADVANCE(7);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_CR_LF);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym__character);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(23);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '/') ADVANCE(24);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_CARET);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_AMP);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(aux_sym_punctuation_token1);
      if (lookahead == '*') ADVANCE(23);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(aux_sym_punctuation_token2);
      if (lookahead == '/') ADVANCE(24);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(aux_sym_punctuation_token3);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym__whitespace);
      if (lookahead == ' ' ||
          lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(26);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_BSLASH);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token1);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 3, .external_lex_state = 1},
  [2] = {.lex_state = 3, .external_lex_state = 1},
  [3] = {.lex_state = 3, .external_lex_state = 1},
  [4] = {.lex_state = 3, .external_lex_state = 1},
  [5] = {.lex_state = 3, .external_lex_state = 1},
  [6] = {.lex_state = 3, .external_lex_state = 1},
  [7] = {.lex_state = 3, .external_lex_state = 1},
  [8] = {.lex_state = 3, .external_lex_state = 1},
  [9] = {.lex_state = 1, .external_lex_state = 1},
  [10] = {.lex_state = 1, .external_lex_state = 1},
  [11] = {.lex_state = 1, .external_lex_state = 1},
  [12] = {.lex_state = 1, .external_lex_state = 1},
  [13] = {.lex_state = 3, .external_lex_state = 1},
  [14] = {.lex_state = 3, .external_lex_state = 1},
  [15] = {.lex_state = 3, .external_lex_state = 1},
  [16] = {.lex_state = 3, .external_lex_state = 1},
  [17] = {.lex_state = 3, .external_lex_state = 1},
  [18] = {.lex_state = 1, .external_lex_state = 1},
  [19] = {.lex_state = 1, .external_lex_state = 1},
  [20] = {.lex_state = 3, .external_lex_state = 1},
  [21] = {.lex_state = 3, .external_lex_state = 1},
  [22] = {.lex_state = 3, .external_lex_state = 1},
  [23] = {.lex_state = 3, .external_lex_state = 1},
  [24] = {.lex_state = 3, .external_lex_state = 1},
  [25] = {.lex_state = 3, .external_lex_state = 1},
  [26] = {.lex_state = 3, .external_lex_state = 1},
  [27] = {.lex_state = 3, .external_lex_state = 1},
  [28] = {.lex_state = 3, .external_lex_state = 1},
  [29] = {.lex_state = 3, .external_lex_state = 1},
  [30] = {.lex_state = 3, .external_lex_state = 1},
  [31] = {.lex_state = 3, .external_lex_state = 1},
  [32] = {.lex_state = 3, .external_lex_state = 1},
  [33] = {.lex_state = 3, .external_lex_state = 1},
  [34] = {.lex_state = 3, .external_lex_state = 1},
  [35] = {.lex_state = 3, .external_lex_state = 1},
  [36] = {.lex_state = 3, .external_lex_state = 1},
  [37] = {.lex_state = 3, .external_lex_state = 1},
  [38] = {.lex_state = 3, .external_lex_state = 1},
  [39] = {.lex_state = 3, .external_lex_state = 1},
  [40] = {.lex_state = 3, .external_lex_state = 1},
  [41] = {.lex_state = 3, .external_lex_state = 1},
  [42] = {.lex_state = 3, .external_lex_state = 1},
  [43] = {.lex_state = 3, .external_lex_state = 1},
  [44] = {.lex_state = 3, .external_lex_state = 1},
  [45] = {.lex_state = 3, .external_lex_state = 1},
  [46] = {.lex_state = 1, .external_lex_state = 1},
  [47] = {.lex_state = 1, .external_lex_state = 1},
  [48] = {.lex_state = 1, .external_lex_state = 1},
  [49] = {.lex_state = 1, .external_lex_state = 1},
  [50] = {.lex_state = 1, .external_lex_state = 1},
  [51] = {.lex_state = 1, .external_lex_state = 1},
  [52] = {.lex_state = 1, .external_lex_state = 1},
  [53] = {.lex_state = 2, .external_lex_state = 1},
  [54] = {.lex_state = 3, .external_lex_state = 1},
  [55] = {.lex_state = 0, .external_lex_state = 1},
};

enum {
  ts_external_token__precedingwhitespace = 0,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__precedingwhitespace] = sym__precedingwhitespace,
};

static const bool ts_external_scanner_states[2][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__precedingwhitespace] = true,
  },
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_LF] = ACTIONS(1),
    [anon_sym_CR] = ACTIONS(1),
    [anon_sym_CR_LF] = ACTIONS(1),
    [anon_sym_] = ACTIONS(1),
    [sym__character] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym__] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_CARET] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_BQUOTE] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_DOLLAR] = ACTIONS(1),
    [anon_sym_AMP] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [aux_sym_punctuation_token1] = ACTIONS(1),
    [aux_sym_punctuation_token2] = ACTIONS(1),
    [aux_sym_punctuation_token3] = ACTIONS(1),
    [sym__whitespace] = ACTIONS(1),
    [anon_sym_BSLASH] = ACTIONS(1),
    [aux_sym_escape_sequence_token1] = ACTIONS(1),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [1] = {
    [sym_document] = STATE(55),
    [sym_non_structural] = STATE(3),
    [sym_punctuation] = STATE(7),
    [sym__word] = STATE(13),
    [sym_paragraph] = STATE(40),
    [sym__word_segment] = STATE(21),
    [sym__ws_segment] = STATE(21),
    [sym__punc_segment] = STATE(21),
    [sym__att_mod_seg] = STATE(21),
    [sym__paragraph_segment] = STATE(21),
    [sym_bold_open] = STATE(46),
    [sym_bold] = STATE(8),
    [aux_sym_document_repeat1] = STATE(3),
    [aux_sym__word_repeat1] = STATE(17),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_LF] = ACTIONS(7),
    [anon_sym_CR] = ACTIONS(9),
    [anon_sym_CR_LF] = ACTIONS(7),
    [anon_sym_] = ACTIONS(7),
    [sym__character] = ACTIONS(11),
    [anon_sym_STAR] = ACTIONS(13),
    [anon_sym_SLASH] = ACTIONS(15),
    [anon_sym_DASH] = ACTIONS(17),
    [anon_sym__] = ACTIONS(17),
    [anon_sym_BANG] = ACTIONS(17),
    [anon_sym_CARET] = ACTIONS(17),
    [anon_sym_COMMA] = ACTIONS(17),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_PERCENT] = ACTIONS(17),
    [anon_sym_DOLLAR] = ACTIONS(17),
    [anon_sym_AMP] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(17),
    [aux_sym_punctuation_token1] = ACTIONS(19),
    [aux_sym_punctuation_token2] = ACTIONS(19),
    [aux_sym_punctuation_token3] = ACTIONS(15),
    [sym__whitespace] = ACTIONS(21),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [2] = {
    [sym_non_structural] = STATE(2),
    [sym_punctuation] = STATE(7),
    [sym__word] = STATE(13),
    [sym_paragraph] = STATE(40),
    [sym__word_segment] = STATE(21),
    [sym__ws_segment] = STATE(21),
    [sym__punc_segment] = STATE(21),
    [sym__att_mod_seg] = STATE(21),
    [sym__paragraph_segment] = STATE(21),
    [sym_bold_open] = STATE(46),
    [sym_bold] = STATE(8),
    [aux_sym_document_repeat1] = STATE(2),
    [aux_sym__word_repeat1] = STATE(17),
    [ts_builtin_sym_end] = ACTIONS(23),
    [anon_sym_LF] = ACTIONS(25),
    [anon_sym_CR] = ACTIONS(28),
    [anon_sym_CR_LF] = ACTIONS(25),
    [anon_sym_] = ACTIONS(25),
    [sym__character] = ACTIONS(31),
    [anon_sym_STAR] = ACTIONS(34),
    [anon_sym_SLASH] = ACTIONS(37),
    [anon_sym_DASH] = ACTIONS(40),
    [anon_sym__] = ACTIONS(40),
    [anon_sym_BANG] = ACTIONS(40),
    [anon_sym_CARET] = ACTIONS(40),
    [anon_sym_COMMA] = ACTIONS(40),
    [anon_sym_BQUOTE] = ACTIONS(40),
    [anon_sym_PERCENT] = ACTIONS(40),
    [anon_sym_DOLLAR] = ACTIONS(40),
    [anon_sym_AMP] = ACTIONS(40),
    [anon_sym_COLON] = ACTIONS(40),
    [aux_sym_punctuation_token1] = ACTIONS(43),
    [aux_sym_punctuation_token2] = ACTIONS(43),
    [aux_sym_punctuation_token3] = ACTIONS(37),
    [sym__whitespace] = ACTIONS(46),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [3] = {
    [sym_non_structural] = STATE(2),
    [sym_punctuation] = STATE(7),
    [sym__word] = STATE(13),
    [sym_paragraph] = STATE(40),
    [sym__word_segment] = STATE(21),
    [sym__ws_segment] = STATE(21),
    [sym__punc_segment] = STATE(21),
    [sym__att_mod_seg] = STATE(21),
    [sym__paragraph_segment] = STATE(21),
    [sym_bold_open] = STATE(46),
    [sym_bold] = STATE(8),
    [aux_sym_document_repeat1] = STATE(2),
    [aux_sym__word_repeat1] = STATE(17),
    [ts_builtin_sym_end] = ACTIONS(49),
    [anon_sym_LF] = ACTIONS(7),
    [anon_sym_CR] = ACTIONS(9),
    [anon_sym_CR_LF] = ACTIONS(7),
    [anon_sym_] = ACTIONS(7),
    [sym__character] = ACTIONS(11),
    [anon_sym_STAR] = ACTIONS(13),
    [anon_sym_SLASH] = ACTIONS(15),
    [anon_sym_DASH] = ACTIONS(17),
    [anon_sym__] = ACTIONS(17),
    [anon_sym_BANG] = ACTIONS(17),
    [anon_sym_CARET] = ACTIONS(17),
    [anon_sym_COMMA] = ACTIONS(17),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_PERCENT] = ACTIONS(17),
    [anon_sym_DOLLAR] = ACTIONS(17),
    [anon_sym_AMP] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(17),
    [aux_sym_punctuation_token1] = ACTIONS(19),
    [aux_sym_punctuation_token2] = ACTIONS(19),
    [aux_sym_punctuation_token3] = ACTIONS(15),
    [sym__whitespace] = ACTIONS(21),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [4] = {
    [sym_punctuation] = STATE(7),
    [sym__word] = STATE(13),
    [sym__word_segment] = STATE(32),
    [sym__ws_segment] = STATE(32),
    [sym__punc_segment] = STATE(32),
    [sym__att_mod_seg] = STATE(32),
    [sym__paragraph_segment] = STATE(32),
    [sym_bold_open] = STATE(46),
    [sym_bold] = STATE(8),
    [aux_sym__word_repeat1] = STATE(17),
    [ts_builtin_sym_end] = ACTIONS(51),
    [anon_sym_LF] = ACTIONS(51),
    [anon_sym_CR] = ACTIONS(53),
    [anon_sym_CR_LF] = ACTIONS(51),
    [anon_sym_] = ACTIONS(51),
    [sym__character] = ACTIONS(11),
    [anon_sym_STAR] = ACTIONS(13),
    [anon_sym_SLASH] = ACTIONS(15),
    [anon_sym_DASH] = ACTIONS(17),
    [anon_sym__] = ACTIONS(17),
    [anon_sym_BANG] = ACTIONS(17),
    [anon_sym_CARET] = ACTIONS(17),
    [anon_sym_COMMA] = ACTIONS(17),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_PERCENT] = ACTIONS(17),
    [anon_sym_DOLLAR] = ACTIONS(17),
    [anon_sym_AMP] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(17),
    [aux_sym_punctuation_token1] = ACTIONS(19),
    [aux_sym_punctuation_token2] = ACTIONS(19),
    [aux_sym_punctuation_token3] = ACTIONS(15),
    [sym__whitespace] = ACTIONS(21),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [5] = {
    [sym_punctuation] = STATE(7),
    [sym__word] = STATE(13),
    [sym__word_segment] = STATE(25),
    [sym__ws_segment] = STATE(25),
    [sym__punc_segment] = STATE(25),
    [sym__att_mod_seg] = STATE(25),
    [sym__paragraph_segment] = STATE(25),
    [sym_bold_open] = STATE(46),
    [sym_bold] = STATE(8),
    [aux_sym__word_repeat1] = STATE(17),
    [ts_builtin_sym_end] = ACTIONS(55),
    [anon_sym_LF] = ACTIONS(55),
    [anon_sym_CR] = ACTIONS(57),
    [anon_sym_CR_LF] = ACTIONS(55),
    [anon_sym_] = ACTIONS(55),
    [sym__character] = ACTIONS(11),
    [anon_sym_STAR] = ACTIONS(13),
    [anon_sym_SLASH] = ACTIONS(15),
    [anon_sym_DASH] = ACTIONS(17),
    [anon_sym__] = ACTIONS(17),
    [anon_sym_BANG] = ACTIONS(17),
    [anon_sym_CARET] = ACTIONS(17),
    [anon_sym_COMMA] = ACTIONS(17),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_PERCENT] = ACTIONS(17),
    [anon_sym_DOLLAR] = ACTIONS(17),
    [anon_sym_AMP] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(17),
    [aux_sym_punctuation_token1] = ACTIONS(19),
    [aux_sym_punctuation_token2] = ACTIONS(19),
    [aux_sym_punctuation_token3] = ACTIONS(15),
    [sym__whitespace] = ACTIONS(21),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [6] = {
    [sym_punctuation] = STATE(7),
    [sym__word] = STATE(13),
    [sym__word_segment] = STATE(32),
    [sym__ws_segment] = STATE(32),
    [sym__punc_segment] = STATE(32),
    [sym__att_mod_seg] = STATE(32),
    [sym__paragraph_segment] = STATE(32),
    [sym_bold_open] = STATE(46),
    [sym_bold] = STATE(8),
    [aux_sym__word_repeat1] = STATE(17),
    [ts_builtin_sym_end] = ACTIONS(59),
    [anon_sym_LF] = ACTIONS(59),
    [anon_sym_CR] = ACTIONS(61),
    [anon_sym_CR_LF] = ACTIONS(59),
    [anon_sym_] = ACTIONS(59),
    [sym__character] = ACTIONS(11),
    [anon_sym_STAR] = ACTIONS(13),
    [anon_sym_SLASH] = ACTIONS(15),
    [anon_sym_DASH] = ACTIONS(17),
    [anon_sym__] = ACTIONS(17),
    [anon_sym_BANG] = ACTIONS(17),
    [anon_sym_CARET] = ACTIONS(17),
    [anon_sym_COMMA] = ACTIONS(17),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_PERCENT] = ACTIONS(17),
    [anon_sym_DOLLAR] = ACTIONS(17),
    [anon_sym_AMP] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(17),
    [aux_sym_punctuation_token1] = ACTIONS(19),
    [aux_sym_punctuation_token2] = ACTIONS(19),
    [aux_sym_punctuation_token3] = ACTIONS(15),
    [sym__whitespace] = ACTIONS(21),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [7] = {
    [sym_punctuation] = STATE(7),
    [sym__word] = STATE(13),
    [sym__word_segment] = STATE(27),
    [sym__ws_segment] = STATE(27),
    [sym__punc_segment] = STATE(27),
    [sym__att_mod_seg] = STATE(27),
    [sym__paragraph_segment] = STATE(27),
    [sym_bold_open] = STATE(46),
    [sym_bold] = STATE(8),
    [aux_sym__word_repeat1] = STATE(17),
    [ts_builtin_sym_end] = ACTIONS(63),
    [anon_sym_LF] = ACTIONS(63),
    [anon_sym_CR] = ACTIONS(65),
    [anon_sym_CR_LF] = ACTIONS(63),
    [anon_sym_] = ACTIONS(63),
    [sym__character] = ACTIONS(11),
    [anon_sym_STAR] = ACTIONS(13),
    [anon_sym_SLASH] = ACTIONS(15),
    [anon_sym_DASH] = ACTIONS(17),
    [anon_sym__] = ACTIONS(17),
    [anon_sym_BANG] = ACTIONS(17),
    [anon_sym_CARET] = ACTIONS(17),
    [anon_sym_COMMA] = ACTIONS(17),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_PERCENT] = ACTIONS(17),
    [anon_sym_DOLLAR] = ACTIONS(17),
    [anon_sym_AMP] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(17),
    [aux_sym_punctuation_token1] = ACTIONS(19),
    [aux_sym_punctuation_token2] = ACTIONS(19),
    [aux_sym_punctuation_token3] = ACTIONS(15),
    [sym__whitespace] = ACTIONS(21),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [8] = {
    [sym_punctuation] = STATE(7),
    [sym__ws_segment] = STATE(23),
    [sym__punc_segment] = STATE(23),
    [sym__att_mod_seg] = STATE(23),
    [sym_link_modifier] = STATE(54),
    [sym_bold_open] = STATE(46),
    [sym_bold] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(67),
    [anon_sym_LF] = ACTIONS(67),
    [anon_sym_CR] = ACTIONS(69),
    [anon_sym_CR_LF] = ACTIONS(67),
    [anon_sym_] = ACTIONS(67),
    [sym__character] = ACTIONS(67),
    [anon_sym_STAR] = ACTIONS(13),
    [anon_sym_SLASH] = ACTIONS(15),
    [anon_sym_DASH] = ACTIONS(17),
    [anon_sym__] = ACTIONS(17),
    [anon_sym_BANG] = ACTIONS(17),
    [anon_sym_CARET] = ACTIONS(17),
    [anon_sym_COMMA] = ACTIONS(17),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_PERCENT] = ACTIONS(17),
    [anon_sym_DOLLAR] = ACTIONS(17),
    [anon_sym_AMP] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(71),
    [aux_sym_punctuation_token1] = ACTIONS(19),
    [aux_sym_punctuation_token2] = ACTIONS(19),
    [aux_sym_punctuation_token3] = ACTIONS(15),
    [sym__whitespace] = ACTIONS(21),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [9] = {
    [sym_punctuation] = STATE(10),
    [sym__word] = STATE(9),
    [sym_bold_close] = STATE(41),
    [sym__bold_word_segment] = STATE(41),
    [sym__bold_ws_segment] = STATE(41),
    [sym__bold_punc_segment] = STATE(41),
    [sym__bold_paragraph_segment] = STATE(41),
    [aux_sym__word_repeat1] = STATE(47),
    [anon_sym_LF] = ACTIONS(73),
    [anon_sym_CR] = ACTIONS(75),
    [anon_sym_CR_LF] = ACTIONS(73),
    [sym__character] = ACTIONS(77),
    [anon_sym_STAR] = ACTIONS(79),
    [anon_sym_SLASH] = ACTIONS(81),
    [anon_sym_DASH] = ACTIONS(83),
    [anon_sym__] = ACTIONS(83),
    [anon_sym_BANG] = ACTIONS(83),
    [anon_sym_CARET] = ACTIONS(83),
    [anon_sym_COMMA] = ACTIONS(83),
    [anon_sym_BQUOTE] = ACTIONS(83),
    [anon_sym_PERCENT] = ACTIONS(83),
    [anon_sym_DOLLAR] = ACTIONS(83),
    [anon_sym_AMP] = ACTIONS(83),
    [anon_sym_COLON] = ACTIONS(83),
    [aux_sym_punctuation_token1] = ACTIONS(85),
    [aux_sym_punctuation_token2] = ACTIONS(85),
    [aux_sym_punctuation_token3] = ACTIONS(81),
    [sym__whitespace] = ACTIONS(87),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [10] = {
    [sym_punctuation] = STATE(10),
    [sym__word] = STATE(9),
    [sym_bold_close] = STATE(39),
    [sym__bold_word_segment] = STATE(39),
    [sym__bold_ws_segment] = STATE(39),
    [sym__bold_punc_segment] = STATE(39),
    [sym__bold_paragraph_segment] = STATE(39),
    [aux_sym__word_repeat1] = STATE(47),
    [anon_sym_LF] = ACTIONS(73),
    [anon_sym_CR] = ACTIONS(75),
    [anon_sym_CR_LF] = ACTIONS(73),
    [sym__character] = ACTIONS(77),
    [anon_sym_STAR] = ACTIONS(89),
    [anon_sym_SLASH] = ACTIONS(81),
    [anon_sym_DASH] = ACTIONS(83),
    [anon_sym__] = ACTIONS(83),
    [anon_sym_BANG] = ACTIONS(83),
    [anon_sym_CARET] = ACTIONS(83),
    [anon_sym_COMMA] = ACTIONS(83),
    [anon_sym_BQUOTE] = ACTIONS(83),
    [anon_sym_PERCENT] = ACTIONS(83),
    [anon_sym_DOLLAR] = ACTIONS(83),
    [anon_sym_AMP] = ACTIONS(83),
    [anon_sym_COLON] = ACTIONS(83),
    [aux_sym_punctuation_token1] = ACTIONS(85),
    [aux_sym_punctuation_token2] = ACTIONS(85),
    [aux_sym_punctuation_token3] = ACTIONS(81),
    [sym__whitespace] = ACTIONS(87),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [11] = {
    [sym_punctuation] = STATE(7),
    [sym__word] = STATE(13),
    [sym__word_segment] = STATE(32),
    [sym__ws_segment] = STATE(32),
    [sym__punc_segment] = STATE(32),
    [sym__att_mod_seg] = STATE(32),
    [sym__paragraph_segment] = STATE(32),
    [sym_bold_open] = STATE(46),
    [sym_bold] = STATE(8),
    [aux_sym__word_repeat1] = STATE(17),
    [sym__character] = ACTIONS(11),
    [anon_sym_STAR] = ACTIONS(13),
    [anon_sym_SLASH] = ACTIONS(15),
    [anon_sym_DASH] = ACTIONS(17),
    [anon_sym__] = ACTIONS(17),
    [anon_sym_BANG] = ACTIONS(17),
    [anon_sym_CARET] = ACTIONS(17),
    [anon_sym_COMMA] = ACTIONS(17),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_PERCENT] = ACTIONS(17),
    [anon_sym_DOLLAR] = ACTIONS(17),
    [anon_sym_AMP] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(17),
    [aux_sym_punctuation_token1] = ACTIONS(19),
    [aux_sym_punctuation_token2] = ACTIONS(19),
    [aux_sym_punctuation_token3] = ACTIONS(15),
    [sym__whitespace] = ACTIONS(21),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [12] = {
    [sym_punctuation] = STATE(10),
    [sym__word] = STATE(9),
    [sym__bold_word_segment] = STATE(36),
    [sym__bold_ws_segment] = STATE(36),
    [sym__bold_punc_segment] = STATE(36),
    [sym__bold_paragraph_segment] = STATE(36),
    [aux_sym__word_repeat1] = STATE(47),
    [anon_sym_LF] = ACTIONS(73),
    [anon_sym_CR] = ACTIONS(75),
    [anon_sym_CR_LF] = ACTIONS(73),
    [sym__character] = ACTIONS(77),
    [anon_sym_STAR] = ACTIONS(81),
    [anon_sym_SLASH] = ACTIONS(81),
    [anon_sym_DASH] = ACTIONS(83),
    [anon_sym__] = ACTIONS(83),
    [anon_sym_BANG] = ACTIONS(83),
    [anon_sym_CARET] = ACTIONS(83),
    [anon_sym_COMMA] = ACTIONS(83),
    [anon_sym_BQUOTE] = ACTIONS(83),
    [anon_sym_PERCENT] = ACTIONS(83),
    [anon_sym_DOLLAR] = ACTIONS(83),
    [anon_sym_AMP] = ACTIONS(83),
    [anon_sym_COLON] = ACTIONS(83),
    [aux_sym_punctuation_token1] = ACTIONS(85),
    [aux_sym_punctuation_token2] = ACTIONS(85),
    [aux_sym_punctuation_token3] = ACTIONS(81),
    [sym__whitespace] = ACTIONS(87),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [13] = {
    [sym_punctuation] = STATE(7),
    [sym__ws_segment] = STATE(45),
    [sym__punc_segment] = STATE(45),
    [sym_link_modifier] = STATE(53),
    [ts_builtin_sym_end] = ACTIONS(91),
    [anon_sym_LF] = ACTIONS(91),
    [anon_sym_CR] = ACTIONS(93),
    [anon_sym_CR_LF] = ACTIONS(91),
    [anon_sym_] = ACTIONS(91),
    [sym__character] = ACTIONS(91),
    [anon_sym_STAR] = ACTIONS(15),
    [anon_sym_SLASH] = ACTIONS(15),
    [anon_sym_DASH] = ACTIONS(17),
    [anon_sym__] = ACTIONS(17),
    [anon_sym_BANG] = ACTIONS(17),
    [anon_sym_CARET] = ACTIONS(17),
    [anon_sym_COMMA] = ACTIONS(17),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_PERCENT] = ACTIONS(17),
    [anon_sym_DOLLAR] = ACTIONS(17),
    [anon_sym_AMP] = ACTIONS(17),
    [anon_sym_COLON] = ACTIONS(95),
    [aux_sym_punctuation_token1] = ACTIONS(19),
    [aux_sym_punctuation_token2] = ACTIONS(19),
    [aux_sym_punctuation_token3] = ACTIONS(15),
    [sym__whitespace] = ACTIONS(21),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [14] = {
    [sym__word] = STATE(9),
    [sym__bold_word_segment] = STATE(30),
    [aux_sym__word_repeat1] = STATE(47),
    [ts_builtin_sym_end] = ACTIONS(97),
    [anon_sym_LF] = ACTIONS(97),
    [anon_sym_CR] = ACTIONS(99),
    [anon_sym_CR_LF] = ACTIONS(97),
    [anon_sym_] = ACTIONS(97),
    [sym__character] = ACTIONS(77),
    [anon_sym_STAR] = ACTIONS(99),
    [anon_sym_SLASH] = ACTIONS(99),
    [anon_sym_DASH] = ACTIONS(97),
    [anon_sym__] = ACTIONS(97),
    [anon_sym_BANG] = ACTIONS(97),
    [anon_sym_CARET] = ACTIONS(97),
    [anon_sym_COMMA] = ACTIONS(97),
    [anon_sym_BQUOTE] = ACTIONS(97),
    [anon_sym_PERCENT] = ACTIONS(97),
    [anon_sym_DOLLAR] = ACTIONS(97),
    [anon_sym_AMP] = ACTIONS(97),
    [anon_sym_COLON] = ACTIONS(97),
    [aux_sym_punctuation_token1] = ACTIONS(99),
    [aux_sym_punctuation_token2] = ACTIONS(99),
    [aux_sym_punctuation_token3] = ACTIONS(99),
    [sym__whitespace] = ACTIONS(97),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [15] = {
    [sym__word] = STATE(9),
    [sym__bold_word_segment] = STATE(37),
    [aux_sym__word_repeat1] = STATE(47),
    [ts_builtin_sym_end] = ACTIONS(97),
    [anon_sym_LF] = ACTIONS(97),
    [anon_sym_CR] = ACTIONS(99),
    [anon_sym_CR_LF] = ACTIONS(97),
    [anon_sym_] = ACTIONS(97),
    [sym__character] = ACTIONS(77),
    [anon_sym_STAR] = ACTIONS(99),
    [anon_sym_SLASH] = ACTIONS(99),
    [anon_sym_DASH] = ACTIONS(97),
    [anon_sym__] = ACTIONS(97),
    [anon_sym_BANG] = ACTIONS(97),
    [anon_sym_CARET] = ACTIONS(97),
    [anon_sym_COMMA] = ACTIONS(97),
    [anon_sym_BQUOTE] = ACTIONS(97),
    [anon_sym_PERCENT] = ACTIONS(97),
    [anon_sym_DOLLAR] = ACTIONS(97),
    [anon_sym_AMP] = ACTIONS(97),
    [anon_sym_COLON] = ACTIONS(97),
    [aux_sym_punctuation_token1] = ACTIONS(99),
    [aux_sym_punctuation_token2] = ACTIONS(99),
    [aux_sym_punctuation_token3] = ACTIONS(99),
    [sym__whitespace] = ACTIONS(97),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [16] = {
    [aux_sym__word_repeat1] = STATE(16),
    [ts_builtin_sym_end] = ACTIONS(101),
    [anon_sym_LF] = ACTIONS(101),
    [anon_sym_CR] = ACTIONS(103),
    [anon_sym_CR_LF] = ACTIONS(101),
    [anon_sym_] = ACTIONS(101),
    [sym__character] = ACTIONS(105),
    [anon_sym_STAR] = ACTIONS(103),
    [anon_sym_SLASH] = ACTIONS(103),
    [anon_sym_DASH] = ACTIONS(101),
    [anon_sym__] = ACTIONS(101),
    [anon_sym_BANG] = ACTIONS(101),
    [anon_sym_CARET] = ACTIONS(101),
    [anon_sym_COMMA] = ACTIONS(101),
    [anon_sym_BQUOTE] = ACTIONS(101),
    [anon_sym_PERCENT] = ACTIONS(101),
    [anon_sym_DOLLAR] = ACTIONS(101),
    [anon_sym_AMP] = ACTIONS(101),
    [anon_sym_COLON] = ACTIONS(101),
    [aux_sym_punctuation_token1] = ACTIONS(103),
    [aux_sym_punctuation_token2] = ACTIONS(103),
    [aux_sym_punctuation_token3] = ACTIONS(103),
    [sym__whitespace] = ACTIONS(101),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [17] = {
    [aux_sym__word_repeat1] = STATE(16),
    [ts_builtin_sym_end] = ACTIONS(108),
    [anon_sym_LF] = ACTIONS(108),
    [anon_sym_CR] = ACTIONS(110),
    [anon_sym_CR_LF] = ACTIONS(108),
    [anon_sym_] = ACTIONS(108),
    [sym__character] = ACTIONS(112),
    [anon_sym_STAR] = ACTIONS(110),
    [anon_sym_SLASH] = ACTIONS(110),
    [anon_sym_DASH] = ACTIONS(108),
    [anon_sym__] = ACTIONS(108),
    [anon_sym_BANG] = ACTIONS(108),
    [anon_sym_CARET] = ACTIONS(108),
    [anon_sym_COMMA] = ACTIONS(108),
    [anon_sym_BQUOTE] = ACTIONS(108),
    [anon_sym_PERCENT] = ACTIONS(108),
    [anon_sym_DOLLAR] = ACTIONS(108),
    [anon_sym_AMP] = ACTIONS(108),
    [anon_sym_COLON] = ACTIONS(108),
    [aux_sym_punctuation_token1] = ACTIONS(110),
    [aux_sym_punctuation_token2] = ACTIONS(110),
    [aux_sym_punctuation_token3] = ACTIONS(110),
    [sym__whitespace] = ACTIONS(108),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [18] = {
    [sym_punctuation] = STATE(10),
    [sym__word] = STATE(9),
    [sym__bold_word_segment] = STATE(29),
    [sym__bold_punc_segment] = STATE(29),
    [aux_sym__word_repeat1] = STATE(47),
    [aux_sym__bold_paragraph_segment_repeat1] = STATE(51),
    [sym__character] = ACTIONS(77),
    [anon_sym_STAR] = ACTIONS(81),
    [anon_sym_SLASH] = ACTIONS(81),
    [anon_sym_DASH] = ACTIONS(83),
    [anon_sym__] = ACTIONS(83),
    [anon_sym_BANG] = ACTIONS(83),
    [anon_sym_CARET] = ACTIONS(83),
    [anon_sym_COMMA] = ACTIONS(83),
    [anon_sym_BQUOTE] = ACTIONS(83),
    [anon_sym_PERCENT] = ACTIONS(83),
    [anon_sym_DOLLAR] = ACTIONS(83),
    [anon_sym_AMP] = ACTIONS(83),
    [anon_sym_COLON] = ACTIONS(83),
    [aux_sym_punctuation_token1] = ACTIONS(85),
    [aux_sym_punctuation_token2] = ACTIONS(85),
    [aux_sym_punctuation_token3] = ACTIONS(81),
    [sym__whitespace] = ACTIONS(114),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [19] = {
    [sym_punctuation] = STATE(10),
    [sym__word] = STATE(9),
    [sym__bold_word_segment] = STATE(44),
    [sym__bold_punc_segment] = STATE(44),
    [aux_sym__word_repeat1] = STATE(47),
    [aux_sym__bold_paragraph_segment_repeat1] = STATE(18),
    [sym__character] = ACTIONS(77),
    [anon_sym_STAR] = ACTIONS(81),
    [anon_sym_SLASH] = ACTIONS(81),
    [anon_sym_DASH] = ACTIONS(83),
    [anon_sym__] = ACTIONS(83),
    [anon_sym_BANG] = ACTIONS(83),
    [anon_sym_CARET] = ACTIONS(83),
    [anon_sym_COMMA] = ACTIONS(83),
    [anon_sym_BQUOTE] = ACTIONS(83),
    [anon_sym_PERCENT] = ACTIONS(83),
    [anon_sym_DOLLAR] = ACTIONS(83),
    [anon_sym_AMP] = ACTIONS(83),
    [anon_sym_COLON] = ACTIONS(83),
    [aux_sym_punctuation_token1] = ACTIONS(85),
    [aux_sym_punctuation_token2] = ACTIONS(85),
    [aux_sym_punctuation_token3] = ACTIONS(81),
    [sym__whitespace] = ACTIONS(116),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [20] = {
    [aux_sym_paragraph_repeat1] = STATE(20),
    [ts_builtin_sym_end] = ACTIONS(118),
    [anon_sym_LF] = ACTIONS(120),
    [anon_sym_CR] = ACTIONS(123),
    [anon_sym_CR_LF] = ACTIONS(120),
    [anon_sym_] = ACTIONS(118),
    [sym__character] = ACTIONS(118),
    [anon_sym_STAR] = ACTIONS(126),
    [anon_sym_SLASH] = ACTIONS(126),
    [anon_sym_DASH] = ACTIONS(118),
    [anon_sym__] = ACTIONS(118),
    [anon_sym_BANG] = ACTIONS(118),
    [anon_sym_CARET] = ACTIONS(118),
    [anon_sym_COMMA] = ACTIONS(118),
    [anon_sym_BQUOTE] = ACTIONS(118),
    [anon_sym_PERCENT] = ACTIONS(118),
    [anon_sym_DOLLAR] = ACTIONS(118),
    [anon_sym_AMP] = ACTIONS(118),
    [anon_sym_COLON] = ACTIONS(118),
    [aux_sym_punctuation_token1] = ACTIONS(126),
    [aux_sym_punctuation_token2] = ACTIONS(126),
    [aux_sym_punctuation_token3] = ACTIONS(126),
    [sym__whitespace] = ACTIONS(118),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [21] = {
    [aux_sym_paragraph_repeat1] = STATE(22),
    [ts_builtin_sym_end] = ACTIONS(128),
    [anon_sym_LF] = ACTIONS(130),
    [anon_sym_CR] = ACTIONS(132),
    [anon_sym_CR_LF] = ACTIONS(130),
    [anon_sym_] = ACTIONS(134),
    [sym__character] = ACTIONS(128),
    [anon_sym_STAR] = ACTIONS(136),
    [anon_sym_SLASH] = ACTIONS(136),
    [anon_sym_DASH] = ACTIONS(128),
    [anon_sym__] = ACTIONS(128),
    [anon_sym_BANG] = ACTIONS(128),
    [anon_sym_CARET] = ACTIONS(128),
    [anon_sym_COMMA] = ACTIONS(128),
    [anon_sym_BQUOTE] = ACTIONS(128),
    [anon_sym_PERCENT] = ACTIONS(128),
    [anon_sym_DOLLAR] = ACTIONS(128),
    [anon_sym_AMP] = ACTIONS(128),
    [anon_sym_COLON] = ACTIONS(128),
    [aux_sym_punctuation_token1] = ACTIONS(136),
    [aux_sym_punctuation_token2] = ACTIONS(136),
    [aux_sym_punctuation_token3] = ACTIONS(136),
    [sym__whitespace] = ACTIONS(128),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [22] = {
    [aux_sym_paragraph_repeat1] = STATE(20),
    [ts_builtin_sym_end] = ACTIONS(51),
    [anon_sym_LF] = ACTIONS(138),
    [anon_sym_CR] = ACTIONS(140),
    [anon_sym_CR_LF] = ACTIONS(138),
    [anon_sym_] = ACTIONS(142),
    [sym__character] = ACTIONS(51),
    [anon_sym_STAR] = ACTIONS(53),
    [anon_sym_SLASH] = ACTIONS(53),
    [anon_sym_DASH] = ACTIONS(51),
    [anon_sym__] = ACTIONS(51),
    [anon_sym_BANG] = ACTIONS(51),
    [anon_sym_CARET] = ACTIONS(51),
    [anon_sym_COMMA] = ACTIONS(51),
    [anon_sym_BQUOTE] = ACTIONS(51),
    [anon_sym_PERCENT] = ACTIONS(51),
    [anon_sym_DOLLAR] = ACTIONS(51),
    [anon_sym_AMP] = ACTIONS(51),
    [anon_sym_COLON] = ACTIONS(51),
    [aux_sym_punctuation_token1] = ACTIONS(53),
    [aux_sym_punctuation_token2] = ACTIONS(53),
    [aux_sym_punctuation_token3] = ACTIONS(53),
    [sym__whitespace] = ACTIONS(51),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(146), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(144), 16,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [30] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(150), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(148), 16,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [60] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(154), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(152), 16,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [90] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(158), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(156), 16,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [120] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(162), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(160), 16,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [150] = 4,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(164), 1,
      sym__character,
    ACTIONS(150), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(148), 15,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [182] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(169), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(167), 16,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [212] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(173), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(171), 16,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [242] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(177), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(175), 16,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [272] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(126), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(118), 16,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [302] = 4,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(179), 1,
      anon_sym_STAR,
    ACTIONS(150), 5,
      anon_sym_CR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(148), 16,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [334] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(61), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(59), 16,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [364] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(53), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(51), 16,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [394] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(184), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(182), 16,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [424] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(188), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(186), 16,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [454] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(150), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(148), 16,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [484] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(192), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(190), 16,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [514] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(196), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(194), 16,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [544] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(200), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(198), 16,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [574] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(204), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(202), 16,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [604] = 5,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(150), 1,
      anon_sym_CR,
    ACTIONS(148), 5,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__whitespace,
    ACTIONS(209), 5,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(206), 11,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
  [638] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(214), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(212), 16,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [668] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(218), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(216), 16,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [698] = 9,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(77), 1,
      sym__character,
    STATE(9), 1,
      sym__word,
    STATE(10), 1,
      sym_punctuation,
    STATE(47), 1,
      aux_sym__word_repeat1,
    ACTIONS(85), 2,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
    STATE(26), 2,
      sym__bold_word_segment,
      sym__bold_punc_segment,
    ACTIONS(81), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token3,
    ACTIONS(83), 10,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
  [739] = 5,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(220), 1,
      sym__character,
    STATE(48), 1,
      aux_sym__word_repeat1,
    ACTIONS(110), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(108), 13,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [772] = 5,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(222), 1,
      sym__character,
    STATE(48), 1,
      aux_sym__word_repeat1,
    ACTIONS(103), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(101), 13,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [805] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(150), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(148), 14,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [833] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(150), 6,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(148), 14,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
      sym__whitespace,
  [861] = 5,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(229), 1,
      sym__whitespace,
    STATE(51), 1,
      aux_sym__bold_paragraph_segment_repeat1,
    ACTIONS(227), 5,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(225), 11,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
  [891] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(234), 5,
      anon_sym_STAR,
      anon_sym_SLASH,
      aux_sym_punctuation_token1,
      aux_sym_punctuation_token2,
      aux_sym_punctuation_token3,
    ACTIONS(232), 11,
      sym__character,
      anon_sym_DASH,
      anon_sym__,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_COMMA,
      anon_sym_BQUOTE,
      anon_sym_PERCENT,
      anon_sym_DOLLAR,
      anon_sym_AMP,
      anon_sym_COLON,
  [915] = 5,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(236), 1,
      anon_sym_STAR,
    STATE(8), 1,
      sym_bold,
    STATE(31), 1,
      sym__att_mod_seg,
    STATE(46), 1,
      sym_bold_open,
  [931] = 5,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(11), 1,
      sym__character,
    STATE(13), 1,
      sym__word,
    STATE(17), 1,
      aux_sym__word_repeat1,
    STATE(42), 1,
      sym__word_segment,
  [947] = 2,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(238), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(23)] = 0,
  [SMALL_STATE(24)] = 30,
  [SMALL_STATE(25)] = 60,
  [SMALL_STATE(26)] = 90,
  [SMALL_STATE(27)] = 120,
  [SMALL_STATE(28)] = 150,
  [SMALL_STATE(29)] = 182,
  [SMALL_STATE(30)] = 212,
  [SMALL_STATE(31)] = 242,
  [SMALL_STATE(32)] = 272,
  [SMALL_STATE(33)] = 302,
  [SMALL_STATE(34)] = 334,
  [SMALL_STATE(35)] = 364,
  [SMALL_STATE(36)] = 394,
  [SMALL_STATE(37)] = 424,
  [SMALL_STATE(38)] = 454,
  [SMALL_STATE(39)] = 484,
  [SMALL_STATE(40)] = 514,
  [SMALL_STATE(41)] = 544,
  [SMALL_STATE(42)] = 574,
  [SMALL_STATE(43)] = 604,
  [SMALL_STATE(44)] = 638,
  [SMALL_STATE(45)] = 668,
  [SMALL_STATE(46)] = 698,
  [SMALL_STATE(47)] = 739,
  [SMALL_STATE(48)] = 772,
  [SMALL_STATE(49)] = 805,
  [SMALL_STATE(50)] = 833,
  [SMALL_STATE(51)] = 861,
  [SMALL_STATE(52)] = 891,
  [SMALL_STATE(53)] = 915,
  [SMALL_STATE(54)] = 931,
  [SMALL_STATE(55)] = 947,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2),
  [25] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(40),
  [28] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(40),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(17),
  [34] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(43),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(24),
  [40] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(24),
  [43] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(38),
  [46] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(5),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paragraph, 2),
  [53] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_paragraph, 2),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ws_segment, 1),
  [57] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__ws_segment, 1),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paragraph, 3),
  [61] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_paragraph, 3),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__punc_segment, 1),
  [65] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__punc_segment, 1),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__att_mod_seg, 1),
  [69] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__att_mod_seg, 1),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [75] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [79] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [81] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [85] = {.entry = {.count = 1, .reusable = false}}, SHIFT(50),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__word_segment, 1),
  [93] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__word_segment, 1),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bold_close, 1),
  [99] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bold_close, 1),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__word_repeat1, 2),
  [103] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__word_repeat1, 2),
  [105] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__word_repeat1, 2), SHIFT_REPEAT(16),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__word, 1),
  [110] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__word, 1),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2),
  [120] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(11),
  [123] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(11),
  [126] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_paragraph_repeat1, 2),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paragraph, 1),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [132] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [136] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_paragraph, 1),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [140] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__att_mod_seg, 2),
  [146] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__att_mod_seg, 2),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_punctuation, 1),
  [150] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_punctuation, 1),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ws_segment, 2),
  [154] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__ws_segment, 2),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bold, 2, .dynamic_precedence = 1),
  [158] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bold, 2, .dynamic_precedence = 1),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__punc_segment, 2),
  [162] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__punc_segment, 2),
  [164] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_punctuation, 1), REDUCE(sym_link_modifier, 1, .dynamic_precedence = 1),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bold_paragraph_segment, 3, .production_id = 1),
  [169] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bold_paragraph_segment, 3, .production_id = 1),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bold_word_segment, 3),
  [173] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bold_word_segment, 3),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__word_segment, 3),
  [177] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__word_segment, 3),
  [179] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_punctuation, 1), REDUCE(sym_link_modifier, 1, .dynamic_precedence = 1),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bold_ws_segment, 2),
  [184] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bold_ws_segment, 2),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bold_punc_segment, 3),
  [188] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bold_punc_segment, 3),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bold_punc_segment, 2),
  [192] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bold_punc_segment, 2),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_non_structural, 1),
  [196] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_non_structural, 1),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bold_word_segment, 2),
  [200] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bold_word_segment, 2),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__att_mod_seg, 3),
  [204] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__att_mod_seg, 3),
  [206] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_punctuation, 1), REDUCE(sym_bold_open, 1),
  [209] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_punctuation, 1), REDUCE(sym_bold_open, 1),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bold_paragraph_segment, 2, .production_id = 1),
  [214] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bold_paragraph_segment, 2, .production_id = 1),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__word_segment, 2),
  [218] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__word_segment, 2),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [222] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__word_repeat1, 2), SHIFT_REPEAT(48),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__bold_paragraph_segment_repeat1, 2),
  [227] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__bold_paragraph_segment_repeat1, 2),
  [229] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__bold_paragraph_segment_repeat1, 2), SHIFT_REPEAT(51),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bold_open, 1),
  [234] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bold_open, 1),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [238] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_norg_external_scanner_create(void);
void tree_sitter_norg_external_scanner_destroy(void *);
bool tree_sitter_norg_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_norg_external_scanner_serialize(void *, char *);
void tree_sitter_norg_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_norg(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_norg_external_scanner_create,
      tree_sitter_norg_external_scanner_destroy,
      tree_sitter_norg_external_scanner_scan,
      tree_sitter_norg_external_scanner_serialize,
      tree_sitter_norg_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
