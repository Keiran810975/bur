#include <bits/stdc++.h>
using namespace std;
#define int long long
void read (int &x) {
    char ch = getchar(); x = 0; int f = 0;
    while (!isdigit(ch)) { if (ch == '-') f = 1; ch = getchar(); }
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
    if (f) x = -x;
} const int N = 1e6 + 5, mod = 998244353;
int n, m, k, a[N], K[N];
int f[N][2];
signed main() {
    read (n), read (m), read (k);
    for (int i = 1; i <= m; ++i) read (a[i]), K[a[i]] = 1;
    f[1][0] = k - 1, f[1][1] = 1 - K[1];
    for (int i = 2; i <= n; ++i) {
        f[i][0] = f[i - 1][1] * (k - 1) + f[i - 1][0] * (k - 2);
        f[i][1] = K[i] ? 0 : f[i - 1][0];
        f[i][0] %= mod;
    }
    printf ("%lld\n", (f[n][0] + f[n][1]) % mod);
    return 0;
}