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
    DEDENT,
};

struct Scanner {
    TSLexer* lexer;
    std::vector<int16_t> headings;

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

        // TODO: Generalize
        if (valid_symbols[HEADING] && lexer->lookahead == '*') {
            size_t count = 0;
            lexer->mark_end(lexer);

            while (lexer->lookahead == '*') {
                count++;
                advance();
            }

            if (!iswspace(lexer->lookahead))
                return false;

            if (valid_symbols[DEDENT] && count <= headings.back()) {
                headings.pop_back();
                lexer->result_symbol = DEDENT;
                return true;
            } else {
                headings.push_back(count);
                lexer->mark_end(lexer);
                lexer->result_symbol = HEADING;
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

        size_t total_size = scanner->headings.size() * sizeof(int16_t);
        std::memcpy(buffer, scanner->headings.data(), total_size);

        return total_size;
    }

    void tree_sitter_norg_external_scanner_deserialize(void *payload,
            const char *buffer,
            unsigned length) {
        if (length == 0)
            return;

        auto scanner = static_cast<Scanner*>(payload);
        scanner->headings.resize(length / sizeof(int16_t));
        std::memcpy(scanner->headings.data(), buffer, length);
    }
}
