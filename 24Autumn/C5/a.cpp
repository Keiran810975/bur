#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Point{
    int x;
    int y;
};
//外积

int c(Point A, Point B, Point C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        scanf("%d",&n);
        Point p[100005];
        scanf("%lld%lld",&p[0].x,&p[0].y);
        for(int i=1;i<n;i++){
            scanf("%lld%lld",&p[i].x,&p[i].y);
        }
        int res=0;
        for(int i=1;i<n-1;i++){
            if(c(p[0], p[i], p[i+1])!=0){
                res=1;
                break;
            }
        }
        if(res==1){
            printf("how?\n");
        }else{
            printf("boo how! boo how!\n");
        }

    }
    return 0;
}