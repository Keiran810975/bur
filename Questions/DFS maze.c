//迷宫为m×n格（表示有m行、n列），其中有可走的也有不可走的，用1表示可以走，0表示不可以走。
//入口为第1行第1列（即左上角），出口为第 m 行第 n 列（即右下角），保证这两个点位都是1。请判断
//是否能走出迷宫。
//如果能，请计算通过迷宫要行走的距离（规定只有一条出路且每一步的距离为1）。
//如果不能，请计算可以到达的离起点直线距离最远的点
#include<stdio.h>
#include<math.h>
int a[30][30],b[30][30],m,n,yes,ans,c = 1,d = 1,l;
void dfs (int x,int y) {
if(x == m && y == n) {
yes = 1;
}
if(yes == 1) return ;
if( b[x+1][y] == 0 && a[x+1][y] == 1) {
ans ++;
b[x+1][y] = 1;
if(l < pow(x,2) + pow(y-1,2)) {
l = pow(x,2) + pow(y-1,2);
c = x+1;
d = y;
}
dfs(x+1,y);
if(yes == 1) return ;
ans --;
}
if( b[x][y+1] == 0 && a[x][y+1] == 1) {
ans ++;
b[x][y+1] = 1;
if(l < pow(x-1,2) + pow(y,2)) {
l = pow(x-1,2) + pow(y,2);
c = x;
d = y+1;
}
dfs(x,y+1);
if(yes == 1) return;
ans --;
}
if( b[x-1][y] == 0 && a[x-1][y] == 1) {
ans ++;
b[x-1][y] = 1;
dfs(x-1,y);
if(yes == 1) return;
ans --;
}
if( b[x][y-1] == 0 && a[x][y-1] == 1) {
ans ++;
b[x][y-1] = 1;
dfs(x,y-1);
if(yes == 1) return;
ans--;
}
return;
}
int main() {
scanf("%d%d",&m,&n);
for(int i = 1;i <= m;i ++) {
for(int j = 1;j <= n;j ++) {
scanf("%d",&a[i][j]);
}
}
dfs(1,1);
if(yes == 1) printf("%d",ans);
else printf("(%d,%d)",c,d);
return 0;
}