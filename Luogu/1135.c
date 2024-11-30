#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int n,a,b;
int k[250];
int shit[250];
int min=1e9;
//int st[250];
void dfs(int floor,int cnt){
    if(cnt>=min)return;
    if(floor<1||floor>n)return;
    if(cnt>=shit[floor])return;
    if(floor==b){
        min=cnt;
        return;
    }
    shit[floor]=cnt;
    if(floor+k[floor]<=n){
        //st[floor+k[floor]]=1;
        dfs(floor+k[floor],cnt+1);
        //st[floor+k[floor]]=0;
    }
    if(floor-k[floor]>0){
        //st[floor-k[floor]]=1;
        dfs(floor-k[floor],cnt+1);
        //st[floor-k[floor]]=0;
    }
    
}
int main(){
    //memset(shit,1e9,sizeof(shit));
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        shit[i]=1e9;
    }
    dfs(a,0);
    if(min!=1e9)printf("%d\n",min);
    else printf("-1\n");
    return 0;
}