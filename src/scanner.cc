#include <bitset>
#include <cwctype>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <ratio>
#include <unordered_map>
#include <vector>
#include <list>

#include "tree_sitter/parser.h"

/// GENERAL NOTES ABOUT THIS FILE
///
/// 1. The code may look dated in terms of C++ coding style. This is surprisingly a feature, not a bug.
///    MacOS suffers from terrible compiler compatibility, requiring us to write pre-C++11 code. Ouchie.
/// 2. Quotes, lists and headings (the "nestable detached modifiers") are parsed in this scanner to allow for
///    "infinite" nesting (in reality the cap is at the 16 bit integer limit).

// GENERAL TODOS: Detect the treesitter "error mode" in the scanner.

// Generally discouraged, but fine because this is a confined, single file
// scanner.
using namespace std;

// Make TokenType derive from `char` for compact serialization.
enum TokenType : char {
    WHITESPACE,

    PARAGRAPH_BREAK,

    PUNCTUATION,

    MAYBE_OPENING_MODIFIER,

    BOLD_OPEN,
    BOLD_CLOSE,

    ITALIC_OPEN,
    ITALIC_CLOSE,

    UNDERLINE_OPEN,
    UNDERLINE_CLOSE,

    STRIKETHROUGH_OPEN,
    STRIKETHROUGH_CLOSE,

    SPOILER_OPEN,
    SPOILER_CLOSE,

    SUPERSCRIPT_OPEN,
    SUPERSCRIPT_CLOSE,

    SUBSCRIPT_OPEN,
    SUBSCRIPT_CLOSE,

    VERBATIM_OPEN,
    VERBATIM_CLOSE,

    INLINE_MATH_OPEN,
    INLINE_MATH_CLOSE,

    INLINE_MACRO_OPEN,
    INLINE_MACRO_CLOSE,
};

TokenType char_to_token(int32_t c) {
    switch (c) {
        case '*':
            return BOLD_OPEN;
        case '/':
            return ITALIC_OPEN;
        case '_':
            return UNDERLINE_OPEN;
        case '-':
            return STRIKETHROUGH_OPEN;
        case '!':
            return SPOILER_OPEN;
        case '^':
            return SUPERSCRIPT_OPEN;
        case ',':
            return SUBSCRIPT_OPEN;
        case '`':
            return VERBATIM_OPEN;
        case '$':
            return INLINE_MATH_OPEN;
        case '&':
            return INLINE_MACRO_OPEN;
    }

    return WHITESPACE;
}

struct Scanner {
    TSLexer* lexer;
    std::unordered_map<TokenType, size_t> attached_modifiers;

    Scanner() {
        attached_modifiers[BOLD_OPEN] = 0;
        attached_modifiers[ITALIC_OPEN] = 0;
        attached_modifiers[UNDERLINE_OPEN] = 0;
        attached_modifiers[STRIKETHROUGH_OPEN] = 0;
        attached_modifiers[SPOILER_OPEN] = 0;
        attached_modifiers[SUPERSCRIPT_OPEN] = 0;
        attached_modifiers[SUBSCRIPT_OPEN] = 0;
        attached_modifiers[VERBATIM_OPEN] = 0;
        attached_modifiers[INLINE_MATH_OPEN] = 0;
        attached_modifiers[INLINE_MACRO_OPEN] = 0;
    }

    /**
     * Returns `true` if the character provided is a separator character (but not a newline).
     */
    bool is_whitespace(int32_t character) {
        return iswspace(character) && character != '\n' && character != '\r';
    }

    /**
     * @brief Searches through a range of valid symbols.
     *
     * @param valid_symbols Usually `valid_symbols` that were passed to you in the `scan` function.
     * @param start The beginning index to start search (inclusive).
     * @param end The end index of the search (inclusive).
     */
    int32_t get_valid_symbol(const bool* valid_symbols, size_t start, size_t end) {
        for (; start <= end; start++) {
            if (valid_symbols[start])
                return start;
        }

        return -1;
    }

    bool scan(const bool *valid_symbols) {
        // We return false here to allow the lexer to fall back
        // to the grammar, which allows the existence of `\0`.
        if (lexer->eof(lexer))
            return false;

        // If we are at the beginning of a line, parse any whitespace that we encounter.
        // This is then returned as `$._preceding_whitespace`, which is part of the `extras`
        // group, meaning it can theoretically exist "anywhere in the document". This prevents
        // odd errors with preceding whitespace like ` @end`, where `@end` isn't parsed because
        // a `$._whitespace` is encountered, causing the parser to continue parsing as if everything
        // were a `$.paragraph_segment`.
        if (lexer->get_column(lexer) == 0) {
            if (is_whitespace(lexer->lookahead)) {
                while (is_whitespace(lexer->lookahead))
                    advance();

                lexer->result_symbol = WHITESPACE;
                return true;
            }
        }

        if (valid_symbols[PARAGRAPH_BREAK] && (lexer->lookahead == '\n' || lexer->lookahead == '\r')) {
            advance();

            if (lexer->lookahead == '\n' || lexer->lookahead == '\r') {
                advance();
                lexer->result_symbol = PARAGRAPH_BREAK;
                attached_modifiers.clear();
                return true;
            }

            return false;
        }

        if (valid_symbols[MAYBE_OPENING_MODIFIER] && is_whitespace(lexer->lookahead)) {
            while (is_whitespace(lexer->lookahead))
                advance();

            if (char_to_token(lexer->lookahead) != 0) {
                lexer->result_symbol = MAYBE_OPENING_MODIFIER;
                return true;
            }

            return false;
        }

        const TokenType next_token = char_to_token(lexer->lookahead);

        if (next_token != 0 && (valid_symbols[next_token] || valid_symbols[next_token + 1])) {
            const int32_t character = lexer->lookahead;

            advance();

            if (lexer->lookahead == character) {
                while (lexer->lookahead == character)
                    advance();

                lexer->result_symbol = PUNCTUATION;
                return true;
            }

            if (attached_modifiers[next_token] > 0 && valid_symbols[next_token + 1] && (!lexer->lookahead || iswspace(lexer->lookahead) || iswpunct(lexer->lookahead))) {
                attached_modifiers[next_token] -= 1;
                lexer->result_symbol = next_token + 1;
                return true;
            }
            else if (valid_symbols[next_token] && lexer->lookahead && !iswspace(lexer->lookahead)) {
                const TokenType token = char_to_token(lexer->lookahead);

                if (token != 0 && attached_modifiers[token] > 0) {
                    lexer->result_symbol = PUNCTUATION;
                    return true;
                }

                attached_modifiers[next_token] += 1;
                lexer->result_symbol = next_token;
                return true;
            }

            lexer->result_symbol = PUNCTUATION;
            return true;
        }


        return false;
    }

    void skip() { lexer->advance(lexer, true); }
    void advance() { lexer->advance(lexer, false); }
};

extern "C" {
    void *tree_sitter_norg_external_scanner_create() { return new Scanner(); }

    void tree_sitter_norg_external_scanner_destroy(void *payload) {
        delete static_cast<Scanner *>(payload);
    }

    bool tree_sitter_norg_external_scanner_scan(void *payload, TSLexer *lexer,
            const bool *valid_symbols) {
        Scanner *scanner = static_cast<Scanner*>(payload);
        scanner->lexer = lexer;
        return scanner->scan(valid_symbols);
    }

    unsigned tree_sitter_norg_external_scanner_serialize(void *payload,
            char *buffer) {
        Scanner* scanner = static_cast<Scanner* >(payload);
        return 0;
    }

    void tree_sitter_norg_external_scanner_deserialize(void *payload,
            const char *buffer,
            unsigned length) {

    }
}
