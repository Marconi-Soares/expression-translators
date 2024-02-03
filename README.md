## Limitations
Once there's no Lexer, it only handles a few characters as tokens. Those are:
* `"+"`
* `"-"`
* `[0...9]`

Also, it doesn't read a file but instead uses `cin.get()` to read directly from the terminal.
## Grammars and Semantic Actions
Until the 5th class, we were mainly studying grammar
```bash
# PREFIX TO POSTFIX GRAMMAR
expr -> + expr expr { print("+") }
      | - expr expr { print("-") }
      | term
term -> 0 { print('0') }
      | 1 { print('1') }
      | 2 { print('2') }
      | ...
      | 9 { print('9') }
```
```bash
# INFIX TO POSTFIX GRAMMAR
expr -> term oper
oper -> + term { print("+") } oper
      | - term { print("-") } oper
      | null
term -> 0 { print('0') }
      | 1 { print('1') }
      | 2 { print('2') }
      | ...
      | 9 { print('9') }
```
## Running
You are going to need <a href="https://clang.llvm.org/">clang++</a> and <a href="https://www.gnu.org/software/make/">make</a> to run this project.
### Prefix to Postfix
```bash
cd prefix
make all
./bin/parser
```
```bash
# 1+1 is the infix form
+11 # input in prefix form
11+ # output in postfix form
```

### Infix to Postfix
#### grammar with semantic actions

```bash
cd postfix
make all
./bin/parser
```
```bash
1+1 # the infix form
11+ # output in postfix form
```
###### Projeto feito com informações até a quinta aula do <a href="https://www.youtube.com/playlist?list=PLX6Nyaq0ebfhI396WlWN6WlBm-tp7vDtV">curso de compiladores</a>
