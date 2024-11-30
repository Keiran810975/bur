#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long t;
long long n,a;
long long c[10100],e[10100];
int main(){
    
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&a);
        for(int i=0;i<n;i++)scanf("%lld",&c[i]);
        for(int i=0;i<n;i++)scanf("%lld",&e[i]);
        int cnt=0;
        int sig=0;
        for(int i=0;i<n;i++){
            if(a<c[i]&&a<e[i]){
                break;
            }
            cnt++;
            if(a>=c[i]&&a<e[i]){
                a+=c[i];
            }
            else if(a<c[i]&&a>=e[i]){
                a+=e[i];
            }
            else if(a>=c[i]&&a>=e[i]){
                long long maxx=a+c[i];
                if(a+e[i]>maxx)maxx=a+e[i];
                if(a+c[i]+e[i]>maxx)maxx=a+c[i]+e[i];
                a=maxx;
                //printf("$$%d$$",a);
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}