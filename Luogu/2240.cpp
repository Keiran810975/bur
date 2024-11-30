#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct coin{
    int m,v;
    double p;
};
coin cc[200];
bool cmp(coin a,coin b){
    return a.p>b.p;
}
int main(){
    int n,t;
    cin>>n>>t;
    for(int i=0;i<n;i++){
        scanf("%d%d",&cc[i].m,&cc[i].v);
        cc[i].p=(double)cc[i].v/cc[i].m;
    }
    sort(cc,cc+n,cmp);
    double sheng=(double)t;
    double res=0;
    int k=-1;
    for(int i=0;i<n;i++){
        if(sheng>=cc[i].m){
            res+=cc[i].v;
            sheng-=cc[i].m;
        }else{
            k=i;
            break;
        }
    }

    if(k!=-1)res+=sheng*cc[k].p;
    printf("%.2lf\n",res);
    return 0;
}