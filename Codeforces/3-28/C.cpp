#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int h,m;
        scanf("%02d:%02d",&h,&m);
        if(h>12){
            h-=12;
            printf("%02d:%02d PM\n",h,m);
        }else if(h>0&&h<12){
            printf("%02d:%02d AM\n",h,m);
        }else if(h==0){
            h=12;
            printf("%02d:%02d AM\n",h,m);
        }else if(h==12){
            printf("%02d:%02d PM\n",h,m);
        }
    }
    return 0;
}