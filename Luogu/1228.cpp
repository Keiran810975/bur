#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int x,y;
int power(int a){
    int sum=1;
    for(int i=1;i<=a;i++){
        sum*=2;
    }
    return sum;
}
//a,b代表一个矩形区域左上角的点的坐标
void f(int n,int x,int y,int a,int b){
    if(n==1)return;
    if(x-a+1<=n/2&&y-b+1<=n/2){
        cout<<
    }
}
int main(){

    return 0;
}