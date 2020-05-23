yacc -d par.y
lex lex.l
g++ -g y.tab.c lex.yy.c -ll -o ICG
clear
