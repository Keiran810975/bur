#include <bits/stdc++.h>
using namespace std;
#define int long long
void read (int &x) {
    char ch = getchar(); x = 0; int f = 0;
    while (!isdigit(ch)) { if (ch == '-') f = 1; ch = getchar(); }
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
    if (f) x = -x;
} 
const int N = 1005;
int n, m, a[N][N], f[N][N];
void work () {
    read (n), read (m);
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) read (a[i][j]);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            f[i][j] = 0;
            f[i][j] = max (f[i - 1][j], f[i][j - 1]) + a[i][j];
            if (i == 1 && j == 1) f[i][j] = a[i][j];
        }
    }
    printf ("%lld\n", f[n][m]);
}
signed main() {
    memset (f, 0xcf, sizeof (f));
    int T; read (T);
    while (T--) work ();
}