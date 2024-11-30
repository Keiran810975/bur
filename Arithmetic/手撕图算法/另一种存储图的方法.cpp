#include<iostream> 
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;  
struct edge{       //存边的结构体
	int u,v;
}; 
vector <int> e[100001]; 
vector <edge> s;
bool vis1[100001]={0},vis2[100001]={0}; //标记数组
bool cmp(edge x,edge y){  //排序规则
	if(x.v==y.v)
	return x.u<y.u;
	else return x.v<y.v;
}
void dfs(int x){
	vis1[x]=1;
	cout<<x<<" ";
	for(int i=0;i<e[x].size();i++){
		int point=s[e[x][i]].v;
		if(!vis1[point]){
			dfs(point);
		}
	}
}
void bfs(int x){
	queue <int> q;
	q.push(x);
	cout<<x<<" ";
	vis2[x]=1;
	while(!q.empty()){
		int fro=q.front();
		for(int i=0;i<e[fro].size();i++){
			int point=s[e[fro][i]].v;
			if(!vis2[point]){
				q.push(point); 
				cout<<point<<" ";
				vis2[point]=1;
			}
		}
		q.pop();
	}
}
int main(){
	int n,m; 
	cin>>n>>m; 
	for(int i=0;i<m;i++){
		int uu,vv;
		scanf("%d%d",&uu,&vv);
		s.push_back((edge){uu,vv});   
	}
	sort(s.begin(),s.end(),cmp); 
	for(int i=0;i<m;i++)   
		e[s[i].u].push_back(i); 
	dfs(1);
	printf("\n");
	bfs(1);
}