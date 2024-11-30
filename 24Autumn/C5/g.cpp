#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define int long long
struct Point {
    int x, y;
};

struct Query {
    int x, y, r, id;
};

struct QuadTree {
    int x_min, x_max, y_min, y_max;
    vector<Point> points;
    QuadTree *nw, *ne, *sw, *se;

    QuadTree(int x_min, int x_max, int y_min, int y_max)
        : x_min(x_min), x_max(x_max), y_min(y_min), y_max(y_max),
          nw(nullptr), ne(nullptr), sw(nullptr), se(nullptr) {}

    void insert(Point p) {
        if (points.size() < 10 || (x_max - x_min <= 1 && y_max - y_min <= 1)) {
            points.push_back(p);
            return;
        }
        if (!nw) subdivide();
        if (p.x <= (x_min + x_max) / 2) {
            if (p.y <= (y_min + y_max) / 2) nw->insert(p);
            else sw->insert(p);
        } else {
            if (p.y <= (y_min + y_max) / 2) ne->insert(p);
            else se->insert(p);
        }
    }

    int query(int x, int y, int r) {
        if (x_min > x + r || x_max < x - r || y_min > y + r || y_max < y - r) return 0;
        if (x_min >= x - r && x_max <= x + r && y_min >= y - r && y_max <= y + r)
            return points.size();
        int cnt = 0;
        for (const auto& p : points)
            if ((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y) <= r * r) ++cnt;
        if (nw) cnt += nw->query(x, y, r) + ne->query(x, y, r) + sw->query(x, y, r) + se->query(x, y, r);
        return cnt;
    }

    void subdivide() {
        int x_mid = (x_min + x_max) / 2, y_mid = (y_min + y_max) / 2;
        nw = new QuadTree(x_min, x_mid, y_min, y_mid);
        ne = new QuadTree(x_mid + 1, x_max, y_min, y_mid);
        sw = new QuadTree(x_min, x_mid, y_mid + 1, y_max);
        se = new QuadTree(x_mid + 1, x_max, y_mid + 1, y_max);
        for (const auto& p : points) {
            if (p.x <= x_mid) {
                if (p.y <= y_mid) nw->insert(p);
                else sw->insert(p);
            } else {
                if (p.y <= y_mid) ne->insert(p);
                else se->insert(p);
            }
        }
        points.clear();
    }
};

signed main() {
    int n, q;
    cin >> n >> q;

    vector<Point> friends(n);
    for (int i = 0; i < n; ++i) cin >> friends[i].x >> friends[i].y;

    QuadTree tree(-1e9, 1e9, -1e9, 1e9);
    for (const auto& p : friends) tree.insert(p);

    for (int i = 0; i < q; ++i) {
        int x, y, r;
        cin >> x >> y >> r;
        cout << tree.query(x, y, r) << endl;
    }

    return 0;
}
