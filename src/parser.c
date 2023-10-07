#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 45
#define LARGE_STATE_COUNT 11
#define SYMBOL_COUNT 35
#define ALIAS_COUNT 1
#define TOKEN_COUNT 14
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
  anon_sym_SEMI = 8,
  aux_sym_punctuation_token1 = 9,
  sym__whitespace = 10,
  anon_sym_BSLASH = 11,
  aux_sym_escape_sequence_token1 = 12,
  sym__precedingwhitespace = 13,
  sym_document = 14,
  sym_non_structural = 15,
  sym_punctuation = 16,
  sym__word = 17,
  sym_paragraph = 18,
  sym__word_segment = 19,
  sym__ws_segment = 20,
  sym__punc_segment = 21,
  sym__att_mod_seg = 22,
  sym__paragraph_segment = 23,
  sym_bold_open = 24,
  sym_bold_close = 25,
  sym__bold_word_segment = 26,
  sym__bold_ws_segment = 27,
  sym__bold_punc_segment = 28,
  sym__bold_paragraph_segment = 29,
  sym_bold = 30,
  aux_sym_document_repeat1 = 31,
  aux_sym__word_repeat1 = 32,
  aux_sym_paragraph_repeat1 = 33,
  aux_sym__bold_paragraph_segment_repeat1 = 34,
  alias_sym_newline = 35,
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
  [anon_sym_SEMI] = ";",
  [aux_sym_punctuation_token1] = "punctuation_token1",
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
  [anon_sym_SEMI] = anon_sym_SEMI,
  [aux_sym_punctuation_token1] = aux_sym_punctuation_token1,
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
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_punctuation_token1] = {
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
  [33] = 33,
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
      if (eof) ADVANCE(2);
      if (lookahead == 0) ADVANCE(6);
      if (lookahead == '\n') ADVANCE(3);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '*') ADVANCE(8);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == ';') ADVANCE(10);
      if (lookahead == '\\') ADVANCE(13);
      if (lookahead == ' ' ||
          lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(12);
      if (sym__character_character_set_1(lookahead)) ADVANCE(7);
      if (lookahead != 0) ADVANCE(14);
      END_STATE();
    case 1:
      if (eof) ADVANCE(2);
      if (lookahead == 0) ADVANCE(6);
      if (lookahead == '\n') ADVANCE(3);
      if (lookahead == '\r') ADVANCE(4);
      if (lookahead == '*') ADVANCE(8);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == ';') ADVANCE(10);
      if (lookahead == ' ' ||
          lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(12);
      if (sym__character_character_set_1(lookahead)) ADVANCE(7);
      END_STATE();
    case 2:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(anon_sym_LF);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(anon_sym_CR);
      if (lookahead == '\n') ADVANCE(5);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_CR_LF);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(sym__character);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(11);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(aux_sym_punctuation_token1);
      if (lookahead == '*') ADVANCE(11);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym__whitespace);
      if (lookahead == ' ' ||
          lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(12);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_BSLASH);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token1);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 1, .external_lex_state = 1},
  [2] = {.lex_state = 1, .external_lex_state = 1},
  [3] = {.lex_state = 1, .external_lex_state = 1},
  [4] = {.lex_state = 1, .external_lex_state = 1},
  [5] = {.lex_state = 1, .external_lex_state = 1},
  [6] = {.lex_state = 1, .external_lex_state = 1},
  [7] = {.lex_state = 1, .external_lex_state = 1},
  [8] = {.lex_state = 1, .external_lex_state = 1},
  [9] = {.lex_state = 1, .external_lex_state = 1},
  [10] = {.lex_state = 1, .external_lex_state = 1},
  [11] = {.lex_state = 1, .external_lex_state = 1},
  [12] = {.lex_state = 1, .external_lex_state = 1},
  [13] = {.lex_state = 1, .external_lex_state = 1},
  [14] = {.lex_state = 1, .external_lex_state = 1},
  [15] = {.lex_state = 1, .external_lex_state = 1},
  [16] = {.lex_state = 1, .external_lex_state = 1},
  [17] = {.lex_state = 1, .external_lex_state = 1},
  [18] = {.lex_state = 1, .external_lex_state = 1},
  [19] = {.lex_state = 1, .external_lex_state = 1},
  [20] = {.lex_state = 1, .external_lex_state = 1},
  [21] = {.lex_state = 1, .external_lex_state = 1},
  [22] = {.lex_state = 1, .external_lex_state = 1},
  [23] = {.lex_state = 1, .external_lex_state = 1},
  [24] = {.lex_state = 1, .external_lex_state = 1},
  [25] = {.lex_state = 1, .external_lex_state = 1},
  [26] = {.lex_state = 1, .external_lex_state = 1},
  [27] = {.lex_state = 1, .external_lex_state = 1},
  [28] = {.lex_state = 1, .external_lex_state = 1},
  [29] = {.lex_state = 1, .external_lex_state = 1},
  [30] = {.lex_state = 1, .external_lex_state = 1},
  [31] = {.lex_state = 1, .external_lex_state = 1},
  [32] = {.lex_state = 1, .external_lex_state = 1},
  [33] = {.lex_state = 1, .external_lex_state = 1},
  [34] = {.lex_state = 1, .external_lex_state = 1},
  [35] = {.lex_state = 1, .external_lex_state = 1},
  [36] = {.lex_state = 1, .external_lex_state = 1},
  [37] = {.lex_state = 1, .external_lex_state = 1},
  [38] = {.lex_state = 1, .external_lex_state = 1},
  [39] = {.lex_state = 1, .external_lex_state = 1},
  [40] = {.lex_state = 1, .external_lex_state = 1},
  [41] = {.lex_state = 1, .external_lex_state = 1},
  [42] = {.lex_state = 1, .external_lex_state = 1},
  [43] = {.lex_state = 1, .external_lex_state = 1},
  [44] = {.lex_state = 0, .external_lex_state = 1},
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
    [anon_sym_SEMI] = ACTIONS(1),
    [aux_sym_punctuation_token1] = ACTIONS(1),
    [sym__whitespace] = ACTIONS(1),
    [anon_sym_BSLASH] = ACTIONS(1),
    [aux_sym_escape_sequence_token1] = ACTIONS(1),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [1] = {
    [sym_document] = STATE(44),
    [sym_non_structural] = STATE(2),
    [sym_punctuation] = STATE(6),
    [sym__word] = STATE(15),
    [sym_paragraph] = STATE(32),
    [sym__word_segment] = STATE(22),
    [sym__ws_segment] = STATE(22),
    [sym__punc_segment] = STATE(22),
    [sym__att_mod_seg] = STATE(22),
    [sym__paragraph_segment] = STATE(22),
    [sym_bold_open] = STATE(42),
    [sym_bold] = STATE(10),
    [aux_sym_document_repeat1] = STATE(2),
    [aux_sym__word_repeat1] = STATE(18),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_LF] = ACTIONS(7),
    [anon_sym_CR] = ACTIONS(9),
    [anon_sym_CR_LF] = ACTIONS(7),
    [anon_sym_] = ACTIONS(7),
    [sym__character] = ACTIONS(11),
    [anon_sym_STAR] = ACTIONS(13),
    [anon_sym_SLASH] = ACTIONS(15),
    [anon_sym_SEMI] = ACTIONS(15),
    [aux_sym_punctuation_token1] = ACTIONS(17),
    [sym__whitespace] = ACTIONS(19),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [2] = {
    [sym_non_structural] = STATE(3),
    [sym_punctuation] = STATE(6),
    [sym__word] = STATE(15),
    [sym_paragraph] = STATE(32),
    [sym__word_segment] = STATE(22),
    [sym__ws_segment] = STATE(22),
    [sym__punc_segment] = STATE(22),
    [sym__att_mod_seg] = STATE(22),
    [sym__paragraph_segment] = STATE(22),
    [sym_bold_open] = STATE(42),
    [sym_bold] = STATE(10),
    [aux_sym_document_repeat1] = STATE(3),
    [aux_sym__word_repeat1] = STATE(18),
    [ts_builtin_sym_end] = ACTIONS(21),
    [anon_sym_LF] = ACTIONS(7),
    [anon_sym_CR] = ACTIONS(9),
    [anon_sym_CR_LF] = ACTIONS(7),
    [anon_sym_] = ACTIONS(7),
    [sym__character] = ACTIONS(11),
    [anon_sym_STAR] = ACTIONS(13),
    [anon_sym_SLASH] = ACTIONS(15),
    [anon_sym_SEMI] = ACTIONS(15),
    [aux_sym_punctuation_token1] = ACTIONS(17),
    [sym__whitespace] = ACTIONS(19),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [3] = {
    [sym_non_structural] = STATE(3),
    [sym_punctuation] = STATE(6),
    [sym__word] = STATE(15),
    [sym_paragraph] = STATE(32),
    [sym__word_segment] = STATE(22),
    [sym__ws_segment] = STATE(22),
    [sym__punc_segment] = STATE(22),
    [sym__att_mod_seg] = STATE(22),
    [sym__paragraph_segment] = STATE(22),
    [sym_bold_open] = STATE(42),
    [sym_bold] = STATE(10),
    [aux_sym_document_repeat1] = STATE(3),
    [aux_sym__word_repeat1] = STATE(18),
    [ts_builtin_sym_end] = ACTIONS(23),
    [anon_sym_LF] = ACTIONS(25),
    [anon_sym_CR] = ACTIONS(28),
    [anon_sym_CR_LF] = ACTIONS(25),
    [anon_sym_] = ACTIONS(25),
    [sym__character] = ACTIONS(31),
    [anon_sym_STAR] = ACTIONS(34),
    [anon_sym_SLASH] = ACTIONS(37),
    [anon_sym_SEMI] = ACTIONS(37),
    [aux_sym_punctuation_token1] = ACTIONS(40),
    [sym__whitespace] = ACTIONS(43),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [4] = {
    [sym_punctuation] = STATE(6),
    [sym__word] = STATE(15),
    [sym__word_segment] = STATE(27),
    [sym__ws_segment] = STATE(27),
    [sym__punc_segment] = STATE(27),
    [sym__att_mod_seg] = STATE(27),
    [sym__paragraph_segment] = STATE(27),
    [sym_bold_open] = STATE(42),
    [sym_bold] = STATE(10),
    [aux_sym__word_repeat1] = STATE(18),
    [ts_builtin_sym_end] = ACTIONS(46),
    [anon_sym_LF] = ACTIONS(46),
    [anon_sym_CR] = ACTIONS(48),
    [anon_sym_CR_LF] = ACTIONS(46),
    [anon_sym_] = ACTIONS(46),
    [sym__character] = ACTIONS(11),
    [anon_sym_STAR] = ACTIONS(13),
    [anon_sym_SLASH] = ACTIONS(15),
    [anon_sym_SEMI] = ACTIONS(15),
    [aux_sym_punctuation_token1] = ACTIONS(17),
    [sym__whitespace] = ACTIONS(19),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [5] = {
    [sym_punctuation] = STATE(6),
    [sym__word] = STATE(15),
    [sym__word_segment] = STATE(39),
    [sym__ws_segment] = STATE(39),
    [sym__punc_segment] = STATE(39),
    [sym__att_mod_seg] = STATE(39),
    [sym__paragraph_segment] = STATE(39),
    [sym_bold_open] = STATE(42),
    [sym_bold] = STATE(10),
    [aux_sym__word_repeat1] = STATE(18),
    [ts_builtin_sym_end] = ACTIONS(50),
    [anon_sym_LF] = ACTIONS(50),
    [anon_sym_CR] = ACTIONS(52),
    [anon_sym_CR_LF] = ACTIONS(50),
    [anon_sym_] = ACTIONS(50),
    [sym__character] = ACTIONS(11),
    [anon_sym_STAR] = ACTIONS(13),
    [anon_sym_SLASH] = ACTIONS(15),
    [anon_sym_SEMI] = ACTIONS(15),
    [aux_sym_punctuation_token1] = ACTIONS(17),
    [sym__whitespace] = ACTIONS(19),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [6] = {
    [sym_punctuation] = STATE(6),
    [sym__word] = STATE(15),
    [sym__word_segment] = STATE(37),
    [sym__ws_segment] = STATE(37),
    [sym__punc_segment] = STATE(37),
    [sym__att_mod_seg] = STATE(37),
    [sym__paragraph_segment] = STATE(37),
    [sym_bold_open] = STATE(42),
    [sym_bold] = STATE(10),
    [aux_sym__word_repeat1] = STATE(18),
    [ts_builtin_sym_end] = ACTIONS(54),
    [anon_sym_LF] = ACTIONS(54),
    [anon_sym_CR] = ACTIONS(56),
    [anon_sym_CR_LF] = ACTIONS(54),
    [anon_sym_] = ACTIONS(54),
    [sym__character] = ACTIONS(11),
    [anon_sym_STAR] = ACTIONS(13),
    [anon_sym_SLASH] = ACTIONS(15),
    [anon_sym_SEMI] = ACTIONS(15),
    [aux_sym_punctuation_token1] = ACTIONS(17),
    [sym__whitespace] = ACTIONS(19),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [7] = {
    [sym_punctuation] = STATE(6),
    [sym__word] = STATE(15),
    [sym__word_segment] = STATE(27),
    [sym__ws_segment] = STATE(27),
    [sym__punc_segment] = STATE(27),
    [sym__att_mod_seg] = STATE(27),
    [sym__paragraph_segment] = STATE(27),
    [sym_bold_open] = STATE(42),
    [sym_bold] = STATE(10),
    [aux_sym__word_repeat1] = STATE(18),
    [ts_builtin_sym_end] = ACTIONS(58),
    [anon_sym_LF] = ACTIONS(58),
    [anon_sym_CR] = ACTIONS(60),
    [anon_sym_CR_LF] = ACTIONS(58),
    [anon_sym_] = ACTIONS(58),
    [sym__character] = ACTIONS(11),
    [anon_sym_STAR] = ACTIONS(13),
    [anon_sym_SLASH] = ACTIONS(15),
    [anon_sym_SEMI] = ACTIONS(15),
    [aux_sym_punctuation_token1] = ACTIONS(17),
    [sym__whitespace] = ACTIONS(19),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [8] = {
    [sym_punctuation] = STATE(9),
    [sym__word] = STATE(8),
    [sym_bold_close] = STATE(36),
    [sym__bold_word_segment] = STATE(36),
    [sym__bold_ws_segment] = STATE(36),
    [sym__bold_punc_segment] = STATE(36),
    [sym__bold_paragraph_segment] = STATE(36),
    [aux_sym__word_repeat1] = STATE(18),
    [anon_sym_LF] = ACTIONS(62),
    [anon_sym_CR] = ACTIONS(64),
    [anon_sym_CR_LF] = ACTIONS(62),
    [sym__character] = ACTIONS(11),
    [anon_sym_STAR] = ACTIONS(66),
    [anon_sym_SLASH] = ACTIONS(15),
    [anon_sym_SEMI] = ACTIONS(15),
    [aux_sym_punctuation_token1] = ACTIONS(17),
    [sym__whitespace] = ACTIONS(68),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [9] = {
    [sym_punctuation] = STATE(9),
    [sym__word] = STATE(8),
    [sym_bold_close] = STATE(24),
    [sym__bold_word_segment] = STATE(24),
    [sym__bold_ws_segment] = STATE(24),
    [sym__bold_punc_segment] = STATE(24),
    [sym__bold_paragraph_segment] = STATE(24),
    [aux_sym__word_repeat1] = STATE(18),
    [anon_sym_LF] = ACTIONS(62),
    [anon_sym_CR] = ACTIONS(64),
    [anon_sym_CR_LF] = ACTIONS(62),
    [sym__character] = ACTIONS(11),
    [anon_sym_STAR] = ACTIONS(70),
    [anon_sym_SLASH] = ACTIONS(15),
    [anon_sym_SEMI] = ACTIONS(15),
    [aux_sym_punctuation_token1] = ACTIONS(17),
    [sym__whitespace] = ACTIONS(68),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
  [10] = {
    [sym_punctuation] = STATE(6),
    [sym__ws_segment] = STATE(34),
    [sym__punc_segment] = STATE(34),
    [sym__att_mod_seg] = STATE(34),
    [sym_bold_open] = STATE(42),
    [sym_bold] = STATE(10),
    [ts_builtin_sym_end] = ACTIONS(72),
    [anon_sym_LF] = ACTIONS(72),
    [anon_sym_CR] = ACTIONS(74),
    [anon_sym_CR_LF] = ACTIONS(72),
    [anon_sym_] = ACTIONS(72),
    [sym__character] = ACTIONS(72),
    [anon_sym_STAR] = ACTIONS(13),
    [anon_sym_SLASH] = ACTIONS(15),
    [anon_sym_SEMI] = ACTIONS(15),
    [aux_sym_punctuation_token1] = ACTIONS(17),
    [sym__whitespace] = ACTIONS(19),
    [sym__precedingwhitespace] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 12,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(11), 1,
      sym__character,
    ACTIONS(17), 1,
      aux_sym_punctuation_token1,
    ACTIONS(64), 1,
      anon_sym_CR,
    ACTIONS(68), 1,
      sym__whitespace,
    ACTIONS(76), 1,
      anon_sym_STAR,
    STATE(8), 1,
      sym__word,
    STATE(9), 1,
      sym_punctuation,
    STATE(18), 1,
      aux_sym__word_repeat1,
    ACTIONS(15), 2,
      anon_sym_SLASH,
      anon_sym_SEMI,
    ACTIONS(62), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(41), 4,
      sym__bold_word_segment,
      sym__bold_ws_segment,
      sym__bold_punc_segment,
      sym__bold_paragraph_segment,
  [42] = 12,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(11), 1,
      sym__character,
    ACTIONS(13), 1,
      anon_sym_STAR,
    ACTIONS(17), 1,
      aux_sym_punctuation_token1,
    ACTIONS(19), 1,
      sym__whitespace,
    STATE(6), 1,
      sym_punctuation,
    STATE(10), 1,
      sym_bold,
    STATE(15), 1,
      sym__word,
    STATE(18), 1,
      aux_sym__word_repeat1,
    STATE(42), 1,
      sym_bold_open,
    ACTIONS(15), 2,
      anon_sym_SLASH,
      anon_sym_SEMI,
    STATE(27), 5,
      sym__word_segment,
      sym__ws_segment,
      sym__punc_segment,
      sym__att_mod_seg,
      sym__paragraph_segment,
  [84] = 7,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(11), 1,
      sym__character,
    STATE(8), 1,
      sym__word,
    STATE(18), 1,
      aux_sym__word_repeat1,
    STATE(30), 1,
      sym__bold_word_segment,
    ACTIONS(80), 3,
      anon_sym_CR,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(78), 7,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [114] = 7,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(11), 1,
      sym__character,
    STATE(8), 1,
      sym__word,
    STATE(18), 1,
      aux_sym__word_repeat1,
    STATE(40), 1,
      sym__bold_word_segment,
    ACTIONS(80), 3,
      anon_sym_CR,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(78), 7,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [144] = 9,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(17), 1,
      aux_sym_punctuation_token1,
    ACTIONS(19), 1,
      sym__whitespace,
    ACTIONS(76), 1,
      anon_sym_STAR,
    ACTIONS(84), 1,
      anon_sym_CR,
    STATE(6), 1,
      sym_punctuation,
    ACTIONS(15), 2,
      anon_sym_SLASH,
      anon_sym_SEMI,
    STATE(35), 2,
      sym__ws_segment,
      sym__punc_segment,
    ACTIONS(82), 5,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
  [178] = 5,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(90), 1,
      sym__character,
    STATE(16), 1,
      aux_sym__word_repeat1,
    ACTIONS(88), 3,
      anon_sym_CR,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(86), 7,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [202] = 11,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(11), 1,
      sym__character,
    ACTIONS(17), 1,
      aux_sym_punctuation_token1,
    ACTIONS(76), 1,
      anon_sym_STAR,
    ACTIONS(93), 1,
      sym__whitespace,
    STATE(8), 1,
      sym__word,
    STATE(9), 1,
      sym_punctuation,
    STATE(18), 1,
      aux_sym__word_repeat1,
    STATE(43), 1,
      aux_sym__bold_paragraph_segment_repeat1,
    ACTIONS(15), 2,
      anon_sym_SLASH,
      anon_sym_SEMI,
    STATE(26), 2,
      sym__bold_word_segment,
      sym__bold_punc_segment,
  [238] = 5,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(99), 1,
      sym__character,
    STATE(16), 1,
      aux_sym__word_repeat1,
    ACTIONS(97), 3,
      anon_sym_CR,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(95), 7,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [262] = 11,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(11), 1,
      sym__character,
    ACTIONS(17), 1,
      aux_sym_punctuation_token1,
    ACTIONS(76), 1,
      anon_sym_STAR,
    ACTIONS(101), 1,
      sym__whitespace,
    STATE(8), 1,
      sym__word,
    STATE(9), 1,
      sym_punctuation,
    STATE(17), 1,
      aux_sym__bold_paragraph_segment_repeat1,
    STATE(18), 1,
      aux_sym__word_repeat1,
    ACTIONS(15), 2,
      anon_sym_SLASH,
      anon_sym_SEMI,
    STATE(38), 2,
      sym__bold_word_segment,
      sym__bold_punc_segment,
  [298] = 6,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(108), 1,
      anon_sym_CR,
    STATE(20), 1,
      aux_sym_paragraph_repeat1,
    ACTIONS(105), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    ACTIONS(111), 2,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(103), 6,
      ts_builtin_sym_end,
      anon_sym_,
      sym__character,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [324] = 7,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(115), 1,
      anon_sym_CR,
    ACTIONS(117), 1,
      anon_sym_,
    STATE(20), 1,
      aux_sym_paragraph_repeat1,
    ACTIONS(60), 2,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(113), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    ACTIONS(58), 5,
      ts_builtin_sym_end,
      sym__character,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [352] = 7,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(123), 1,
      anon_sym_CR,
    ACTIONS(125), 1,
      anon_sym_,
    STATE(21), 1,
      aux_sym_paragraph_repeat1,
    ACTIONS(121), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    ACTIONS(127), 2,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(119), 5,
      ts_builtin_sym_end,
      sym__character,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [380] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(131), 3,
      anon_sym_CR,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(129), 8,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [399] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(135), 3,
      anon_sym_CR,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(133), 8,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [418] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(131), 3,
      anon_sym_CR,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(129), 8,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [437] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(139), 3,
      anon_sym_CR,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(137), 8,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [456] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(111), 3,
      anon_sym_CR,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(103), 8,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [475] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(143), 3,
      anon_sym_CR,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(141), 8,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [494] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(48), 3,
      anon_sym_CR,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(46), 8,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [513] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(147), 3,
      anon_sym_CR,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(145), 8,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [532] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(60), 3,
      anon_sym_CR,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(58), 8,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [551] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(151), 3,
      anon_sym_CR,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(149), 8,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [570] = 5,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(131), 1,
      anon_sym_CR,
    ACTIONS(156), 2,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(153), 3,
      sym__character,
      anon_sym_SLASH,
      anon_sym_SEMI,
    ACTIONS(129), 5,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__whitespace,
  [593] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(161), 3,
      anon_sym_CR,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(159), 8,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [612] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(165), 3,
      anon_sym_CR,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(163), 8,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [631] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(169), 3,
      anon_sym_CR,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(167), 8,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [650] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(173), 3,
      anon_sym_CR,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(171), 8,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [669] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(177), 3,
      anon_sym_CR,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(175), 8,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [688] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(181), 3,
      anon_sym_CR,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(179), 8,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [707] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(185), 3,
      anon_sym_CR,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(183), 8,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [726] = 3,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(189), 3,
      anon_sym_CR,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(187), 8,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      sym__character,
      anon_sym_SLASH,
      anon_sym_SEMI,
      sym__whitespace,
  [745] = 9,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(11), 1,
      sym__character,
    ACTIONS(17), 1,
      aux_sym_punctuation_token1,
    ACTIONS(76), 1,
      anon_sym_STAR,
    STATE(8), 1,
      sym__word,
    STATE(9), 1,
      sym_punctuation,
    STATE(18), 1,
      aux_sym__word_repeat1,
    ACTIONS(15), 2,
      anon_sym_SLASH,
      anon_sym_SEMI,
    STATE(28), 2,
      sym__bold_word_segment,
      sym__bold_punc_segment,
  [775] = 5,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(195), 1,
      sym__whitespace,
    STATE(43), 1,
      aux_sym__bold_paragraph_segment_repeat1,
    ACTIONS(193), 2,
      anon_sym_STAR,
      aux_sym_punctuation_token1,
    ACTIONS(191), 3,
      sym__character,
      anon_sym_SLASH,
      anon_sym_SEMI,
  [794] = 2,
    ACTIONS(3), 1,
      sym__precedingwhitespace,
    ACTIONS(198), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(11)] = 0,
  [SMALL_STATE(12)] = 42,
  [SMALL_STATE(13)] = 84,
  [SMALL_STATE(14)] = 114,
  [SMALL_STATE(15)] = 144,
  [SMALL_STATE(16)] = 178,
  [SMALL_STATE(17)] = 202,
  [SMALL_STATE(18)] = 238,
  [SMALL_STATE(19)] = 262,
  [SMALL_STATE(20)] = 298,
  [SMALL_STATE(21)] = 324,
  [SMALL_STATE(22)] = 352,
  [SMALL_STATE(23)] = 380,
  [SMALL_STATE(24)] = 399,
  [SMALL_STATE(25)] = 418,
  [SMALL_STATE(26)] = 437,
  [SMALL_STATE(27)] = 456,
  [SMALL_STATE(28)] = 475,
  [SMALL_STATE(29)] = 494,
  [SMALL_STATE(30)] = 513,
  [SMALL_STATE(31)] = 532,
  [SMALL_STATE(32)] = 551,
  [SMALL_STATE(33)] = 570,
  [SMALL_STATE(34)] = 593,
  [SMALL_STATE(35)] = 612,
  [SMALL_STATE(36)] = 631,
  [SMALL_STATE(37)] = 650,
  [SMALL_STATE(38)] = 669,
  [SMALL_STATE(39)] = 688,
  [SMALL_STATE(40)] = 707,
  [SMALL_STATE(41)] = 726,
  [SMALL_STATE(42)] = 745,
  [SMALL_STATE(43)] = 775,
  [SMALL_STATE(44)] = 794,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2),
  [25] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(32),
  [28] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(32),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(18),
  [34] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(33),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(23),
  [40] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(25),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(5),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paragraph, 3),
  [48] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_paragraph, 3),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ws_segment, 1),
  [52] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__ws_segment, 1),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__punc_segment, 1),
  [56] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__punc_segment, 1),
  [58] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paragraph, 2),
  [60] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_paragraph, 2),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [64] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [66] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [70] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__att_mod_seg, 1),
  [74] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__att_mod_seg, 1),
  [76] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bold_close, 1),
  [80] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bold_close, 1),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__word_segment, 1),
  [84] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__word_segment, 1),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__word_repeat1, 2),
  [88] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__word_repeat1, 2),
  [90] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__word_repeat1, 2), SHIFT_REPEAT(16),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__word, 1),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__word, 1),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2),
  [105] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(12),
  [108] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(12),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_paragraph_repeat1, 2),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [115] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paragraph, 1),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [123] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_paragraph, 1),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_punctuation, 1),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_punctuation, 1),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bold_punc_segment, 2),
  [135] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bold_punc_segment, 2),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bold_paragraph_segment, 3, .production_id = 1),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bold_paragraph_segment, 3, .production_id = 1),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bold, 2, .dynamic_precedence = 1),
  [143] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bold, 2, .dynamic_precedence = 1),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bold_word_segment, 3),
  [147] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bold_word_segment, 3),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_non_structural, 1),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_non_structural, 1),
  [153] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_punctuation, 1), REDUCE(sym_bold_open, 1),
  [156] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_punctuation, 1), REDUCE(sym_bold_open, 1),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__att_mod_seg, 2),
  [161] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__att_mod_seg, 2),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__word_segment, 2),
  [165] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__word_segment, 2),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bold_word_segment, 2),
  [169] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bold_word_segment, 2),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__punc_segment, 2),
  [173] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__punc_segment, 2),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bold_paragraph_segment, 2, .production_id = 1),
  [177] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bold_paragraph_segment, 2, .production_id = 1),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ws_segment, 2),
  [181] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__ws_segment, 2),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bold_punc_segment, 3),
  [185] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bold_punc_segment, 3),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bold_ws_segment, 2),
  [189] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bold_ws_segment, 2),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__bold_paragraph_segment_repeat1, 2),
  [193] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__bold_paragraph_segment_repeat1, 2),
  [195] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__bold_paragraph_segment_repeat1, 2), SHIFT_REPEAT(43),
  [198] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
