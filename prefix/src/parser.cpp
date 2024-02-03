#include "parser.h"
#include <cctype>
#include <iostream>
using std::cin;
using std::cout;

void Parser::Expr() {
  // expr -> + expr expr { print("+") }
  if (lookahead == '+') {
    Match('+');
    Expr();
    Expr();
    cout << '+';
    return;
  }
  // expr -> - expr expr { print("-") }
  if (lookahead == '-') {
    Match('-');
    Expr();
    Expr();
    cout << '-';
    return;
  }
  // expr -> term
  Term();
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
