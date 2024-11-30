#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int isPrime(int n){
    if(n==1) return 0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int arr[50];
int sum=0;
int n,k,cnt;
void dfs(int x,int start){
    //剪枝
    if(x+n-start<k) return;
    if(x>k){
        if(isPrime(sum)) cnt++;
        return;
    }
    for(int i=start;i<=n;i++){
        sum+=arr[i];
        dfs(x+1,i+1);
        sum-=arr[i];
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    dfs(1,1);
    printf("%d\n",cnt);
    return 0;
}