#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[10]={1,2,3,4,5,6,7,8,9};
void permutation(int l,int r){
    if(l==r){
        for(int i=0;i<=r;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    else{
        for(int i=l;i<=r;i++){
            swap(a[l],a[i]);
            permutation(l+1,r);
            swap(a[l],a[i]);
        }
    }
}
int main(){
    permutation(0,3);
    return 0;
}