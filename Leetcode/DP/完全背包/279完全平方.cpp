#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int numSquares(int n) {
    vector<int> f(n+1,INT_MAX/2);
    f[0]=0;
    for(int i=0;i<=100;i++){
        for(int j=i*i;j<=n;j++){
            f[j]=min(f[j],f[j-i*i]+1);
        }
    }
    return f[n];
}
int main(){

    return 0;
}