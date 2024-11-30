#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isInterleave(string s1, string s2, string s3) {
    int n = s1.length(), m = s2.length(), t = s3.length();
    if (n + m != t) return false; // 长度不匹配，直接返回 false
    // 使用一维 DP 数组优化空间
    vector<bool> dp(m + 1, false);
    dp[0] = true; // 初始化 dp[0] 表示空串匹配情况
    // 处理 s2 和 s3 的匹配情况
    for (int j = 1; j <= m; j++) {
        dp[j] = dp[j - 1] && (s2[j - 1] == s3[j - 1]);
    }
    // 遍历 s1 和 s2，更新 dp 数组
    for (int i = 1; i <= n; i++) {
        dp[0] = dp[0] && (s1[i - 1] == s3[i - 1]); // 处理 s1 和 s3 的匹配情况
        for (int j = 1; j <= m; j++) {
            dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
    }
    return dp[m];
}

int main(){

    return 0;
}