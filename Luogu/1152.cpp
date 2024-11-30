#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int arr[11000000];
int sub[11000000];
int main(){
    int n=0;
    int x;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=1;i<n;i++){
        int a=abs(arr[i]-arr[i-1]);
        sub[a]+=1;
    }
    bool flag=true;
    for(int i=1;i<=n-1;i++){
        if(sub[i]==0)flag=false;
    }
    if(flag)cout<<"Jolly"<<endl;
    else cout<<"Not jolly"<<endl;
    return 0;
}