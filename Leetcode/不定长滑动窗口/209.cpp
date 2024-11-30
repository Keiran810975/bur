#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int minSubArrayLen(int target, vector<int>& nums) {
    int l=0;
    int n=nums.size();
    int len=0;
    int maxLen=INT_MAX;
    int sum=0;
    for(int r=0;r<n;r++){
        sum+=nums[r];
        if(sum<target)continue;
        while(sum>=target){
            sum-=nums[l];
            l++;
        }
        len=r-l+2;
        maxLen=min(maxLen,len);
    }     
    return maxLen==INT_MAX ? 0 : maxLen;
}
int main(){

    return 0;
}