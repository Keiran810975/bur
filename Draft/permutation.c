#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int a[50];int n;
int vis[50]={0};
void perm(int index){
    if(index==n){
        for(int i=0;i<n;i++)printf("%d ",a[i]);
        printf("\n");
    }
    for(int j=1;j<=n;j++){
        if(vis[j]==0){
            a[index]=j;
            vis[j]=1;
            perm(index+1);
            vis[j]=0;
        }
    }
}
int main(){
    scanf("%d",&n);
    perm(0);
    return 0;
}