#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        if(n%2==0){
            cout<<"YES"<<'\n';
            int sig=1;
            for(int i=0;i<n/2;i++){
                if(sig==1){
                    cout<<"AA";
                }else{
                    cout<<"BB";
                }
                sig*=-1;
            }
            cout<<'\n';
        }else{
            cout<<"NO"<<'\n';
        }
    }
    return 0;
}