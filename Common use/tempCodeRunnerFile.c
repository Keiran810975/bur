#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
long long f(long long n){
        long long lsum=0;long long lnum=n;long long cnt=1;long long cnt2=1;
    for(long long i=1;i<=n;i++)lsum+=i;
    if(lnum==1)return lsum;
    else if(lnum%2==0){
        lsum=(lsum+lnum/2)/2;cnt+=2;lnum=lnum/2;f(lnum);
    }
    else if(lnum%2==1){
        lsum-=n-cnt2+1+(lsum-(n-cnt2+1))/2;lsum+=cnt*((lnum-1)/2);
        cnt+=2;cnt2+=1;lnum=(lnum-1)/2;f(lnum);
    }
    }
int main(){
    long long n;scanf("%lld",&n);
    printf("%lld",f(n));
    return 0;
}