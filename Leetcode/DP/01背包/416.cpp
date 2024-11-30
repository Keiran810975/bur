#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool canPartition(vector<int>& nums) {
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n;i++)sum+=nums[i];
    if(sum%2==1)return false;
    int cap=sum/2;
    vector<int> f(sum+1,INT_MIN);
    f[0]=0;
    int s=0;
    for(int i=0;i<n;i++){
        s=(s+nums[i]>cap)?cap:s+nums[i];
        for(int j=s;j>=nums[i];j--){
            f[j]=max(f[j],f[j-nums[i]]+nums[i]);
        }
    } 
    return f[cap]>0;
}
int main(){

    return 0;
}