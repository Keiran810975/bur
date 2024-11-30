#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point {
    long long x, y;
    Point(long long x = 0, long long y = 0) : x(x), y(y) {}
};

// 向量叉积
long long cross(const Point& O, const Point& A, const Point& B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// 计算两点之间距离平方
long long dist2(const Point& A, const Point& B) {
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

// 凸包算法（Andrew算法）
vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n <= 1) return points;
    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
    vector<Point> hull;

    // 下半部分
    for (const auto& p : points) {
        while (hull.size() >= 2 && cross(hull[hull.size() - 2], hull.back(), p) <= 0)
            hull.pop_back();
        hull.push_back(p);
    }

    // 上半部分
    int t = hull.size() + 1;
    for (int i = n - 1; i >= 0; --i) {
        while (hull.size() >= t && cross(hull[hull.size() - 2], hull.back(), points[i]) <= 0)
            hull.pop_back();
        hull.push_back(points[i]);
    }

    hull.pop_back(); // 删除最后一个重复点
    return hull;
}

// 旋转卡壳法求最大距离平方
long long maxDist2(const vector<Point>& hull) {
    int m = hull.size();
    if (m < 2) return 0;
    long long maxDist = 0;
    for (int i = 0, j = 1; i < m; ++i) {
        while (dist2(hull[i], hull[(j + 1) % m]) > dist2(hull[i], hull[j]))
            j = (j + 1) % m;
        maxDist = max(maxDist, dist2(hull[i], hull[j]));
    }
    return maxDist;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<Point> points(n);
        for (int i = 0; i < n; ++i) {
            cin >> points[i].x >> points[i].y;
        }

        // 计算凸包
        vector<Point> hull = convexHull(points);

        // 计算最大距离平方
        cout << maxDist2(hull) << endl;
    }
    return 0;
}
