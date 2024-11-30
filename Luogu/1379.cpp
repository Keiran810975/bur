#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int cnt;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
char s[20];
char tar[]="123804765";
map <string,int>mp;
deque <string> q;
int bfs(string x){
    q.push_back(x);
    mp[s]=0;
    while(q.size()){
        string t=q.front();
        q.pop_front();
        int dis=mp[t];
        if(t==tar)return mp[t];
        int a=t.find('0');
        int x1=a/3,y1=a%3;//0的横纵坐标
        for(int i=0;i<4;i++){
            int x2=x1+dx[i],y2=y1+dy[i];
            if(x2<0||x2>=3||y2<0||y2>=3)continue;
            int tmp=x2*3+y2;
            swap(t[a],t[tmp]);
            if(!mp.count(t)){
                q.push_back(t);
                mp[t]=dis+1;
            }
            if(t==tar)return mp[t];
            swap(t[a],t[tmp]);
        }
    }
    return mp[tar];
}
int main(){
    scanf("%s",s);
    int res=bfs(s);
    printf("%d\n",res);
    return 0;
}