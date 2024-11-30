#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int n,k;
int st[250];
int cnt;
void dfs(int x,int sum,int start){
    if(sum>n)return;
    //if(x<=k&&sum==n)return;
    if(x>k){
        if(sum==n){
            cnt++;
        }
        return;
    }
    for(int i=start;sum+i*(k-x+1)<=n;i++){
        start=i;
        dfs(x+1,sum+i,start);
    }
}
int main(){
    scanf("%d%d",&n,&k);
    dfs(1,0,1);
    printf("%d\n",cnt);
    return 0;
}