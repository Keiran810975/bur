#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    while(n--){
int t;cin>>t;
    int sig=1;
    int cnt=0;
    for(int i=0;i<2*t;i++){
        for(int j=0;j<2*t;j++){
            if((i/2+j/2)%2==1)cout<<'.';
            else cout<<'#';
    }
    cout<<'\n';
    }
    }
    return 0;
}