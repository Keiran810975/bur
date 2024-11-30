#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void ex(unsigned int n){
    if(n==0){
        printf("0");return;
    }
    int p=0;
    for(int i=31;i>=0;i--){
        if(((n>>i)&1)==1){
            if(!p)p++;
            else printf("+");
            printf("2(");
            ex(i);
            printf(")");
        }
    }
}
int main(){
    unsigned int n;scanf("%u",&n);
    ex(n);
    return 0;
}