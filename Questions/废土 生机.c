#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
long long f(long long n){
    int k;
    if(n==1||n==2)return 1;
    else{
        for(k=1;k<=31;k++){
        if((2<<k)+1<=n&&(3*(2<<k)/2+1)>n)return ((2<<(k-1))+1);
        else if(3*(2<<k)/2+1<=n&&(2<<k+1)>n)return (n-(2<<k));
    }
    }
    
}
int main(){
    int m,n;scanf("%d%d",&m,&n);
   long long sum1=f(m)*f(n);long long sum2=m*f(n)+(n-f(n))*f(m);long long sum3=m*n-sum2;
   printf("%lld\n%lld\n%lld\n",sum1,sum2,sum3);
    return 0;
}