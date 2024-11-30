#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e6 + 5;

int n, q;
int a[N], pre[N];

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		pre[a[i]]++;
	}
	for (int i = 1; i < N; i++)
		pre[i] += pre[i - 1];
	while (q--)
	{
		int d, k;
		scanf("%d%d", &d, &k);
		int l = min(1ll * k * d, 1ll * N - 1);
		int r = min(1ll * k * d + d - 1, 1ll * N - 1);
		printf("%d\n", pre[r] - pre[max(0, l - 1)]);
	}
	return 0;
}
