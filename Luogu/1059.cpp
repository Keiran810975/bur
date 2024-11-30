#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int arr[1100];
int main(){
    int n,k=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int s;
        cin>>s;
        if(arr[s]==0){
            arr[s]++;
            k++;
        }
    }
    cout<<k<<'\n';
    for(int i=1;i<=1000;i++){
        if(arr[i]>0){
            cout<<i<<" ";
        }
    }
    return 0;
}