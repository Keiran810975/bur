#include<stdio.h>
int main(){
    int n,m,lim;
    scanf("%d%d%d",&n,&m,&lim);
    int d[200001]={0};
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        d[a]+=c;d[b+1]-=c;
    }
    int sum=0,cnt=0;
    for(int i=1;i<=n;i++){
        sum+=d[i];
        if(sum>=lim)cnt++;
    }
    printf("%d",cnt);
    return 0;
}