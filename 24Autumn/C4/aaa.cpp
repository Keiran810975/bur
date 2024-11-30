#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct dish{
    int w,v;
    double vv;
};
//sort的比较函数
bool cmp(dish a,dish b){
    return a.vv>b.vv;
}

dish d[100010];
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        scanf("%d%d",&d[i].v,&d[i].w);
        d[i].vv=(double)d[i].v/d[i].w;
    }
    sort(d,d+n,cmp);
    double ans=0.0;
    for(int i=0;i<n;i++){
        if(k>0&&k>=d[i].w){
            ans+=d[i].v;
            k-=d[i].w;
        }else{
            ans+=k*d[i].vv;
            break;
        }
    }
    printf("%.3f\n",ans);
    return 0;
}