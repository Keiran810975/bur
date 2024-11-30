#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int f[10000],a[10000],sg[10000];
bool vis[10000];
void getSG(int n){
    for(int i=1;i<=n;i++){
        for(int j=0;f[j]<=i;j++)vis[sg[i-f[j]]]=1;
        for(int j=0;j<=n;j++){
            if(!vis[j]){
                sg[i]=j;break;
            }
        }
    }
}
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)f[i]=i;//f[]：可以取走石子的个数
    getSG(n);
    
    return 0;
}