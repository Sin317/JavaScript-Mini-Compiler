struct tentr{
	int type,scope,lndec,lnused;
	struct tentr *n;
	char *d;
};



char *getsname(int s);
char *getname(int c);
char *ap3(char *a,char *b,char *c);
char *ap(char *a,char *b);
void add_type_name(char *d, int type);
int chkentr(char *d);
void printall();
int mkentr(int type,char *d,int scp);
