#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[30];
int n,k;
int cnt;
bool isPrime(int n){
    if(n<2) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
void dfs(int m,int sum,int start){
    if(m==k){
        if(isPrime(sum)) cnt++;
        return;
    }
    for(int i=start;i<n;i++){
        dfs(m+1,sum+a[i],i+1);
    }
    return;
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(0,0,0);
    cout<<cnt<<endl;
    return 0;
}