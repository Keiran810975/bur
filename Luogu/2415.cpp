#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[1000];
long long ans=0;
int main() {
    int n=0;
    while(cin>>a[n++]);
    for(int i=0;i<n;i++){
        ans+=a[i];
    }
    ans*=pow(2,n-2);
    cout<<ans;

}