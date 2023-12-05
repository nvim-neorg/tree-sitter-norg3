#include <cwctype>
#include <iostream>
#include <algorithm>
#include <cstring>
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

    BOLD_OPEN,
    BOLD_CLOSE,

    ITALIC_OPEN,
    ITALIC_CLOSE,

    MAYBE_OPENING_MODIFIER,
};

struct Scanner {
    TSLexer* lexer;
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

        if ((valid_symbols[BOLD_OPEN] || valid_symbols[BOLD_CLOSE] || valid_symbols[ITALIC_OPEN] || valid_symbols[ITALIC_CLOSE]) && (lexer->lookahead == '*' || lexer->lookahead == '/')) {
            const int32_t character = lexer->lookahead;

            skip();

            if (lexer->lookahead == character) {
                skip();
                return false;
            }

            if (valid_symbols[BOLD_CLOSE] && character == '*' && (iswspace(lexer->lookahead) || iswpunct(lexer->lookahead))) {
                lexer->result_symbol = BOLD_CLOSE;
                return true;
            }
            else if (valid_symbols[BOLD_OPEN] && character == '*' && !iswspace(lexer->lookahead)) {
                lexer->result_symbol = BOLD_OPEN;
                return true;
            }

            if (valid_symbols[ITALIC_CLOSE] && character == '/' && (iswspace(lexer->lookahead) || iswpunct(lexer->lookahead))) {
                lexer->result_symbol = ITALIC_CLOSE;
                return true;
            }
            else if (valid_symbols[ITALIC_OPEN] && character == '/' && !iswspace(lexer->lookahead)) {
                lexer->result_symbol = ITALIC_OPEN;
                return true;
            }

            return false;
        }

        if (valid_symbols[MAYBE_OPENING_MODIFIER] && is_whitespace(lexer->lookahead)) {
            while (is_whitespace(lexer->lookahead))
                advance();

            if (lexer->lookahead == '*' || lexer->lookahead == '/') {
                lexer->result_symbol = MAYBE_OPENING_MODIFIER;
                return true;
            }

            return false;
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
        return 0;
    }

    void tree_sitter_norg_external_scanner_deserialize(void *payload,
            const char *buffer,
            unsigned length) {
    }
}
