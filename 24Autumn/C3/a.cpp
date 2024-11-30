#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int m;
//三者最大值
int max(int a,int b,int c){
    return max(max(a,b),c);
}
int line[3][10005];
int cache[3][10005];
int timee[3][3];
//第i条，第j个装配站
int dfs(int i,int j){
    if(i<0||j<0)return 0;
    if(cache[i][j]!=-1)return cache[i][j];
    if(i==2){
        cache[i][j]=min(dfs(0,j-1)+timee[i][0],dfs(1,j-1)+timee[i][1],dfs(i,j-1));
    }
    else if(i==1){
        cache[i][j]=min(dfs(0,j-1)+timee[i][0],dfs(2,j-1)+timee[i][2],dfs(i,j-1));
    }
    else if(i==0){
        cache[i][j]=min(dfs(1,j-1)+timee[i][1],dfs(2,j-1)+timee[i][2],dfs(i,j-1));
    }
    return cache[i][j];
}
int main(){
    int t;
    while(t--){
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
        int res=min(dfs(0,m-1),dfs(1,m-1),dfs(2,m-1));
        printf("%d\n",res);
    }
    return 0;
}