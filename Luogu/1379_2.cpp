#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int cnt;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
char s[20];
char tar[]="123804765";
map <string,int>mp;
map <string,int>vis;
deque <string> q;
int bfs(){
    q.push_back(s);
    q.push_back(tar);
    mp[s]=0,mp[tar]=0;
    vis[s]=1,vis[tar]=2;
    while(q.size()){
        string t=q.front();
        q.pop_front();
        int dis=mp[t];
        int a=t.find('0');
        string tt=t;
        int x1=a/3,y1=a%3;//0的横纵坐标
        for(int i=0;i<4;i++){
            int x2=x1+dx[i],y2=y1+dy[i];
            if(x2<0||x2>=3||y2<0||y2>=3)continue;
            int tmp=x2*3+y2;
            swap(t[a],t[tmp]);
            if(vis[t]+vis[tt]==3)return mp[t]+mp[tt]+1;
            if(!mp.count(t)){
                q.push_back(t);
                mp[t]=dis+1;
                vis[t]=vis[tt];
            }
            swap(t[a],t[tmp]);
        }
    }
    return -1;
}
int main(){
    scanf("%s",s);
    int res=bfs();
    printf("%d\n",res);
    return 0;
}