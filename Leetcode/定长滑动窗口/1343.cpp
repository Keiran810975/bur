#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int x=k*threshold;
    int n=arr.size();
    int sum=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(i<k-1)continue;
        if(sum>=x)cnt++;
        sum-=arr[i-k+1];
    }
    return cnt;
}
int main(){

    return 0;
}