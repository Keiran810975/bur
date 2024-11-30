#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7, N = 1e6 + 5;
int n, k, l, r, f[N];
#define get(x) (x >= 0 ? f[x] : 0)
signed main() {
    scanf ("%lld %lld %lld %lld", &n, &k, &l, &r);
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        f[i] = f[i - 1] + (get (i - l) - get (i - r - 1)) * k;
        f[i] = (f[i] % mod + mod) % mod;
    }
    printf ("%lld\n", f[n]);
    return 0;
}