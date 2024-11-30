#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
int l[200050];
void swap(int *x,int *y){
    int temp=*y;
    *y=*x;
    *x=temp;
}
int priQ[200050];//堆(小根堆)
int len;//记录堆的长度
void put(int x){
    int f;
    len++;
    priQ[len]=x;
    int b=len;
    while(b!=1&&priQ[b]<priQ[b/2]){
        swap(&priQ[b],&priQ[b/2]);
        b=b/2;
    }
}
int get(){//取出堆顶
    int x=priQ[1];
    priQ[1]=priQ[len];
    len--;
    int f=1,c;
    while(2*f<=len){
        if(2*f+1>len||priQ[2*f]<priQ[2*f+1])c=2*f;
        else c=2*f+1;
        if(priQ[f]<priQ[c]){
        swap(&priQ[f],&priQ[c]);
        f=c;
    }else return x;
    }
    return x;
}
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%lld",&l[i]);
        put(l[i]);
    }
    int ans=0;
    while(len>1){
        int a=get();
        int b=get();
        ans+=2*(a+b);
        put(a+b);
    }
    printf("%lld\n",ans);
    return 0;
}