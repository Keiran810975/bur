#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
    Point(long long x = 0, long long y = 0) : x(x), y(y) {}
};

// 向量叉积
long long cross(const Point& O, const Point& A, const Point& B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
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

// 投影到法线方向，返回投影的最小值和最大值
void projectToAxis(const vector<Point>& poly, const Point& axis, long long& min_proj, long long& max_proj) {
    min_proj = max_proj = axis.x * poly[0].x + axis.y * poly[0].y;
    for (const auto& p : poly) {
        long long proj = axis.x * p.x + axis.y * p.y;
        min_proj = min(min_proj, proj);
        max_proj = max(max_proj, proj);
    }
}

// 判断两个凸多边形是否相交
bool isIntersect(const vector<Point>& poly1, const vector<Point>& poly2) {
    for (int i = 0; i < poly1.size(); i++) {
        Point p1 = poly1[i];
        Point p2 = poly1[(i + 1) % poly1.size()];

        // 计算法线方向
        Point edge = {p2.x - p1.x, p2.y - p1.y};
        Point normal = {-edge.y, edge.x};

        // 投影poly1
        long long min1, max1;
        projectToAxis(poly1, normal, min1, max1);

        // 投影poly2
        long long min2, max2;
        projectToAxis(poly2, normal, min2, max2);

        // 检查投影是否有重叠
        if (max1 < min2 || max2 < min1) {
            return false; // 不重叠，凸包不相交
        }
    }
    return true; // 所有轴的投影都有重叠，凸包相交
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<Point> p(n);
        vector<Point> q(m);
        
        // 输入点集p和q
        for (int i = 0; i < n; i++) {
            scanf("%lld%lld", &p[i].x, &p[i].y);
        }
        for (int i = 0; i < m; i++) {
            scanf("%lld%lld", &q[i].x, &q[i].y);
        }

        // 计算两个凸包
        vector<Point> pp = convexHull(p);
        vector<Point> qq = convexHull(q);

        // 判断两个凸包是否相交
        if (isIntersect(pp, qq)) {
            printf("not empty\n");
        } else {
            printf("empty\n");
        }
    }
    return 0;
}
