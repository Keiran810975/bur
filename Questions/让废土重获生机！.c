#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
long long f(long long n){
    int k;
    if(n==1||n==2)return 1;
    else{
        for(k=1;;k++){
        if((1<<k)+1<=n&&((1<<k)*3/2+1)>n)return ((1<<(k-1))+1);
        else if((1<<k)*3/2+1<=n&&((1<<(k+1))+1)>n)return (n-(1<<k));
    }
    }
    
}
int main(){
    long long m,n;scanf("%lld%lld",&m,&n);
   long long sum1=f(m)*f(n);long long sum2=m*f(n)+n*f(m)-f(m)*f(n);long long sum3=m*n-sum2;
   printf("%lld\n%lld\n%lld\n",sum1,sum2,sum3);
    return 0;
}