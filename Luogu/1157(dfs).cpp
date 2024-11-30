#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[30];
int n,k;
int ans[30];
void dfs(int m,int start){
    if(m==k){
        for(int i=0;i<k;i++)cout << setw(3) << ans[i];
        cout << endl;
        return;
    }
    for(int i=start;i<n;i++){
        ans[m]=a[i];
        dfs(m+1,i+1);
    }
    return;
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
    dfs(0,0);
    return 0;
}