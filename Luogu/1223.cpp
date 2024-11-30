#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
struct ren{
    int a;  
    int id;
};
ren r[1100];
bool cmp(ren a,ren b){
    return a.a<b.a;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        r[i].id=i;
    }
    for(int i=0;i<n;i++){
        cin>>r[i].a;
    }
    sort(r,r+n,cmp);
    for(int i=0;i<n;i++){
        printf("%d ",r[i].id+1);
    }
    // for(int i=0;i<n;i++){
    //     printf("%d ",r[i].a);
    // }
    printf("\n");
    double ans=0;
    for(int i=0;i<n-1;i++){
        ans+=(double)r[i].a*(n-i-1);
    }
    ans/=n;
    printf("%.2lf",ans);
    return 0;
}