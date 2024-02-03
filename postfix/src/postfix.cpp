#include "parser.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
  Parser tradutor;
  try {
    tradutor.start();
  } catch (SyntaxError) {
    cout << "^\n";
    cout << "Erro de Sintaxe";
  }
  cout << endl;
}
