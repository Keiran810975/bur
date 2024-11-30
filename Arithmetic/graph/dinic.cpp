#include<bits/stdc++.h>
using namespace std;
#define int long long
/* 
当问题中出现较大的数值变量，可以使用 #define int long long 将所有int修改为long long
这样的做法可以避免运算过程中溢出，或部分变量忘记修改为longlong类型引发的错误
全部改为long long会在一定程度上降低运行效率
记得把 int main() 改为 signed main()
*/
int n, m;
int s, t;
const int N = 1e5 + 5, M = 1e5 + 5; // 表示点数和边数的上限。视具体情况而定 
struct edge{
	int to;
	int ne;         // next
	int v;      // to 表示当前边到达的点，ne 表示下一条边的下标，相当于链表指针，v 表示剩余容量。
} ed[M];    
// dinic算法中一般用链式前向心的方式存储边，简单来说就是给每个点开一个 链表 存储出边
// 具体可以参照 https://blog.csdn.net/m0_52711790/article/details/127900225
int head[N];        // 链式前向心中的头指针数组
int p = 1;
int d[N];//层
// int fr[N];
void add(int f, int to, int v) {  // 链式前向心的加边操作，和链表添加类似
    // 添加一条从f到to，容量为v的边
	//head[f]是这条边起点f的第一条边
	ed[++p].to = to, ed[p].ne = head[f], head[f] = p, ed[p].v = v;     // 正向边，剩余容量为v
	ed[++p].to = f, ed[p].ne = head[to], head[to] = p, ed[p].v = 0;    // 最大流算法中的反向边，初始容量为0
}       
bool bfs() {            // dinic算法每轮先通过bfs进行分层
	for (int i = 0; i <= n; ++i) d[i] = -1; // d[i] 表示节点 i 位于第几层。初值为-1
	queue<int> q;
	q.push (s);
	d[s]=0;
	// fr[s] = head[s];
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = head[x]; i ; i = ed[i].ne) {  // 跳转链表的方式遍历所有边
			int to = ed[i].to;
			if (d[to] == -1 && ed[i].v) {      // 如果to尚未遍历且这条边还有容量，进行遍历
				d[to] = d[x] + 1;
				// fr[to] = head[to];
				q.push(to);
				if (to == t) return true;
			}
		}
	}
	return false;
}
const int inf = (1ll << 60);     // 定义一个表示“无穷大”的常量
int dfs(int now, int flow) {        // 当前走到now，之前得到的最大流通量为flow
	if (now == t) return flow;      // 寻找通路的递归边界
    int res = 0;
	for (int i = head[now]; i && res < flow; i = ed[i].ne) {  
		int to = ed[i].to;
		// fr[r] = i;
		if (ed[i].v == 0 || d[to] != d[now] + 1) continue;  // 无剩余容量或不满足分层图中的关系
		int get = dfs (to, min (flow - res, ed[i].v));   // 递归计算这一条边走下去最多能流通多少流量
		if (get == 0) d[to] = -1;       // 如果留不通，标记为-1，下次就不会走了
		ed[i].v -= get;
		ed[i ^ 1].v += get;         // 正边流量减少；反边增加，用于“反悔”操作
		//i^1:异或运算，相当于i+1，i为奇数时，i+1为偶数，i为偶数时，i+1为奇数
		res += get;
	}
    /*
        for (int i = fr[r]; i && res < flow; i = ed[i].ne)  
        利用 fr 数组的优化（当前弧优化），减少循环次数。此模板暂不提及
        代码里关于fr数组的其它内容也已经注释
        当前弧优化可以参照 https://blog.csdn.net/qq_43580151/article/details/103129679
    */
	return res;
}
int dinic() {
	int ans = 0;
	int tem = 0;
	while (bfs()) {
		while (tem = dfs (s, inf))     // 初始时流通量记为inf，给后面的搜索足够的“发挥空间”
			ans += tem;
	}
	return ans;
}
int sum;
int T;
void sol() {
    scanf ("%lld %lld %lld %lld", &n, &m, &s, &t);
	p = 1;          // 重置边的计数器
	for (int i = 1; i <= n; ++i) head[i] = 0;  // 重置每个链表的表头
	for (int i = 1, x, y, z; i <= m; ++i) {
        scanf ("%lld %lld %lld", &x, &y, &z);
		add (x, y, z);
	}
	int ans = dinic();
	printf("%lld\n",ans);
}
signed main(){
	scanf ("%lld", &T);
	while (T--) sol();
	return 0;
}