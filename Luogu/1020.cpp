#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int m[100010];
int f[100010];
int d[100010];
int main(){
    int n=1;
    while(scanf("%d",&m[n])!=EOF){
        n++;
    }
    n--;
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(m[i]<=m[j]){
                f[i]=max(f[i],f[j]);
            }
        }
        f[i]+=1;
        ans=max(ans,f[i]);
    }
    printf("%d\n",ans);
    
    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(m[i]>m[j]){
                d[i]=max(d[i],d[j]);
            }
        }
        d[i]+=1;
        res=max(res,d[i]);
    }
    printf("%d\n",res);


    return 0;
}