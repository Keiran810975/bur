#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int findTargetSumWays(vector<int>& nums, int target) {
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
    }
    sum-=abs(target);
    if(sum<0||sum%2)return 0;
    int cap=sum/2;
    vector<int> f(cap+1,0);
    f[0]=1;
    for(int i=0;i<n;i++){
        for(int j=cap;j>=nums[i];j--){
            f[j]+=f[j-nums[i]];
        }
    }
    return f[cap];
}
int main(){

    return 0;
}