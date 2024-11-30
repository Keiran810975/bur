#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
const int oo = 1e9;

int n, m;
int sx, sy, tx, ty;
char _mp[N];
char *mp[N];
int _dis[N];
int *dis[N];
int _tar[2][2][N];
int *tar[2][2][N];
int qx[N], qy[N], ql, qr;
int ans;

void get(int cx, int cy, int dx, int dy, int &nx, int &ny)
{
	int xx = (dx + dy + 1) / 2, yy = (dx - dy + 1) / 2;
	if (tar[xx][yy][cx][cy] >= 0)
	{
		nx = cx + dx * tar[xx][yy][cx][cy];
		ny = cy + dy * tar[xx][yy][cx][cy];
		return;
	}
	nx = cx; ny = cy;
	int step = 0;
	while (0 <= nx + dx && nx + dx < n
		&& 0 <= ny + dy && ny + dy < m
		&& mp[nx + dx][ny + dy] != '#'
		&& tar[xx][yy][nx][ny] == -1)
	{
		nx += dx; ny += dy;
		step++;
	}
	if (tar[xx][yy][nx][ny] < 0)
		tar[xx][yy][nx][ny] = 0;
	for (int i = 0; i < step; i++)
		tar[xx][yy][cx + dx * i][cy + dy * i] = tar[xx][yy][nx][ny] + step - i;
	get(nx, ny, dx, dy, nx, ny);
}

void solve()
{
	scanf("%d%d", &n, &m);
	scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
	sx--; sy--; tx--; ty--;
	for (int i = 0; i < n; i++)
	{
		mp[i] = _mp + i * m;
		dis[i] = _dis + i * m;
		for (int x = 0; x < 2; x++)
			for (int y = 0; y < 2; y++)
				tar[x][y][i] = _tar[x][y] + i * m;
		scanf("%s", mp[i]);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			dis[i][j] = oo;
			for (int x = 0; x < 2; x++)
				for (int y = 0; y < 2; y++)
					tar[x][y][i][j] = -1;
		}
	dis[sx][sy] = 0;
	ql = qr = 1;
	qx[ql] = sx; qy[ql] = sy;
	while (ql <= qr)
	{
		int cx = qx[ql], cy = qy[ql];
		int nx, ny;
		for (int dx = -1; dx <= 1; dx++)
			for (int dy = -1; dy <= 1; dy++)
			{
				if ((dx != 0) == (dy != 0))
					continue;
				get(cx, cy, dx, dy, nx, ny);
				if (dis[cx][cy] + 1 >= dis[nx][ny])
					continue;
				dis[nx][ny] = dis[cx][cy] + 1;
				qr++;
				qx[qr] = nx; qy[qr] = ny;
			}
		ql++;
	}
	ans = dis[tx][ty];
	for (int i = 0; i < tx; i++)
	{
		int nx, ny;
		get(i, ty, 1, 0, nx, ny);
		if (nx >= tx)
			ans = min(ans, dis[i][ty] + 1);
	}
	for (int i = tx + 1; i < n; i++)
	{
		int nx, ny;
		get(i, ty, -1, 0, nx, ny);
		if (nx <= tx)
			ans = min(ans, dis[i][ty] + 1);
	}
	for (int j = 0; j < ty; j++)
	{
		int nx, ny;
		get(tx, j, 0, 1, nx, ny);
		if (ny >= ty)
			ans = min(ans, dis[tx][j] + 1);
	}
	for (int j = ty + 1; j < m; j++)
	{
		int nx, ny;
		get(tx, j, 0, -1, nx, ny);
		if (ny <= ty)
			ans = min(ans, dis[tx][j] + 1);
	}
	if (ans == oo)
		ans = -1;
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}
