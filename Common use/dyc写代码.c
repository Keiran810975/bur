#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int dyc(int k){
    if(k==0)return 1;
    else if(k%3==0)return (dyc(k/3)+1);
    else return (dyc(k-1)+1);
}
int max(int x,int max){
    if(dyc(x)>dyc(x-1))max=dyc(x);
}
int main(){
    int t;scanf("%d",&t);
    for(int i=0;i<t;i++){
        long long l,r;scanf("%lld%lld",&l,&r);
        int max=0;
        for(long long j=l;j<=r;j++)if(dyc(j)>max)max=dyc(j);
        printf("%d\n",max);
    }
    

    return 0;
}