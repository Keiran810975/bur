#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct point {
    double x, y;
};

//计算三角形面积
double area(point A, point B, point C) {
    return abs((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y)) / 2.0;
}

//多边形面积
double polygonArea(const vector<point>& points) {
    int n = points.size();
    double area = 0.0;

    for (int i = 0; i < n; ++i) {
        // 当前点 (x_i, y_i) 和下一点 (x_{i+1}, y_{i+1})
        int next = (i + 1) % n;
        area += points[i].x * points[next].y - points[i].y * points[next].x;
    }

    return fabs(area) / 2.0; // 取绝对值除以2
}

// 计算两点之间的叉积
double cross(const point& a, const point& b, const point& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// 计算两点之间的欧几里得距离（用于排序时的次要条件）
double distance(const point& a, const point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// 起点（全局变量，用于排序）
point pivot;

// 比较函数，用于极角排序
bool polarOrder(const point& a, const point& b) {
    double cp = cross(pivot, a, b);
    if (cp == 0) {
        // 共线点按距离从近到远排序
        return distance(pivot, a) < distance(pivot, b);
    }
    return cp > 0; // 逆时针为正序
}

// Graham Scan 主函数
vector<point> grahamScan(vector<point>& points) {
    int n = points.size();

    // 第一步：找到 y 坐标最小的点（若相等，选择 x 坐标更小）
    pivot = *min_element(points.begin(), points.end(), [](const point& a, const point& b) {
        return a.y < b.y || (a.y == b.y && a.x < b.x);
    });

    // 第二步：按极角排序
    sort(points.begin(), points.end(), polarOrder);

    // 第三步：构建凸包
    vector<point> hull; // 栈，用于存储凸包点
    for (const auto& p : points) {
        // 当栈顶点与新点构成的方向为顺时针或共线时，弹出栈顶
        while (hull.size() >= 2 && cross(hull[hull.size() - 2], hull.back(), p) <= 0) {
            hull.pop_back();
        }
        hull.push_back(p); // 将当前点加入凸包
    }

    return hull;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        scanf("%d",&n);
        vector<point> points(n);
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&points[i].x,&points[i].y);
        }
        vector<point> scan=grahamScan(points);
        double res=polygonArea(scan);
        printf("%.1lf",res);
    }

    return 0;
}
