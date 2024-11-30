#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int shit=0;
    int n=customers.size();
    for(int i=0;i<n;i++){
        shit+=customers[i]*(grumpy[i]^1);
    }
    int cnt=0,maxc=0;
    for(int i=0;i<n;i++){
        if(grumpy[i]==1)cnt+=customers[i];
        if(i<minutes-1)continue;
        maxc=max(maxc,cnt);
        if(grumpy[i-minutes+1]==1)cnt-=customers[i-minutes+1];
    }
    return shit+maxc;
}
int main(){

    return 0;
}