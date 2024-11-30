#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[20020];
//下滤(把最大的元素放到堆顶) 
void down(int i,int n){
    int t;
    for(;i*2<=n;){
        if(i*2+1<=n&&a[i*2+1]>a[i*2]) t=i*2+1;
        else t=i*2;
        if(a[t]>a[i]){
            swap(a[i],a[t]);
            i=t;
        }
    }
}
int sum=0,cnt=0;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(sum<m){
        down(1,n);  
        sum+=a[1];
        a[1]=a[n--];
        cnt++;
    }
    cout<<cnt<<endl;

    return 0;
}