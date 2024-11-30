#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int ff(int n){
    int sum=0;int sums=0; 
    for(int k=1;k<=n;k++)sum+=k;
    if(n==1)return 1;
    else if(n==2||n==3||n==4||n==5)return 2;
    else if(n%2==0){
        int cnt=0,i;
        for(i=n-2;i>0;i-=4){cnt++;sums+=i;}
        sum-=sums;
        ff(cnt);
    }
    else if(n%2==1){
        int cnt=0,i;
        for(i=n-3;i>0;i-=4){cnt++;sums+=i;}
        sum-=sums;
        ff(cnt);
    }
    return sum;
}
int main(){
    int n;scanf("%d",&n);
    printf("%d",ff(n));
    return 0;
}