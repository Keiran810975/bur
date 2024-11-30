#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char num[1000001];
int main(){
    scanf("%s",num);
    long long m;scanf("%lld",&m);
    int x=num[0]-'0';
    long long b=x%m;
    for(int i=1;i<strlen(num);i++){
        b=(b*10+x)%m;
    }
    printf("%lld",b);
    return 0;
}