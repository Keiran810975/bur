#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int n,k;
char board[11][11];
int st[11];
int res;
void dfs(int x,int cnt){
    if(cnt==k){
        res++;
        return;
    }
    if(x==n)return; 
    for(int i=0;i<n;i++){
        if(board[x][i]=='#'&&st[x]==0){
            st[x]=1;
            dfs(x+1,cnt+1);
            st[x]=0;
        }
    }
    dfs(x+1,cnt);
}
int main(){
    while(scanf("%d%d",&n,&k)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%s",board[i]);
        }
        res=0;
        dfs(0);
        printf("%d\n",res);
    }
    return 0;
}
