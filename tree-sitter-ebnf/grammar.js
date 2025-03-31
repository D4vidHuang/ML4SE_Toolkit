module.exports = grammar({
  name: 'EBNF',

//  word: $ => $.identifier,
  conflicts: $ => [[$.sequenceNoSelection]],

  rules: {
    // TODO: add the actual grammar rules
    source_file: $ => repeat($.rule),

    rule: $ => seq($.lhs, '::=', $.rhs, ';'),
    lhs: $ => seq($.identifier),
    rhs: $ => seq($.sequence),
	
    sequence: $ => repeat1(choice($.statements, $.selectionStatement)),
    statements: $ => prec(2, choice($.quantifiedStatement, $.parenthesizedStatement, $.terminal, $.identifier)),

    quantifiedStatement: $ => seq(choice($.oneOrMore, $.zeroOrMore, $.optional), optional('?')),
    oneOrMore: $ => seq($.quantifierBase, '+'),
    zeroOrMore: $ => seq($.quantifierBase, '*'),
    optional: $ => seq($.quantifierBase, '?'),

    quantifierBase: $ => choice($.parenthesizedStatement, $.identifier, $.terminal),
	
    parenthesizedStatement: $ => seq('(', $.sequence, ')'),

    selectionStatement: $ => seq($.sequenceNoSelection, repeat1(seq('|', $.sequenceNoSelection))),

    sequenceNoSelection: $ => repeat1($.statementsNoSelection),
    statementsNoSelection: $ => choice($.quantifiedStatement, $.parenthesizedStatement, $.terminal, $.identifier),

    terminal: $ => seq("'", $.stringContent, "'"),
    stringContent: $ => /[a-z0-9]*/,
    identifier: _ => /[_A-z]+/,
  }
});
