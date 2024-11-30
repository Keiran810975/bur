#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int n,k;
int arr[22];
void dfs(int x,int start){
    if(x>k){
        for(int i=1;i<=k;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i=start;i<=n;i++){
        arr[x]=i;
        dfs(x+1,i+1);
        arr[x]=0; 
    }
}
int main(){
    scanf("%d%d",&n,&k);
    dfs(1,1);
    return 0;
}