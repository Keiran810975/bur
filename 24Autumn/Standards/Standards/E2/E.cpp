#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
const long long oo = 1e18;

int n, w;
int a[N];
long long f[N];

void solve()
{
	scanf("%d%d", &n, &w);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = n; i; i--)
	{
		f[i] = -oo;
		long long t = a[i];
		for (int j = i + 1, k = 2; ; j += k, k++)
		{
			f[i] = max(f[i], t + (j <= n ? f[j] - w : 0));
			if (j > n)
				break;
			t += a[j];
		}
	}
	printf("%lld\n", f[1]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}
