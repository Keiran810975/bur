#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long squ=0,rec=0;
    int n,m;
    cin>>n>>m;
    int x=min(n,m);
    int y=max(n,m);
    for(int i=1;i<=x;i++){
        squ+=(x-i+1)*(y-i+1);
    }
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if(i==j) continue;
            rec+=((x-i+1)*(y-j+1));
        }
    }
    cout<<squ<<" "<<rec<<endl;
    return 0;
}