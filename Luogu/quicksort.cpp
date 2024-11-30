#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[1000],b[1000],c[1000],d[1000];
void quicksort(int l,int r){
    if(l>=r)return;
    int mid=l+rand()%(r-l+1);
    int tb=0,tc=0,td=0;
    for(int i=l;i<=r;i++){
        if(a[i]<mid)b[++tb]=a[i];
        else if(a[i]>mid)c[++tc]=a[i];
        else d[++td]=a[i];
    }
    for(int i=1;i<=tb;i++)a[l+i-1]=b[i];
    for(int i=1;i<=td;i++)a[l+i-1+tb]=d[i];
    for(int i=1;i<=tc;i++)a[l+i-1+tb+td]=c[i];
    quicksort(l,l+tb-1);
    quicksort(l+tb+td,r);
}
int main(){
    int n;
    srand((int)time(0));// 初始化随机数种子，使用当前时间作为种子
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    quicksort(0,n-1);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";

    return 0;
}