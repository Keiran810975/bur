#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
char s[110];
int yihao(int x,int y){
    if(x==0||y==0)return 0;
    if(x>0&&y<0)return 0;
    if(x<0&&y>0)return 0;
    return abs(x)/abs(y);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int l;
        cin>>l;
        int p,q;
        cin>>p>>q;
        scanf("%s",s);
        int x=0,y=0;
        int cnt=0;
        for(int i=0;i<l;i++){
            switch(s[i]){
                case 'U':y++;break;
                case 'D':y--;break;
                case 'L':x--;break;
                case 'R':x++;break;
            }
            cnt++;
            if(x==p&&y==q){
                break;
            }
            
        }
        int cishu=min(yihao(p,x),yihao(q,y));
        cnt*=abs(cishu);
        x*=abs(cishu);
        y*=abs(cishu);
        bool sig=false;
        for(int j=0;j<l;j++){
            switch(s[j]){
                case 'U':y++;break;
                case 'D':y--;break;
                case 'L':x--;break;
                case 'R':x++;break;
            }
            cnt++;
            if(x==p&&y==q){
                break;
            }
        }
        cout<<cnt<<'$'<<'\n';
    }
    return 0;
}