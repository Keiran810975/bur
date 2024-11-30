#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;
const int maxn=1e5+10,maxm=2e5+10;
ll INF=1e18;
struct Edge{int nex,v;ll w;} e[maxm];
int n,m,s,t,cnt,head[maxn];
ll d[maxn];
inline void add(int u,int v,ll w) {
	e[++cnt].v=v;e[cnt].w=w;e[cnt].nex=head[u];head[u]=cnt;
}
struct Node{
	int u;ll d;
	//表面重载小于号实则重载的是大于号,因为默认大根堆 
	bool operator < (const Node & rhs) const {
		return d>rhs.d;
	}
};
ll ti;
int main() {
    scanf("%d%d%d%lld",&n,&m,&s,&ti);
    for(int i=1,u,v,w;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);add(v,u,w);
    }
	priority_queue<Node> q;
	for(int i=1;i<=n;i++) d[i]=INF;
    d[s]=0;
    q.push({s,d[s]});
    while(!q.empty()) {
        Node x=q.top();q.pop();
        int u=x.u;
        if(x.d!=d[u]) continue;
        for(int i=head[u];i;i=e[i].nex) {
            int v=e[i].v,w=e[i].w;
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                q.push({v,d[v]});
            }
        }
    }
    vector<pil> ve;
    for(int i=1;i<=n;i++) {
    	if(d[i]>ti) {
    		ve.push_back({i,d[i]==INF?-1:d[i]});
		}
	}
	printf("%d\n",(int)ve.size());
	for(pil x : ve) printf("%d %lld\n",x.first,x.second);
    return 0;
}