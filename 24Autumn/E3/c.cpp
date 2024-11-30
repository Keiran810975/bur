#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,contain;
int v,w;
const int MM=250000;
int f[MM+1];
signed main(){
    scanf("%lld%lld",&n,&contain);
    for(int i=1;i<=MM;i++){
        f[i]=contain+1;
    }
    f[0]=0;
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&v,&w);
        for(int j=MM;j>=w;j--){
            f[j]=min(f[j],f[j-w]+v);
        }
    }
    int res=0;
    for(int j=0;j<=MM;j++){
        if(f[j]<=contain){
            res=j;
        }
    }
    printf("%lld\n",res);
    return 0;
}