#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
char g[110][110];
char ans[110][110];
typedef pair<int,int> pii;
queue <pii> q;
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};
char s[]="yizhong";
void bfs(){
    while(q.size()&&!q.empty()){
        pii t=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int a=t.first+dx[i],b=t.second+dy[i];
            if(a<0||a>=n||b<0||b>=n)continue;
            char c=g[t.first][t.second];
            int index=0;
            for(int j=0;j<7;j++){
                if(s[j]=='c'){
                    index=j;
                    break;
                }
            }

            if(g[a][b]!=s[index+1])continue;
            q.push({a,b});
            ans[a][b]=s[index+1];
        }   
    }
}
int main(){
    memset(ans,'*',sizeof ans);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",g[i]);
        int l=strlen(g[i]);
        for(int j=0;j<l;j++){
            if(g[i][j]=='y'){
                q.push({i,j});
                ans[i][j]='y';
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%c",ans[i][j]);
        }
        printf("$$$$$$$4\n");
    }
    bfs();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%c",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}