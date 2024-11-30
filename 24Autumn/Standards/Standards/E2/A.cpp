#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e4 + 5;
const long long oo = 1e18;

int n, a;
int c[N], e[N];
long long f;

void solve()
{
	scanf("%d%d", &n, &a);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &e[i]);
	f = a;
	for (int i = 1; i <= n; i++)
	{
		if (f < c[i] && f < e[i])
		{
			printf("%d\n", i - 1);
			return;
		}
		long long nx = -oo;
		if (f >= c[i])
			nx = max(nx, f + c[i]);
		if (f >= e[i])
			nx = max(nx, f + e[i]);
		if (f >= c[i] && f >= e[i])
			nx = max(nx, f + c[i] + e[i]);
		f = nx;
	}
	printf("%d\n", n);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}
