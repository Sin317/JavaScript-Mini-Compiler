%{
#include <iostream>
using namespace std;

#include<ctype.h>
#include <stdlib.h>
#include <string.h>


int line_number = 1;
char printf_str[100];
char identifier_name[50];
int symbol_table_length = 0;
int i = 0;
int j = 0;
char type[30][10];
char name[30][10];
char value[30][100];
int line_num[30];
char for_spe[30];
int scope=0;
int scopes[100];

%}
id [a-zA-Z][a-zA-Z0-9]*
alpha [A-Za-z_]
digit [0-9]
%%
"\n" line_number++;
var[' ']{id}";" {int r=0; int flag=0; char id[100]="";;
			for(int q=4;yytext[q]!='=';++q)
			id[r++]=yytext[q];
			//cout<<id;
		for(int p=0;p<symbol_table_length;p++)
		{
	if(strcmp(id,name[p])==0)
	{
	flag=1;
	break;
	}
	}
	if(flag!=1){
		                    strcpy(type[symbol_table_length], "var");
				    scopes[symbol_table_length]=scope;
		                    for(i = 4; yytext[i]!=';'; ++i)
		                        name[symbol_table_length][j++] = yytext[i];
		                    for_spe[symbol_table_length] = 'd';
		                    line_num[symbol_table_length] = line_number;
		                    symbol_table_length++;j=0;} else {cout<<"Multiple declarations of"<<id<<"at line number "<<line_number<<"\n";//exit(0);
}
};
var[' '][a-zA-Z][a-zA-Z0-9]*['=']{digit}*";" {int r=0; int flag=0; char id[100]="";;
		for(int q=4;yytext[q]!='=';++q)
		id[r++]=yytext[q];
		//cout<<id;
	for(int p=0;p<symbol_table_length;p++)
	{
if(strcmp(id,name[p])==0)
{
flag=1;
break;
}
}
if(flag!=1){
                            strcpy(type[symbol_table_length], "var");
			    scopes[symbol_table_length]=scope;
                            for(i = 4; yytext[i]!='='; ++i)
                                name[symbol_table_length][j++] = yytext[i];
                            while(yytext[i]!='\0') {
                                if(yytext[i] == '='){
                                    j = 0;
                                    i++;
                                    for(;yytext[i]!=';'; ++i)
                                        value[symbol_table_length][j++] = yytext[i];
                                    break;
                                }
                            }
                            for_spe[symbol_table_length] = 'd';
                            line_num[symbol_table_length] = line_number;
                            symbol_table_length++;j=0;} else {cout<<"Multiple declarations of"<<id<<"at line number "<<line_number<<"\n";//exit(0);
}};

var[' '][a-zA-Z][a-zA-Z0-9]*['=']\".*\"";" {int r=0; int flag=0; char id[100]="";;
			for(int q=4;yytext[q]!='=';++q)
			id[r++]=yytext[q];
			//cout<<id;
		for(int p=0;p<symbol_table_length;p++)
		{
	if(strcmp(id,name[p])==0)
	{
	flag=1;
	break;
	}
	}
	if(flag!=1){
		                    strcpy(type[symbol_table_length], "var");
				    scopes[symbol_table_length]=scope;
		                    for(i = 4; yytext[i]!='='; ++i)
		                        name[symbol_table_length][j++] = yytext[i];
		                    while(yytext[i]!='\0') {
		                        if(yytext[i] == '='){
		                            j = 0;
		                            i++;
		                            for(;yytext[i]!=';'; ++i)
					    {
					        //cout<<yytext[i]<<"\n";
		                                value[symbol_table_length][j] = yytext[i];
						j++;
						}
		                            break;
		                        }
		                    }
		                    for_spe[symbol_table_length] = 'd';
		                    line_num[symbol_table_length] = line_number;
		                    symbol_table_length++;j=0;} else {cout<<"Multiple declarations of"<<id<<"at line number "<<line_number<<"\n";//exit(0)
;}
};


{id}['=']{digit}*";" {int r=0; int flag=0; char id[100]="";;
		for(int q=0;yytext[q]!='=';++q)
		id[r++]=yytext[q];
		//cout<<id;
		int pos;
	for(int p=0;p<symbol_table_length;p++)
	{
if(strcmp(id,name[p])==0) //found
{
//cout<<id;
flag=1;
pos=p;
break;
}
}
if(flag==1){
                            //strcpy(type[symbol_table_length], "var");
			    //scopes[symbol_table_length]=scope;
			    i=strlen(id);
			    //cout<<i;
                            while(yytext[i]!='\0') {
                                if(yytext[i] == '='){
                                    j = 0;
                                    i++;
                                    for(;yytext[i]!=';'; ++i)
                                        value[pos][j++] = yytext[i];
                                    break;
                                }
                            }
                            //for_spe[symbol_table_length] = 'd';
                            //line_num[symbol_table_length] = line_number;
                            //symbol_table_length++;
				j=0;} else {cout<<"Did Not Find declaration of"<<id<<"at line number "<<line_number<<"\n";//exit(0);
}};


{id}['=']\".*\"";" {int r=0; int flag=0; char id[100]="";;
		for(int q=0;yytext[q]!='=';++q)
		id[r++]=yytext[q];
		//cout<<id;
		int pos;
	for(int p=0;p<symbol_table_length;p++)
	{
if(strcmp(id,name[p])==0) //found
{
//cout<<id;
flag=1;
pos=p;
break;
}
}
if(flag==1){
                            //strcpy(type[symbol_table_length], "var");
			    //scopes[symbol_table_length]=scope;
			    i=strlen(id);
			    //cout<<i;
                            while(yytext[i]!='\0') {
                                if(yytext[i] == '='){
                                    j = 0;
                                    i++;
                                    for(;yytext[i]!=';'; ++i)
                                        value[pos][j++] = yytext[i];
                                    break;
                                }
                            }
                            //for_spe[symbol_table_length] = 'd';
                            //line_num[symbol_table_length] = line_number;
                            //symbol_table_length++;
				j=0;} else {cout<<"Did Not Find declaration of"<<id<<"at line number "<<line_number<<"\n";}};


[ \t\n]

"//".*["\n"*] {line_number++;};
"/*"(.|"\n")*"*/"(" "|\n)* {line_number++;};
"while" {return (WHILE);}
"for" return (FOR);
"if" return (IF);
"else" return (ELSE);
"do" return (DO);
"break" return (BREAK);
"continue" return (CONTINUE);
"alert" return (ALERT);
"var" return (VAR);
"switch" return (SWITCH);
"case" return (CASE);
"default" return (DEFAULT);
{digit}+    return (NUM);
{alpha}({alpha}|{digit})*    return (ID);
\".*\" return (STRING);
":" return (T_co);
"<"   return (T_lt);
">"     return (T_gt);
"="     return (T_eq);
"<="    return (T_lteq);
">="    return (T_gteq);
"=="    return (T_eqeq);
"!="    return (T_neq);
"+"     return (T_pl);
"-"     return (T_min);
"*"     return (T_mul);
"/"     return (T_div);
"++"    return (T_incr);
"--"    return (T_decr);
"!"     return (T_neq);
"||"    return (T_or);
"&&"    return (T_and);
"{"	{scope++; return (open);}
"}"	{scope--; return (clo);}
.    return yytext[0];
%%
