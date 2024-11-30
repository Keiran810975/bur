
#include <stdio.h>

#define N 100005

int n, s;
int t[N];
int las[N], pre[N], suf[N];
int gpre[N], gsuf[N];

void solve()
{
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; i++)
		las[i] = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", &t[i]);
	for (int i = 1; i <= n; i++)
	{
		pre[i] = suf[i] = 0;
		if (las[t[i]])
		{
			suf[las[t[i]]] = i;
			pre[i] = las[t[i]];
		}
		las[t[i]] = i;
		gpre[i] = i - 1;
		gsuf[i] = i + 1;
	}
	gpre[n + 1] = gsuf[0] = gpre[1] = gsuf[n] = 0;
	for (int i = 1; i <= n; i++)
	{
		printf("%d%c", s, " \n"[i == n]);
		pre[suf[s]] = pre[s];
		suf[pre[s]] = suf[s];
		gpre[gsuf[s]] = gpre[s];
		gsuf[gpre[s]] = gsuf[s];
		if (pre[s] && suf[s])
		{
			int l = s - pre[s], r = suf[s] - s;
			s = l <= r ? pre[s] : suf[s];
		}
		else if (pre[s] || suf[s])
			s = pre[s] | suf[s];
		else if (gpre[s] && gsuf[s])
		{
			int l = s - gpre[s], r = gsuf[s] - s;
			s = l <= r ? gpre[s] : gsuf[s];
		}
		else if (gpre[s] || gsuf[s])
			s = gpre[s] | gsuf[s];
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
