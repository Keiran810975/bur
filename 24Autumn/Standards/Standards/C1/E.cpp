#include <stdio.h>

// #define multicases

const int N=3e4 + 5;
const int mod=10007;

int n, m, q;
int a[N], b[N];

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 0; i <= m; i++)
		scanf("%d", &b[i]);
	scanf("%d", &q);
	while (q--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		int vx = 0, vy = 0;
		for (int i = 0, p = 1; i <= n; i++, p = p * x % mod)
			vx = (vx + p * a[i]) % mod;
		for (int i = 0, p = 1; i <= m; i++, p = p * y % mod)
			vy = (vy + p * b[i]) % mod;
		printf("%d\n", vx * vy % mod);
	}
}

int main()
{
	int T = 1;
	#ifdef multicases
		scanf("%d", &T);
	#endif
	while (T--)
		solve();
	return 0;
}