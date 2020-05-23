%{
#include <iostream>
using namespace std;
extern "C"
{
	#include "header.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>
	#include <stdarg.h>
	
	void yyerror(const char*);
	int yylex();
	extern char* yytext;
	//void yytext(const char*);
	char *getsname(int s);
	char *getname(int c);
	char *ap3(char *a,char *b,char *c);
	char *ap(char *a,char *b);
	void add_type_name(char *d, int type);
	int chkentr(char *d);
	void printall();
	int mkentr(int type,char *d,int scp);
	extern int scs[100],stop,sid, elno,lbl,tmp;
	extern char *ygbl,bbuf[1000],ysign[10];
	extern int gl ;
	extern int q1,q2 ;
	struct tentr idtopp={0},stopp={0},ntopp={0};
}
%}

%union{
struct {char *code,*ast;int next;} stt;
struct {char *code,*ast;int idn;} eq;
struct {int dt[4];} dt;
struct {int idn,off;char *code,*ast;} ls;
}
%type<stt> estt seq statement for if while do_while switch switch_body
%type<eq> expr unit defn anyopl anyoph rhsl rhsh
%type<ls> list
%type<dt> elb lhs lhsv edt lhs1
%token T_VAR T_DEF T_KEY T_ID T_NUM T_LBR T_RBR T_STR T_SHA T_LCG T_LOP T_OP1 T_OP2 T_OP3 T_OP4 T_FOR T_IF T_ELSE T_IN T_LET T_WHILE T_SWITCH T_DO T_CASE T_BREAK
%start start
%%
start:seq{FILE *f;f=fopen("/home/chaitra/Javascript-Mini-Compiler/Optimization/input1.txt","w");
	printf("%s",$1.code);
	fprintf(f,"%s",$1.code);
	fclose(f);};
estt:;
elb:;
edt:;

anyopl:T_LOP {$$.code=strdup(ysign);}|T_OP1 {$$.code=strdup(ysign);}|T_LCG {$$.code=strdup(ysign);};

anyoph:T_OP2 {$$.code=strdup(ysign);}|T_OP3 {$$.code=strdup(ysign);};

adlm:';'|'\n'|"";

seq:statement seq{$$.code=ap($1.code,$2.code);
	//$$.ast=ap3($1.ast,strdup("\n"),$2.ast);
	//printf("CONFUSION \n");
	}|
	{$$.code=strdup("");
	//printf("CONFUSION 2\n");
	//$$.ast=strdup("");
	};

statement:defn adlm {$$.code=$1.code;
		//$$.ast=$1.ast;
		}|
	expr adlm {$$.code=$1.code;
	//$$.ast=$1.ast;
	}|
	for {$$.code=$1.code;
	//$$.ast=$1.ast;
	}|
	while {$$.code=$1.code;printf("while-1\n");}|
	if {$$.code=$1.code;
	//$$.ast=$1.ast;
	}|
	'{'{scs[stop++]=sid++;} seq '}' {stop--;} adlm  
	{$$.code=$3.code;$$.ast=ap3(strdup("{"),$3.ast,strdup("} "));}|
	do_while {$$.code=$1.code;}|
	'{'{scs[stop++]=sid++;} seq '}' {stop--;} adlm
	{$$.code=$3.code;
		printf("DO_WHILE\n");
	//$$.ast=ap3(strdup("{"),$3.ast,strdup("} "));
	}|
	switch {$$.code = $1.code;}|
	adlm {$$.code=strdup("");$$.ast=strdup("");};

lhs1:T_ID {int v=mkentr(0,ygbl,scs[stop-1]);$$.dt[0]=v;};
lhs : T_ID {int v=chkentr(ygbl);if(v==-1){printf("variable not found\n");
//exit(0);
		}
v=mkentr(0,ygbl,scs[stop-1]);$$.dt[0]=v;
$$.dt[0]=v;} ;
lhsv:T_ID {int v=chkentr(ygbl);if(v==-1){printf("variable not found\n");
//exit(0);
		}
v=mkentr(0,ygbl,scs[stop-1]);$$.dt[0]=v;
$$.dt[0]=v;};

eqb:'='|T_SHA;

expr: T_VAR lhs1 eqb expr 
	{char *a;sprintf(bbuf,"%s = t%d\n",a=getname($2.dt[0]),$4.idn);
	$$.code=ap($4.code,strdup(bbuf));$$.idn=$4.idn;
	sprintf(bbuf,"%s = (",a);$$.ast=ap3(strdup(bbuf),$4.ast,strdup(")"));
	}|
	lhs eqb expr 
	{char *a;sprintf(bbuf,"%s = t%d\n",a=getname($1.dt[0]),$3.idn);
	$$.code=ap($3.code,strdup(bbuf));$$.idn=$3.idn;
	sprintf(bbuf,"%s = (",a);$$.ast=ap3(strdup(bbuf),$3.ast,strdup(")"));
	}|
	rhsl {$$.code=$1.code;$$.idn=$1.idn;$$.ast=$1.ast;};
rhsl:rhsh anyopl rhsl 
	{int k=tmp++;
	sprintf(bbuf,"t%d = t%d %s t%d\n",k,$1.idn,$2.code,$3.idn);
	$$.code=ap3($1.code,$3.code,strdup(bbuf));$$.idn=k;
	$$.ast=ap3(ap3(strdup(" ("),$1.ast,strdup(") ")),$2.code,ap3(strdup(" ("),$3.ast,strdup(") ")));free($2.code);}|
	rhsh {$$.code=$1.code;$$.idn=$1.idn;$$.ast=$1.ast;};

rhsh:unit anyoph rhsh 
	{int k=tmp++;
	sprintf(bbuf,"t%d = t%d %s t%d\n",k,$1.idn,$2.code,$3.idn);
	$$.code=ap3($1.code,$3.code,strdup(bbuf));$$.idn=k;
	$$.ast=ap3(ap3(strdup(" ("),$1.ast,strdup(") ")),$2.code,ap3(strdup(" ("),$3.ast,strdup(") ")));free($2.code);}|
	unit {$$.code=$1.code;$$.idn=$1.idn;$$.ast=$1.ast;};

unit: lhsv {char *a;int k=tmp++;
	sprintf(bbuf,"t%d = %s\n",k,a=getname($1.dt[0]));
	$$.code=strdup(bbuf);$$.idn=k;$$.ast=strdup(a);}|	
	T_OP4 lhsv |lhsv T_OP4|
	T_STR {int k=tmp++;add_type_name(ygbl, 1);
	sprintf(bbuf,"t%d = %s\n",k,yytext);
	//sprintf(bbuf,"mov t%d %s\n",k,yytext);
	$$.code=strdup(bbuf);$$.idn=k;$$.ast=strdup(yytext);}|
	T_NUM {int k=tmp++;add_type_name(ygbl, 0);
	sprintf(bbuf,"t%d = %s\n",k,yytext);
	//sprintf(bbuf,"mov t%d %s\n",k,yytext);
	$$.code=strdup(bbuf);$$.idn=k;$$.ast=strdup(yytext);}|
	'[' list ']' {$$.code=$2.code;$$.idn=$2.idn;add_type_name(ygbl, 2);$$.ast=ap3(strdup(" ["),$2.ast,strdup("] "));} |
	lhsv '[' expr ']' {char *a;int k=tmp++;$$.idn=tmp++;sprintf(bbuf,"t%d = %s\nt%d=t%d[t%d]\n",k,a=getname($1.dt[0]),$$.idn,k,$3.idn);$$.code=ap($3.code,strdup(bbuf));sprintf(bbuf," %s[",a);$$.ast=ap3(strdup(bbuf),$3.ast,strdup("] "));};

func:lhsv '(' list ')';

list: list ',' expr {sprintf(bbuf,"t%d[%d]=t%d\n",$1.idn,$1.off+1,$3.idn);$$.code=ap3($1.code,$3.code,strdup(bbuf));$$.off=$1.off+1;$$.idn=$1.idn;$$.ast=ap3($1.ast,strdup(","),$3.ast);}|
	expr {$$.idn=tmp++;$$.off=0;sprintf(bbuf,"t%d[%d]=t%d\n",$$.idn,$$.off,$1.idn);$$.code=ap($1.code,strdup(bbuf));$$.ast=$1.ast;}|{$$.code=strdup("");$$.idn=tmp++;$$.ast=strdup("");};

defn: T_VAR vtail|T_LET vtail;

vtail:lhs |lhs ',' vtail|lhs '=' expr|lhs '=' expr ',' vtail;

varop:T_VAR|T_LET|;

for: T_FOR edt {$2.dt[0]=lbl++;$2.dt[1]=lbl++;} 
	'(' expr ';' expr ';' expr ')' statement { 
	char *a,*b,*c;
	sprintf(bbuf,"label l%d\n",$2.dt[0]);
	a=ap3($5.code,strdup(bbuf),$7.code);
	sprintf(bbuf,"iffalse t%d goto (l%d)\n",$7.idn,$2.dt[1]);
	b=ap3(strdup(bbuf),$11.code,$9.code);
	sprintf(bbuf,"goto (l%d)\nlabel l%d\n",$2.dt[0],$2.dt[1]);
	$$.code=ap3(a,b,strdup(bbuf));
	a=ap3(strdup("for ("),$5.ast,strdup(";"));
	a=ap3(a,$7.ast,strdup(";"));
	a=ap3(a,$9.ast,strdup(")"));
	$$.ast=ap(a,$11.ast);
};

while: T_WHILE  edt {$2.dt[0]=lbl++;$2.dt[1]=lbl++;}
	'(' expr ')' statement {
	//printf("CHECKING : \n");
	char *a,*b,*bbuf1;
	sprintf(bbuf,"label l%d\n",$2.dt[0]);
	//printf("I AM HERE\n");
	a = ap(strdup(bbuf),$5.code);//,$7.code);//rm $7
	//printf("I AM HERE ALSO \n");
	sprintf(bbuf,"iffalse t%d goto (l%d)\n",$5.idn,$2.dt[1]);
	b=ap(strdup(bbuf),$7.code);
	sprintf(bbuf,"goto (l%d)\nlabel l%d\n",$2.dt[0],$2.dt[1]);
	//printf("I AM HERE ALSO again\n");
	$$.code=ap3(a,b,strdup(bbuf));
	//printf("I AM HERE ALSO again again\n");
};


do_while: T_DO edt { $2.dt[0]=lbl++;$2.dt[1]=lbl++;}
	  statement {//printf("WHAT IS HAPPENING\n");
	//$$.code = $4.code;
	} T_WHILE '(' expr ')' {//$$.code = $4.code;}  ;
	char *a,*b,*c;
			sprintf(bbuf,"label l%d\n",$2.dt[0]);
			a = ap(strdup(bbuf),$4.code);
			sprintf(bbuf,"",$2.dt[0]);
			b = ap(a,strdup(bbuf));
			sprintf(bbuf,"%s\n",$8.code);
			c = ap(b,bbuf);
			sprintf(bbuf,"iftrue t%d goto (l%d)\n",$8.idn,$2.dt[0]);
			$$.code = ap(c,strdup(bbuf)); };
	// T_WHILE  expr {printf("IDKKKK\n");} ;
if : T_IF '('expr')' edt 
	{$5.dt[0]=lbl++;$5.dt[1]=lbl++;$5.dt[2]=lbl++;}
	statement T_ELSE statement 
	{char *a,*b,*c;
	sprintf(bbuf,"iftrue t%d goto (l%d)\ngoto (l%d)\nlabel l%d\n",$3.idn,$5.dt[0],$5.dt[1],$5.dt[0]);
	a=ap3($3.code,strdup(bbuf),$7.code);
	sprintf(bbuf,"goto (l%d)\nlabel l%d\n",$5.dt[2],$5.dt[1]);
	b=ap(strdup(bbuf),$9.code);
	sprintf(bbuf,"label l%d\n",$5.dt[2]);
	$$.code=ap3(a,b,strdup(bbuf));
	a=ap3(strdup("if("),$3.ast,strdup(")"));
	a=ap3(a,$7.ast,strdup(" else "));
	$$.ast=ap(a,$9.ast);
};

switch :T_SWITCH '(' expr {printf("WASSSUPPP\n");q1 = $3.idn;q2=1;} ')' ':'  switch_body  {$$.code  = ap($3.code,$7.code);} ;

switch_body : T_CASE T_ID ':' statement T_BREAK ';' switch_body {
									char *a,*b,*c;
									if(q2==1 || gl){
											sprintf(bbuf,"if t%d not equalto %s goto label s%d\n",q1,"heyy",q2);
											a = ap(strdup(bbuf),$4.code);
											
											
									}
									else{
										sprintf(bbuf,"label s%d\n",q2);
										a = ap(bbuf,$4.code);					
										

									}
									b = ap(a,$7.code);
									$$.code = b;
									gl = 0;
									gl++;

								} |
			
			
			
			{
				$$.code  = strdup(" ");
			}
			;

			

%%
int main(){
	if(!yyparse())
	{
		printf("ICG Done\n");
	}
	else
		printf("Unsuccessful\n");

	return 0;
}
int mkentr(int type,char *d,int scp)
{
	struct tentr *a,*b;int c=0;
	switch(type){
		case 0:a=&idtopp;
				break;
		case 1:a=&stopp;
				break;
		case 2:a=&ntopp;
				break;
		default:return -1;
	}
	while(a->n!=NULL){
		if(strcmp(a->n->d,d)==0)
			return c;
		a=a->n;
		c++;
	}
	b=(tentr*)malloc(sizeof(struct tentr));
	b->n=NULL;
	b->d=strdup(d);
	a->n=b;
	if(type==0){
		b->scope=scp;
		b->lndec=b->lnused=elno;
		b->type=-1;
	}
	return c;
}

void printall(){
	struct tentr *a;
	printf("\n\nidentifiers:\n");
	a=&idtopp;
	printf("Name \t scope \t type \t declared line \t last used line\n");
	printf("--------------------------------------------------------\n");
	while(a->n!=NULL){
		printf("%s \t %d \t %d \t %d \t\t %d\n",a->n->d,a->n->scope,a->n->type,a->n->lndec,a->n->lnused);
		a=a->n;
		}
	printf("\n\nstrings:\n");
	a=&stopp;
	while(a->n!=NULL){
		printf("%s\n",a->n->d);
		a=a->n;
		}
	printf("\n\nnumber:\n");
	a=&ntopp;
	while(a->n!=NULL){
		printf("%s\n",a->n->d);
		a=a->n;
	}
}


int chkentr(char *d)
{
	int tp=stop-1,pscp;
	//printf("chkentr called!!!\n");
	struct tentr *a;int c=0;
	for(tp=stop-1;tp>=0;tp--){
			pscp=scs[0];a=&idtopp;
			while(a->n!=NULL){
				if(strcmp(d,a->n->d)==0&&(pscp==a->n->scope||1)){
					a->n->lnused=elno;return c;}a=a->n;c++;
				}
		}
		
	printf("Error in line %d, %s not found\n", elno,d);
	//printf("chkentr exited\n");
	return -1;
}

void add_type_name(char *d, int type)
{
	int tp=stop-1,pscp;
	struct tentr *a;
	for(tp=stop-1;tp>=0;tp--){
		pscp=scs[tp];a=&idtopp;
		while(a->n!=NULL){
			if(strcmp(d,a->n->d)==0&&pscp==a->n->scope){
				a->n->type=type;return;}a=a->n;
			}
		}
		
	printf("Error in line %d, %s not found\n", elno,d);
}

//more string functions

char *ap(char *a,char *b)
{
	char *o;int m,n;m=strlen(a);n=strlen(b);
	o=(char*)malloc(sizeof(char)*(m+n+10));
	strcpy(o,a);strcpy(o+m,b);return o;
}

char *ap3(char *a,char *b,char *c)
{
	char *o;int m,n,p;m=strlen(a);n=strlen(b);p=strlen(c);
	o=(char*)malloc(sizeof(char)*(m+n+p+10));
	strcpy(o,a);strcpy(o+m,b);strcpy(o+m+n,c);return o;
}

char *getname(int c)
{
	struct tentr *t;int i;
	t=idtopp.n;
	for(i=0;i<c;i++)t=t->n;
	return t->d;
}

char *getsname(int s)
{
	return "<sign>";
}
