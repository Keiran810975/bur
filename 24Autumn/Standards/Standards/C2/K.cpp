#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;

const int N = 2e5 + 5;

int n, q;
unsigned long long a[N];
map <int, unsigned long long> m;

unsigned long long rnd()
{
	return rand() & 0xffffu;
}

void solve()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		int v;
		scanf("%d", &v);
		if (!m.count(v))
			m[v] = rnd() << 48 | rnd() << 32 | rnd() << 16 | rnd();
		a[i] = m[v];
		a[i] ^= a[i - 1];
	}
	while (q--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		if ((a[r] ^ a[l - 1]) == 0)
			printf("NO\n");
		else
			printf("YES\n");
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}
