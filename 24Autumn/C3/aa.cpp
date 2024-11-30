#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int m;
//三者最大值
int max(int a,int b,int c){
    return max(max(a,b),c);
}
//三者最小值
long long min(long long a,long long b,long long c){
    return min(min(a,b),c);
}
long long line[3][10005];
long long cache[3][10005];
long long timee[3][3];
//第i条，第j个装配站
long long dfs(int i,int j){
    if(j==0)return line[i][j];
    if(cache[i][j]!=-1)return cache[i][j];
    if(i==2){
        cache[i][j]=min(dfs(0,j-1)+timee[0][i],dfs(1,j-1)+timee[1][i],dfs(i,j-1))+line[i][j];
    }
    else if(i==1){
        cache[i][j]=min(dfs(0,j-1)+timee[0][i],dfs(2,j-1)+timee[2][i],dfs(i,j-1))+line[i][j];
    }
    else if(i==0){
        cache[i][j]=min(dfs(1,j-1)+timee[1][i],dfs(2,j-1)+timee[2][i],dfs(i,j-1))+line[i][j];
    }
    return cache[i][j];
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(cache,-1,sizeof(cache));
        scanf("%d",&m);
        for(int i=0;i<3;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&line[i][j]);
            }
        }
        
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++){
                scanf("%d",&timee[i][j]);
            }
        long long res=min(dfs(0,m-1),dfs(1,m-1),dfs(2,m-1));
        printf("%lld\n",res);
    }
    return 0;
}