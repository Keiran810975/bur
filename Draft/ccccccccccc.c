#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int main(){
    char s[100];
    FILE *op=fopen("in.txt","r");
    FILE *ou=fopen("in_crpyt.txt","w");
    gets(s);
    char ch[1000];
    fputs(s,ou);
    while(fgets(ch,1000,op)!=NULL){
        fputs(ch,ou);
    }
    return 0;
}