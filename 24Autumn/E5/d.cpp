#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[100010];
int mid[100010];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int t,tt;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        mid[0]=a[0],t=a[0],tt=a[0];
        int m=(n+1)/2;
        for(int i=1;i<m;i++){
            int x=a[2*i-1],y=a[2*i];
            if(x<mid[i-1])t=x;
            if(y<mid[i-1]&&y>x)t=y;
            if(x>mid[i-1])tt=x;
            if(y>mid[i-1]&&y<x)tt=y;
            if((x>=mid[i-1]&&y<=mid[i-1])||(x<=mid[i-1]&&y>=mid[i-1])){
                mid[i]=mid[i-1];
            }
            else if(x>mid[i-1]&&y>mid[i-1]){
                mid[i]=tt;
            }else{
                mid[i]=t;
            }
        }
        for(int i=0;i<m;i++){
            cout<<mid[i]<<" ";
        }
        printf("\n");
    }
    return 0;
}