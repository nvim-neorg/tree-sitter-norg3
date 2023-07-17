#include <cwctype>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <vector>

#include "tree_sitter/parser.h"

using namespace std;

enum TokenType : char {
    WHITESPACE,

    HEADING,
    UNORDERED_LIST,
    ORDERED_LIST,
    QUOTE,
    DEDENT,
};

struct Scanner {
    TSLexer* lexer;
    std::unordered_map<char, std::vector<int16_t>> indents;

    bool scan(const bool *valid_symbols) {
        if (lexer->eof(lexer))
            return false;

        // TODO: Maybe remove this part from the scanner? Is it doable?
        if (lexer->get_column(lexer) == 0) {
            const bool found_whitespace = iswspace(lexer->lookahead) && lexer->lookahead != '\n' && lexer->lookahead != '\r';

            if (found_whitespace) {
                while (iswspace(lexer->lookahead) && lexer->lookahead != '\n' && lexer->lookahead != '\r')
                    advance();

                lexer->result_symbol = WHITESPACE;
                return true;
            }
        }

        if ((valid_symbols[HEADING] && lexer->lookahead == '*') || (valid_symbols[UNORDERED_LIST] && lexer->lookahead == '-') || (valid_symbols[ORDERED_LIST] && lexer->lookahead == '~') || (valid_symbols[QUOTE] && lexer->lookahead == '>')) {
            int32_t character = lexer->lookahead;
            auto& indent_vector = indents[lexer->lookahead];
            size_t count = 0;
            lexer->mark_end(lexer);

            while (lexer->lookahead == character) {
                count++;
                advance();
            }

            if (!iswspace(lexer->lookahead))
                return false;

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
        auto scanner = static_cast<Scanner*>(payload);

        size_t total_size = 0;

        for (const auto& kv : scanner->indents) {
            int16_t size = kv.second.size();
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

        auto scanner = static_cast<Scanner*>(payload);

        size_t head = 0;

        while (head < length) {
            char key = buffer[head];
            int16_t len = 0;
            std::memcpy(&len, &buffer[head + 1], sizeof(len));

            scanner->indents[key].resize(len);
            std::memcpy(scanner->indents[key].data(), &buffer[head + 3], len * sizeof(int16_t));
            head += (len * sizeof(int16_t)) + 3;
        }
    }
}
