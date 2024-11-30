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


// unordered map, requires:
//   int m.hash(Tk *p)
//   int m.eq(Tk *x, Tk *y)
#define UMAP_BITS 20
#define UMAP_SIZE (1<<UMAP_BITS)
#define umap(Tk, Tv, m)                                                      \
    int m##_p=1, m##_c[UMAP_SIZE]; Tk m##_k[UMAP_SIZE]; Tv m##_v[UMAP_SIZE]; \
    int m##_hash(Tk *p); int m##_eq(Tk *x, Tk *y);                           \
    Tv *m##__get(Tk k, int c) {                                              \
        int v=m##_hash(&k)&(UMAP_SIZE-1);                                    \
        for(int i=1; m##_c[v]==m##_p; i++, v=(v+i)&(UMAP_SIZE-1))            \
            if (m##_eq(&m##_k[v], &k)) return &m##_v[v];                     \
        if (!c) return 0;                                                    \
        m##_c[v]=m##_p; m##_k[v]=k; memset(&m##_v[v], 0, sizeof(Tv));        \
        return &m##_v[v];                                                    \
    }                                                                        \
    Tv *m##_get(Tk k) { return m##__get(k, 1); }                             \
    Tv *m##_set(Tk k, Tv v) { *m##__get(k, 1)=v; }                           \
    int m##_cnt(Tk k) { return m##__get(k, 0)!=0; }                          \
    void m##_clear() { m##_p++; }

#define pair long long
#define pair_first(x) ((int)(x >> 32))
#define pair_second(x) ((int)(x & (-1)))
#define make_pair(x, y) ((pair)(((unsigned long long)x << 32) | (unsigned int)y))


ci(N, 1005);

int n, q;
int x[N], y[N];

umap(pair, int, m);
int m_hash(pair *p) { return *p; }
int m_eq(pair *x, pair *y) { return *x == *y; }

int gcd(int x, int y)
{
	if (x == 0 || y == 0)
		return x + y;
	return x % y == 0 ? y : gcd(y, x % y);
}

void solve()
{
	gi(n);
	for (int i = 1; i <= n; i++)
	{
		gi(x[i]); gi(y[i]);
	}
	gi(q);
	while (q--)
	{
		int xx, yy, ans = 0;
		gi(xx); gi(yy);
		m_clear();
		for (int i = 1; i <= n; i++)
		{
			int dx = xx - x[i], dy = yy - y[i];
			int g = gcd(dx, dy);
			dx /= g; dy /= g;
			if (dx < 0)
			{
				dx = -dx;
				dy = -dy;
			}
			if (dx == 0 && dy < 0)
				dy = -dy;
			int *p = m_get(make_pair(dx, dy));
			(*p)++;
			if ((*p & 1) ^ 1)
				ans++;
		}
		wi(ans);
	}
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