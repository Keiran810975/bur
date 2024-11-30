#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void gray(int n,int i){
    if(n==1&&i==1)printf("0\n");
    else if(n==1&&i==2)printf("1\n");
    else if(i<=(1<<(n-1))){printf("0");gray(n-1,i);}
    else if(i>(1<<(n-1))){printf("1");gray(n-1,(1<<n)-i+1); }
}
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=(1<<n);i++)gray(n,i);
    return 0;
}