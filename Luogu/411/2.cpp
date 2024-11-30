#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int b[100005];
int f[100005][2];
int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    f[0][0]=a[0];
    f[0][1]=b[0];
    for(int i=1;i<n;i++){
        f[i][0]=max(f[i-1][0]+a[i],f[i-1][1]);
        f[i][1]=max(f[i-1][0],f[i-1][1]+b[i]);
    }
    cout<<max(f[n-1][0],f[n-1][1]);

    return 0;
}