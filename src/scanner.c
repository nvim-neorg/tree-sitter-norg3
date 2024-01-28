#include <stdio.h>
#include <string.h>
#include <wctype.h>

#include "tree_sitter/parser.h"

// #define DEBUG

#ifdef DEBUG
	#define unreachable() fprintf(stderr, "unreachable src/scanner.c:%d\n", __LINE__)
	#define assert(a, ...) \
		if (!(a)) {\
			fprintf(stderr, __VA_ARGS__);\
			exit(EXIT_FAILURE);\
		}
    #define LOG(...) \
            printf("log[%d]: ", __LINE__);\
            printf(__VA_ARGS__);
#else
	#define unreachable() while (false);
	#define assert(a, ...) while (false);
    #define LOG(...) while (false);
#endif

#define lex_next self->lexer->lookahead

#define lex_eof self->lexer->eof(self->lexer)

#define lex_column self->lexer->get_column(self->lexer)

#define lex_mark_end() \
    self->lexer->mark_end(self->lexer)

#define lex_set_result(result) \
    self->lexer->result_symbol = result

#define lex_advance() \
	self->lexer->advance(self->lexer, false)

#define lex_skip() \
	self->lexer->advance(self->lexer, true)

#define lex_advance_newline() \
    if (lex_next == '\r') { \
        lex_advance(); \
        if (lex_next == '\n' && !lex_eof) lex_advance(); \
    } else { \
        lex_advance(); \
    }

// vec<u32> ////////////////////////////////////////////////////////////////////
typedef struct vec_u32 vec_u32;
struct vec_u32 {
	size_t cap;
	size_t len;
	uint32_t* vec;
};
static struct vec_u32 vec_u32_new() {
	return (struct vec_u32) {.cap = 0, .len = 0, .vec = NULL};
}
static void vec_u32_drop(struct vec_u32 self) {
	if (self.vec != NULL) {
		free(self.vec);
	}
}
static void vec_u32_clear(struct vec_u32* self) {
    if (self->vec != NULL) {
        free(self->vec);
    }
    self->cap = 0;
    self->len = 0;
    self->vec = NULL;
}
static void vec_u32_push(struct vec_u32* self, uint32_t value) {
	assert(self != NULL, "vec_u32_push");
	if (self->len + 1 > self->cap) {
		self->cap = self->len + 8;
		self->vec = realloc(self->vec, sizeof(uint32_t) * self->cap);
		if (self->vec == NULL) {
			fprintf(stderr, "vec_u32_push: malloc failed\n");
			exit(EXIT_FAILURE);
		}
	}
	self->vec[self->len++] = value;
}
static uint32_t vec_u32_pop(struct vec_u32* self) {
	assert(self != NULL, "vec_u32_pop");
	if (self->len < 1) {
        fprintf(stderr, "vec_u32_pop: empty vec\n");
        exit(EXIT_FAILURE);
	}
	return self->vec[self->len--];
}
static uint32_t vec_u32_back(struct vec_u32* self) {
	assert(self != NULL, "vec_u32_back");
	if (self->len < 1) {
        fprintf(stderr, "vec_u32_back: empty vec\n");
        exit(EXIT_FAILURE);
	}
	return self->vec[self->len - 1];
}
static uint32_t vec_u32_back_or(struct vec_u32* self, uint32_t fallback) {
	assert(self != NULL, "vec_u32_back");
	if (self->len < 1) {
        return fallback;
	}
	return self->vec[self->len - 1];
}
static bool vec_u32_empty(struct vec_u32* self) {
    return (self->len == 0);
}
static bool vec_u32_has(struct vec_u32* self, const uint32_t kind) {
	assert(self != NULL, "vec_u32_has");
    for (size_t i = 0; i < self->len; i++) {
        if (self->vec[i] == kind) {
            return true;
        }
    }
    return false;
}
static size_t vec_u32_serialize(struct vec_u32* self, char* buffer) {
	assert(self != NULL, "vec_u32_serialize");
	size_t written = 0;
	memcpy(buffer, &self->len, sizeof self->len);
	written += sizeof self->len;
	if (self->len > 0) {
		memcpy(buffer + written, self->vec, self->len * sizeof(uint32_t));
		written += self->len * sizeof(uint32_t);
	}
	return written;
}
static size_t vec_u32_deserialize(struct vec_u32* self, const char* buffer) {
	assert(self != NULL, "vec_u32_deserialize");
	size_t read = 0;
	memcpy(&self->len, buffer, sizeof self->len);
	read += sizeof self->len;
	if (self->len > self->cap) {
		self->cap = self->len;
		self->vec = realloc(self->vec, sizeof(uint32_t) * self->cap);
		if (self->vec == NULL) {
			fprintf(stderr, "vec_u32_deserialize: malloc failed\n");
			exit(EXIT_FAILURE);
		}
	}
	if (self->len > 0) {
		memcpy(self->vec, buffer + read, self->len * sizeof *self->vec);
		read += self->len * sizeof *self->vec;
	}
	return read;
}
//////////////////////////////////////////////////////////////////// vec<u32> //

typedef enum token_type token_type;

enum token_type {
    WHITESPACE,

    PARAGRAPH_BREAK,
    NEWLINE,
    FAILED_CLOSE,
    FLAG_INSIDE_VERBATIM,

    PUNCTUATION,

    DESC_OPEN,
    DESC_CLOSE,
    TARGET_OPEN,
    TARGET_CLOSE,

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
    FLAG_INDENT_SEGMENT_END,

    ERROR_MODE,
};

typedef enum {
    ACCEPT,
    FAIL,
    SCAN_SKIP, // "SKIP" conflicts with <parser.h>
} Action;

#define TRY_SCAN(action) \
    switch (action) {\
        case SCAN_SKIP:\
            break;\
        case ACCEPT:\
            return true;\
        case FAIL:\
            return false;\
    }

token_type char_to_attached_mod(int32_t c) {
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

token_type char_to_detached_mod(int32_t c) {
    switch (c) {
        case '*':
            return HEADING;
        case '-':
            return UNORDERED_LIST;
    }
    return WHITESPACE;
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
 * Returns `true` if the character provided is a separator character (but not a newline).
 */
bool is_whitespace(int32_t character) {
    return iswspace(character) && !is_newline(character);
}

static bool is_free_form(vec_u32* att_stack, const token_type kind) {
    for (size_t i = 0; i < att_stack->len; i++) {
        if (att_stack->vec[i] == kind) {
            return ++i < att_stack->len && att_stack->vec[i] == FREE_FORM_OPEN;
        }
    }
    return false;
}

typedef struct Scanner Scanner;

struct Scanner {
    TSLexer* lexer;
    // std::unordered_map< char, std::vector<uint16_t> > indents;
    // std::deque<TokenType> att_deque;
    vec_u32 att_stack;
    vec_u32 indent_heading;
    vec_u32 indent_list;
    bool single_line_mode;
};

bool scan_newline(Scanner *self, const bool *valid_symbols) {
    while (is_whitespace(self->lexer->lookahead))
        lex_skip();

    if (is_newline(lex_next)) {
        lex_advance_newline();
        if (!valid_symbols[FAILED_CLOSE])
            self->lexer->mark_end(self->lexer);

        if (valid_symbols[NEWLINE]) {
            self->single_line_mode = false;
            lex_set_result(NEWLINE);
            return true;
        }
        if (self->single_line_mode) {
            if (valid_symbols[FAILED_CLOSE] && !vec_u32_empty(&self->att_stack)) {
                const token_type fail_type = vec_u32_pop(&self->att_stack);
                lex_set_result(FAILED_CLOSE);
                return true;
            }
            self->single_line_mode = false;
            LOG("paragraph break in single line mode\n");
            lex_set_result(PARAGRAPH_BREAK);
            vec_u32_clear(&self->att_stack);
            return true;
        }

        while (is_whitespace(lex_next))
            lex_skip();
        if (self->lexer->eof(self->lexer) || is_newline(lex_next)) {
            if (valid_symbols[FAILED_CLOSE] && !vec_u32_empty(&self->att_stack)) {
                const token_type fail_type = vec_u32_pop(&self->att_stack);
                lex_set_result(FAILED_CLOSE);
                return true;
            }
            LOG("paragraph break by eof or double newline\n");
            lex_set_result(PARAGRAPH_BREAK);
            vec_u32_clear(&self->att_stack);
            return true;
        }
        const int32_t character = lex_next;
        lex_skip();
        if (char_to_detached_mod(character) != 0 || character == '_' || character == '=') {
            size_t count = 1;
            while (lex_next == character) {
                count++;
                lex_skip();
            }
            if (iswspace(lex_next)) {
                if (valid_symbols[FAILED_CLOSE] && !vec_u32_empty(&self->att_stack)) {
                    const token_type fail_type = vec_u32_pop(&self->att_stack);
                    lex_set_result(FAILED_CLOSE);
                    return true;
                }
                LOG("paragraph break by detached modifier\n");
                lex_set_result(PARAGRAPH_BREAK);
                vec_u32_clear(&self->att_stack);
                return true;
            }
        }
        if ((character == '#'
            || character == '+'
            || character == '.'
            || character == '|'
            || character == '@'
            || character == '=')
            && is_word(lex_next)
        ) {
            if (valid_symbols[FAILED_CLOSE] && !vec_u32_empty(&self->att_stack)) {
                const token_type fail_type = vec_u32_pop(&self->att_stack);
                lex_set_result(FAILED_CLOSE);
                return true;
            }
            LOG("paragraph break by tag prefix\n");
            lex_set_result(PARAGRAPH_BREAK);
            vec_u32_clear(&self->att_stack);
            return true;
        }
    }
    return false;
}

static bool scan_linkable_close(Scanner *self, const bool *valid_symbols, const token_type kind) {
    if (valid_symbols[kind]) {
        lex_advance();
        lex_mark_end();
        lex_set_result(kind);
        vec_u32_pop(&self->att_stack);
        return true;
    }
    if (vec_u32_has(&self->att_stack, (token_type)(kind - 1))
        && valid_symbols[FAILED_CLOSE]
    ) {
        const token_type fail_type = vec_u32_pop(&self->att_stack);
        lex_set_result(FAILED_CLOSE);
        return true;
    }
    return false;
}

Action scan_linkables(Scanner *self, const bool *valid_symbols) {
    LOG("linkable\n");
    if (lex_next == '[' && valid_symbols[DESC_OPEN]) {
        lex_advance();
        lex_mark_end();
        lex_set_result(DESC_OPEN);
        vec_u32_push(&self->att_stack, DESC_OPEN);
        return ACCEPT;
    }
    if (lex_next == '{' && valid_symbols[TARGET_OPEN]) {
        lex_advance();
        lex_mark_end();
        lex_set_result(TARGET_OPEN);
        vec_u32_push(&self->att_stack, TARGET_OPEN);
        LOG("target\n");
        return ACCEPT;
    }
    if (!valid_symbols[FLAG_INSIDE_VERBATIM] && !vec_u32_empty(&self->att_stack)) {
        if (lex_next == ']')
            return scan_linkable_close(self, valid_symbols, DESC_CLOSE) ? ACCEPT : FAIL;
        if (lex_next == '}')
            return scan_linkable_close(self, valid_symbols, TARGET_CLOSE) ? ACCEPT : FAIL;
    }
    return SCAN_SKIP;
}

Action scan_detached_modifier(Scanner *self, const bool *valid_symbols, const int32_t character) {
    const token_type kind = char_to_detached_mod(character);
    const bool is_weak_deli_valid = character == '-' && valid_symbols[WEAK_DELIMITING_MODIFIER];
    if (kind == 0
        || !(valid_symbols[kind] || is_weak_deli_valid)
        || !(lex_next == character || is_whitespace(lex_next))
    ) return SCAN_SKIP;

    vec_u32 *indent_vec = kind == HEADING ? &self->indent_heading : &self->indent_list;
    size_t count = 1;
    while (lex_next == character) {
        count++;
        lex_advance();
    }

    // Every detached modifier must be immediately followed by whitespace. If it is not, return false.
    if (!is_whitespace(lex_next)) {
        // There is an edge case that can be parsed here however - the weak delimiting modifier may
        // consist of two or more `-` characters, and must be immediately succeeded with a newline.
        // If those criteria are met, return the `WEAK_DELIMITING_MODIFIER` instead.
        if (character == '-' && count >= 2 && is_newline(lex_next)) {
            // Advance past the newline as well.
            lex_advance_newline();

            if (!valid_symbols[FLAG_INDENT_SEGMENT_END])
                vec_u32_pop(&self->indent_heading);
            // When `mark_end()` is called again we essentially move the previous checkpoint to the new "head".
            lex_mark_end();
            lex_set_result(WEAK_DELIMITING_MODIFIER);
            return ACCEPT;
        }
        return FAIL;
    }

    if (valid_symbols[DEDENT] && !vec_u32_empty(indent_vec) && count <= vec_u32_back(indent_vec)) {
        vec_u32_pop(indent_vec);
        lex_set_result(DEDENT);
        return ACCEPT;
    }

    vec_u32_push(indent_vec, count);
    lex_mark_end();
    lex_set_result(kind);
    self->single_line_mode = (kind == HEADING);

    return ACCEPT;
}

bool scan_free_form_close(Scanner *self, const bool *valid_symbols, const int32_t character) {
    const token_type kind_token = char_to_attached_mod(lex_next);
    const token_type close_token = (token_type)(kind_token + 1);
    if (kind_token != 0
        && (valid_symbols[FREE_FORM_CLOSE]
            || valid_symbols[FAILED_CLOSE] && vec_u32_has(&self->att_stack, FREE_FORM_OPEN))
        && vec_u32_has(&self->att_stack, kind_token)
    ) {
        if (!valid_symbols[FAILED_CLOSE])
            lex_mark_end();
        lex_advance();
        if (!is_word(lex_next)) {
            if (valid_symbols[FAILED_CLOSE]) {
                const token_type fail_type = vec_u32_pop(&self->att_stack);
                lex_set_result(FAILED_CLOSE);
                return true;
            }
            if (valid_symbols[FREE_FORM_CLOSE]
                && vec_u32_back_or(&self->att_stack, 0) == FREE_FORM_OPEN
                && self->att_stack.vec[self->att_stack.len - 2] == kind_token
            ) {
                lex_set_result(FREE_FORM_CLOSE);
                vec_u32_pop(&self->att_stack);
                return true;
            }
        }
        return false;
    }
    if (valid_symbols[FREE_FORM_OPEN]) {
        lex_mark_end();
        lex_set_result(FREE_FORM_OPEN);
        vec_u32_push(&self->att_stack, FREE_FORM_OPEN);
        return true;
    }
    return false;
}

bool scan_attached_modifier(Scanner *self, const bool *valid_symbols, int32_t character) {
    bool link_mod_left = false;
    if (character == ':' && valid_symbols[NOT_OPEN]) {
        character = lex_next;
        lex_advance();
        link_mod_left = true;
    }
    const token_type kind_token = char_to_attached_mod(character);
    const token_type close_token = (token_type)(kind_token + 1);
    if (kind_token == 0
        // 5th case in link-mod-00
        || (link_mod_left && vec_u32_has(&self->att_stack, kind_token))
        // repeated modifier
        || (lex_next == character)) {
        LOG("fail scan_attached_modifier\n");
        return false;
    }

    // _CLOSE
    const bool valid_failed_close = valid_symbols[FAILED_CLOSE] && vec_u32_back_or(&self->att_stack, 0) != kind_token;
    if (!valid_symbols[NOT_CLOSE]
        && (valid_symbols[close_token] || valid_failed_close)
        && !is_word(lex_next)
        && vec_u32_has(&self->att_stack, kind_token)
    ) {
        if (valid_failed_close
            && (kind_token < VERBATIM_OPEN)
            // check if its' not free-form markup to check free-16
            && !is_free_form(&self->att_stack, kind_token)
        ) {
            const token_type fail_type = vec_u32_pop(&self->att_stack);
            lex_set_result(FAILED_CLOSE);
            return true;
        }
        while (vec_u32_back_or(&self->att_stack, 0) != kind_token) {
            // don't skip FREE_FORM here
            if (vec_u32_back_or(&self->att_stack, 0) == FREE_FORM_OPEN) {
                LOG("fail scan_attached_modifier\n");
                return false;
            }
            vec_u32_pop(&self->att_stack);
        }
        vec_u32_pop(&self->att_stack);
        lex_set_result(close_token);
        lex_mark_end();
        if (lex_next == ':') {
            lex_advance();
            if (is_word(lex_next)) {
                lex_mark_end();
            }
        }
        return true;
    }
    // _OPEN
    if ((link_mod_left || !valid_symbols[NOT_OPEN])
        && valid_symbols[kind_token]
        && !vec_u32_has(&self->att_stack, kind_token)
        && lex_next && !iswspace(lex_next)
    ) {
        lex_mark_end();
        const int32_t next_char = lex_next;
        const token_type next_token = char_to_attached_mod(next_char);
        if (next_token != 0 && vec_u32_has(&self->att_stack, next_token)) {
            lex_advance();
            if (!lex_next || !is_word(lex_next) && lex_next != next_char) {
                lex_set_result(PUNCTUATION);
                return true;
            }
        }
        vec_u32_push(&self->att_stack, kind_token);
        lex_set_result(kind_token);
        return true;
    }
    LOG("fail scan_attached_modifier\n");
    return false;
}

bool scan(Scanner *self, const bool *valid_symbols) {
    // check if parser is in error-recovery mode
    const bool error_mode = valid_symbols[ERROR_MODE];

    // We return false here to allow the lexer to fall back
    // to the grammar, which allows the existence of `\0`.
    if (lex_eof) {
        if (valid_symbols[FAILED_CLOSE] && !vec_u32_empty(&self->att_stack)) {
            const token_type fail_type = vec_u32_pop(&self->att_stack);
            lex_set_result(FAILED_CLOSE);
            return true;
        }
        if (valid_symbols[PARAGRAPH_BREAK]) {
            lex_set_result(PARAGRAPH_BREAK);
            vec_u32_clear(&self->att_stack);
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
    if (lex_column == 0 && is_whitespace(lex_next)) {
        while (is_whitespace(lex_next))
            lex_advance();

        lex_set_result(WHITESPACE);
        return true;
    }

    lex_mark_end();
    if (iswspace(lex_next))
        return scan_newline(self, valid_symbols);

    TRY_SCAN(scan_linkables(self, valid_symbols));

    const int32_t character = lex_next;
    lex_advance();

    TRY_SCAN(scan_detached_modifier(self, valid_symbols, character));

    // TODO: add tags

    if (character == '|')
        return scan_free_form_close(self, valid_symbols, character);

    return scan_attached_modifier(self, valid_symbols, character);
}

void *tree_sitter_norg_external_scanner_create() {
    LOG("tree_sitter_norg_external_scanner_create\n");
	Scanner* self = malloc(sizeof(Scanner));
    self->att_stack = vec_u32_new();
    self->indent_heading = vec_u32_new();
    self->indent_list = vec_u32_new();
    self->single_line_mode = false;
    return self;
}

void tree_sitter_norg_external_scanner_destroy(void *payload) {
    LOG("tree_sitter_norg_external_scanner_destroy\n");
	struct Scanner* scanner = payload;
	vec_u32_drop(scanner->att_stack);
	vec_u32_drop(scanner->indent_heading);
	vec_u32_drop(scanner->indent_list);
	free(scanner);
}

unsigned tree_sitter_norg_external_scanner_serialize(
	void *payload,
	char *buffer
) {
    LOG("tree_sitter_norg_external_scanner_serialize\n");
	struct Scanner* scanner = payload;
	size_t written = 0;
	written += vec_u32_serialize(&scanner->att_stack, buffer + written);
	written += vec_u32_serialize(&scanner->indent_heading, buffer + written);
	written += vec_u32_serialize(&scanner->indent_list, buffer + written);
	return written;
}

void tree_sitter_norg_external_scanner_deserialize(
	void *payload,
	const char *buffer,
	unsigned length
) {
    LOG("tree_sitter_norg_external_scanner_deserialize\n");
	Scanner* scanner = payload;
    scanner->att_stack.len = 0;
    scanner->indent_heading.len = 0;
    scanner->indent_list.len = 0;
	if (length != 0) {
		size_t read = 0;
		read += vec_u32_deserialize(&scanner->att_stack, buffer + read);
		read += vec_u32_deserialize(&scanner->indent_heading, buffer + read);
		read += vec_u32_deserialize(&scanner->indent_list, buffer + read);
    }
}

bool tree_sitter_norg_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
    LOG("tree_sitter_norg_external_scanner_scan\n");
    Scanner* scanner = payload;
    scanner->lexer = lexer;
    return scan(scanner, valid_symbols);
}
