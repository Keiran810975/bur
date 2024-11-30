#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
const int mod=998244353;
//三叉卡特兰数  
//i+j+k=n
//求和dp[i]*dp[j]*dp[k]

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("$$%lld\n",catalan(n));
    }
    return 0;
}