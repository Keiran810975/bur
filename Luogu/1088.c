#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int st[10030],first[10030],arr[10030];
int cnt;
int n,m;
int sig=0;
void dfs(int x){
    if(sig==1)return;
    if(x>n){
        cnt++;
        if(cnt==m+1){
            for(int i=1;i<=n;i++){
                printf("%d ",arr[i]);
            }
            printf("\n");
            sig=1;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        //从火星人的数开始
        if(!cnt){
            i=first[x];
        }
        if(!st[i]){
            st[i]=1;
            arr[x]=i;
            dfs(x+1);
            st[i]=0;
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&first[i]);
    dfs(1);
    return 0;
}