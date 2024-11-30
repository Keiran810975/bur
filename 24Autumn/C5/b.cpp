#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Point{
    int x;
    int y;
};


double dis(Point a, Point b, Point c){
    int up=abs((c.y-b.y)*a.x-(c.x-b.x)*a.y+b.x*c.y-c.x*b.y);
    double down=sqrt((c.y-b.y)*(c.y-b.y)+(c.x-b.x)*(c.x-b.x));
    return (double)up/down;
}

//判断垂点是否在线段上
bool jj(Point a, Point b, Point c){
    int x1=a.x-b.x, y1=a.y-b.y;
    int x2=c.x-b.x, y2=c.y-b.y;
    int x3=a.x-c.x, y3=a.y-c.y;
    int x4=b.x-c.x, y4=b.y-c.y;
    int s=x1*x2+y1*y2;
    int t=x3*x4+y3*y4;
    if(s>=0&&t>=0)return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        Point a,b,c;
        cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
        if(jj(a,b,c)){
            double res=dis(a,b,c);
            printf("%.3lf\n",res);
        }else{
            double r1=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
            double r2=sqrt((a.x-c.x)*(a.x-c.x)+(a.y-c.y)*(a.y-c.y));
            double res=min(r1,r2);
            printf("%.3lf\n",res);
        }
        
    }
    return 0;
}