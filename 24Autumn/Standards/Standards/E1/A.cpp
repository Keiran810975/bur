#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct stu {
    int a, b, c; string s;
    bool operator < (const stu &x) const {
        if (a + b + c == x.a + x.b + x.c) {
            return a == x.a ? s < x.s : a > x.a;
        } else return a + b + c > x.a + x.b + x.c;
    }
} a[N];
int n;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  // 加速cin,cout(c++独有的输入输出语句)
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].s >> a[i].a >> a[i].b >> a[i].c;
    }
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) cout << a[i].s << '\n';
    return 0;
}