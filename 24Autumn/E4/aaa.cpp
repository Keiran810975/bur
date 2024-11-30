#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;

int n,m,x,y,z,maxflow,deep[5000];//deep深度 
struct Edge{
    int next,to,dis;
}edge[5050];
int num_edge=-1,head[5000],cur[5000];//cur用于复制head 
queue <int> q;

void add_edge(int from,int to,int dis,bool flag)
{
    edge[++num_edge].next=head[from];
    edge[num_edge].to=to;
    if (flag) edge[num_edge].dis=dis;//反图的边权为 0
    head[from]=num_edge;
}

//bfs用来分层 
bool bfs(int s,int t)
{
    memset(deep,0x7f,sizeof(deep));
    while (!q.empty()) q.pop();
    for (int i=1; i<=n; i++) cur[i]=head[i];
    deep[s]=0;
    q.push(s);

    while (!q.empty())
    {
        int now=q.front(); q.pop();
        for (int i=head[now]; i!=-1; i=edge[i].next)
        {
            if (deep[edge[i].to]>inf && edge[i].dis)//dis在此处用来做标记 是正图还是返图 
            {
                deep[edge[i].to]=deep[now]+1;
                q.push(edge[i].to);
            }
        }
    }
    if (deep[t]<inf) return true;
    else return false;
}

//dfs找增加的流的量 
int dfs(int now,int t,int limit)//limit为源点到这个点的路径上的最小边权 
{
    if (!limit || now==t) return limit;

    int flow=0,f;
    for (int i=cur[now]; i!=-1; i=edge[i].next)
    {
        cur[now]=i;
        if (deep[edge[i].to]==deep[now]+1 && (f=dfs(edge[i].to,t,min(limit,edge[i].dis))))
        {
            flow+=f;
            limit-=f;
            edge[i].dis-=f;
            edge[i^1].dis+=f;
            if (!limit) break;
        }
    }
    return flow;
}

void Dinic(int s,int t)
{
    while (bfs(s,t))
        maxflow+=dfs(s,t,inf);
}

signed main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
         memset(head,-1,sizeof(head));
        int s,t;
        cin>>n>>m;
        cin>>s>>t;
        for (int i=1; i<=m; i++)
        {
            cin>>x>>y>>z;
            add_edge(x,y,z,1); add_edge(y,x,z,0);
        }
        Dinic(s,t);
        cout<<maxflow<<endl;
    }

   
    return 0;
}