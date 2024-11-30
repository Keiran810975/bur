#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
char first[100];
char s[200][200];
int len[200];
int sig[200];
int sig2[200];
int main(){
    int n;scanf("%d",&n);
    scanf("%s",first);
    int l=strlen(first);
    int max=0;
    int flag;
    for(int i=0;i<n-1;i++){
        scanf("%s",s[i]);
        len[i]=strlen(s[i]);
        if(abs(l-len[i])>max){
            max=abs(l-len[i]);
            flag=i;
        }
    }
    //printf("%d",max);
    char aa[200];
    strcpy(aa,s[flag]);
    //printf("%s %s",first,aa);
    int fff;
    int a=strlen(aa);
    int b=strlen(first);
    fff=(a<b)?a:b;
    int ggg=(a>b)?a:b;
    printf("%s %s %d ",first,aa,max);
    // char ccc[200];
    // int k=0;
    // for(int i=0;i<fff;i++){
    //     if(first[i]!=aa[i]){
    //         if(a>b){
    //             ccc[k++]=aa[i];
    //             }
    //         else ccc[k++]=first[i];
    //     }
    // }
    //printf("%s %s %d %s",first,aa,max,ccc);
    //printf("%d\n",fff);
    if(b>a){
        for(int i=0;i<fff;i++){
            for(int j=0;j<b;j++){
                if(aa[i]==first[j]){
                    sig[j]=1;
                    break;
                }
            }
        }
        }else{
            for(int i=0;i<fff;i++){
            for(int j=0;j<a;j++){
                if(aa[j]==first[i]){
                    sig[j]=1;
                    break;
                    }
            }
        }
    }
    //for(int i=0;i<30;i++)printf("%d",sig[i]);
    if(b>a){
        for(int i=0;i<ggg;i++)
        if(sig[i]==0)printf("%c",first[i]);
    }else{
        for(int i=0;i<ggg;i++)
        if(sig[i]==0)printf("%c",aa[i]);
    }
    
    printf("\n");
    return 0;
}