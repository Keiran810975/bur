#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,k;//n个格子，k个机器人
int a[110000];//记录机器人的位置
//遍历时间t，通过二分查找降低复杂度
bool check(int mid){
    int pos=0;//代表1到pos位置的格子已经被清扫
    for(int i=0;i<k;i++){
        int t=mid;
        if(pos<a[i])t-=2*(a[i]-pos-1);//消耗时间清扫左边未清扫的格子
        if(t<0)return false;//时间不够，扫不完
        pos=a[i]+t/2;//如果剩余时间就往右
    }
    if(pos<n)return false;//没扫完
    return true;
}
void sc(){
    cin>>n>>k;
    for(int i=0;i<k;i++)cin>>a[i];
    sort(a,a+k);//对输入的机器人位置从小到大排序
}
int main(){
    sc();
    int left=0,right=2*n,ans=2*n;
    while(left<=right){
        int mid=(left+right)>>1;//取中间位置
        if(check(mid))ans=mid,right=mid-1;//时间够，往左缩
        else left=mid+1;//时间不够，往右
    }
    cout<<ans<<endl;
    return 0;
}