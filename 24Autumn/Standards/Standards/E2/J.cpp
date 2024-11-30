#include <bits/stdc++.h>
using namespace std;
#define int long long
void read (int &x) {
    char ch = getchar(); x = 0; int f = 0;
    while (!isdigit(ch)) { if (ch == '-') f = 1; ch = getchar(); }
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
    if (f) x = -x;
} const int N = 1e5 + 5, mod = 998244353;
int n, k, m, a[N], b[N], f[N], c[N];
void work () {
    read (n), read (k);
    for (int i = 1; i <= n; ++i) read (a[i]);
    for (int i = 1; i <= n; ++i) read (b[i]);
    read (m);
    for (int i = 1; i <= m; ++i) read (c[i]);
    memset (f, 0xcf, sizeof (int) * (n + 3));
    f[k] = 0;
    int one = 0, two = f[0];
    for (int i = 1; i <= m; ++i) {
        int tmp = f[c[i]];
        f[c[i]] += a[c[i]];
        if (tmp == one) f[c[i]] = max (f[c[i]], two + b[c[i]]);
        else f[c[i]] = max (f[c[i]], one + b[c[i]]);
        if (tmp == one) {
            one = f[c[i]];
        } else {
            if (f[c[i]] > one)  two = one, one = f[c[i]];
            else if (f[c[i]] > two) two = f[c[i]];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max (ans, f[i]);
    printf ("%lld\n", ans);
}
signed main() {
    // freopen ("4.in", "r", stdin);
    int T; read (T);
    while (T--) work ();
    return 0;
}