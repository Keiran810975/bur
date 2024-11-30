#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[10]={1,2,3,4,5,6,7,8,9};
//全排列
int q,w,e;
int cnt;
void permutation(int k,int n){
    if(k==n){
        int x=100*a[0]+10*a[1]+a[2];
        int y=100*a[3]+10*a[4]+a[5];
        int z=100*a[6]+10*a[7]+a[8];
        if(w*x==q*y&&e*x==q*z){
            cout<<x<<" "<<y<<" "<<z<<endl;
            cnt++;
        }
    }
    else{
        for(int i=k;i<n;i++){
            swap(a[k],a[i]);
            permutation(k+1,n);
            swap(a[k],a[i]);
        }
    }
}
int main(){
    cin>>q>>w>>e;
    permutation(0,9);
    if(cnt==0) cout<<"No!!!"<<endl;

    return 0;
}