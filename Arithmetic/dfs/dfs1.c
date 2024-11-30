#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int n;
int st[100001];
void dfs(int x){
    if(x>n){
        for(int i=1;i<=n;i++){
            if(st[i]==1)printf("%d ",i);
        }
        printf("\n");
        return;
    }
    st[x]=2;
    dfs(x+1);
    st[x]=1;
    dfs(x+1);
    st[x]=0;
}


int main(){
    scanf("%d",&n);
    dfs(1);
    return 0;
}