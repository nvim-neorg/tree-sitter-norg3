#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 101
#define LARGE_STATE_COUNT 7
#define SYMBOL_COUNT 28
#define ALIAS_COUNT 0
#define TOKEN_COUNT 18
#define EXTERNAL_TOKEN_COUNT 10
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum {
  sym__character = 1,
  sym_punctuation = 2,
  sym_whitespace = 3,
  anon_sym_LF = 4,
  anon_sym_CR = 5,
  anon_sym_CR_LF = 6,
  sym_paragraph_break = 7,
  sym__preceding_whitespace = 8,
  sym_bold_open = 9,
  sym_bold_close = 10,
  sym_italic_open = 11,
  sym_italic_close = 12,
  sym_underline_open = 13,
  sym_underline_close = 14,
  sym_strikethrough_open = 15,
  sym_strikethrough_close = 16,
  sym_maybe_opening_modifier = 17,
  sym_document = 18,
  sym_word = 19,
  sym_open_conflict = 20,
  sym_bold = 21,
  sym_italic = 22,
  sym_underline = 23,
  sym_strikethrough = 24,
  aux_sym_document_repeat1 = 25,
  aux_sym_word_repeat1 = 26,
  aux_sym_paragraph_repeat1 = 27,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym__character] = "_character",
  [sym_punctuation] = "punctuation",
  [sym_whitespace] = "whitespace",
  [anon_sym_LF] = "\n",
  [anon_sym_CR] = "\r",
  [anon_sym_CR_LF] = "\r\n",
  [sym_paragraph_break] = "paragraph_break",
  [sym__preceding_whitespace] = "_preceding_whitespace",
  [sym_bold_open] = "bold_open",
  [sym_bold_close] = "bold_close",
  [sym_italic_open] = "italic_open",
  [sym_italic_close] = "italic_close",
  [sym_underline_open] = "underline_open",
  [sym_underline_close] = "underline_close",
  [sym_strikethrough_open] = "strikethrough_open",
  [sym_strikethrough_close] = "strikethrough_close",
  [sym_maybe_opening_modifier] = "maybe_opening_modifier",
  [sym_document] = "document",
  [sym_word] = "word",
  [sym_open_conflict] = "open_conflict",
  [sym_bold] = "bold",
  [sym_italic] = "italic",
  [sym_underline] = "underline",
  [sym_strikethrough] = "strikethrough",
  [aux_sym_document_repeat1] = "document_repeat1",
  [aux_sym_word_repeat1] = "word_repeat1",
  [aux_sym_paragraph_repeat1] = "paragraph_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym__character] = sym__character,
  [sym_punctuation] = sym_punctuation,
  [sym_whitespace] = sym_whitespace,
  [anon_sym_LF] = anon_sym_LF,
  [anon_sym_CR] = anon_sym_CR,
  [anon_sym_CR_LF] = anon_sym_CR_LF,
  [sym_paragraph_break] = sym_paragraph_break,
  [sym__preceding_whitespace] = sym__preceding_whitespace,
  [sym_bold_open] = sym_bold_open,
  [sym_bold_close] = sym_bold_close,
  [sym_italic_open] = sym_italic_open,
  [sym_italic_close] = sym_italic_close,
  [sym_underline_open] = sym_underline_open,
  [sym_underline_close] = sym_underline_close,
  [sym_strikethrough_open] = sym_strikethrough_open,
  [sym_strikethrough_close] = sym_strikethrough_close,
  [sym_maybe_opening_modifier] = sym_maybe_opening_modifier,
  [sym_document] = sym_document,
  [sym_word] = sym_word,
  [sym_open_conflict] = sym_open_conflict,
  [sym_bold] = sym_bold,
  [sym_italic] = sym_italic,
  [sym_underline] = sym_underline,
  [sym_strikethrough] = sym_strikethrough,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
  [aux_sym_word_repeat1] = aux_sym_word_repeat1,
  [aux_sym_paragraph_repeat1] = aux_sym_paragraph_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym__character] = {
    .visible = false,
    .named = true,
  },
  [sym_punctuation] = {
    .visible = true,
    .named = true,
  },
  [sym_whitespace] = {
    .visible = true,
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
  [sym_paragraph_break] = {
    .visible = true,
    .named = true,
  },
  [sym__preceding_whitespace] = {
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
  [sym_italic_open] = {
    .visible = true,
    .named = true,
  },
  [sym_italic_close] = {
    .visible = true,
    .named = true,
  },
  [sym_underline_open] = {
    .visible = true,
    .named = true,
  },
  [sym_underline_close] = {
    .visible = true,
    .named = true,
  },
  [sym_strikethrough_open] = {
    .visible = true,
    .named = true,
  },
  [sym_strikethrough_close] = {
    .visible = true,
    .named = true,
  },
  [sym_maybe_opening_modifier] = {
    .visible = true,
    .named = true,
  },
  [sym_document] = {
    .visible = true,
    .named = true,
  },
  [sym_word] = {
    .visible = true,
    .named = true,
  },
  [sym_open_conflict] = {
    .visible = true,
    .named = true,
  },
  [sym_bold] = {
    .visible = true,
    .named = true,
  },
  [sym_italic] = {
    .visible = true,
    .named = true,
  },
  [sym_underline] = {
    .visible = true,
    .named = true,
  },
  [sym_strikethrough] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_document_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_word_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_paragraph_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 2,
  [4] = 2,
  [5] = 2,
  [6] = 2,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 13,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 17,
  [22] = 18,
  [23] = 17,
  [24] = 20,
  [25] = 19,
  [26] = 18,
  [27] = 17,
  [28] = 11,
  [29] = 12,
  [30] = 11,
  [31] = 14,
  [32] = 20,
  [33] = 15,
  [34] = 19,
  [35] = 9,
  [36] = 18,
  [37] = 19,
  [38] = 20,
  [39] = 19,
  [40] = 18,
  [41] = 9,
  [42] = 15,
  [43] = 11,
  [44] = 12,
  [45] = 13,
  [46] = 14,
  [47] = 14,
  [48] = 15,
  [49] = 13,
  [50] = 9,
  [51] = 12,
  [52] = 20,
  [53] = 11,
  [54] = 12,
  [55] = 13,
  [56] = 14,
  [57] = 15,
  [58] = 9,
  [59] = 17,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 60,
  [64] = 60,
  [65] = 60,
  [66] = 60,
  [67] = 61,
  [68] = 61,
  [69] = 62,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 61,
  [76] = 61,
  [77] = 62,
  [78] = 62,
  [79] = 62,
  [80] = 71,
  [81] = 70,
  [82] = 72,
  [83] = 73,
  [84] = 74,
  [85] = 70,
  [86] = 74,
  [87] = 73,
  [88] = 72,
  [89] = 71,
  [90] = 70,
  [91] = 70,
  [92] = 71,
  [93] = 72,
  [94] = 74,
  [95] = 74,
  [96] = 73,
  [97] = 72,
  [98] = 71,
  [99] = 73,
  [100] = 100,
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
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == '\r') ADVANCE(8);
      if (lookahead == ' ' ||
          lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(5);
      if (sym__character_character_set_1(lookahead)) ADVANCE(3);
      if (lookahead != 0 &&
          lookahead != 8232 &&
          lookahead != 8233) ADVANCE(4);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(6);
      if (lookahead == '\r') ADVANCE(9);
      if (lookahead == ' ' ||
          lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(5);
      if (sym__character_character_set_1(lookahead)) ADVANCE(3);
      if (lookahead != 0 &&
          lookahead != 8232 &&
          lookahead != 8233) ADVANCE(4);
      END_STATE();
    case 2:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(sym__character);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(sym_punctuation);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(sym_whitespace);
      if (lookahead == ' ' ||
          lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(5);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_LF);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == 0 ||
          lookahead == '\n') ADVANCE(11);
      if (lookahead == '\r') ADVANCE(12);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_CR);
      if (lookahead == 0) ADVANCE(11);
      if (lookahead == '\n') ADVANCE(13);
      if (lookahead == '\r') ADVANCE(12);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_CR);
      if (lookahead == '\n') ADVANCE(10);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_CR_LF);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_paragraph_break);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_paragraph_break);
      if (lookahead == '\n') ADVANCE(11);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_paragraph_break);
      if (lookahead == 0 ||
          lookahead == '\n') ADVANCE(11);
      if (lookahead == '\r') ADVANCE(12);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0, .external_lex_state = 2},
  [2] = {.lex_state = 0, .external_lex_state = 3},
  [3] = {.lex_state = 1, .external_lex_state = 4},
  [4] = {.lex_state = 1, .external_lex_state = 5},
  [5] = {.lex_state = 1, .external_lex_state = 6},
  [6] = {.lex_state = 1, .external_lex_state = 7},
  [7] = {.lex_state = 0, .external_lex_state = 2},
  [8] = {.lex_state = 0, .external_lex_state = 2},
  [9] = {.lex_state = 0, .external_lex_state = 2},
  [10] = {.lex_state = 0, .external_lex_state = 2},
  [11] = {.lex_state = 0, .external_lex_state = 2},
  [12] = {.lex_state = 0, .external_lex_state = 2},
  [13] = {.lex_state = 0, .external_lex_state = 2},
  [14] = {.lex_state = 0, .external_lex_state = 2},
  [15] = {.lex_state = 0, .external_lex_state = 2},
  [16] = {.lex_state = 1, .external_lex_state = 8},
  [17] = {.lex_state = 1, .external_lex_state = 9},
  [18] = {.lex_state = 1, .external_lex_state = 10},
  [19] = {.lex_state = 1, .external_lex_state = 8},
  [20] = {.lex_state = 1, .external_lex_state = 11},
  [21] = {.lex_state = 1, .external_lex_state = 9},
  [22] = {.lex_state = 1, .external_lex_state = 10},
  [23] = {.lex_state = 1, .external_lex_state = 9},
  [24] = {.lex_state = 1, .external_lex_state = 11},
  [25] = {.lex_state = 1, .external_lex_state = 8},
  [26] = {.lex_state = 1, .external_lex_state = 10},
  [27] = {.lex_state = 1, .external_lex_state = 9},
  [28] = {.lex_state = 1, .external_lex_state = 8},
  [29] = {.lex_state = 1, .external_lex_state = 8},
  [30] = {.lex_state = 1, .external_lex_state = 10},
  [31] = {.lex_state = 1, .external_lex_state = 8},
  [32] = {.lex_state = 1, .external_lex_state = 11},
  [33] = {.lex_state = 1, .external_lex_state = 8},
  [34] = {.lex_state = 1, .external_lex_state = 8},
  [35] = {.lex_state = 1, .external_lex_state = 8},
  [36] = {.lex_state = 1, .external_lex_state = 10},
  [37] = {.lex_state = 1, .external_lex_state = 8},
  [38] = {.lex_state = 1, .external_lex_state = 11},
  [39] = {.lex_state = 1, .external_lex_state = 8},
  [40] = {.lex_state = 1, .external_lex_state = 10},
  [41] = {.lex_state = 1, .external_lex_state = 10},
  [42] = {.lex_state = 1, .external_lex_state = 10},
  [43] = {.lex_state = 1, .external_lex_state = 11},
  [44] = {.lex_state = 1, .external_lex_state = 11},
  [45] = {.lex_state = 1, .external_lex_state = 11},
  [46] = {.lex_state = 1, .external_lex_state = 11},
  [47] = {.lex_state = 1, .external_lex_state = 10},
  [48] = {.lex_state = 1, .external_lex_state = 11},
  [49] = {.lex_state = 1, .external_lex_state = 10},
  [50] = {.lex_state = 1, .external_lex_state = 11},
  [51] = {.lex_state = 1, .external_lex_state = 10},
  [52] = {.lex_state = 1, .external_lex_state = 11},
  [53] = {.lex_state = 1, .external_lex_state = 9},
  [54] = {.lex_state = 1, .external_lex_state = 9},
  [55] = {.lex_state = 1, .external_lex_state = 9},
  [56] = {.lex_state = 1, .external_lex_state = 9},
  [57] = {.lex_state = 1, .external_lex_state = 9},
  [58] = {.lex_state = 1, .external_lex_state = 9},
  [59] = {.lex_state = 1, .external_lex_state = 9},
  [60] = {.lex_state = 1, .external_lex_state = 2},
  [61] = {.lex_state = 0, .external_lex_state = 2},
  [62] = {.lex_state = 0, .external_lex_state = 2},
  [63] = {.lex_state = 1, .external_lex_state = 2},
  [64] = {.lex_state = 1, .external_lex_state = 2},
  [65] = {.lex_state = 1, .external_lex_state = 2},
  [66] = {.lex_state = 1, .external_lex_state = 2},
  [67] = {.lex_state = 1, .external_lex_state = 11},
  [68] = {.lex_state = 1, .external_lex_state = 9},
  [69] = {.lex_state = 1, .external_lex_state = 9},
  [70] = {.lex_state = 0, .external_lex_state = 2},
  [71] = {.lex_state = 0, .external_lex_state = 2},
  [72] = {.lex_state = 0, .external_lex_state = 2},
  [73] = {.lex_state = 0, .external_lex_state = 2},
  [74] = {.lex_state = 0, .external_lex_state = 2},
  [75] = {.lex_state = 1, .external_lex_state = 10},
  [76] = {.lex_state = 1, .external_lex_state = 8},
  [77] = {.lex_state = 1, .external_lex_state = 8},
  [78] = {.lex_state = 1, .external_lex_state = 11},
  [79] = {.lex_state = 1, .external_lex_state = 10},
  [80] = {.lex_state = 1, .external_lex_state = 10},
  [81] = {.lex_state = 1, .external_lex_state = 9},
  [82] = {.lex_state = 1, .external_lex_state = 10},
  [83] = {.lex_state = 1, .external_lex_state = 10},
  [84] = {.lex_state = 1, .external_lex_state = 10},
  [85] = {.lex_state = 1, .external_lex_state = 11},
  [86] = {.lex_state = 1, .external_lex_state = 8},
  [87] = {.lex_state = 1, .external_lex_state = 8},
  [88] = {.lex_state = 1, .external_lex_state = 8},
  [89] = {.lex_state = 1, .external_lex_state = 8},
  [90] = {.lex_state = 1, .external_lex_state = 10},
  [91] = {.lex_state = 1, .external_lex_state = 8},
  [92] = {.lex_state = 1, .external_lex_state = 11},
  [93] = {.lex_state = 1, .external_lex_state = 11},
  [94] = {.lex_state = 1, .external_lex_state = 11},
  [95] = {.lex_state = 1, .external_lex_state = 9},
  [96] = {.lex_state = 1, .external_lex_state = 9},
  [97] = {.lex_state = 1, .external_lex_state = 9},
  [98] = {.lex_state = 1, .external_lex_state = 9},
  [99] = {.lex_state = 1, .external_lex_state = 11},
  [100] = {.lex_state = 0, .external_lex_state = 2},
};

enum {
  ts_external_token__preceding_whitespace = 0,
  ts_external_token_bold_open = 1,
  ts_external_token_bold_close = 2,
  ts_external_token_italic_open = 3,
  ts_external_token_italic_close = 4,
  ts_external_token_underline_open = 5,
  ts_external_token_underline_close = 6,
  ts_external_token_strikethrough_open = 7,
  ts_external_token_strikethrough_close = 8,
  ts_external_token_maybe_opening_modifier = 9,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__preceding_whitespace] = sym__preceding_whitespace,
  [ts_external_token_bold_open] = sym_bold_open,
  [ts_external_token_bold_close] = sym_bold_close,
  [ts_external_token_italic_open] = sym_italic_open,
  [ts_external_token_italic_close] = sym_italic_close,
  [ts_external_token_underline_open] = sym_underline_open,
  [ts_external_token_underline_close] = sym_underline_close,
  [ts_external_token_strikethrough_open] = sym_strikethrough_open,
  [ts_external_token_strikethrough_close] = sym_strikethrough_close,
  [ts_external_token_maybe_opening_modifier] = sym_maybe_opening_modifier,
};

static const bool ts_external_scanner_states[12][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__preceding_whitespace] = true,
    [ts_external_token_bold_open] = true,
    [ts_external_token_bold_close] = true,
    [ts_external_token_italic_open] = true,
    [ts_external_token_italic_close] = true,
    [ts_external_token_underline_open] = true,
    [ts_external_token_underline_close] = true,
    [ts_external_token_strikethrough_open] = true,
    [ts_external_token_strikethrough_close] = true,
    [ts_external_token_maybe_opening_modifier] = true,
  },
  [2] = {
    [ts_external_token__preceding_whitespace] = true,
  },
  [3] = {
    [ts_external_token__preceding_whitespace] = true,
    [ts_external_token_bold_open] = true,
    [ts_external_token_italic_open] = true,
    [ts_external_token_underline_open] = true,
    [ts_external_token_strikethrough_open] = true,
  },
  [4] = {
    [ts_external_token__preceding_whitespace] = true,
    [ts_external_token_bold_open] = true,
    [ts_external_token_italic_open] = true,
    [ts_external_token_underline_open] = true,
    [ts_external_token_strikethrough_open] = true,
    [ts_external_token_strikethrough_close] = true,
  },
  [5] = {
    [ts_external_token__preceding_whitespace] = true,
    [ts_external_token_bold_open] = true,
    [ts_external_token_italic_open] = true,
    [ts_external_token_underline_open] = true,
    [ts_external_token_underline_close] = true,
    [ts_external_token_strikethrough_open] = true,
  },
  [6] = {
    [ts_external_token__preceding_whitespace] = true,
    [ts_external_token_bold_open] = true,
    [ts_external_token_italic_open] = true,
    [ts_external_token_italic_close] = true,
    [ts_external_token_underline_open] = true,
    [ts_external_token_strikethrough_open] = true,
  },
  [7] = {
    [ts_external_token__preceding_whitespace] = true,
    [ts_external_token_bold_open] = true,
    [ts_external_token_bold_close] = true,
    [ts_external_token_italic_open] = true,
    [ts_external_token_underline_open] = true,
    [ts_external_token_strikethrough_open] = true,
  },
  [8] = {
    [ts_external_token__preceding_whitespace] = true,
    [ts_external_token_bold_close] = true,
  },
  [9] = {
    [ts_external_token__preceding_whitespace] = true,
    [ts_external_token_underline_close] = true,
  },
  [10] = {
    [ts_external_token__preceding_whitespace] = true,
    [ts_external_token_strikethrough_close] = true,
  },
  [11] = {
    [ts_external_token__preceding_whitespace] = true,
    [ts_external_token_italic_close] = true,
  },
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym__character] = ACTIONS(1),
    [sym_punctuation] = ACTIONS(1),
    [sym_whitespace] = ACTIONS(1),
    [anon_sym_LF] = ACTIONS(1),
    [anon_sym_CR] = ACTIONS(1),
    [anon_sym_CR_LF] = ACTIONS(1),
    [sym_paragraph_break] = ACTIONS(1),
    [sym__preceding_whitespace] = ACTIONS(3),
    [sym_bold_open] = ACTIONS(1),
    [sym_bold_close] = ACTIONS(1),
    [sym_italic_open] = ACTIONS(1),
    [sym_italic_close] = ACTIONS(1),
    [sym_underline_open] = ACTIONS(1),
    [sym_underline_close] = ACTIONS(1),
    [sym_strikethrough_open] = ACTIONS(1),
    [sym_strikethrough_close] = ACTIONS(1),
    [sym_maybe_opening_modifier] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(100),
    [sym_word] = STATE(10),
    [aux_sym_document_repeat1] = STATE(7),
    [aux_sym_word_repeat1] = STATE(61),
    [aux_sym_paragraph_repeat1] = STATE(10),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym__character] = ACTIONS(7),
    [sym_punctuation] = ACTIONS(9),
    [sym_whitespace] = ACTIONS(9),
    [anon_sym_LF] = ACTIONS(11),
    [anon_sym_CR] = ACTIONS(11),
    [anon_sym_CR_LF] = ACTIONS(11),
    [sym_paragraph_break] = ACTIONS(13),
    [sym__preceding_whitespace] = ACTIONS(3),
  },
  [2] = {
    [sym_open_conflict] = STATE(70),
    [sym_bold] = STATE(70),
    [sym_italic] = STATE(70),
    [sym_underline] = STATE(70),
    [sym_strikethrough] = STATE(70),
    [ts_builtin_sym_end] = ACTIONS(15),
    [sym__character] = ACTIONS(15),
    [sym_punctuation] = ACTIONS(15),
    [sym_whitespace] = ACTIONS(15),
    [anon_sym_LF] = ACTIONS(17),
    [anon_sym_CR] = ACTIONS(17),
    [anon_sym_CR_LF] = ACTIONS(17),
    [sym_paragraph_break] = ACTIONS(15),
    [sym__preceding_whitespace] = ACTIONS(3),
    [sym_bold_open] = ACTIONS(19),
    [sym_italic_open] = ACTIONS(21),
    [sym_underline_open] = ACTIONS(23),
    [sym_strikethrough_open] = ACTIONS(25),
  },
  [3] = {
    [sym_open_conflict] = STATE(90),
    [sym_bold] = STATE(90),
    [sym_italic] = STATE(90),
    [sym_underline] = STATE(90),
    [sym_strikethrough] = STATE(90),
    [sym__character] = ACTIONS(15),
    [sym_punctuation] = ACTIONS(15),
    [sym_whitespace] = ACTIONS(15),
    [anon_sym_LF] = ACTIONS(15),
    [anon_sym_CR] = ACTIONS(17),
    [anon_sym_CR_LF] = ACTIONS(15),
    [sym__preceding_whitespace] = ACTIONS(3),
    [sym_bold_open] = ACTIONS(27),
    [sym_italic_open] = ACTIONS(29),
    [sym_underline_open] = ACTIONS(31),
    [sym_strikethrough_open] = ACTIONS(33),
    [sym_strikethrough_close] = ACTIONS(15),
  },
  [4] = {
    [sym_open_conflict] = STATE(81),
    [sym_bold] = STATE(81),
    [sym_italic] = STATE(81),
    [sym_underline] = STATE(81),
    [sym_strikethrough] = STATE(81),
    [sym__character] = ACTIONS(15),
    [sym_punctuation] = ACTIONS(15),
    [sym_whitespace] = ACTIONS(15),
    [anon_sym_LF] = ACTIONS(15),
    [anon_sym_CR] = ACTIONS(17),
    [anon_sym_CR_LF] = ACTIONS(15),
    [sym__preceding_whitespace] = ACTIONS(3),
    [sym_bold_open] = ACTIONS(35),
    [sym_italic_open] = ACTIONS(37),
    [sym_underline_open] = ACTIONS(39),
    [sym_underline_close] = ACTIONS(15),
    [sym_strikethrough_open] = ACTIONS(41),
  },
  [5] = {
    [sym_open_conflict] = STATE(85),
    [sym_bold] = STATE(85),
    [sym_italic] = STATE(85),
    [sym_underline] = STATE(85),
    [sym_strikethrough] = STATE(85),
    [sym__character] = ACTIONS(15),
    [sym_punctuation] = ACTIONS(15),
    [sym_whitespace] = ACTIONS(15),
    [anon_sym_LF] = ACTIONS(15),
    [anon_sym_CR] = ACTIONS(17),
    [anon_sym_CR_LF] = ACTIONS(15),
    [sym__preceding_whitespace] = ACTIONS(3),
    [sym_bold_open] = ACTIONS(43),
    [sym_italic_open] = ACTIONS(45),
    [sym_italic_close] = ACTIONS(15),
    [sym_underline_open] = ACTIONS(47),
    [sym_strikethrough_open] = ACTIONS(49),
  },
  [6] = {
    [sym_open_conflict] = STATE(91),
    [sym_bold] = STATE(91),
    [sym_italic] = STATE(91),
    [sym_underline] = STATE(91),
    [sym_strikethrough] = STATE(91),
    [sym__character] = ACTIONS(15),
    [sym_punctuation] = ACTIONS(15),
    [sym_whitespace] = ACTIONS(15),
    [anon_sym_LF] = ACTIONS(15),
    [anon_sym_CR] = ACTIONS(17),
    [anon_sym_CR_LF] = ACTIONS(15),
    [sym__preceding_whitespace] = ACTIONS(3),
    [sym_bold_open] = ACTIONS(51),
    [sym_bold_close] = ACTIONS(15),
    [sym_italic_open] = ACTIONS(53),
    [sym_underline_open] = ACTIONS(55),
    [sym_strikethrough_open] = ACTIONS(57),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 9,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(7), 1,
      sym__character,
    ACTIONS(59), 1,
      ts_builtin_sym_end,
    ACTIONS(61), 1,
      sym_paragraph_break,
    STATE(8), 1,
      aux_sym_document_repeat1,
    STATE(61), 1,
      aux_sym_word_repeat1,
    ACTIONS(9), 2,
      sym_punctuation,
      sym_whitespace,
    STATE(10), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
    ACTIONS(11), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [32] = 9,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(63), 1,
      ts_builtin_sym_end,
    ACTIONS(65), 1,
      sym__character,
    ACTIONS(74), 1,
      sym_paragraph_break,
    STATE(8), 1,
      aux_sym_document_repeat1,
    STATE(61), 1,
      aux_sym_word_repeat1,
    ACTIONS(68), 2,
      sym_punctuation,
      sym_whitespace,
    STATE(10), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
    ACTIONS(71), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [64] = 7,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(79), 1,
      sym__character,
    STATE(61), 1,
      aux_sym_word_repeat1,
    ACTIONS(77), 2,
      ts_builtin_sym_end,
      sym_paragraph_break,
    ACTIONS(82), 2,
      sym_punctuation,
      sym_whitespace,
    STATE(9), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
    ACTIONS(85), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [91] = 7,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(7), 1,
      sym__character,
    STATE(61), 1,
      aux_sym_word_repeat1,
    ACTIONS(9), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(88), 2,
      ts_builtin_sym_end,
      sym_paragraph_break,
    STATE(9), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
    ACTIONS(11), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [118] = 7,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(92), 1,
      sym__character,
    STATE(76), 1,
      aux_sym_word_repeat1,
    ACTIONS(90), 2,
      ts_builtin_sym_end,
      sym_paragraph_break,
    ACTIONS(95), 2,
      sym_punctuation,
      sym_whitespace,
    STATE(19), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
    ACTIONS(98), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [145] = 7,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(101), 1,
      sym__character,
    STATE(67), 1,
      aux_sym_word_repeat1,
    ACTIONS(90), 2,
      ts_builtin_sym_end,
      sym_paragraph_break,
    ACTIONS(104), 2,
      sym_punctuation,
      sym_whitespace,
    STATE(20), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
    ACTIONS(107), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [172] = 7,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(110), 1,
      sym__character,
    STATE(68), 1,
      aux_sym_word_repeat1,
    ACTIONS(90), 2,
      ts_builtin_sym_end,
      sym_paragraph_break,
    ACTIONS(113), 2,
      sym_punctuation,
      sym_whitespace,
    STATE(21), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
    ACTIONS(116), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [199] = 7,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(119), 1,
      sym__character,
    STATE(75), 1,
      aux_sym_word_repeat1,
    ACTIONS(90), 2,
      ts_builtin_sym_end,
      sym_paragraph_break,
    ACTIONS(122), 2,
      sym_punctuation,
      sym_whitespace,
    STATE(22), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
    ACTIONS(125), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [226] = 7,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(79), 1,
      sym__character,
    STATE(61), 1,
      aux_sym_word_repeat1,
    ACTIONS(77), 2,
      ts_builtin_sym_end,
      sym_paragraph_break,
    ACTIONS(82), 2,
      sym_punctuation,
      sym_whitespace,
    STATE(9), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
    ACTIONS(85), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [253] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(90), 1,
      sym_bold_close,
    ACTIONS(110), 1,
      sym__character,
    ACTIONS(116), 1,
      anon_sym_CR,
    STATE(68), 1,
      aux_sym_word_repeat1,
    ACTIONS(113), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(128), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(17), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [281] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(131), 1,
      sym__character,
    ACTIONS(137), 1,
      anon_sym_CR,
    ACTIONS(139), 1,
      sym_underline_close,
    STATE(68), 1,
      aux_sym_word_repeat1,
    ACTIONS(133), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(135), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(58), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [309] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(141), 1,
      sym__character,
    ACTIONS(147), 1,
      anon_sym_CR,
    ACTIONS(149), 1,
      sym_strikethrough_close,
    STATE(75), 1,
      aux_sym_word_repeat1,
    ACTIONS(143), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(145), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(41), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [337] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(151), 1,
      sym__character,
    ACTIONS(157), 1,
      anon_sym_CR,
    ACTIONS(159), 1,
      sym_bold_close,
    STATE(76), 1,
      aux_sym_word_repeat1,
    ACTIONS(153), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(155), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(35), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [365] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(161), 1,
      sym__character,
    ACTIONS(167), 1,
      anon_sym_CR,
    ACTIONS(169), 1,
      sym_italic_close,
    STATE(67), 1,
      aux_sym_word_repeat1,
    ACTIONS(163), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(165), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(50), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [393] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(131), 1,
      sym__character,
    ACTIONS(137), 1,
      anon_sym_CR,
    ACTIONS(171), 1,
      sym_underline_close,
    STATE(68), 1,
      aux_sym_word_repeat1,
    ACTIONS(133), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(135), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(58), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [421] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(141), 1,
      sym__character,
    ACTIONS(147), 1,
      anon_sym_CR,
    ACTIONS(173), 1,
      sym_strikethrough_close,
    STATE(75), 1,
      aux_sym_word_repeat1,
    ACTIONS(143), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(145), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(41), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [449] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(131), 1,
      sym__character,
    ACTIONS(137), 1,
      anon_sym_CR,
    ACTIONS(175), 1,
      sym_underline_close,
    STATE(68), 1,
      aux_sym_word_repeat1,
    ACTIONS(133), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(135), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(58), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [477] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(161), 1,
      sym__character,
    ACTIONS(167), 1,
      anon_sym_CR,
    ACTIONS(177), 1,
      sym_italic_close,
    STATE(67), 1,
      aux_sym_word_repeat1,
    ACTIONS(163), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(165), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(50), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [505] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(151), 1,
      sym__character,
    ACTIONS(157), 1,
      anon_sym_CR,
    ACTIONS(179), 1,
      sym_bold_close,
    STATE(76), 1,
      aux_sym_word_repeat1,
    ACTIONS(153), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(155), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(35), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [533] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(141), 1,
      sym__character,
    ACTIONS(147), 1,
      anon_sym_CR,
    ACTIONS(181), 1,
      sym_strikethrough_close,
    STATE(75), 1,
      aux_sym_word_repeat1,
    ACTIONS(143), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(145), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(41), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [561] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(131), 1,
      sym__character,
    ACTIONS(137), 1,
      anon_sym_CR,
    ACTIONS(183), 1,
      sym_underline_close,
    STATE(68), 1,
      aux_sym_word_repeat1,
    ACTIONS(133), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(135), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(58), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [589] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(90), 1,
      sym_bold_close,
    ACTIONS(92), 1,
      sym__character,
    ACTIONS(98), 1,
      anon_sym_CR,
    STATE(76), 1,
      aux_sym_word_repeat1,
    ACTIONS(95), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(185), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(39), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [617] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(90), 1,
      sym_bold_close,
    ACTIONS(101), 1,
      sym__character,
    ACTIONS(107), 1,
      anon_sym_CR,
    STATE(67), 1,
      aux_sym_word_repeat1,
    ACTIONS(104), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(188), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(38), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [645] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(90), 1,
      sym_strikethrough_close,
    ACTIONS(92), 1,
      sym__character,
    ACTIONS(98), 1,
      anon_sym_CR,
    STATE(76), 1,
      aux_sym_word_repeat1,
    ACTIONS(95), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(185), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(37), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [673] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(90), 1,
      sym_bold_close,
    ACTIONS(119), 1,
      sym__character,
    ACTIONS(125), 1,
      anon_sym_CR,
    STATE(75), 1,
      aux_sym_word_repeat1,
    ACTIONS(122), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(191), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(36), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [701] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(161), 1,
      sym__character,
    ACTIONS(167), 1,
      anon_sym_CR,
    ACTIONS(194), 1,
      sym_italic_close,
    STATE(67), 1,
      aux_sym_word_repeat1,
    ACTIONS(163), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(165), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(50), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [729] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(77), 1,
      sym_bold_close,
    ACTIONS(196), 1,
      sym__character,
    ACTIONS(205), 1,
      anon_sym_CR,
    STATE(76), 1,
      aux_sym_word_repeat1,
    ACTIONS(199), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(202), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(35), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [757] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(151), 1,
      sym__character,
    ACTIONS(157), 1,
      anon_sym_CR,
    ACTIONS(208), 1,
      sym_bold_close,
    STATE(76), 1,
      aux_sym_word_repeat1,
    ACTIONS(153), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(155), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(35), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [785] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(77), 1,
      sym_bold_close,
    ACTIONS(196), 1,
      sym__character,
    ACTIONS(205), 1,
      anon_sym_CR,
    STATE(76), 1,
      aux_sym_word_repeat1,
    ACTIONS(199), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(202), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(35), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [813] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(141), 1,
      sym__character,
    ACTIONS(147), 1,
      anon_sym_CR,
    ACTIONS(210), 1,
      sym_strikethrough_close,
    STATE(75), 1,
      aux_sym_word_repeat1,
    ACTIONS(143), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(145), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(41), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [841] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(151), 1,
      sym__character,
    ACTIONS(157), 1,
      anon_sym_CR,
    ACTIONS(212), 1,
      sym_bold_close,
    STATE(76), 1,
      aux_sym_word_repeat1,
    ACTIONS(153), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(155), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(35), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [869] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(161), 1,
      sym__character,
    ACTIONS(167), 1,
      anon_sym_CR,
    ACTIONS(214), 1,
      sym_italic_close,
    STATE(67), 1,
      aux_sym_word_repeat1,
    ACTIONS(163), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(165), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(50), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [897] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(151), 1,
      sym__character,
    ACTIONS(157), 1,
      anon_sym_CR,
    ACTIONS(216), 1,
      sym_bold_close,
    STATE(76), 1,
      aux_sym_word_repeat1,
    ACTIONS(153), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(155), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(35), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [925] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(141), 1,
      sym__character,
    ACTIONS(147), 1,
      anon_sym_CR,
    ACTIONS(218), 1,
      sym_strikethrough_close,
    STATE(75), 1,
      aux_sym_word_repeat1,
    ACTIONS(143), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(145), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(41), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [953] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(77), 1,
      sym_strikethrough_close,
    ACTIONS(220), 1,
      sym__character,
    ACTIONS(229), 1,
      anon_sym_CR,
    STATE(75), 1,
      aux_sym_word_repeat1,
    ACTIONS(223), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(226), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(41), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [981] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(77), 1,
      sym_strikethrough_close,
    ACTIONS(220), 1,
      sym__character,
    ACTIONS(229), 1,
      anon_sym_CR,
    STATE(75), 1,
      aux_sym_word_repeat1,
    ACTIONS(223), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(226), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(41), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [1009] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(90), 1,
      sym_italic_close,
    ACTIONS(92), 1,
      sym__character,
    ACTIONS(98), 1,
      anon_sym_CR,
    STATE(76), 1,
      aux_sym_word_repeat1,
    ACTIONS(95), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(185), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(34), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [1037] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(90), 1,
      sym_italic_close,
    ACTIONS(101), 1,
      sym__character,
    ACTIONS(107), 1,
      anon_sym_CR,
    STATE(67), 1,
      aux_sym_word_repeat1,
    ACTIONS(104), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(188), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(32), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [1065] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(90), 1,
      sym_italic_close,
    ACTIONS(110), 1,
      sym__character,
    ACTIONS(116), 1,
      anon_sym_CR,
    STATE(68), 1,
      aux_sym_word_repeat1,
    ACTIONS(113), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(128), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(27), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [1093] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(90), 1,
      sym_italic_close,
    ACTIONS(119), 1,
      sym__character,
    ACTIONS(125), 1,
      anon_sym_CR,
    STATE(75), 1,
      aux_sym_word_repeat1,
    ACTIONS(122), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(191), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(26), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [1121] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(90), 1,
      sym_strikethrough_close,
    ACTIONS(119), 1,
      sym__character,
    ACTIONS(125), 1,
      anon_sym_CR,
    STATE(75), 1,
      aux_sym_word_repeat1,
    ACTIONS(122), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(191), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(40), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [1149] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(77), 1,
      sym_italic_close,
    ACTIONS(232), 1,
      sym__character,
    ACTIONS(241), 1,
      anon_sym_CR,
    STATE(67), 1,
      aux_sym_word_repeat1,
    ACTIONS(235), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(238), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(50), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [1177] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(90), 1,
      sym_strikethrough_close,
    ACTIONS(110), 1,
      sym__character,
    ACTIONS(116), 1,
      anon_sym_CR,
    STATE(68), 1,
      aux_sym_word_repeat1,
    ACTIONS(113), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(128), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(59), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [1205] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(77), 1,
      sym_italic_close,
    ACTIONS(232), 1,
      sym__character,
    ACTIONS(241), 1,
      anon_sym_CR,
    STATE(67), 1,
      aux_sym_word_repeat1,
    ACTIONS(235), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(238), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(50), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [1233] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(90), 1,
      sym_strikethrough_close,
    ACTIONS(101), 1,
      sym__character,
    ACTIONS(107), 1,
      anon_sym_CR,
    STATE(67), 1,
      aux_sym_word_repeat1,
    ACTIONS(104), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(188), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(52), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [1261] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(161), 1,
      sym__character,
    ACTIONS(167), 1,
      anon_sym_CR,
    ACTIONS(244), 1,
      sym_italic_close,
    STATE(67), 1,
      aux_sym_word_repeat1,
    ACTIONS(163), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(165), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(50), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [1289] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(90), 1,
      sym_underline_close,
    ACTIONS(92), 1,
      sym__character,
    ACTIONS(98), 1,
      anon_sym_CR,
    STATE(76), 1,
      aux_sym_word_repeat1,
    ACTIONS(95), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(185), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(25), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [1317] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(90), 1,
      sym_underline_close,
    ACTIONS(101), 1,
      sym__character,
    ACTIONS(107), 1,
      anon_sym_CR,
    STATE(67), 1,
      aux_sym_word_repeat1,
    ACTIONS(104), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(188), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(24), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [1345] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(90), 1,
      sym_underline_close,
    ACTIONS(110), 1,
      sym__character,
    ACTIONS(116), 1,
      anon_sym_CR,
    STATE(68), 1,
      aux_sym_word_repeat1,
    ACTIONS(113), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(128), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(23), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [1373] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(90), 1,
      sym_underline_close,
    ACTIONS(119), 1,
      sym__character,
    ACTIONS(125), 1,
      anon_sym_CR,
    STATE(75), 1,
      aux_sym_word_repeat1,
    ACTIONS(122), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(191), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(18), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [1401] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(77), 1,
      sym_underline_close,
    ACTIONS(246), 1,
      sym__character,
    ACTIONS(255), 1,
      anon_sym_CR,
    STATE(68), 1,
      aux_sym_word_repeat1,
    ACTIONS(249), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(252), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(58), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [1429] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(77), 1,
      sym_underline_close,
    ACTIONS(246), 1,
      sym__character,
    ACTIONS(255), 1,
      anon_sym_CR,
    STATE(68), 1,
      aux_sym_word_repeat1,
    ACTIONS(249), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(252), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(58), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [1457] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(131), 1,
      sym__character,
    ACTIONS(137), 1,
      anon_sym_CR,
    ACTIONS(258), 1,
      sym_underline_close,
    STATE(68), 1,
      aux_sym_word_repeat1,
    ACTIONS(133), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(135), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(58), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [1485] = 7,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(151), 1,
      sym__character,
    ACTIONS(157), 1,
      anon_sym_CR,
    STATE(76), 1,
      aux_sym_word_repeat1,
    ACTIONS(153), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(155), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(33), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [1510] = 5,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(262), 1,
      sym__character,
    STATE(62), 1,
      aux_sym_word_repeat1,
    ACTIONS(264), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
    ACTIONS(260), 4,
      ts_builtin_sym_end,
      sym_punctuation,
      sym_whitespace,
      sym_paragraph_break,
  [1531] = 5,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(268), 1,
      sym__character,
    STATE(62), 1,
      aux_sym_word_repeat1,
    ACTIONS(271), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
    ACTIONS(266), 4,
      ts_builtin_sym_end,
      sym_punctuation,
      sym_whitespace,
      sym_paragraph_break,
  [1552] = 7,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(141), 1,
      sym__character,
    ACTIONS(147), 1,
      anon_sym_CR,
    STATE(75), 1,
      aux_sym_word_repeat1,
    ACTIONS(143), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(145), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(42), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [1577] = 7,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(7), 1,
      sym__character,
    ACTIONS(11), 1,
      anon_sym_CR,
    STATE(61), 1,
      aux_sym_word_repeat1,
    ACTIONS(9), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(273), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(15), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [1602] = 7,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(161), 1,
      sym__character,
    ACTIONS(167), 1,
      anon_sym_CR,
    STATE(67), 1,
      aux_sym_word_repeat1,
    ACTIONS(163), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(165), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(48), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [1627] = 7,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(131), 1,
      sym__character,
    ACTIONS(137), 1,
      anon_sym_CR,
    STATE(68), 1,
      aux_sym_word_repeat1,
    ACTIONS(133), 2,
      sym_punctuation,
      sym_whitespace,
    ACTIONS(135), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
    STATE(57), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [1652] = 5,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(264), 1,
      anon_sym_CR,
    ACTIONS(275), 1,
      sym__character,
    STATE(78), 1,
      aux_sym_word_repeat1,
    ACTIONS(260), 5,
      sym_italic_close,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [1672] = 5,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(264), 1,
      anon_sym_CR,
    ACTIONS(277), 1,
      sym__character,
    STATE(69), 1,
      aux_sym_word_repeat1,
    ACTIONS(260), 5,
      sym_underline_close,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [1692] = 5,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(271), 1,
      anon_sym_CR,
    ACTIONS(279), 1,
      sym__character,
    STATE(69), 1,
      aux_sym_word_repeat1,
    ACTIONS(266), 5,
      sym_underline_close,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [1712] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(282), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
    ACTIONS(77), 5,
      ts_builtin_sym_end,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      sym_paragraph_break,
  [1728] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(286), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
    ACTIONS(284), 5,
      ts_builtin_sym_end,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      sym_paragraph_break,
  [1744] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(290), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
    ACTIONS(288), 5,
      ts_builtin_sym_end,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      sym_paragraph_break,
  [1760] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(294), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
    ACTIONS(292), 5,
      ts_builtin_sym_end,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      sym_paragraph_break,
  [1776] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(298), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
    ACTIONS(296), 5,
      ts_builtin_sym_end,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      sym_paragraph_break,
  [1792] = 5,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(264), 1,
      anon_sym_CR,
    ACTIONS(300), 1,
      sym__character,
    STATE(79), 1,
      aux_sym_word_repeat1,
    ACTIONS(260), 5,
      sym_strikethrough_close,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [1812] = 5,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(264), 1,
      anon_sym_CR,
    ACTIONS(302), 1,
      sym__character,
    STATE(77), 1,
      aux_sym_word_repeat1,
    ACTIONS(260), 5,
      sym_bold_close,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [1832] = 5,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(271), 1,
      anon_sym_CR,
    ACTIONS(304), 1,
      sym__character,
    STATE(77), 1,
      aux_sym_word_repeat1,
    ACTIONS(266), 5,
      sym_bold_close,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [1852] = 5,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(271), 1,
      anon_sym_CR,
    ACTIONS(307), 1,
      sym__character,
    STATE(78), 1,
      aux_sym_word_repeat1,
    ACTIONS(266), 5,
      sym_italic_close,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [1872] = 5,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(271), 1,
      anon_sym_CR,
    ACTIONS(310), 1,
      sym__character,
    STATE(79), 1,
      aux_sym_word_repeat1,
    ACTIONS(266), 5,
      sym_strikethrough_close,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [1892] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(286), 1,
      anon_sym_CR,
    ACTIONS(284), 6,
      sym_strikethrough_close,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [1907] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(282), 1,
      anon_sym_CR,
    ACTIONS(77), 6,
      sym_underline_close,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [1922] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(290), 1,
      anon_sym_CR,
    ACTIONS(288), 6,
      sym_strikethrough_close,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [1937] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(294), 1,
      anon_sym_CR,
    ACTIONS(292), 6,
      sym_strikethrough_close,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [1952] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(298), 1,
      anon_sym_CR,
    ACTIONS(296), 6,
      sym_strikethrough_close,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [1967] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(282), 1,
      anon_sym_CR,
    ACTIONS(77), 6,
      sym_italic_close,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [1982] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(298), 1,
      anon_sym_CR,
    ACTIONS(296), 6,
      sym_bold_close,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [1997] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(294), 1,
      anon_sym_CR,
    ACTIONS(292), 6,
      sym_bold_close,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [2012] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(290), 1,
      anon_sym_CR,
    ACTIONS(288), 6,
      sym_bold_close,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [2027] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(286), 1,
      anon_sym_CR,
    ACTIONS(284), 6,
      sym_bold_close,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [2042] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(282), 1,
      anon_sym_CR,
    ACTIONS(77), 6,
      sym_strikethrough_close,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [2057] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(282), 1,
      anon_sym_CR,
    ACTIONS(77), 6,
      sym_bold_close,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [2072] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(286), 1,
      anon_sym_CR,
    ACTIONS(284), 6,
      sym_italic_close,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [2087] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(290), 1,
      anon_sym_CR,
    ACTIONS(288), 6,
      sym_italic_close,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [2102] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(298), 1,
      anon_sym_CR,
    ACTIONS(296), 6,
      sym_italic_close,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [2117] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(298), 1,
      anon_sym_CR,
    ACTIONS(296), 6,
      sym_underline_close,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [2132] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(294), 1,
      anon_sym_CR,
    ACTIONS(292), 6,
      sym_underline_close,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [2147] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(290), 1,
      anon_sym_CR,
    ACTIONS(288), 6,
      sym_underline_close,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [2162] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(286), 1,
      anon_sym_CR,
    ACTIONS(284), 6,
      sym_underline_close,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [2177] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(294), 1,
      anon_sym_CR,
    ACTIONS(292), 6,
      sym_italic_close,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [2192] = 2,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(313), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(7)] = 0,
  [SMALL_STATE(8)] = 32,
  [SMALL_STATE(9)] = 64,
  [SMALL_STATE(10)] = 91,
  [SMALL_STATE(11)] = 118,
  [SMALL_STATE(12)] = 145,
  [SMALL_STATE(13)] = 172,
  [SMALL_STATE(14)] = 199,
  [SMALL_STATE(15)] = 226,
  [SMALL_STATE(16)] = 253,
  [SMALL_STATE(17)] = 281,
  [SMALL_STATE(18)] = 309,
  [SMALL_STATE(19)] = 337,
  [SMALL_STATE(20)] = 365,
  [SMALL_STATE(21)] = 393,
  [SMALL_STATE(22)] = 421,
  [SMALL_STATE(23)] = 449,
  [SMALL_STATE(24)] = 477,
  [SMALL_STATE(25)] = 505,
  [SMALL_STATE(26)] = 533,
  [SMALL_STATE(27)] = 561,
  [SMALL_STATE(28)] = 589,
  [SMALL_STATE(29)] = 617,
  [SMALL_STATE(30)] = 645,
  [SMALL_STATE(31)] = 673,
  [SMALL_STATE(32)] = 701,
  [SMALL_STATE(33)] = 729,
  [SMALL_STATE(34)] = 757,
  [SMALL_STATE(35)] = 785,
  [SMALL_STATE(36)] = 813,
  [SMALL_STATE(37)] = 841,
  [SMALL_STATE(38)] = 869,
  [SMALL_STATE(39)] = 897,
  [SMALL_STATE(40)] = 925,
  [SMALL_STATE(41)] = 953,
  [SMALL_STATE(42)] = 981,
  [SMALL_STATE(43)] = 1009,
  [SMALL_STATE(44)] = 1037,
  [SMALL_STATE(45)] = 1065,
  [SMALL_STATE(46)] = 1093,
  [SMALL_STATE(47)] = 1121,
  [SMALL_STATE(48)] = 1149,
  [SMALL_STATE(49)] = 1177,
  [SMALL_STATE(50)] = 1205,
  [SMALL_STATE(51)] = 1233,
  [SMALL_STATE(52)] = 1261,
  [SMALL_STATE(53)] = 1289,
  [SMALL_STATE(54)] = 1317,
  [SMALL_STATE(55)] = 1345,
  [SMALL_STATE(56)] = 1373,
  [SMALL_STATE(57)] = 1401,
  [SMALL_STATE(58)] = 1429,
  [SMALL_STATE(59)] = 1457,
  [SMALL_STATE(60)] = 1485,
  [SMALL_STATE(61)] = 1510,
  [SMALL_STATE(62)] = 1531,
  [SMALL_STATE(63)] = 1552,
  [SMALL_STATE(64)] = 1577,
  [SMALL_STATE(65)] = 1602,
  [SMALL_STATE(66)] = 1627,
  [SMALL_STATE(67)] = 1652,
  [SMALL_STATE(68)] = 1672,
  [SMALL_STATE(69)] = 1692,
  [SMALL_STATE(70)] = 1712,
  [SMALL_STATE(71)] = 1728,
  [SMALL_STATE(72)] = 1744,
  [SMALL_STATE(73)] = 1760,
  [SMALL_STATE(74)] = 1776,
  [SMALL_STATE(75)] = 1792,
  [SMALL_STATE(76)] = 1812,
  [SMALL_STATE(77)] = 1832,
  [SMALL_STATE(78)] = 1852,
  [SMALL_STATE(79)] = 1872,
  [SMALL_STATE(80)] = 1892,
  [SMALL_STATE(81)] = 1907,
  [SMALL_STATE(82)] = 1922,
  [SMALL_STATE(83)] = 1937,
  [SMALL_STATE(84)] = 1952,
  [SMALL_STATE(85)] = 1967,
  [SMALL_STATE(86)] = 1982,
  [SMALL_STATE(87)] = 1997,
  [SMALL_STATE(88)] = 2012,
  [SMALL_STATE(89)] = 2027,
  [SMALL_STATE(90)] = 2042,
  [SMALL_STATE(91)] = 2057,
  [SMALL_STATE(92)] = 2072,
  [SMALL_STATE(93)] = 2087,
  [SMALL_STATE(94)] = 2102,
  [SMALL_STATE(95)] = 2117,
  [SMALL_STATE(96)] = 2132,
  [SMALL_STATE(97)] = 2147,
  [SMALL_STATE(98)] = 2162,
  [SMALL_STATE(99)] = 2177,
  [SMALL_STATE(100)] = 2192,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 1),
  [17] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_paragraph_repeat1, 1),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2),
  [65] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(61),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(2),
  [71] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(64),
  [74] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(8),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2),
  [79] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(61),
  [82] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(2),
  [85] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(64),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 1),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_open_conflict, 1, .dynamic_precedence = -1),
  [92] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_open_conflict, 1, .dynamic_precedence = -1), SHIFT(76),
  [95] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_open_conflict, 1, .dynamic_precedence = -1), SHIFT(6),
  [98] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_open_conflict, 1, .dynamic_precedence = -1), SHIFT(60),
  [101] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_open_conflict, 1, .dynamic_precedence = -1), SHIFT(67),
  [104] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_open_conflict, 1, .dynamic_precedence = -1), SHIFT(5),
  [107] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_open_conflict, 1, .dynamic_precedence = -1), SHIFT(65),
  [110] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_open_conflict, 1, .dynamic_precedence = -1), SHIFT(68),
  [113] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_open_conflict, 1, .dynamic_precedence = -1), SHIFT(4),
  [116] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_open_conflict, 1, .dynamic_precedence = -1), SHIFT(66),
  [119] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_open_conflict, 1, .dynamic_precedence = -1), SHIFT(75),
  [122] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_open_conflict, 1, .dynamic_precedence = -1), SHIFT(3),
  [125] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_open_conflict, 1, .dynamic_precedence = -1), SHIFT(63),
  [128] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_open_conflict, 1, .dynamic_precedence = -1), SHIFT(66),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [137] = {.entry = {.count = 1, .reusable = false}}, SHIFT(66),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [147] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [157] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [167] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [185] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_open_conflict, 1, .dynamic_precedence = -1), SHIFT(60),
  [188] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_open_conflict, 1, .dynamic_precedence = -1), SHIFT(65),
  [191] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_open_conflict, 1, .dynamic_precedence = -1), SHIFT(63),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [196] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(76),
  [199] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(6),
  [202] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(60),
  [205] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(60),
  [208] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [210] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [220] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(75),
  [223] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(3),
  [226] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(63),
  [229] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(63),
  [232] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(67),
  [235] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(5),
  [238] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(65),
  [241] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(65),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [246] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(68),
  [249] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(4),
  [252] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(66),
  [255] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(66),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_word, 1),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [264] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_word, 1),
  [266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_word_repeat1, 2),
  [268] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_word_repeat1, 2), SHIFT_REPEAT(62),
  [271] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_word_repeat1, 2),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [277] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [279] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_word_repeat1, 2), SHIFT_REPEAT(69),
  [282] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_paragraph_repeat1, 2),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bold, 3),
  [286] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bold, 3),
  [288] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_italic, 3),
  [290] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_italic, 3),
  [292] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_underline, 3),
  [294] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_underline, 3),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_strikethrough, 3),
  [298] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_strikethrough, 3),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [304] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_word_repeat1, 2), SHIFT_REPEAT(77),
  [307] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_word_repeat1, 2), SHIFT_REPEAT(78),
  [310] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_word_repeat1, 2), SHIFT_REPEAT(79),
  [313] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
