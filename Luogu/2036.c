#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int n;
int sour[20],bitter[20];
int st[20];
//int s=1,b;
int min=1e9;
void dfs(int x,int s,int b){
    if(x>n){
        if(s!=1||b!=0){
            int sub=abs(s-b);
            if(sub<min)min=sub;
        }
        return;
    }
    dfs(x+1,s*sour[x],b+bitter[x]);
    dfs(x+1,s,b);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&sour[i],&bitter[i]);
    }
    dfs(1,1,0);
    printf("%d\n",min);
    return 0;
}