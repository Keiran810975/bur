#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    int x;
    while(t--){
        int n;cin>>n;
        for(int i=2;;i++){
            char a[10]={'\0'};
            int cnt=0;
            int j=i;
            while(j){
                a[cnt++]=j%2+'0';
                j/=2;
            }
            strrev(a);
            //cout<<a<<'\n';
            x=atoi(a);
            cout<<x<<' ';
            if(x<=n){
                while(n%x==0){
                    n/=x;
                }
            }
            if(n==1){
                cout<<"YES"<<'\n';
                break;
            }else if(n<x){
                cout<<"NO"<<'\n';
                break;
            }
        }
    }
    return 0;
}