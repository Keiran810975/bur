#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,a[100001],b[100001],c[100001],d[100001];
void quickSort(int l,int r){
	if (l>=r) return;// 如果左边界大于等于右边界，则返回，表示已经排序完成
	int mid=rand()%(r-l+1)+l;
	int tb=0,tc=0,td=0;// 初始化三个临时数组，分别用于存储小于、等于和大于中间值的元素
	for (int i=l;i<=r;i++){
		if (a[i]<a[mid]) b[++tb]=a[i];// 如果元素小于中间值，将其存储在临时数组 b 中
		else if (a[i]>a[mid]) c[++tc]=a[i]; // 如果元素大于中间值，将其存储在临时数组 c 中
		else d[++td]=a[i]; // 如果元素等于中间值，将其存储在临时数组 d 中
	}
	// 将临时数组 b 和 d 的元素复制回原数组 a
	for (int i=1;i<=tb;i++) a[l+i-1]=b[i];
	for (int i=1;i<=td;i++) a[l+i-1+tb]=d[i];
	for (int i=1;i<=tc;i++) a[l+i-1+tb+td]=c[i];
	quickSort(l,l+tb-1);// 对小于中间值的子数组排序
	quickSort(l+tb+td,r);// 对大于中间值的子数组排序
}

int main(){
    srand((int)time(0));// 初始化随机数种子，使用当前时间作为种子
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    quickSort(0,n-1);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
}