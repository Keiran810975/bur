#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int n;
int st[20],arr[20];
int col[20];
int diag[100];//记录对角线是否已经有棋子
int diag2[100];
int cnt;
void dfs(int x){
    if(x>n){
        cnt++;
        if(cnt<=3){
            for(int i=1;i<=n;i++){
                printf("%d ",arr[i]);
            }
            printf("\n");
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!st[x]&&!diag[i-x+20]&&!col[i]&&!diag2[i+x]){
            st[x]=1;
            diag[i-x+20]=1;
            col[i]=1;
            diag2[i+x]=1;
            arr[x]=i;
            dfs(x+1);
            st[x]=0;
            diag[i-x+20]=0;
            col[i]=0;
            diag2[i+x]=0;
        }
    }
}
int main(){
    scanf("%d",&n);
    dfs(1);
    printf("%d\n",cnt);
    return 0;
}