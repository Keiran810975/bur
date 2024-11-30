#include<bits/stdc++.h>
using namespace std;
const int N = 5e6+10;
pair<int,int> d[N];
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    int st=0,ed =1;
    for(int i=n;i>=1;i--)d[ed++]={i,0};
    while(q--){
        int t;
        scanf("%d",&t);
        getchar();
        if(t==1){
            char c;
            scanf("%c",&c);
            int x=d[ed-1].first;
            int y = d[ed-1].second;
            if(c=='R')d[ed++]={x+1,y};
            if(c=='L')d[ed++]={x-1,y};
            if(c=='U')d[ed++]={x,y+1};
            if(c=='D')d[ed++]={x,y-1};
            st++;
        }else{
            int x;
            scanf("%d",&x);
            printf("%d %d\n",d[ed-x].first,d[ed-x].second);
        }
    }
}
