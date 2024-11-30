#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int deleteAndEarn(vector<int>& nums) {
    vector<int> shit(20050);
    int n=nums.size();
    for(int i=0;i<n;i++){
        shit[nums[i]]+=nums[i];
    }
    vector<int> f(20055);
    f[0]=0;
    f[1]=shit[1];
    for(int i=1;i<20050;i++){
        f[i+1]=max(f[i],f[i-1]+shit[i]);
    }
    return f[20050];
}
int main(){

    return 0;
}