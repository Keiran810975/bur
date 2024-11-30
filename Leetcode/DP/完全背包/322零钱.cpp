#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
    int n=coins.size();
    vector<int> f(amount+1,INT_MAX);
    f[0]=0;
    for(int i=0;i<n;i++){
        for(int j=coins[i];j<=amount;j++){
            f[j]=min(f[j-coins[i]]+1,f[j]);
        }

    }      
    return f[amount]==INT_MAX?f[amount]:-1;  
}
int main(){

    return 0;
}