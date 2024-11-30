#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100010];
signed main(){
    int n,x;
    int cnt=0;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    if(a[0]>x){
        cnt+=a[0]-x;
        a[0]=x;
    }
    for(int i=1;i<n;i++){
        if(a[i]+a[i-1]>x){
            int c=a[i]+a[i-1]-x;
            cnt+=c;
            if(a[i]>=c)a[i]-=c;
            else{
                int tmp=cnt-a[i];
                a[i]=0;
                a[i-1]-=tmp;
            }
        }
    }
    printf("%lld\n",cnt);

    return 0;
}