yacc -d yacc.y
lex lex.l
g++ -g y.tab.c lex.yy.c graph.cpp -ll -o AST
clear
