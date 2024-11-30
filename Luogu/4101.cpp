#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int h=n/m;
        if(n%m!=0)h++;
        //cout<<h<<'\n';
        int x=n-h;
        if(x&1)cout<<"0"<<'\n';
        else cout<<"1"<<'\n';
    }
    return 0;
}