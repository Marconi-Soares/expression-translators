#include "parser.h"
#include <cctype>
#include <iostream>
using std::cin;
using std::cout;

void Parser::Expr() {
  // expr -> term oper
  Term();
  while (true) {
    // oper -> + term { print(-) } oper
    if (lookahead == '+') {
      Match('+');
      Term();
      cout << '+';
      continue;
    }
    // oper -> - term { print(-) } oper
    if (lookahead == '-') {
      Match('-');
      Term();
      cout << '-';
      continue;
    }
    // vazia
    return;
  }
}

void Parser::Term() {
  if (isdigit(lookahead)) {
    // term -> {lookahead} { print(lookahead) }
    cout << lookahead;
    Match(lookahead);
    return;
  }
  throw SyntaxError{};
}

void Parser::Match(char t) {
  if (t == lookahead) {
    lookahead = cin.get();
    return;
  }
  throw SyntaxError{};
}

Parser::Parser() { lookahead = 0; }

void Parser::start() {
  lookahead = cin.get();
  Expr();
  if (lookahead != '\n') {
    throw SyntaxError{};
  }
}
