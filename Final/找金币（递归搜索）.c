#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int cnt;int a[110][110];int flag[110][110];
void shit(int i,int j){
    if(a[i][j]==0||flag[i][j]==1)return;
    cnt+=a[i][j];flag[i][j]=1;
    shit(i+1,j);
    shit(i-1,j);
    shit(i,j-1);
    shit(i,j+1);
}
int main(){
   int n;scanf("%d",&n);
   for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        scanf("%d",&a[i][j]);
    }
   }
   int max=0;
   for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        int flag[110][110]={0};
        shit(i,j);
        if(cnt>max)max=cnt;
        cnt=0;
    }
   }
   printf("%d",max);
    return 0;
}