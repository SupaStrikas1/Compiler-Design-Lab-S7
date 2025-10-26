#include <stdio.h>
#include <string.h>

char in[100], st[100]; 
int top=-1,len;

void show(int i,char *act){
    printf("$"); for(int j=0;j<=top;j++) printf("%c",st[j]);
    printf("\t\t%s$\t\t%s\n",&in[i],act);
}

void reduce(int i){
    int r=1;
    while(r){
        r=0;
        if(top>=2 && st[top-2]=='S' && (st[top-1]=='+'||st[top-1]=='-') && st[top]=='S')
            {st[top-=2]='S'; show(i,"REDUCE S→S+S/S-S"); r=1;}
        else if(top>=2 && st[top-2]=='('&&st[top-1]=='S'&&st[top]==')')
            {st[top-=2]='S'; show(i,"REDUCE S→(S)"); r=1;}
        else if(top>=0 && st[top]=='i')
            {st[top]='S'; show(i,"REDUCE S→i"); r=1;}
    }
}

int main(){
    printf("Enter input: "); scanf("%s",in); len=strlen(in);
    printf("\n%-15s%-15sAction\n-----------------------------------\n","Stack","Input");
    for(int i=0;i<len;i++){ st[++top]=in[i]; show(i+1,"SHIFT"); reduce(i+1); }
    if(top==0&&st[0]=='S') printf("$S\t\t$\t\tACCEPT\nAccepted.\n");
    else printf("Rejected.\n");
}
