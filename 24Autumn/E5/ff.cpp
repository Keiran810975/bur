#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
};

bool canReach(ll px, ll py, ll dx, ll dy, ll sx, ll sy) {
    if (dx == 0 && dy == 0) return px == sx && py == sy;
    if (dx == 0) return (px == sx) && (py - sy) % dy == 0 && (py - sy) / dy >= 0;
    if (dy == 0) return (py == sy) && (px - sx) % dx == 0 && (px - sx) / dx >= 0;
    ll k1 = (px - sx) / dx, k2 = (py - sy) / dy;
    return (px - sx) % dx == 0 && (py - sy) % dy == 0 && k1 == k2 && k1 >= 0;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        ll p, q;
        cin >> p >> q;
        string s;
        cin >> s;

        ll dx = 0, dy = 0; 
        vector<Point> path(n + 1);
        path[0] = {0, 0};
        for (ll i = 0; i < n; ++i) {
            if (s[i] == 'U') dy++;
            else if (s[i] == 'D') dy--;
            else if (s[i] == 'L') dx--;
            else if (s[i] == 'R') dx++;
            path[i + 1] = {path[i].x + (s[i] == 'R') - (s[i] == 'L'), 
                           path[i].y + (s[i] == 'U') - (s[i] == 'D')};
        }
        ll result = -1;
        for (ll i = 0; i <= n; ++i) {
            ll sx = path[i].x, sy = path[i].y;
            if (canReach(p, q, dx, dy, sx, sy)) {
                ll fullRounds = 0;
                if (dx != 0) fullRounds = (p - sx) / dx;
                if (dy != 0) fullRounds = (q - sy) / dy;
                result = fullRounds * n + i;
                break;
            }
        }
        cout << result << '\n';
    }
    return 0;
}
