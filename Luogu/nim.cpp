#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int stone[11000];
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int f;
        for(int i=0;i<n;i++)cin>>stone[i];
        f=stone[0];
        for(int i=1;i<n;i++)f^=stone[i];
        if(f)cout<<"Yes"<<'\n';
        else cout<<"No"<<'\n';
    }
    return 0;
}