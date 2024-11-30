#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct spot{
    double x,y,z;
};
bool cmp(spot a,spot b){
    return a.z<b.z;
}
int main(){
    int n;
    cin>>n;
    vector<spot> spots(n);
    for(int i=0;i<n;i++){
        cin>>spots[i].x>>spots[i].y>>spots[i].z;
    }
    sort(spots.begin(),spots.end(),cmp);
    double ans=0;
    for(int i=1;i<n;i++){
        ans+=sqrt(pow(spots[i].x-spots[i-1].x,2)+pow(spots[i].y-spots[i-1].y,2)+pow(spots[i].z-spots[i-1].z,2));
    }
    printf("%.3lf",ans);
    return 0;
}