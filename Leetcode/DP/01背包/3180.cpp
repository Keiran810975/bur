#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maxTotalReward(vector<int>& rewardValues) {
    int n = rewardValues.size();
    sort(rewardValues.begin(), rewardValues.end());
    vector<int> f(n + 1, 0); 
    for (int i = 0; i < n; i++) {
        for (int j = i-1; j >= 0; j--) {
            if (rewardValues[i] > f[j]) {
                f[j + 1] = max(f[j + 1], f[j] + rewardValues[i]);
            }
        }
    }
    return *max_element(f.begin(), f.end());
}
int main(){
    int t;cin>>t;

    vector<int> a(t);
    for(int i=0;i<t;i++){
        cin>>a[i];
    }
    int ans=maxTotalReward(a);
    cout<<'\n'<<ans<<'\n';
    return 0;
}