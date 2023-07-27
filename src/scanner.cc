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

using namespace std;

enum TokenType : char {
    WHITESPACE,

    HEADING,
    UNORDERED_LIST,
    ORDERED_LIST,
    QUOTE,

    WEAK_DELIMITING_MODIFIER,

    BOLD_OPEN,
    ITALIC_OPEN,
    STRIKETHROUGH_OPEN,
    UNDERLINE_OPEN,
    SPOILER_OPEN,
    SUPERSCRIPT_OPEN,
    SUBSCRIPT_OPEN,
    VERBATIM_OPEN,
    NULL_MODIFIER_OPEN,
    INLINE_MATH_OPEN,
    INLINE_MACRO_OPEN,

    BOLD_CLOSE,
    ITALIC_CLOSE,
    STRIKETHROUGH_CLOSE,
    UNDERLINE_CLOSE,
    SPOILER_CLOSE,
    SUPERSCRIPT_CLOSE,
    SUBSCRIPT_CLOSE,
    VERBATIM_CLOSE,
    NULL_MODIFIER_CLOSE,
    INLINE_MATH_CLOSE,
    INLINE_MACRO_CLOSE,

    DEDENT,
};

struct Scanner {
    TSLexer* lexer;
    std::unordered_map<char, std::vector<uint16_t>> indents;
    std::unordered_map<int32_t, TokenType> attached_modifiers = { {'*', BOLD_OPEN}, {'/', ITALIC_OPEN}, {'_', UNDERLINE_OPEN}, {'-', STRIKETHROUGH_OPEN}, {'%', NULL_MODIFIER_OPEN}, {'`', VERBATIM_OPEN}, {'!', SPOILER_OPEN}, {'&', INLINE_MACRO_OPEN} };

    bool is_whitespace(int32_t character) {
        return iswspace(character) && character != '\n' && character != '\r';
    }

    int32_t get_valid_symbol(const bool* valid_symbols, size_t start, size_t end) {
        for (; start <= end; start++) {
            if (valid_symbols[start])
                return start;
        }

        return -1;
    }

    bool scan(const bool *valid_symbols) {
        if (lexer->eof(lexer))
            return false;

        if (lexer->get_column(lexer) == 0) {
            if (is_whitespace(lexer->lookahead)) {
                while (is_whitespace(lexer->lookahead))
                    advance();

                lexer->result_symbol = WHITESPACE;
                return true;
            }
        }

        if ((valid_symbols[HEADING] && lexer->lookahead == '*') || (valid_symbols[UNORDERED_LIST] && lexer->lookahead == '-') || (valid_symbols[ORDERED_LIST] && lexer->lookahead == '~') || (valid_symbols[QUOTE] && lexer->lookahead == '>')) {
            int32_t character = lexer->lookahead;
            std::vector<uint16_t>& indent_vector = indents[lexer->lookahead];
            size_t count = 0;
            lexer->mark_end(lexer);

            while (lexer->lookahead == character) {
                count++;
                advance();
            }

            if (!is_whitespace(lexer->lookahead)) {
                if (character == '-' && count >= 2 && (lexer->lookahead == '\n' || lexer->lookahead == '\r')) {
                    // Advance past the newline as well.
                    advance();
                    lexer->mark_end(lexer);
                    lexer->result_symbol = WEAK_DELIMITING_MODIFIER;
                    return true;
                }
                else {
                    std::unordered_map<int32_t, TokenType>::iterator iter = attached_modifiers.find(character);

                    if (iter != attached_modifiers.end() && count == 1) {
                        lexer->mark_end(lexer);
                        lexer->result_symbol = iter->second;
                        return true;
                    }
                }

                return false;
            }

            if (valid_symbols[DEDENT] && !indent_vector.empty() && count <= indent_vector.back()) {
                indent_vector.pop_back();
                lexer->result_symbol = DEDENT;
                return true;
            } else {
                indent_vector.push_back(count);
                lexer->mark_end(lexer);
                switch (character) {
                    case '*': lexer->result_symbol = HEADING; break;
                    case '-': lexer->result_symbol = UNORDERED_LIST; break;
                    case '~': lexer->result_symbol = ORDERED_LIST; break;
                    case '>': lexer->result_symbol = QUOTE; break;
                }
                return true;
            }
        }

        int32_t valid_closing_symbol = get_valid_symbol(valid_symbols, BOLD_CLOSE, INLINE_MACRO_CLOSE);

        if (valid_closing_symbol != -1 && !is_whitespace(lexer->lookahead)) {
            std::unordered_map<int32_t, TokenType>::iterator iter = attached_modifiers.find(lexer->lookahead);

            // NOTE: It's possible that this gets executed despite the next character not being tied to the "expected"
            // valid_symbol from the valid_symbols list. I.e. we could be looking ahead to a `*` but succeeding in parsing
            // this because valid_symbols[ITALIC_CLOSE] is valid.
            // This is also why we get errors on a single closing bold modifier. It shouldn't be being parsed, but because
            // we are already in the context of e.g. an italic then we are theoretically looking for any valid attached modifier
            // character.

            if (iter == attached_modifiers.end()) {
                advance();
                iter = attached_modifiers.find(lexer->lookahead);
            }

            if (iter != attached_modifiers.end()) {
                if (!valid_symbols[iter->second + (INLINE_MACRO_OPEN - BOLD_OPEN) + 1])
                    return false;

                advance();

                // ensure it is not a double modifier
                if (iswspace(lexer->lookahead) || iswpunct(lexer->lookahead) && (lexer->lookahead != iter->first)) {
                    lexer->mark_end(lexer);
                    lexer->result_symbol = iter->second + (INLINE_MACRO_OPEN - BOLD_OPEN) + 1;
                    return true;
                }

                return false;
            }

            return false;
        }

        int32_t valid_opening_symbol = get_valid_symbol(valid_symbols, BOLD_OPEN, INLINE_MACRO_OPEN);

        if (valid_opening_symbol != -1 && (is_whitespace(lexer->lookahead) || iswpunct(lexer->lookahead))) {
            std::unordered_map<int32_t, TokenType>::iterator iter = attached_modifiers.find(lexer->lookahead);

            if (iter == attached_modifiers.end()) {
                advance();
                iter = attached_modifiers.find(lexer->lookahead);
            }

            if (iter != attached_modifiers.end()) {
                advance();

                // The second check also ensures that a double modifier is not considered valid.
                // Recall that it should be dismissed in all cases as per the specification.
                if (!is_whitespace(lexer->lookahead)) {
                    // TODO:
                    // if (lexer->lookahead != iter->first) {
                    //     advance();
                    //     lexer->mark_end(lexer);
                    //     return false;
                    // }

                    lexer->result_symbol = iter->second;
                    lexer->mark_end(lexer);
                    return true;
                }

                return false;
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
        Scanner* scanner = static_cast<Scanner*>(payload);

        size_t total_size = 0;

        for (const std::pair<char, std::vector<uint16_t>>& kv : scanner->indents) {
            uint16_t size = kv.second.size();
            buffer[total_size] = kv.first;

            std::memcpy(&buffer[total_size + 1], &size, sizeof(size));
            std::memcpy(&buffer[total_size + 3], kv.second.data(), size * sizeof(size));

            total_size += (size * sizeof(size)) + 3;
        }

        return total_size;
    }

    void tree_sitter_norg_external_scanner_deserialize(void *payload,
            const char *buffer,
            unsigned length) {
        if (length == 0)
            return;

        Scanner* scanner = static_cast<Scanner*>(payload);

        size_t head = 0;

        while (head < length) {
            char key = buffer[head];
            uint16_t len = 0;
            std::memcpy(&len, &buffer[head + 1], sizeof(len));

            scanner->indents[key].resize(len);
            std::memcpy(scanner->indents[key].data(), &buffer[head + 3], len * sizeof(uint16_t));
            head += (len * sizeof(uint16_t)) + 3;
        }
    }
}
