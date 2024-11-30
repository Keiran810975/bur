#include <stdio.h>
#include <string.h>

#define multicases

const int N=4e5 + 5;

int n, ans;

void solve()
{
	scanf("%d", &n);
	ans = n - (n & 1 ^ 1);
	if ((n & 3) == 2)
	{
		ans += 3;
		if (__builtin_popcount(n + 2) == 1)
			ans++;
	}
	printf("%d\n", ans);
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