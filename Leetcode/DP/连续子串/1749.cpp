//换皮爬楼梯
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maxAbsoluteSum(vector<int>& nums) {
    int n=nums.size();
    vector<int> f(n,0);
    int ans=0;
    f[0]=nums[0];
    for(int i=1;i<n;i++){
        if((f[i-1]>=0&&nums[i]>=0)||(f[i-1]<=0&&nums[i]<=0))f[i]=f[i-1]+nums[i];
        else{
            if(abs(nums[i]+f[i-1])>=abs(nums[i]))f[i]=f[i-1]+nums[i];
            else f[i]=nums[i];
        }
        ans=max(ans,abs(f[i]));
    }
    return ans;
}
int main(){

    return 0;
}