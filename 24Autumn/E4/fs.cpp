#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
vector<int> g[MAXN];
int v[MAXN][3],step[MAXN][3];
int n,m,s,t;
void bfs()
{
	queue<pair<int,int>>q;
	step[s][0]=0;
	v[s][0]=1;
	q.push({s,0});
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop(); 
		int yy=(y+1)%3;
		for(int i=0;i<g[x].size();i++)
			if(!v[g[x][i]][yy])
			{
				v[g[x][i]][yy]=1;
				step[g[x][i]][yy]=step[x][y]+1;
				q.push({g[x][i],yy});
			}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
	}
	cin>>s>>t;
	bfs();
	if(!step[t][0])
		cout<<-1<<endl;
	else
		cout<<step[t][0]/3<<endl;
	return 0;
}