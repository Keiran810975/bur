
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+100,maxm=8e3+100,INF=1e9;
int n,m,s,t,head[maxn],cnt;
struct Edge{
	int to,nex,w;
} e[maxm];
inline void add(int u,int to,int w) {
	e[++cnt].to=to;e[cnt].w=w;e[cnt].nex=head[u];head[u]=cnt;
}
inline int gint() {
	int n=0,f=1;char c;
	for(;(c=getchar())<'0'||c>'9';) if(c=='-') f=-1;
	for(;c<='9'&&c>='0';c=getchar()) n=(n<<1)+(n<<3)+(c^48);
	return n*f;
}
int dis[maxn],cur[maxn];
queue<int> q;
inline int bfs() {
	memset(dis,0,sizeof dis);dis[s]=1;q.push(s);
	for(int i=1;i<=t;i++) cur[i]=head[i];
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(int i=head[u];~i;i=e[i].nex) {
			int v=e[i].to;
			if(!dis[v]&&e[i].w>0) {
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	return dis[t];
}
int a;
inline int dfs(int u,int low) {
	if(u==t) return low;
	for(int &i=cur[u];~i;i=e[i].nex) {
		int v=e[i].to;
		if(dis[v]==dis[u]+1&&e[i].w>0&&(a=dfs(v,min(low,e[i].w)))) {
			return e[i].w-=a,e[i^1].w+=a,a;
		}
	}
	return 0;
}
int A[maxn],V[maxn],xx[maxn],yy[maxn],ww[maxn];
int main(){
	int T=gint();
	while(T--) {
		memset(head,0xff,sizeof head);cnt=-1;
		n=gint();m=gint();
		s=n+m+1;t=s+1;
		for(int i=1;i<=n;i++) {
			A[i]=gint();V[i]=gint();
		}
		int tot=0,cov=0;
		for(int i=1;i<=m;i++) {
			xx[i]=gint();yy[i]=gint();ww[i]=gint();
			tot+=ww[i];
			add(n+i,t,ww[i]);add(t,n+i,0);
			if(xx[i]==1||yy[i]==1) cov+=ww[i];
		}
		int maxx=min(cov+V[1],A[1])-1;
		if(A[1]<V[1]) {
			puts("No");
			continue;
		}
		bool ok=1;
		add(s,1,A[1]-V[1]);add(1,s,0);
		for(int i=2;i<=n;i++) {
			A[i]=min(maxx,A[i])-V[i];
			if(A[i]<0) {
				ok=0;
				break;
			}
			add(s,i,A[i]);add(i,s,0);
		}
		if(!ok) {
			puts("No");
			continue;
		}
		for(int i=1;i<=m;i++) {
			if(xx[i]!=yy[i]) {
				add(xx[i],n+i,A[xx[i]]);add(n+i,xx[i],0);
				add(yy[i],n+i,A[yy[i]]);add(n+i,yy[i],0);
			}
			else {
				add(xx[i],n+i,A[xx[i]]);add(n+i,xx[i],0);
			}
		}
		int ans=0,tmp=0;
		while(bfs()) {
			while((tmp=dfs(s,INF))) ans+=tmp;
		}
		puts((tot==ans)?"Yes":"No");
	}
	return 0;
}
