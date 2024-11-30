#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// 它的用法是 nth_element(a+x,a+x+y,a+x+len);。

// 执行之后数组 aa 下标 xx 到 x+y−1x+y−1 的元素都小于 a[x+y]a[x+y]，
// 下标 x+y+1x+y+1 到 x+len−1x+len−1 的元素 都大于 a[x+y]a[x+y]，但不保证数组有序。
// 此时 a[x+y]a[x+y] 就是数组区间 xx 到 x+len−1x+len−1 中第 yy 小的数，
// 当然也可以自己定义 cmpcmp 函数。
int a[5000005];
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    nth_element(a,a+k,a+n);
    cout<<a[k]<<endl;
    return 0;
}