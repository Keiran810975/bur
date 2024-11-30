//换皮爬楼梯
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int countGoodStrings(int low, int high, int zero, int one) {
    vector<int> f(high+1);
    const int m=1e9+7;
    f[0]=1;
    int ans=0;
    for(int i=0;i<=high;i++){
        if(i>=zero)f[i]=f[i-zero];
        if(i>=one){
            f[i]+=f[i-one];
            f[i]%=m;
        }
        if(i>=low){
            ans+=f[i];
            ans%=m;
        }
    }
    return ans;
}
int main(){

    return 0;
}