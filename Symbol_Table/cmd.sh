yacc -d yacc.y
lex lex.l
g++ y.tab.c -ly -ll -w -o SYT

