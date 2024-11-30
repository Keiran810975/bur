#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int n;
int cnt;
int arr[11];
void dfs(int x,int sum){
    if(sum>n)return;
    if(x>10){
        if(sum==n){
            for(int i=1;i<=10;i++)printf("%d ",arr[i]);
            printf("\n");
            cnt++;
        }
        return;
    }
    for(int i=1;i<=3;i++){
        //if(sum+i<=n){
            arr[x]=i;
            dfs(x+1,sum+i);
            arr[x]=0;
        //}
    }
}
int main(){
    scanf("%d",&n);
    dfs(1,0);
    return 0;
}