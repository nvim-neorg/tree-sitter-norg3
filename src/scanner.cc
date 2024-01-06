#include <bitset>
#include <cwctype>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <ratio>
#include <unordered_map>
#include <vector>
#include <list>
#include <deque>

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
    FAILED_CLOSE,
    NEWLINE,
    DESC_CLOSE,
    CURLY_CLOSE,
    INSIDE_VERBATIM,

    PUNCTUATION,

    NOT_OPEN,
    NOT_CLOSE,

    FREE_FORM_OPEN,
    FREE_FORM_CLOSE,

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

    INLINE_COMMENT_OPEN,
    INLINE_COMMENT_CLOSE,

    VERBATIM_OPEN,
    VERBATIM_CLOSE,

    INLINE_MATH_OPEN,
    INLINE_MATH_CLOSE,

    INLINE_MACRO_OPEN,
    INLINE_MACRO_CLOSE,

    HEADING,
    UNORDERED_LIST,

    WEAK_DELIMITING_MODIFIER,
    DEDENT,
    INDENT_SEGMENT_END,

    ERROR_SENTINEL,
};

TokenType char_to_attached_mod(int32_t c) {
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
        case '%':
            return INLINE_COMMENT_OPEN;
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
    std::unordered_map< char, std::vector<uint16_t> > indents;
    std::deque<TokenType> att_deque;

    bool single_line_mode;

    Scanner() {
        single_line_mode = false;
    }

    /**
     * Returns `true` if the character provided is a separator character (but not a newline).
     */
    bool is_whitespace(int32_t character) {
        return iswspace(character) && character != '\n' && character != '\r';
    }
    /**
     * Returns `true` if the character provided is neither whitespace nor punctuation
     */
    bool is_word(int32_t character) {
        return character && !iswspace(character) && !iswpunct(character);
    }
    /**
     * Returns `true` if the character provided is either \n or \r
     */
    bool is_newline(int32_t character) {
        return character == '\n' || character == '\r';
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

    bool did_open(TokenType kind) {
        return std::find(att_deque.begin(), att_deque.end(), kind) != att_deque.end();
    }

    /**
     * we parse free_form_close from here to return `_failed_close` before
     */
    bool scan_free_form_close(const bool *valid_symbols, int32_t character) {
        const TokenType kind_token = char_to_attached_mod(lexer->lookahead);
        const TokenType close_token = (TokenType)(kind_token + 1);
        if (kind_token != 0
            && (valid_symbols[FREE_FORM_CLOSE]
                || valid_symbols[FAILED_CLOSE] && did_open(FREE_FORM_OPEN))
            && did_open(kind_token)
            // && attached_modifiers[kind_token]
        ) {
            if (!valid_symbols[FAILED_CLOSE]) lexer->mark_end(lexer);
            advance();
            if (!is_word(lexer->lookahead)) {
                if (valid_symbols[FAILED_CLOSE]) {
                    const TokenType fail_type = att_deque.front();
                    att_deque.pop_front();
                    lexer->result_symbol = FAILED_CLOSE;
                    return true;
                }
                if (valid_symbols[FREE_FORM_CLOSE] && att_deque.front() == FREE_FORM_OPEN && att_deque[1] == kind_token) {
                    lexer->result_symbol = FREE_FORM_CLOSE;
                    att_deque.pop_front();
                    return true;
                }
            }
            return false;
        }
        if (valid_symbols[FREE_FORM_OPEN]) {
            lexer->mark_end(lexer);
            lexer->result_symbol = FREE_FORM_OPEN;
            att_deque.push_front(FREE_FORM_OPEN);
            return true;
        }
        return false;
    }

    /**
     * this function may advance more than one character
     * put this at the bottom of `scan()`
     */
    bool scan_attached_modifier(const bool *valid_symbols, int32_t character) {
        bool link_mod_left = false;
        if (character == ':' && valid_symbols[NOT_OPEN]) {
            character = lexer->lookahead;
            advance();
            link_mod_left = true;
        }
        const TokenType kind_token = char_to_attached_mod(character);
        const TokenType close_token = (TokenType)(kind_token + 1);
        if ((kind_token == 0)
            // 5th case in link-mod-00
            || (link_mod_left && valid_symbols[close_token])
            // repeated modifier
            || (lexer->lookahead == character))
            return false;

        // NOT_CLOSE
        if (valid_symbols[NOT_CLOSE] && valid_symbols[close_token]
            && !valid_symbols[kind_token]
        ) {
            lexer->mark_end(lexer);
            lexer->result_symbol = NOT_CLOSE;
            return true;
        }

        // _CLOSE
        const bool valid_failed_close = valid_symbols[FAILED_CLOSE]
            && att_deque.front() != kind_token;
        const bool valid_att_close = valid_symbols[close_token];
        if (
            !is_word(lexer->lookahead) &&
            !valid_symbols[NOT_CLOSE] &&
            did_open(kind_token) &&
            (valid_att_close || valid_failed_close)
        ) {
            if (valid_failed_close && (kind_token < VERBATIM_OPEN)
                && att_deque[1] != FREE_FORM_OPEN
            ) {
                const TokenType fail_type = att_deque.front();
                att_deque.pop_front();
                // std::cout << "pop" << std::endl;
                lexer->result_symbol = FAILED_CLOSE;
                return true;
            }
            // pop until matching kind
            // this doesn't happen in most cases, but when there was non-verbatim
            // opener in completed verbatim, parser should remove those from stack
            while (att_deque.front() != kind_token) {
                // don't skip FREE_FORM here
                if (att_deque.front() == FREE_FORM_OPEN) {
                    return false;
                }
                att_deque.pop_front();
            }
            att_deque.pop_front();
            lexer->result_symbol = close_token;
            lexer->mark_end(lexer);
            if (lexer->lookahead == ':') {
                advance();
                if (is_word(lexer->lookahead)) {
                    lexer->mark_end(lexer);
                }
            }
            // if (att_deque.front() == kind_token) {
            //     return true;
            // } else {
                // std::cout << "faaail" << std::endl;
            //     return false;
            // }
            return true;
        }
        // NOT_OPEN
        if (!link_mod_left && valid_symbols[NOT_OPEN]) {
            // there can be NOT_OPEN even when BOLD_CLOSE is valid.
            // see att-11 for example
            lexer->mark_end(lexer);
            lexer->result_symbol = NOT_OPEN;
            return true;
        }
        // _OPEN
        const bool can_open = (att_deque.empty() || !did_open(kind_token));
        if (
            // this is needed for att-25
            // but causes lot of problems like att-24
            // search from att_deque instead
            // attached_modifiers[kind_token] == 0 &&
            can_open &&
            valid_symbols[kind_token] && lexer->lookahead && !iswspace(lexer->lookahead)
        ) {
            lexer->mark_end(lexer);
            // // solves free-02 and att-16:
            // // check if valid [free-form-]close token follows
            // bool is_free_form = false;
            // if (lexer->lookahead == '|') {
            //     is_free_form  = true;
            //     skip();
            // }
            const int32_t next_char = lexer->lookahead;
            const TokenType next_token = char_to_attached_mod(next_char);
            if (next_token != 0 && did_open(next_token)) {
                advance();
                if (!lexer->lookahead || !is_word(lexer->lookahead) && lexer->lookahead != next_char) {
                    lexer->result_symbol = PUNCTUATION;
                    return true;
                }
            }

            att_deque.push_front(kind_token);
            lexer->result_symbol = kind_token;
            return true;
        }

        return false;
    }

    bool scan_detached_modifier(const bool *valid_symbols, int32_t character, TokenType kind) {
        std::vector<uint16_t>& indent_vector = indents[character];
        size_t count = 1;
        while (lexer->lookahead == character) {
            count++;
            advance();
        }

        // Every detached modifier must be immediately followed by whitespace. If it is not, return false.
        if (!is_whitespace(lexer->lookahead)) {
            // There is an edge case that can be parsed here however - the weak delimiting modifier may
            // consist of two or more `-` characters, and must be immediately succeeded with a newline.
            // If those criteria are met, return the `WEAK_DELIMITING_MODIFIER` instead.
            if (character == '-' && count >= 2 && is_newline(lexer->lookahead)) {
                // Advance past the newline as well.
                advance_newline();

                // FIXME: weak delimiting modifier should be able to used with other detached modifiers
                if (!valid_symbols[INDENT_SEGMENT_END])
                    indents['*'].pop_back();
                // When `mark_end()` is called again we essentially move the previous checkpoint to the new "head".
                lexer->mark_end(lexer);
                lexer->result_symbol = WEAK_DELIMITING_MODIFIER;
                return true;
            }

            return false;
        }

        if (valid_symbols[DEDENT] && !indent_vector.empty() && count <= indent_vector.back()) {
            indent_vector.pop_back();
            lexer->result_symbol = DEDENT;
            return true;
        }

        indent_vector.push_back(count);
        lexer->mark_end(lexer);
        lexer->result_symbol = kind;
        if (kind == HEADING)
            single_line_mode = true;
        return true;
    }

    bool scan_newline(const bool *valid_symbols) {
        while (is_whitespace(lexer->lookahead))
            skip();
        if (is_newline(lexer->lookahead)) {
            advance();
            if (!valid_symbols[FAILED_CLOSE]) {
                lexer->mark_end(lexer);
            }

            if (valid_symbols[NEWLINE]) {
                // cancel single-line, this occurs when heading has slide/indent_segment prefixs
                single_line_mode = false;
                lexer->result_symbol = NEWLINE;
                return true;
            }
            // when parsing single-line paragraph (aka. title,) return paragraph break immediately
            if (single_line_mode) {
                if (valid_symbols[FAILED_CLOSE]) {
                    const TokenType fail_type = att_deque.front();
                    att_deque.pop_front();
                    lexer->result_symbol = FAILED_CLOSE;
                    return true;
                }
                single_line_mode = false;
                lexer->result_symbol = PARAGRAPH_BREAK;
                return true;
            }

            while (is_whitespace(lexer->lookahead))
                skip();
            if (lexer->eof(lexer) || is_newline(lexer->lookahead)) {
                if (valid_symbols[FAILED_CLOSE]) {
                    const TokenType fail_type = att_deque.front();
                    att_deque.pop_front();
                    lexer->result_symbol = FAILED_CLOSE;
                    return true;
                }
                lexer->result_symbol = PARAGRAPH_BREAK;
                att_deque.clear();
                return true;
            }
            if (lexer->lookahead == '*' || lexer->lookahead == '-' || lexer->lookahead == '_' || lexer->lookahead == '=') {
                int32_t character = lexer->lookahead;
                skip();
                size_t count = 1;
                while (lexer->lookahead == character) {
                    count++;
                    skip();
                }
                if (iswspace(lexer->lookahead)) {
                    if (valid_symbols[FAILED_CLOSE]) {
                        const TokenType fail_type = att_deque.front();
                        att_deque.pop_front();
                        lexer->result_symbol = FAILED_CLOSE;
                        return true;
                    }
                    lexer->result_symbol = PARAGRAPH_BREAK;
                    att_deque.clear();
                    return true;
                }
            }
        }
        return false;
    }

    bool scan(const bool *valid_symbols) {
        // the external scanner don't try any recovery
        // if (valid_symbols[ERROR_SENTINEL]) {
        //     return false;
        // }

        // We return false here to allow the lexer to fall back
        // to the grammar, which allows the existence of `\0`.
        if (lexer->eof(lexer)) {
            if (valid_symbols[FAILED_CLOSE]) {
                lexer->result_symbol = FAILED_CLOSE;
                return true;
            }
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

        lexer->mark_end(lexer);
        if (iswspace(lexer->lookahead))
            return scan_newline(valid_symbols);

        if (valid_symbols[INSIDE_VERBATIM] && (lexer->lookahead == ']' || lexer->lookahead == '}')) {
            advance();
            lexer->mark_end(lexer);
            lexer->result_symbol = PUNCTUATION;
            return true;
        }
        if (lexer->lookahead == ']') {
            if (valid_symbols[DESC_CLOSE]) {
                advance();
                lexer->mark_end(lexer);
                lexer->result_symbol = DESC_CLOSE;
                return true;
            }
            if (valid_symbols[FAILED_CLOSE]) {
                const TokenType fail_type = att_deque.front();
                att_deque.pop_front();
                lexer->result_symbol = FAILED_CLOSE;
                return true;
            }
            return false;
        }
        if (lexer->lookahead == '}') {
            if (valid_symbols[CURLY_CLOSE]) {
                advance();
                lexer->mark_end(lexer);
                lexer->result_symbol = CURLY_CLOSE;
                return true;
            }
            if (valid_symbols[FAILED_CLOSE]) {
                const TokenType fail_type = att_deque.front();
                att_deque.pop_front();
                lexer->result_symbol = FAILED_CLOSE;
                return true;
            }
            return false;
        }

        // take one lookahead first as we need at least two lookahead to distinguish
        // detached modifiers from others (e.g. heading_prefix and bold_open)
        lexer->mark_end(lexer);
        const int32_t character = lexer->lookahead;
        advance();

        if (valid_symbols[HEADING] && character == '*' && (lexer->lookahead == '*' || is_whitespace(lexer->lookahead)))
            return scan_detached_modifier(valid_symbols, character, HEADING);
        if ((valid_symbols[UNORDERED_LIST] || valid_symbols[WEAK_DELIMITING_MODIFIER]) && character == '-' && (lexer->lookahead == '-' || is_whitespace(lexer->lookahead)))
            return scan_detached_modifier(valid_symbols, character, UNORDERED_LIST);

        // TODO: add other detached modifiers

        if (character == '|')
            return scan_free_form_close(valid_symbols, character);

        // this should be end of scan() because attached modifiers need more than two lookaheads
        return scan_attached_modifier(valid_symbols, character);
    }

    void skip() { lexer->advance(lexer, true); }
    void advance() { lexer->advance(lexer, false); }
    void advance_newline() {
        if (lexer->lookahead == '\r') {
            advance();
            if (lexer->lookahead == '\n' && !lexer->eof(lexer)) advance();
        } else {
            advance();
        }
    }
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
        buffer[total_size++] = scanner->att_deque.size();

        for (std::deque<TokenType>::iterator v = scanner->att_deque.begin(); v != scanner->att_deque.end(); ++v) {
            TokenType a = *v;
            buffer[total_size++] = a;
        }

        buffer[total_size++] = scanner->single_line_mode;

        // NOTE: We cannot use range-based for loops as they are a post C++11 addition. Fun.
        for (std::unordered_map< char, std::vector<uint16_t> >::iterator kv = scanner->indents.begin(); kv != scanner->indents.end(); ++kv) {
            uint16_t size = kv->second.size();
            buffer[total_size] = kv->first;

            std::memcpy(&buffer[total_size + 1], &size, sizeof(size));
            std::memcpy(&buffer[total_size + 3], kv->second.data(), size * sizeof(size));

            total_size += (size * sizeof(size)) + 3;
        }

        return total_size;
    }

    void tree_sitter_norg_external_scanner_deserialize(void *payload,
            const char *buffer,
            unsigned length) {
        Scanner* scanner = static_cast<Scanner*>(payload);
        if (length == 0) {
            scanner->att_deque.clear();
            return;
        }
        scanner->att_deque.clear();
        size_t head = 0;
        size_t d_size = buffer[head++];
        while (head < d_size+1) {
            scanner->att_deque.push_back((TokenType)(buffer[head++]));
        }

        scanner->single_line_mode = buffer[head++];

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
