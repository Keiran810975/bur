#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
int w[100010];
int f[100010][2];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    f[1][0]=0;
    f[1][1]=w[1];
    for(int i=2;i<=n;i++){
        f[i][0]=max(f[i-1][0],f[i-1][1]);
        f[i][1]=f[i-1][0]+w[i];
    }
    printf("%d\n",max(f[n][1],f[n][0]));

    return 0;
}