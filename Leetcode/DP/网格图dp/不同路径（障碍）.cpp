#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m=obstacleGrid.size(),n=obstacleGrid[0].size();
    int f[110][110];
    memset(f,0,sizeof f);
    f[0][0]=obstacleGrid[0][0]?0:1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(obstacleGrid[i][j])f[i][j]=0;
            else{
                if(i>0)f[i][j]+=f[i-1][j];
                if(j>0)f[i][j]+=f[i][j-1];
            }
        }
    }
    return f[m-1][n-1];
}
int main(){

    return 0;
}