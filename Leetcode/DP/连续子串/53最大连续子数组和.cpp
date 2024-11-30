#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int>& nums) {
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
    vector<int> f(n+1,0);
    f[0]=nums[0];
    int ans=f[0];
    for(int i=1;i<n;i++){
        f[i]=max(f[i-1],0)+nums[i];
        ans=max(ans,f[i]);
    }
    return ans;
    }
}
int main(){

    return 0;
}