#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e4+10;

struct edge {
    int v, w;

    edge(){}
    edge(int vv,int ww){
        v=vv;w=ww;
    }
};

struct node {
    int dis, u;
    node (){}
    node (int diss,int uu){dis=diss;u=uu;}
    bool operator>(const node& a) const { return dis > a.dis; }
};

vector<edge> e[maxn];
int dis[maxn], vis[maxn];
priority_queue<node, vector<node>, greater<node> > q;
int cnt;
void dijkstra(int s) {
    for(int i=1;i<=cnt;i++)dis[i]=INT_MAX;
    dis[s] = 0;
    q.push(node(0, s));
    while (!q.empty()) {
        int u = q.top().u;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto ed : e[u]) {
            int v = ed.v, w = ed.w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                // cout<<v<<" "<<dis[v]<<" "<<dis[u]<<" "<<w<<"\n";
                q.push(node(dis[v], v));
            }
        }
    }
}

map<pair<int,int>,int> mp;
vector<int> es[2010];
int l[maxn],r[maxn],h[maxn];
int main(){
    int n;
    cin>>n;
    int s,t;
    cin>>s>>t;
    for(int i=1;i<=n;i++){
        cin>>l[i]>>r[i]>>h[i];
        mp[make_pair(l[i],h[i])]=i;
        mp[make_pair(r[i],h[i])]=n+i;
        es[i].push_back(i);
        es[i].push_back(n+i);
        e[i].push_back(edge(n+i,r[i]-l[i]));
        e[n+i].push_back(edge(i,r[i]-l[i]));
    }
    cnt=2*n+1;
    for(int i=1;i<=n;i++){
        //left
        int hh = -1,idx = i;
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(l[j]<=l[i]&&l[i]<=r[j]&&h[j]<=h[i]){
                if(h[j]>hh){
                    hh=h[j];
                    idx=j;
                }
            }
        }
        if(hh!=-1){
            if(!mp[make_pair(l[i],hh)]){
                mp[make_pair(l[i],hh)]=cnt++;
            }
            int v = mp[make_pair(l[i],hh)];
            e[i].push_back(edge(v,h[i]-hh));
            e[idx].push_back(edge(v,abs(l[i]-l[idx])));
            e[n+idx].push_back(edge(v,abs(l[i]-r[idx])));
            e[v].push_back(edge(idx,abs(l[i]-l[idx])));
            e[v].push_back(edge(n+idx,abs(l[i]-r[idx])));
            es[idx].push_back(v);
        }
        //right
        hh = -1,idx = i;
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(l[j]<=r[i]&&r[i]<=r[j]&&h[j]<=h[i]){
                if(h[j]>hh){
                    hh=h[j];
                    idx=j;
                }
            }
        }
        
        if(hh!=-1){
            if(!mp[make_pair(r[i],hh)]){
                mp[make_pair(r[i],hh)]=cnt++;
            }
            int v = mp[make_pair(r[i],hh)];
            e[n+i].push_back(edge(v,h[i]-hh));
            e[idx].push_back(edge(v,abs(r[i]-l[idx])));
            e[n+idx].push_back(edge(v,abs(r[i]-r[idx])));
            e[v].push_back(edge(idx,abs(r[i]-l[idx])));
            e[v].push_back(edge(n+idx,abs(r[i]-r[idx])));
            es[idx].push_back(v);
        }
    }
    dijkstra(s);
    int ans = INT_MAX;
    for(auto i:es[t]){
        ans=min(ans,dis[i]);
    }
    if(ans!=INT_MAX)cout<<ans<<"\n";
    else cout<<"-1\n";

}
