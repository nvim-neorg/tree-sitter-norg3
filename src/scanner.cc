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
    NEWLINE,

    PUNCTUATION,

    NON_OPEN,
    NON_CLOSE,

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

    HEADING,

    ERROR_SENTINEL,
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

    bool single_line_mode;

    Scanner() {
        attached_modifiers.clear();
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
        single_line_mode = false;
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
        // the external scanner don't try any recovery
        if (valid_symbols[ERROR_SENTINEL]) {
            return false;
        }

        // We return false here to allow the lexer to fall back
        // to the grammar, which allows the existence of `\0`.
        if (lexer->eof(lexer)) {
            if (valid_symbols[PARAGRAPH_BREAK]) {
                lexer->result_symbol = PARAGRAPH_BREAK;
                return true;
            }
            return false;
        }

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

        if (iswspace(lexer->lookahead)) {
            while (is_whitespace(lexer->lookahead))
                skip();
            if (lexer->lookahead == '\n' || lexer->lookahead == '\r') {
                advance();

                if (valid_symbols[NEWLINE]) {
                    lexer->result_symbol = NEWLINE;
                    lexer->mark_end(lexer);
                    // cancel single-line, this occurs when heading has slide/indent_segment prefixs
                    if (single_line_mode) single_line_mode = false;
                    return true;
                }
                // when parsing single-line paragraph (aka. title,) return paragraph break immediately
                if (single_line_mode) {
                    single_line_mode = false;
                    lexer->result_symbol = PARAGRAPH_BREAK;
                    return true;
                }

                lexer->mark_end(lexer);
                while (is_whitespace(lexer->lookahead))
                    skip();
                if (lexer->eof(lexer) || lexer->lookahead == '\n' || lexer->lookahead == '\r') {
                    lexer->result_symbol = PARAGRAPH_BREAK;
                    attached_modifiers.clear();
                    return true;
                }
                if (lexer->lookahead == '*') {
                    int32_t character = lexer->lookahead;
                    skip();
                    size_t count = 1;
                    while (lexer->lookahead == character) {
                        count++;
                        skip();
                    }
                    if (is_whitespace(lexer->lookahead)) {
                        lexer->result_symbol = PARAGRAPH_BREAK;
                        attached_modifiers.clear();
                        return true;
                    }
                }
            }
            return false;
        }

        // take one lookahead first as we need at least two lookahead to distinguish heading_prefix and bold_open
        const int32_t character = lexer->lookahead;
        advance();

        if (valid_symbols[HEADING] && character == '*' && (lexer->lookahead == '*' || is_whitespace(lexer->lookahead))) {
            size_t count = 1;
            while (lexer->lookahead == character) {
                count++;
                advance();
            }

            if (!is_whitespace(lexer->lookahead))
                return false;

            lexer->mark_end(lexer);
            switch (character) {
            case '*':
                lexer->result_symbol = HEADING;
                single_line_mode = true;
                break;
            }
            return true;
        }

        // TODO: cleanup here
        int32_t mod_char = character;
        bool advanced = false;
        if (mod_char == ':' && valid_symbols[NON_OPEN]) {
            mod_char = lexer->lookahead;
            advance();
            advanced = true;
        }

        TokenType next_token = char_to_token(mod_char);

        // 5th case in link-mod-00
        if (advanced && next_token != 0 && valid_symbols[next_token + 1])
            return false;

        if (next_token != 0 && (valid_symbols[next_token] || valid_symbols[next_token + 1] || valid_symbols[NON_OPEN])) {
            if (lexer->lookahead == mod_char)
                return false;

            if (valid_symbols[NON_CLOSE] && valid_symbols[next_token + 1]) {
                lexer->result_symbol = NON_CLOSE;
                return true;
            }

            if (attached_modifiers[next_token] > 0 && valid_symbols[next_token + 1] && (!lexer->lookahead || iswspace(lexer->lookahead) || iswpunct(lexer->lookahead))) {
                attached_modifiers[next_token] -= 1;
                lexer->result_symbol = next_token + 1;
                lexer->mark_end(lexer);
                if (lexer->lookahead == ':') {
                    advance();
                    if (!iswspace(lexer->lookahead) && !iswpunct(lexer->lookahead)) {
                        lexer->mark_end(lexer);
                    }
                }
                return true;
            } else if (!advanced && valid_symbols[NON_OPEN]) {
                // there can be NON_OPEN even when BOLD_CLOSE is valid.
                // see att-11 for example
                lexer->result_symbol = NON_OPEN;
                return true;
                // check if attached modifier is open (free-02)
            } else if (valid_symbols[next_token] && lexer->lookahead && !iswspace(lexer->lookahead)) {
                lexer->mark_end(lexer);
                // solves free-02:
                if (lexer->lookahead == '|')
                    advance();
                // solves att-16:
                const int32_t next_mod = lexer->lookahead;
                const TokenType n_token = char_to_token(next_mod);
                if (n_token != 0 && attached_modifiers[n_token]) {
                    advance();
                    if (!lexer->lookahead || iswspace(lexer->lookahead) || iswpunct(lexer->lookahead) && lexer->lookahead != next_mod) {
                        lexer->result_symbol = PUNCTUATION;
                        return true;
                    }
                }

                attached_modifiers[next_token] += 1;
                lexer->result_symbol = next_token;
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
        Scanner* scanner = static_cast<Scanner* >(payload);
        size_t total_size = 0;
        buffer[total_size++] = scanner->single_line_mode;
        return total_size;
    }

    void tree_sitter_norg_external_scanner_deserialize(void *payload,
            const char *buffer,
            unsigned length) {
        Scanner* scanner = static_cast<Scanner*>(payload);
        if (length == 0) {
            scanner->attached_modifiers.clear();
            return;
        }
        size_t head = 0;
        scanner->single_line_mode = buffer[head++];
    }
}
