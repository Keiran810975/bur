#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[100005], b[100005], c[100005];
int m,n,k;
int f[100005][100005];
void dp(){
    f[0][0]=0;
    for(int i=1;i<=n;i++){
        f[i][c[i]]=max(f[i-1][c[i]]+a[c[i]],)
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        for(int i=0;i<n;i++)scanf("%d",&b[i]);
        scanf("%d",&m);
        for(int i=0;i<m;i++)scanf("%d",&c[i]);
    }
    return 0;
}