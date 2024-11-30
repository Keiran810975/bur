#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
    int sum=0;
    int n;scanf("%d",&n);
    sum+=n;
    while(1){
        char c;
        scanf("%c",&c);
        int x;
        if(c=='+'){
            scanf("%d",&x);sum+=x;
        }
        else if(c=='-'){
            scanf("%d",&x);sum-=x;
        }
        else if(c=='='){
            break;
        }
    }
    printf("%d",sum);
    return 0;
}