//打家劫舍
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int rob(vector<int>& nums) {
    int n=nums.size();
    vector<int> f(n+1);
    f[0]=0;
    f[1]=nums[0];
    for(int i=1;i<n;i++){
        f[i+1]=max(f[i],f[i-1]+nums[i]);
    }
    return f[n];
}
int main(){

    return 0;
}