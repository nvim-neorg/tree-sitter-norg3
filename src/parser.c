#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 37
#define LARGE_STATE_COUNT 17
#define SYMBOL_COUNT 21
#define ALIAS_COUNT 0
#define TOKEN_COUNT 12
#define EXTERNAL_TOKEN_COUNT 4
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
  sym_maybe_opening_modifier = 11,
  sym_document = 12,
  sym_word = 13,
  sym_paragraph = 14,
  sym_open_conflict = 15,
  sym_bold = 16,
  aux_sym_document_repeat1 = 17,
  aux_sym_word_repeat1 = 18,
  aux_sym_paragraph_repeat1 = 19,
  aux_sym_paragraph_repeat2 = 20,
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
  [sym_maybe_opening_modifier] = "maybe_opening_modifier",
  [sym_document] = "document",
  [sym_word] = "word",
  [sym_paragraph] = "paragraph",
  [sym_open_conflict] = "open_conflict",
  [sym_bold] = "bold",
  [aux_sym_document_repeat1] = "document_repeat1",
  [aux_sym_word_repeat1] = "word_repeat1",
  [aux_sym_paragraph_repeat1] = "paragraph_repeat1",
  [aux_sym_paragraph_repeat2] = "paragraph_repeat2",
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
  [sym_maybe_opening_modifier] = sym_maybe_opening_modifier,
  [sym_document] = sym_document,
  [sym_word] = sym_word,
  [sym_paragraph] = sym_paragraph,
  [sym_open_conflict] = sym_open_conflict,
  [sym_bold] = sym_bold,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
  [aux_sym_word_repeat1] = aux_sym_word_repeat1,
  [aux_sym_paragraph_repeat1] = aux_sym_paragraph_repeat1,
  [aux_sym_paragraph_repeat2] = aux_sym_paragraph_repeat2,
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
  [sym_paragraph] = {
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
  [aux_sym_paragraph_repeat2] = {
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
  [4] = 4,
  [5] = 5,
  [6] = 5,
  [7] = 4,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 11,
  [14] = 9,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 11,
  [21] = 9,
  [22] = 19,
  [23] = 17,
  [24] = 24,
  [25] = 16,
  [26] = 18,
  [27] = 24,
  [28] = 28,
  [29] = 28,
  [30] = 15,
  [31] = 12,
  [32] = 32,
  [33] = 32,
  [34] = 34,
  [35] = 35,
  [36] = 34,
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
  [2] = {.lex_state = 0, .external_lex_state = 2},
  [3] = {.lex_state = 1, .external_lex_state = 3},
  [4] = {.lex_state = 0, .external_lex_state = 2},
  [5] = {.lex_state = 0, .external_lex_state = 2},
  [6] = {.lex_state = 1, .external_lex_state = 3},
  [7] = {.lex_state = 1, .external_lex_state = 3},
  [8] = {.lex_state = 0, .external_lex_state = 2},
  [9] = {.lex_state = 0, .external_lex_state = 3},
  [10] = {.lex_state = 0, .external_lex_state = 2},
  [11] = {.lex_state = 0, .external_lex_state = 3},
  [12] = {.lex_state = 0, .external_lex_state = 2},
  [13] = {.lex_state = 0, .external_lex_state = 2},
  [14] = {.lex_state = 0, .external_lex_state = 2},
  [15] = {.lex_state = 0, .external_lex_state = 2},
  [16] = {.lex_state = 0, .external_lex_state = 3},
  [17] = {.lex_state = 0, .external_lex_state = 2},
  [18] = {.lex_state = 0, .external_lex_state = 2},
  [19] = {.lex_state = 0, .external_lex_state = 2},
  [20] = {.lex_state = 1, .external_lex_state = 3},
  [21] = {.lex_state = 1, .external_lex_state = 3},
  [22] = {.lex_state = 1, .external_lex_state = 3},
  [23] = {.lex_state = 1, .external_lex_state = 3},
  [24] = {.lex_state = 0, .external_lex_state = 2},
  [25] = {.lex_state = 1, .external_lex_state = 3},
  [26] = {.lex_state = 1, .external_lex_state = 3},
  [27] = {.lex_state = 0, .external_lex_state = 2},
  [28] = {.lex_state = 0, .external_lex_state = 2},
  [29] = {.lex_state = 0, .external_lex_state = 2},
  [30] = {.lex_state = 1, .external_lex_state = 4},
  [31] = {.lex_state = 1, .external_lex_state = 4},
  [32] = {.lex_state = 0, .external_lex_state = 5},
  [33] = {.lex_state = 0, .external_lex_state = 5},
  [34] = {.lex_state = 0, .external_lex_state = 4},
  [35] = {.lex_state = 0, .external_lex_state = 6},
  [36] = {.lex_state = 0, .external_lex_state = 4},
};

enum {
  ts_external_token__preceding_whitespace = 0,
  ts_external_token_bold_open = 1,
  ts_external_token_bold_close = 2,
  ts_external_token_maybe_opening_modifier = 3,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__preceding_whitespace] = sym__preceding_whitespace,
  [ts_external_token_bold_open] = sym_bold_open,
  [ts_external_token_bold_close] = sym_bold_close,
  [ts_external_token_maybe_opening_modifier] = sym_maybe_opening_modifier,
};

static const bool ts_external_scanner_states[7][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__preceding_whitespace] = true,
    [ts_external_token_bold_open] = true,
    [ts_external_token_bold_close] = true,
    [ts_external_token_maybe_opening_modifier] = true,
  },
  [2] = {
    [ts_external_token__preceding_whitespace] = true,
    [ts_external_token_maybe_opening_modifier] = true,
  },
  [3] = {
    [ts_external_token__preceding_whitespace] = true,
    [ts_external_token_bold_close] = true,
    [ts_external_token_maybe_opening_modifier] = true,
  },
  [4] = {
    [ts_external_token__preceding_whitespace] = true,
    [ts_external_token_bold_close] = true,
  },
  [5] = {
    [ts_external_token__preceding_whitespace] = true,
    [ts_external_token_bold_open] = true,
  },
  [6] = {
    [ts_external_token__preceding_whitespace] = true,
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
    [sym_maybe_opening_modifier] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(35),
    [sym_word] = STATE(2),
    [sym_paragraph] = STATE(8),
    [aux_sym_document_repeat1] = STATE(8),
    [aux_sym_word_repeat1] = STATE(13),
    [aux_sym_paragraph_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym__character] = ACTIONS(7),
    [sym_punctuation] = ACTIONS(9),
    [sym_whitespace] = ACTIONS(9),
    [sym_paragraph_break] = ACTIONS(11),
    [sym__preceding_whitespace] = ACTIONS(3),
    [sym_maybe_opening_modifier] = ACTIONS(13),
  },
  [2] = {
    [sym_word] = STATE(4),
    [aux_sym_word_repeat1] = STATE(13),
    [aux_sym_paragraph_repeat1] = STATE(4),
    [aux_sym_paragraph_repeat2] = STATE(15),
    [ts_builtin_sym_end] = ACTIONS(15),
    [sym__character] = ACTIONS(7),
    [sym_punctuation] = ACTIONS(17),
    [sym_whitespace] = ACTIONS(17),
    [anon_sym_LF] = ACTIONS(19),
    [anon_sym_CR] = ACTIONS(19),
    [anon_sym_CR_LF] = ACTIONS(19),
    [sym_paragraph_break] = ACTIONS(15),
    [sym__preceding_whitespace] = ACTIONS(3),
    [sym_maybe_opening_modifier] = ACTIONS(13),
  },
  [3] = {
    [sym_word] = STATE(7),
    [aux_sym_word_repeat1] = STATE(20),
    [aux_sym_paragraph_repeat1] = STATE(7),
    [aux_sym_paragraph_repeat2] = STATE(30),
    [sym__character] = ACTIONS(21),
    [sym_punctuation] = ACTIONS(23),
    [sym_whitespace] = ACTIONS(23),
    [anon_sym_LF] = ACTIONS(25),
    [anon_sym_CR] = ACTIONS(27),
    [anon_sym_CR_LF] = ACTIONS(25),
    [sym__preceding_whitespace] = ACTIONS(3),
    [sym_bold_close] = ACTIONS(15),
    [sym_maybe_opening_modifier] = ACTIONS(29),
  },
  [4] = {
    [sym_word] = STATE(4),
    [aux_sym_word_repeat1] = STATE(13),
    [aux_sym_paragraph_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(31),
    [sym__character] = ACTIONS(33),
    [sym_punctuation] = ACTIONS(36),
    [sym_whitespace] = ACTIONS(36),
    [anon_sym_LF] = ACTIONS(39),
    [anon_sym_CR] = ACTIONS(39),
    [anon_sym_CR_LF] = ACTIONS(39),
    [sym_paragraph_break] = ACTIONS(31),
    [sym__preceding_whitespace] = ACTIONS(3),
    [sym_maybe_opening_modifier] = ACTIONS(41),
  },
  [5] = {
    [sym_word] = STATE(4),
    [aux_sym_word_repeat1] = STATE(13),
    [aux_sym_paragraph_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(44),
    [sym__character] = ACTIONS(7),
    [sym_punctuation] = ACTIONS(17),
    [sym_whitespace] = ACTIONS(17),
    [anon_sym_LF] = ACTIONS(46),
    [anon_sym_CR] = ACTIONS(46),
    [anon_sym_CR_LF] = ACTIONS(46),
    [sym_paragraph_break] = ACTIONS(44),
    [sym__preceding_whitespace] = ACTIONS(3),
    [sym_maybe_opening_modifier] = ACTIONS(13),
  },
  [6] = {
    [sym_word] = STATE(7),
    [aux_sym_word_repeat1] = STATE(20),
    [aux_sym_paragraph_repeat1] = STATE(7),
    [sym__character] = ACTIONS(21),
    [sym_punctuation] = ACTIONS(23),
    [sym_whitespace] = ACTIONS(23),
    [anon_sym_LF] = ACTIONS(44),
    [anon_sym_CR] = ACTIONS(46),
    [anon_sym_CR_LF] = ACTIONS(44),
    [sym__preceding_whitespace] = ACTIONS(3),
    [sym_bold_close] = ACTIONS(44),
    [sym_maybe_opening_modifier] = ACTIONS(29),
  },
  [7] = {
    [sym_word] = STATE(7),
    [aux_sym_word_repeat1] = STATE(20),
    [aux_sym_paragraph_repeat1] = STATE(7),
    [sym__character] = ACTIONS(48),
    [sym_punctuation] = ACTIONS(51),
    [sym_whitespace] = ACTIONS(51),
    [anon_sym_LF] = ACTIONS(31),
    [anon_sym_CR] = ACTIONS(39),
    [anon_sym_CR_LF] = ACTIONS(31),
    [sym__preceding_whitespace] = ACTIONS(3),
    [sym_bold_close] = ACTIONS(31),
    [sym_maybe_opening_modifier] = ACTIONS(54),
  },
  [8] = {
    [sym_word] = STATE(2),
    [sym_paragraph] = STATE(10),
    [aux_sym_document_repeat1] = STATE(10),
    [aux_sym_word_repeat1] = STATE(13),
    [aux_sym_paragraph_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(57),
    [sym__character] = ACTIONS(7),
    [sym_punctuation] = ACTIONS(9),
    [sym_whitespace] = ACTIONS(9),
    [sym_paragraph_break] = ACTIONS(59),
    [sym__preceding_whitespace] = ACTIONS(3),
    [sym_maybe_opening_modifier] = ACTIONS(13),
  },
  [9] = {
    [aux_sym_word_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(61),
    [sym__character] = ACTIONS(63),
    [sym_punctuation] = ACTIONS(61),
    [sym_whitespace] = ACTIONS(61),
    [anon_sym_LF] = ACTIONS(66),
    [anon_sym_CR] = ACTIONS(66),
    [anon_sym_CR_LF] = ACTIONS(66),
    [sym_paragraph_break] = ACTIONS(61),
    [sym__preceding_whitespace] = ACTIONS(3),
    [sym_bold_close] = ACTIONS(61),
    [sym_maybe_opening_modifier] = ACTIONS(61),
  },
  [10] = {
    [sym_word] = STATE(2),
    [sym_paragraph] = STATE(10),
    [aux_sym_document_repeat1] = STATE(10),
    [aux_sym_word_repeat1] = STATE(13),
    [aux_sym_paragraph_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(68),
    [sym__character] = ACTIONS(70),
    [sym_punctuation] = ACTIONS(73),
    [sym_whitespace] = ACTIONS(73),
    [sym_paragraph_break] = ACTIONS(76),
    [sym__preceding_whitespace] = ACTIONS(3),
    [sym_maybe_opening_modifier] = ACTIONS(79),
  },
  [11] = {
    [aux_sym_word_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(82),
    [sym__character] = ACTIONS(84),
    [sym_punctuation] = ACTIONS(82),
    [sym_whitespace] = ACTIONS(82),
    [anon_sym_LF] = ACTIONS(86),
    [anon_sym_CR] = ACTIONS(86),
    [anon_sym_CR_LF] = ACTIONS(86),
    [sym_paragraph_break] = ACTIONS(82),
    [sym__preceding_whitespace] = ACTIONS(3),
    [sym_bold_close] = ACTIONS(82),
    [sym_maybe_opening_modifier] = ACTIONS(82),
  },
  [12] = {
    [aux_sym_paragraph_repeat2] = STATE(12),
    [ts_builtin_sym_end] = ACTIONS(44),
    [sym__character] = ACTIONS(44),
    [sym_punctuation] = ACTIONS(44),
    [sym_whitespace] = ACTIONS(44),
    [anon_sym_LF] = ACTIONS(88),
    [anon_sym_CR] = ACTIONS(88),
    [anon_sym_CR_LF] = ACTIONS(88),
    [sym_paragraph_break] = ACTIONS(44),
    [sym__preceding_whitespace] = ACTIONS(3),
    [sym_maybe_opening_modifier] = ACTIONS(44),
  },
  [13] = {
    [aux_sym_word_repeat1] = STATE(14),
    [ts_builtin_sym_end] = ACTIONS(82),
    [sym__character] = ACTIONS(91),
    [sym_punctuation] = ACTIONS(82),
    [sym_whitespace] = ACTIONS(82),
    [anon_sym_LF] = ACTIONS(86),
    [anon_sym_CR] = ACTIONS(86),
    [anon_sym_CR_LF] = ACTIONS(86),
    [sym_paragraph_break] = ACTIONS(82),
    [sym__preceding_whitespace] = ACTIONS(3),
    [sym_maybe_opening_modifier] = ACTIONS(82),
  },
  [14] = {
    [aux_sym_word_repeat1] = STATE(14),
    [ts_builtin_sym_end] = ACTIONS(61),
    [sym__character] = ACTIONS(93),
    [sym_punctuation] = ACTIONS(61),
    [sym_whitespace] = ACTIONS(61),
    [anon_sym_LF] = ACTIONS(66),
    [anon_sym_CR] = ACTIONS(66),
    [anon_sym_CR_LF] = ACTIONS(66),
    [sym_paragraph_break] = ACTIONS(61),
    [sym__preceding_whitespace] = ACTIONS(3),
    [sym_maybe_opening_modifier] = ACTIONS(61),
  },
  [15] = {
    [aux_sym_paragraph_repeat2] = STATE(12),
    [ts_builtin_sym_end] = ACTIONS(96),
    [sym__character] = ACTIONS(96),
    [sym_punctuation] = ACTIONS(96),
    [sym_whitespace] = ACTIONS(96),
    [anon_sym_LF] = ACTIONS(19),
    [anon_sym_CR] = ACTIONS(19),
    [anon_sym_CR_LF] = ACTIONS(19),
    [sym_paragraph_break] = ACTIONS(96),
    [sym__preceding_whitespace] = ACTIONS(3),
    [sym_maybe_opening_modifier] = ACTIONS(96),
  },
  [16] = {
    [ts_builtin_sym_end] = ACTIONS(98),
    [sym__character] = ACTIONS(100),
    [sym_punctuation] = ACTIONS(100),
    [sym_whitespace] = ACTIONS(100),
    [anon_sym_LF] = ACTIONS(103),
    [anon_sym_CR] = ACTIONS(103),
    [anon_sym_CR_LF] = ACTIONS(103),
    [sym_paragraph_break] = ACTIONS(98),
    [sym__preceding_whitespace] = ACTIONS(3),
    [sym_bold_close] = ACTIONS(106),
    [sym_maybe_opening_modifier] = ACTIONS(100),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(110), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
    ACTIONS(108), 6,
      sym_maybe_opening_modifier,
      ts_builtin_sym_end,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      sym_paragraph_break,
  [17] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(114), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
    ACTIONS(112), 6,
      sym_maybe_opening_modifier,
      ts_builtin_sym_end,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      sym_paragraph_break,
  [34] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(39), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
    ACTIONS(31), 6,
      sym_maybe_opening_modifier,
      ts_builtin_sym_end,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      sym_paragraph_break,
  [51] = 5,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(86), 1,
      anon_sym_CR,
    ACTIONS(116), 1,
      sym__character,
    STATE(21), 1,
      aux_sym_word_repeat1,
    ACTIONS(82), 6,
      sym_bold_close,
      sym_maybe_opening_modifier,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [72] = 5,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(66), 1,
      anon_sym_CR,
    ACTIONS(118), 1,
      sym__character,
    STATE(21), 1,
      aux_sym_word_repeat1,
    ACTIONS(61), 6,
      sym_bold_close,
      sym_maybe_opening_modifier,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [93] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(39), 1,
      anon_sym_CR,
    ACTIONS(31), 7,
      sym_bold_close,
      sym_maybe_opening_modifier,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [109] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(110), 1,
      anon_sym_CR,
    ACTIONS(108), 7,
      sym_bold_close,
      sym_maybe_opening_modifier,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [125] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(29), 1,
      sym_maybe_opening_modifier,
    ACTIONS(121), 1,
      sym__character,
    STATE(3), 1,
      aux_sym_paragraph_repeat1,
    STATE(11), 1,
      aux_sym_word_repeat1,
    STATE(16), 1,
      sym_word,
    STATE(34), 1,
      sym_paragraph,
    ACTIONS(123), 2,
      sym_punctuation,
      sym_whitespace,
  [151] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(103), 1,
      anon_sym_CR,
    ACTIONS(100), 7,
      sym_bold_close,
      sym_maybe_opening_modifier,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [167] = 3,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(114), 1,
      anon_sym_CR,
    ACTIONS(112), 7,
      sym_bold_close,
      sym_maybe_opening_modifier,
      sym__character,
      sym_punctuation,
      sym_whitespace,
      anon_sym_LF,
      anon_sym_CR_LF,
  [183] = 8,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(21), 1,
      sym__character,
    ACTIONS(29), 1,
      sym_maybe_opening_modifier,
    STATE(3), 1,
      aux_sym_paragraph_repeat1,
    STATE(20), 1,
      aux_sym_word_repeat1,
    STATE(25), 1,
      sym_word,
    STATE(36), 1,
      sym_paragraph,
    ACTIONS(123), 2,
      sym_punctuation,
      sym_whitespace,
  [209] = 6,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(7), 1,
      sym__character,
    ACTIONS(13), 1,
      sym_maybe_opening_modifier,
    STATE(13), 1,
      aux_sym_word_repeat1,
    ACTIONS(125), 2,
      sym_punctuation,
      sym_whitespace,
    STATE(5), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [230] = 6,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(21), 1,
      sym__character,
    ACTIONS(29), 1,
      sym_maybe_opening_modifier,
    STATE(20), 1,
      aux_sym_word_repeat1,
    ACTIONS(127), 2,
      sym_punctuation,
      sym_whitespace,
    STATE(6), 2,
      sym_word,
      aux_sym_paragraph_repeat1,
  [251] = 5,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(27), 1,
      anon_sym_CR,
    ACTIONS(96), 1,
      sym_bold_close,
    STATE(31), 1,
      aux_sym_paragraph_repeat2,
    ACTIONS(25), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
  [268] = 5,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(44), 1,
      sym_bold_close,
    ACTIONS(132), 1,
      anon_sym_CR,
    STATE(31), 1,
      aux_sym_paragraph_repeat2,
    ACTIONS(129), 2,
      anon_sym_LF,
      anon_sym_CR_LF,
  [285] = 5,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(135), 1,
      sym_punctuation,
    ACTIONS(137), 1,
      sym_bold_open,
    STATE(17), 1,
      sym_bold,
    STATE(19), 1,
      sym_open_conflict,
  [301] = 5,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(139), 1,
      sym_punctuation,
    ACTIONS(141), 1,
      sym_bold_open,
    STATE(22), 1,
      sym_open_conflict,
    STATE(23), 1,
      sym_bold,
  [317] = 2,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(143), 1,
      sym_bold_close,
  [324] = 2,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(145), 1,
      ts_builtin_sym_end,
  [331] = 2,
    ACTIONS(3), 1,
      sym__preceding_whitespace,
    ACTIONS(147), 1,
      sym_bold_close,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(17)] = 0,
  [SMALL_STATE(18)] = 17,
  [SMALL_STATE(19)] = 34,
  [SMALL_STATE(20)] = 51,
  [SMALL_STATE(21)] = 72,
  [SMALL_STATE(22)] = 93,
  [SMALL_STATE(23)] = 109,
  [SMALL_STATE(24)] = 125,
  [SMALL_STATE(25)] = 151,
  [SMALL_STATE(26)] = 167,
  [SMALL_STATE(27)] = 183,
  [SMALL_STATE(28)] = 209,
  [SMALL_STATE(29)] = 230,
  [SMALL_STATE(30)] = 251,
  [SMALL_STATE(31)] = 268,
  [SMALL_STATE(32)] = 285,
  [SMALL_STATE(33)] = 301,
  [SMALL_STATE(34)] = 317,
  [SMALL_STATE(35)] = 324,
  [SMALL_STATE(36)] = 331,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paragraph, 1),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2),
  [33] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(13),
  [36] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(4),
  [39] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_paragraph_repeat1, 2),
  [41] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(32),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat2, 2),
  [46] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_paragraph_repeat2, 2),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(20),
  [51] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(7),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(33),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_word_repeat1, 2),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_word_repeat1, 2), SHIFT_REPEAT(9),
  [66] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_word_repeat1, 2),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2),
  [70] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(13),
  [73] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(2),
  [76] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(10),
  [79] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(32),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_word, 1),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [86] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_word, 1),
  [88] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_paragraph_repeat2, 2), SHIFT_REPEAT(28),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [93] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_word_repeat1, 2), SHIFT_REPEAT(14),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paragraph, 2),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_open_conflict, 2),
  [100] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 1), REDUCE(sym_open_conflict, 2),
  [103] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_paragraph_repeat1, 1), REDUCE(sym_open_conflict, 2),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 1),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2, .dynamic_precedence = 1),
  [110] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_paragraph_repeat1, 2, .dynamic_precedence = 1),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bold, 3),
  [114] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bold, 3),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [118] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_word_repeat1, 2), SHIFT_REPEAT(21),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [129] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat2, 2), SHIFT_REPEAT(29),
  [132] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_paragraph_repeat2, 2), SHIFT_REPEAT(29),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [145] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
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
