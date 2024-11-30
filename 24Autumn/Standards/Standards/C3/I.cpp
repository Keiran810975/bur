#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, c[N]; char a[N];
signed main() {
    scanf ("%s", a + 1); n = strlen (a + 1);
    for (int i = 1; i <= n; ++i) c[i] = c[i - 1] + (a[i] == 'b');
    int tmp = 0, ans = 0;
    for (int i = n; i >= 1; --i) {
        tmp += (a[i] == 'a');
        if (a[i] == 'u') ans += c[i] * tmp * (tmp - 1) / 2;
    }
    printf ("%lld\n", ans);
    return 0;
}
