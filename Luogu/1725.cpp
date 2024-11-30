#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,l,r;
int a[200020];
int f[200020];
int main(){
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=l;j<=r;j++){
            if(i+j>n){
                ans=max(ans,f[i]);
            }else{
                f[i+j]=max(f[i+j],f[i]+a[i+j]);
            }
        }
    }
    printf("%d\n",ans);

    return 0;
}