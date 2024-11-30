#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char pin[150000]=" ";
char aa[320][320];
int main(){
    scanf("%s",pin);
    int n;int len=strlen(pin);
    if((int)(sqrt(len))==sqrt(len))n=sqrt(len);
    else n=sqrt(len)+1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            aa[i][j]=pin[i*n+j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(aa[j][i]!=' ')printf("%c",aa[j][i]);
        }
    }
    return 0;
}