#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
double findMaxAverage(vector<int>& nums, int k) {
    int n=nums.size();
    int sum=0;
    int ans=-INT_MAX;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        if(i<k-1)continue;
        ans=max(ans,sum);
        sum-=nums[i-k+1];
    }
    return (double)ans/k;
}
int main(){


    return 0;
}