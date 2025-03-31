#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 37
#define LARGE_STATE_COUNT 6
#define SYMBOL_COUNT 32
#define ALIAS_COUNT 0
#define TOKEN_COUNT 12
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  anon_sym_COLON_COLON_EQ = 1,
  anon_sym_SEMI = 2,
  anon_sym_QMARK = 3,
  anon_sym_PLUS = 4,
  anon_sym_STAR = 5,
  anon_sym_LPAREN = 6,
  anon_sym_RPAREN = 7,
  anon_sym_PIPE = 8,
  anon_sym_SQUOTE = 9,
  sym_stringContent = 10,
  sym_identifier = 11,
  sym_source_file = 12,
  sym_rule = 13,
  sym_lhs = 14,
  sym_rhs = 15,
  sym_sequence = 16,
  sym_statements = 17,
  sym_quantifiedStatement = 18,
  sym_oneOrMore = 19,
  sym_zeroOrMore = 20,
  sym_optional = 21,
  sym_quantifierBase = 22,
  sym_parenthesizedStatement = 23,
  sym_selectionStatement = 24,
  sym_sequenceNoSelection = 25,
  sym_statementsNoSelection = 26,
  sym_terminal = 27,
  aux_sym_source_file_repeat1 = 28,
  aux_sym_sequence_repeat1 = 29,
  aux_sym_selectionStatement_repeat1 = 30,
  aux_sym_sequenceNoSelection_repeat1 = 31,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_COLON_COLON_EQ] = "::=",
  [anon_sym_SEMI] = ";",
  [anon_sym_QMARK] = "\?",
  [anon_sym_PLUS] = "+",
  [anon_sym_STAR] = "*",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_PIPE] = "|",
  [anon_sym_SQUOTE] = "'",
  [sym_stringContent] = "stringContent",
  [sym_identifier] = "identifier",
  [sym_source_file] = "source_file",
  [sym_rule] = "rule",
  [sym_lhs] = "lhs",
  [sym_rhs] = "rhs",
  [sym_sequence] = "sequence",
  [sym_statements] = "statements",
  [sym_quantifiedStatement] = "quantifiedStatement",
  [sym_oneOrMore] = "oneOrMore",
  [sym_zeroOrMore] = "zeroOrMore",
  [sym_optional] = "optional",
  [sym_quantifierBase] = "quantifierBase",
  [sym_parenthesizedStatement] = "parenthesizedStatement",
  [sym_selectionStatement] = "selectionStatement",
  [sym_sequenceNoSelection] = "sequenceNoSelection",
  [sym_statementsNoSelection] = "statementsNoSelection",
  [sym_terminal] = "terminal",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_sequence_repeat1] = "sequence_repeat1",
  [aux_sym_selectionStatement_repeat1] = "selectionStatement_repeat1",
  [aux_sym_sequenceNoSelection_repeat1] = "sequenceNoSelection_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_COLON_COLON_EQ] = anon_sym_COLON_COLON_EQ,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_QMARK] = anon_sym_QMARK,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [sym_stringContent] = sym_stringContent,
  [sym_identifier] = sym_identifier,
  [sym_source_file] = sym_source_file,
  [sym_rule] = sym_rule,
  [sym_lhs] = sym_lhs,
  [sym_rhs] = sym_rhs,
  [sym_sequence] = sym_sequence,
  [sym_statements] = sym_statements,
  [sym_quantifiedStatement] = sym_quantifiedStatement,
  [sym_oneOrMore] = sym_oneOrMore,
  [sym_zeroOrMore] = sym_zeroOrMore,
  [sym_optional] = sym_optional,
  [sym_quantifierBase] = sym_quantifierBase,
  [sym_parenthesizedStatement] = sym_parenthesizedStatement,
  [sym_selectionStatement] = sym_selectionStatement,
  [sym_sequenceNoSelection] = sym_sequenceNoSelection,
  [sym_statementsNoSelection] = sym_statementsNoSelection,
  [sym_terminal] = sym_terminal,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_sequence_repeat1] = aux_sym_sequence_repeat1,
  [aux_sym_selectionStatement_repeat1] = aux_sym_selectionStatement_repeat1,
  [aux_sym_sequenceNoSelection_repeat1] = aux_sym_sequenceNoSelection_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_COLON_COLON_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_QMARK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym_stringContent] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_rule] = {
    .visible = true,
    .named = true,
  },
  [sym_lhs] = {
    .visible = true,
    .named = true,
  },
  [sym_rhs] = {
    .visible = true,
    .named = true,
  },
  [sym_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym_statements] = {
    .visible = true,
    .named = true,
  },
  [sym_quantifiedStatement] = {
    .visible = true,
    .named = true,
  },
  [sym_oneOrMore] = {
    .visible = true,
    .named = true,
  },
  [sym_zeroOrMore] = {
    .visible = true,
    .named = true,
  },
  [sym_optional] = {
    .visible = true,
    .named = true,
  },
  [sym_quantifierBase] = {
    .visible = true,
    .named = true,
  },
  [sym_parenthesizedStatement] = {
    .visible = true,
    .named = true,
  },
  [sym_selectionStatement] = {
    .visible = true,
    .named = true,
  },
  [sym_sequenceNoSelection] = {
    .visible = true,
    .named = true,
  },
  [sym_statementsNoSelection] = {
    .visible = true,
    .named = true,
  },
  [sym_terminal] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_sequence_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_selectionStatement_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_sequenceNoSelection_repeat1] = {
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
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 6,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(3);
      ADVANCE_MAP(
        '\'', 12,
        '(', 9,
        ')', 10,
        '*', 8,
        '+', 7,
        ':', 1,
        ';', 5,
        '?', 6,
        '|', 11,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('A' <= lookahead && lookahead <= 'z')) ADVANCE(14);
      END_STATE();
    case 1:
      if (lookahead == ':') ADVANCE(2);
      END_STATE();
    case 2:
      if (lookahead == '=') ADVANCE(4);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(anon_sym_COLON_COLON_EQ);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_stringContent);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(13);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_identifier);
      if (('A' <= lookahead && lookahead <= 'z')) ADVANCE(14);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 13},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_COLON_COLON_EQ] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_QMARK] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(36),
    [sym_rule] = STATE(25),
    [sym_lhs] = STATE(30),
    [aux_sym_source_file_repeat1] = STATE(25),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_identifier] = ACTIONS(5),
  },
  [2] = {
    [sym_statements] = STATE(2),
    [sym_quantifiedStatement] = STATE(20),
    [sym_oneOrMore] = STATE(14),
    [sym_zeroOrMore] = STATE(14),
    [sym_optional] = STATE(14),
    [sym_quantifierBase] = STATE(26),
    [sym_parenthesizedStatement] = STATE(10),
    [sym_selectionStatement] = STATE(2),
    [sym_sequenceNoSelection] = STATE(27),
    [sym_statementsNoSelection] = STATE(8),
    [sym_terminal] = STATE(10),
    [aux_sym_sequence_repeat1] = STATE(2),
    [aux_sym_sequenceNoSelection_repeat1] = STATE(8),
    [anon_sym_SEMI] = ACTIONS(7),
    [anon_sym_LPAREN] = ACTIONS(9),
    [anon_sym_RPAREN] = ACTIONS(7),
    [anon_sym_SQUOTE] = ACTIONS(12),
    [sym_identifier] = ACTIONS(15),
  },
  [3] = {
    [sym_statements] = STATE(2),
    [sym_quantifiedStatement] = STATE(20),
    [sym_oneOrMore] = STATE(14),
    [sym_zeroOrMore] = STATE(14),
    [sym_optional] = STATE(14),
    [sym_quantifierBase] = STATE(26),
    [sym_parenthesizedStatement] = STATE(10),
    [sym_selectionStatement] = STATE(2),
    [sym_sequenceNoSelection] = STATE(27),
    [sym_statementsNoSelection] = STATE(8),
    [sym_terminal] = STATE(10),
    [aux_sym_sequence_repeat1] = STATE(2),
    [aux_sym_sequenceNoSelection_repeat1] = STATE(8),
    [anon_sym_SEMI] = ACTIONS(18),
    [anon_sym_LPAREN] = ACTIONS(20),
    [anon_sym_RPAREN] = ACTIONS(18),
    [anon_sym_SQUOTE] = ACTIONS(22),
    [sym_identifier] = ACTIONS(24),
  },
  [4] = {
    [sym_rhs] = STATE(33),
    [sym_sequence] = STATE(35),
    [sym_statements] = STATE(3),
    [sym_quantifiedStatement] = STATE(20),
    [sym_oneOrMore] = STATE(14),
    [sym_zeroOrMore] = STATE(14),
    [sym_optional] = STATE(14),
    [sym_quantifierBase] = STATE(26),
    [sym_parenthesizedStatement] = STATE(10),
    [sym_selectionStatement] = STATE(3),
    [sym_sequenceNoSelection] = STATE(27),
    [sym_statementsNoSelection] = STATE(8),
    [sym_terminal] = STATE(10),
    [aux_sym_sequence_repeat1] = STATE(3),
    [aux_sym_sequenceNoSelection_repeat1] = STATE(8),
    [anon_sym_LPAREN] = ACTIONS(20),
    [anon_sym_SQUOTE] = ACTIONS(22),
    [sym_identifier] = ACTIONS(24),
  },
  [5] = {
    [sym_sequence] = STATE(29),
    [sym_statements] = STATE(3),
    [sym_quantifiedStatement] = STATE(20),
    [sym_oneOrMore] = STATE(14),
    [sym_zeroOrMore] = STATE(14),
    [sym_optional] = STATE(14),
    [sym_quantifierBase] = STATE(26),
    [sym_parenthesizedStatement] = STATE(10),
    [sym_selectionStatement] = STATE(3),
    [sym_sequenceNoSelection] = STATE(27),
    [sym_statementsNoSelection] = STATE(8),
    [sym_terminal] = STATE(10),
    [aux_sym_sequence_repeat1] = STATE(3),
    [aux_sym_sequenceNoSelection_repeat1] = STATE(8),
    [anon_sym_LPAREN] = ACTIONS(20),
    [anon_sym_SQUOTE] = ACTIONS(22),
    [sym_identifier] = ACTIONS(24),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 9,
    ACTIONS(28), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_SQUOTE,
    ACTIONS(34), 1,
      sym_identifier,
    STATE(21), 1,
      sym_quantifiedStatement,
    STATE(26), 1,
      sym_quantifierBase,
    STATE(7), 2,
      sym_statementsNoSelection,
      aux_sym_sequenceNoSelection_repeat1,
    STATE(13), 2,
      sym_parenthesizedStatement,
      sym_terminal,
    ACTIONS(26), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_PIPE,
    STATE(14), 3,
      sym_oneOrMore,
      sym_zeroOrMore,
      sym_optional,
  [34] = 9,
    ACTIONS(39), 1,
      anon_sym_LPAREN,
    ACTIONS(42), 1,
      anon_sym_SQUOTE,
    ACTIONS(45), 1,
      sym_identifier,
    STATE(21), 1,
      sym_quantifiedStatement,
    STATE(26), 1,
      sym_quantifierBase,
    STATE(7), 2,
      sym_statementsNoSelection,
      aux_sym_sequenceNoSelection_repeat1,
    STATE(13), 2,
      sym_parenthesizedStatement,
      sym_terminal,
    ACTIONS(37), 3,
      anon_sym_SEMI,
      anon_sym_RPAREN,
      anon_sym_PIPE,
    STATE(14), 3,
      sym_oneOrMore,
      sym_zeroOrMore,
      sym_optional,
  [68] = 9,
    ACTIONS(20), 1,
      anon_sym_LPAREN,
    ACTIONS(22), 1,
      anon_sym_SQUOTE,
    ACTIONS(26), 1,
      anon_sym_PIPE,
    ACTIONS(48), 1,
      sym_identifier,
    STATE(21), 1,
      sym_quantifiedStatement,
    STATE(26), 1,
      sym_quantifierBase,
    STATE(7), 2,
      sym_statementsNoSelection,
      aux_sym_sequenceNoSelection_repeat1,
    STATE(13), 2,
      sym_parenthesizedStatement,
      sym_terminal,
    STATE(14), 3,
      sym_oneOrMore,
      sym_zeroOrMore,
      sym_optional,
  [100] = 9,
    ACTIONS(20), 1,
      anon_sym_LPAREN,
    ACTIONS(22), 1,
      anon_sym_SQUOTE,
    ACTIONS(48), 1,
      sym_identifier,
    STATE(21), 1,
      sym_quantifiedStatement,
    STATE(22), 1,
      sym_sequenceNoSelection,
    STATE(26), 1,
      sym_quantifierBase,
    STATE(6), 2,
      sym_statementsNoSelection,
      aux_sym_sequenceNoSelection_repeat1,
    STATE(13), 2,
      sym_parenthesizedStatement,
      sym_terminal,
    STATE(14), 3,
      sym_oneOrMore,
      sym_zeroOrMore,
      sym_optional,
  [132] = 3,
    ACTIONS(54), 1,
      anon_sym_PIPE,
    ACTIONS(52), 3,
      anon_sym_QMARK,
      anon_sym_PLUS,
      anon_sym_STAR,
    ACTIONS(50), 5,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_SQUOTE,
      sym_identifier,
  [148] = 1,
    ACTIONS(56), 9,
      anon_sym_SEMI,
      anon_sym_QMARK,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SQUOTE,
      sym_identifier,
  [160] = 1,
    ACTIONS(58), 9,
      anon_sym_SEMI,
      anon_sym_QMARK,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SQUOTE,
      sym_identifier,
  [172] = 2,
    ACTIONS(52), 3,
      anon_sym_QMARK,
      anon_sym_PLUS,
      anon_sym_STAR,
    ACTIONS(54), 6,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SQUOTE,
      sym_identifier,
  [186] = 2,
    ACTIONS(62), 1,
      anon_sym_QMARK,
    ACTIONS(60), 6,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SQUOTE,
      sym_identifier,
  [198] = 3,
    ACTIONS(66), 1,
      anon_sym_PIPE,
    STATE(17), 1,
      aux_sym_selectionStatement_repeat1,
    ACTIONS(64), 5,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_SQUOTE,
      sym_identifier,
  [212] = 1,
    ACTIONS(68), 7,
      anon_sym_SEMI,
      anon_sym_QMARK,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SQUOTE,
      sym_identifier,
  [222] = 3,
    ACTIONS(72), 1,
      anon_sym_PIPE,
    STATE(17), 1,
      aux_sym_selectionStatement_repeat1,
    ACTIONS(70), 5,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_SQUOTE,
      sym_identifier,
  [236] = 1,
    ACTIONS(75), 7,
      anon_sym_SEMI,
      anon_sym_QMARK,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SQUOTE,
      sym_identifier,
  [246] = 1,
    ACTIONS(77), 7,
      anon_sym_SEMI,
      anon_sym_QMARK,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SQUOTE,
      sym_identifier,
  [256] = 2,
    ACTIONS(54), 1,
      anon_sym_PIPE,
    ACTIONS(50), 5,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_SQUOTE,
      sym_identifier,
  [267] = 1,
    ACTIONS(54), 6,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SQUOTE,
      sym_identifier,
  [276] = 1,
    ACTIONS(70), 6,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SQUOTE,
      sym_identifier,
  [285] = 1,
    ACTIONS(79), 6,
      anon_sym_SEMI,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SQUOTE,
      sym_identifier,
  [294] = 4,
    ACTIONS(81), 1,
      ts_builtin_sym_end,
    ACTIONS(83), 1,
      sym_identifier,
    STATE(30), 1,
      sym_lhs,
    STATE(24), 2,
      sym_rule,
      aux_sym_source_file_repeat1,
  [308] = 4,
    ACTIONS(5), 1,
      sym_identifier,
    ACTIONS(86), 1,
      ts_builtin_sym_end,
    STATE(30), 1,
      sym_lhs,
    STATE(24), 2,
      sym_rule,
      aux_sym_source_file_repeat1,
  [322] = 3,
    ACTIONS(88), 1,
      anon_sym_QMARK,
    ACTIONS(90), 1,
      anon_sym_PLUS,
    ACTIONS(92), 1,
      anon_sym_STAR,
  [332] = 2,
    ACTIONS(66), 1,
      anon_sym_PIPE,
    STATE(15), 1,
      aux_sym_selectionStatement_repeat1,
  [339] = 1,
    ACTIONS(94), 2,
      ts_builtin_sym_end,
      sym_identifier,
  [344] = 1,
    ACTIONS(96), 1,
      anon_sym_RPAREN,
  [348] = 1,
    ACTIONS(98), 1,
      anon_sym_COLON_COLON_EQ,
  [352] = 1,
    ACTIONS(100), 1,
      anon_sym_SQUOTE,
  [356] = 1,
    ACTIONS(102), 1,
      sym_stringContent,
  [360] = 1,
    ACTIONS(104), 1,
      anon_sym_SEMI,
  [364] = 1,
    ACTIONS(106), 1,
      anon_sym_COLON_COLON_EQ,
  [368] = 1,
    ACTIONS(108), 1,
      anon_sym_SEMI,
  [372] = 1,
    ACTIONS(110), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(6)] = 0,
  [SMALL_STATE(7)] = 34,
  [SMALL_STATE(8)] = 68,
  [SMALL_STATE(9)] = 100,
  [SMALL_STATE(10)] = 132,
  [SMALL_STATE(11)] = 148,
  [SMALL_STATE(12)] = 160,
  [SMALL_STATE(13)] = 172,
  [SMALL_STATE(14)] = 186,
  [SMALL_STATE(15)] = 198,
  [SMALL_STATE(16)] = 212,
  [SMALL_STATE(17)] = 222,
  [SMALL_STATE(18)] = 236,
  [SMALL_STATE(19)] = 246,
  [SMALL_STATE(20)] = 256,
  [SMALL_STATE(21)] = 267,
  [SMALL_STATE(22)] = 276,
  [SMALL_STATE(23)] = 285,
  [SMALL_STATE(24)] = 294,
  [SMALL_STATE(25)] = 308,
  [SMALL_STATE(26)] = 322,
  [SMALL_STATE(27)] = 332,
  [SMALL_STATE(28)] = 339,
  [SMALL_STATE(29)] = 344,
  [SMALL_STATE(30)] = 348,
  [SMALL_STATE(31)] = 352,
  [SMALL_STATE(32)] = 356,
  [SMALL_STATE(33)] = 360,
  [SMALL_STATE(34)] = 364,
  [SMALL_STATE(35)] = 368,
  [SMALL_STATE(36)] = 372,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_sequence_repeat1, 2, 0, 0),
  [9] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_sequence_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [12] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_sequence_repeat1, 2, 0, 0), SHIFT_REPEAT(32),
  [15] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_sequence_repeat1, 2, 0, 0), SHIFT_REPEAT(10),
  [18] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_sequence, 1, 0, 0),
  [20] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [22] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [24] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_sequenceNoSelection, 1, 0, 0),
  [28] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_sequenceNoSelection, 1, 0, 0), SHIFT(5),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_sequenceNoSelection, 1, 0, 0), SHIFT(32),
  [34] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_sequenceNoSelection, 1, 0, 0), SHIFT(13),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_sequenceNoSelection_repeat1, 2, 0, 0),
  [39] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_sequenceNoSelection_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [42] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_sequenceNoSelection_repeat1, 2, 0, 0), SHIFT_REPEAT(32),
  [45] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_sequenceNoSelection_repeat1, 2, 0, 0), SHIFT_REPEAT(13),
  [48] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statements, 1, 0, 0),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantifierBase, 1, 0, 0),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statementsNoSelection, 1, 0, 0),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parenthesizedStatement, 3, 0, 0),
  [58] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_terminal, 3, 0, 0),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantifiedStatement, 1, 0, 0),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_selectionStatement, 2, 0, 0),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_zeroOrMore, 2, 0, 0),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_selectionStatement_repeat1, 2, 0, 0),
  [72] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_selectionStatement_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_oneOrMore, 2, 0, 0),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_optional, 2, 0, 0),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quantifiedStatement, 2, 0, 0),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [83] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(34),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [88] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [90] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rule, 4, 0, 0),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [98] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_lhs, 1, 0, 0),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rhs, 1, 0, 0),
  [110] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_EBNF(void) {
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
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
