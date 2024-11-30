
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 105;
const int oo = 1e9;

int n;
int c[N];
int f[N][N];

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			f[i][j] = 0;
	for (int l = 1; l <= n; l++)
		for (int i = 1, j = l; j <= n; i++, j++)
		{
			if (i == j)
			{
				f[i][j] = 1;
				continue;
			}
			f[i][j] = oo;
			if (c[i] == c[j])
				f[i][j] = min({f[i][j], f[i + 1][j], f[i][j - 1]});
			for (int k = i + 1; k <= j; k++)
				f[i][j] = min(f[i][j], f[i][k - 1] + f[k][j]);
		}
	printf("%d\n", f[1][n]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}
