#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

const char *in; int pos=0; char la;

void adv(){ la=in[pos++]; }
void err(char *m){ printf("Error: %s at %d\n",m,pos); exit(1); }
void match(char c){ if(la==c) adv(); else err("Unexpected symbol"); }

int E(),T(),F();

int E(){ int v=T(); while(la=='+'){ match('+'); v+=T(); } return v; }
int T(){ int v=F(); while(la=='*'){ match('*'); v*=F(); } return v; }
int F(){
    if(isdigit(la)){ int v=la-'0'; adv(); return v; }
    if(la=='('){ match('('); int v=E(); match(')'); return v; }
    err("Invalid factor"); return 0;
}

int main(){
    char s[100]; printf("Enter expression: "); scanf("%s",s);
    in=s; adv();
    int res=E();
    if(la=='\0') printf("Valid! Result=%d\n",res);
    else err("Extra input");
}
