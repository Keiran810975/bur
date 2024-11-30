#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
char f[100];
    char s[100];
int main(){
    gets(f);
    int sig;
    if(f[1]=='-')sig=1;
    else sig=0;
    int m=0,n=0;
    if(sig==1){
        int i;
        for(i=2;f[i]>='0'&&f[i]<='9';i++){
            m=10*m+f[i]-'0';
        }
        i++;
        for(;f[i]>='0'&&f[i]<='9';i++){
            n=10*n+f[i]-'0';
        }
    }
    else if(sig==0){
        int i;
        for(i=1;f[i]>='0'&&f[i]<='9';i++){
            m=10*m+f[i]-'0';
        }
        i++;
        for(;f[i]>='0'&&f[i]<='9';i++){
            n=10*n+f[i]-'0';
        }
    }
    //printf("%d %d",m,n);
    gets(s);
    int l=strlen(s);
    if(sig==1){
        if(l<=m){
            for(int j=0;j<n-l;j++)printf("#");
            printf("%s",s);
            printf("\n");
        }
        else if(l>m){
            for(int j=0;j<n-m;j++)printf("#");
            for(int j=0;j<m;j++)printf("%c",s[j]);
            printf("\n");
        }
    }
    else if(sig==0){
        if(l<=m){
            printf("%s",s);
            for(int j=0;j<n-l;j++)printf("#");
            printf("\n");
        }
        else if(l>m){
            for(int j=0;j<m;j++)printf("%c",s[j]);
            for(int j=0;j<n-m;j++)printf("#");
            printf("\n");
        }
    }
    return 0;
}