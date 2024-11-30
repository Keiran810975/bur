// 这里有 n 个一样的骰子，每个骰子上都有 k 个面，分别标号为 1 到 k 。
// 给定三个整数 n、k 和 target，请返回投掷骰子的所有可能得到的结果（共有 kn 种方式），使得骰子面朝上的数字总和等于 target。
// 由于答案可能很大，你需要对 109 + 7 取模。
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int numRollsToTarget(int n, int k, int target) {
    if(target<n||target>n*k)return 0;
    const int m=1e9+7;
    vector<vector<int>> f(n+1,vector<int>(target+1));
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=target-n;j++){
            for(int h=0;h<k&&h<=j;h++){
                f[i][j]+=f[i-1][j-h];
                f[i][j]%=m;
            }
        }
    }
    return f[n][target-n];
}
int main(){

    return 0;
}