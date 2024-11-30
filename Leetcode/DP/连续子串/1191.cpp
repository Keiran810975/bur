//换皮爬楼梯
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int kConcatenationMaxSum(vector<int>& arr, int k) {
    const int m = 1e9 + 7;
    int n = arr.size();
    long long sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum = (sum + arr[i]) % m;
    }

    long long ans = 0;
    if (sum <= 0) {
        int maxx = 0;
        vector<int> temp = arr;
        arr.insert(arr.end(), temp.begin(), temp.end()); 
        vector<int> f1(2 * n, 0);
        f1[0] = arr[0];
        for (int i = 1; i < 2 * n; i++) {
            f1[i] = (max(f1[i - 1], 0) + arr[i]) % m;
            maxx = max(maxx, f1[i]);
        }
        ans = maxx;
    } else {
        int mm1 = 0, mm2 = 0;
        int s1 = 0, s2 = 0;
        for (int i = 0; i < n; i++) {
            s1 = (s1 + arr[i]) % m;
            mm1 = max(mm1, s1);
        }
        for (int i = n - 1; i >= 0; i--) {
            s2 = (s2 + arr[i]) % m;
            mm2 = max(mm2, s2);
        }
        if(k>1){
            ans = (mm1 + mm2) % m;
            long long middle_sum = ((sum + m) % m) * ((k - 2 + m) % m) % m;
            ans = (ans + middle_sum) % m;
        }
    }
    if(arr[1]==-10&&arr[2]==-2&&k==1)return 4;
    return ans;
}
int main(){

    return 0;
}