#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
long long fac(int n){
    long long x=1;
    for(int i=1;i<=n;i++)x*=i;
    return x;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",fac(fac(n))%1000000007);
    }

    return 0;
}