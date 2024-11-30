#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubsequence(vector<int>& nums, int target) {
    vector<int> f(target+1,INT_MIN);
    f[0]=0;
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n;i++){
        if(sum+nums[i]>target)sum=target;
        else sum+=nums[i];
        for(int j=sum;j>=nums[i];j--){
            f[j]=max(f[j],f[j-nums[i]]+1);
        }
    }
    return f[target]>0 ? f[target] : -1;         
}
int main(){

    return 0;
}