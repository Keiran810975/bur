#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int node[50];
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>node[i];
    if(node[1]&&node[n]){
        int left=0,right=0;
        for(int i=1;i<=n;i++){
            if(node[i])right++;
            else break;
        }
        for(int i=n;i>=1;i--){
            if(node[i])left++;
            else break;
        }
        //cout<<left<<' '<<right<<' ';
        if(left&1||right&1)cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }else if(!node[1]&&!node[n])cout<<"NO"<<'\n';
    else if(!node[1]&&node[n]){
        int left=0;
        for(int i=n;i>=1;i--){
            if(node[i])left++;
            else break;
        }
        if(left&1)cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }else{
        int right=0;
        for(int i=1;i<=n;i++){
            if(node[i])right++;
            else break;
        }
        //cout<<left<<' '<<right<<' ';
        if(right&1)cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}