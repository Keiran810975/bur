
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define ci(x, v) enum { x=(int)(v) }
#define gi(x) scanf("%d", &(x))
#define wi(x) printf("%d\n", (int)(x))
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define cmax(T, f, v) do { T*_p=&(f), _t=(v); if (_t>*_p) *_p=_t; } while(0);
#define cmin(T, f, v) do { T*_p=&(f), _t=(v); if (_t<*_p) *_p=_t; } while(0);
#define cimax(f, v) cmax(int, f, v)
#define cimin(f, v) cmin(int, f, v)
#define sgn(x) ((x) == 0 ? 0 : ((x) < 0 ? -1 : 1))

#define multicases


#define v_array(T, m, size)                                       \
    T m##_v[size]; int m##_k[size], m##_c;                        \
    T m##_get(int k) { return m##_k[k] == m##_c ? m##_v[k] : 0; } \
    void m##_set(int k, T v) { m##_v[k] = v; m##_k[k] = m##_c; }  \
    void m##_clear() { m##_c++; }

ci(N, 1e5 + 5);
ci(E, 5e5 + 5);

int n, m;
int h[N], to[E], nx[E], et;
int f[N], vis[N], sz[N];
v_array(int, p, N);
	
void ae(int u, int v)
{
	et++;
	to[et] = v;
	nx[et] = h[u];
	h[u] = et;
}

int getf(int u)
{
	return f[u] ? f[u] = getf(f[u]) : u;
}

void solve()
{
	gi(n); gi(m);
	et = 0;
	for (int i = 1; i <= n; i++)
		h[i] = f[i] = sz[i] = vis[i] = 0;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		gi(u); gi(v);
		ae(u, v);
		ae(v, u);
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i])
		{
			vis[i] = 1;
			p_clear();
			for (int j = h[i]; j; j = nx[j])
				p_set(to[j], 1);
			for (int j = 1; j <= n; j++)
				if (getf(i) != getf(j) && !p_get(j))
				{
					f[getf(j)] = i;
					vis[j] = 1;
				}
		}
	for (int i = 1; i <= n; i++)
		sz[getf(i)]++;
	for (int i = 1; i <= n; i++)
		printf("%d%c", sz[getf(i)], " \n"[i == n]);
}

int main()
{
	int st = clock();
	int T = 1;
	#ifdef multicases
		scanf("%d", &T);
	#endif
	while (T--)
		solve();
	int ed = clock();
	fprintf(stderr, "\n# terminated in %.3lfs\n", (1.0 / CLOCKS_PER_SEC) * (ed - st));
	return 0;
}