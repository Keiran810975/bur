#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    while(n--){
        int x,y;
        cin>>x>>y;
        int a,b;
        a=(x>y)?x:y;
        b=(x<y)?x:y;
        int d=a/b;
        if(d>=2)cout<<"Stan wins"<<'\n';
        else{
            int cnt=0;
            while(a&&b){
                cnt++;
                d=max(a/b,b/a);
                if(d>=2)break;
                if(a>=b)a-=b;
                else b-=a;
            }
            if(cnt&1)cout<<"Stan wins"<<'\n';
            else cout<<"Ollie wins"<<'\n';
        }
    }
    return 0;
}