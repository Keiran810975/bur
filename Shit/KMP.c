#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int next[100];
char str[1000],sub[1000];
void CreateNext(){
    int i=1,j=1;
    int l=strlen(sub);
    int prelen=0;//当前共同前后缀的长度
    while(i<l){
        if(sub[prelen]==sub[i]){
            prelen++;
            next[j++]=prelen;
            i++;
        }else{
            if(prelen==0){
                next[j++]=0;
                i++;
            }else{
                prelen=next[prelen-1];
            }
        }
    }
}
int kmp(){
    int i=0,j=0;
    int l=strlen(str);
    while(i<l){
        if(str[i]==sub[j]){
            i++;
            j++;
        }else if(j>0)j=next[j-1];
        else i++;
        if(j==strlen(sub))return (i-j);
    }
}
int main(){
    scanf("%s%s",str,sub);
    CreateNext();
    //for(int i=0;i<5;i++)printf("%d ",next[i]);
    printf("%d",kmp());
    return 0;
}