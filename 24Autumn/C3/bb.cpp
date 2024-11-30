#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int p[10010];
int f[10010];
int cut[10010];
int ans[10010];
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(i<j)continue;
            if(f[i]<p[j]+f[i-j]){
                f[i]=p[j]+f[i-j];
                cut[i]=j;
            }
        }
    }
    int k=0,r=n;
    while(r>0){
        ans[k++]=cut[r];
        r-=cut[r];
    }

    printf("%d\n%d\n",f[n],k);
    for(int i=0;i<k;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");

    return 0;
}