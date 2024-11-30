#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//结构体：点
struct Point {
    int x, y;
};
// 计算两点间的距离(暴力)
double dist(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
// 比较函数，用于按 x 坐标排序
bool compareX(const Point& p1, const Point& p2) {
    return p1.x < p2.x;
}
// 比较函数，用于按 y 坐标排序
bool compareY(const Point& p1, const Point& p2) {
    return p1.y < p2.y;
}
// 暴力法计算点集中最近的两点距离
double bruteForce(const vector<Point>& points, int left, int right) {
    double minDist = 1e9;  // 初始化为一个较大值
    for (int i = left; i < right; ++i) {
        for (int j = i + 1; j <= right; ++j) {
            minDist = min(minDist, dist(points[i], points[j]));
        }
    }
    return minDist;
}
// 合并阶段，计算跨越左右子集边界的最小点对距离
double stripClosest(vector<Point>& strip, double d) {
    double minDist = d;  // 初始化为 dis
    // 按 y 坐标排序
    sort(strip.begin(), strip.end(), compareY);
    // 遍历 strip 中的点，找出距离小于 d 的点对
    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; ++j) {
            minDist = min(minDist, dist(strip[i], strip[j]));
        }
    }
    return minDist;
}
// 分治法求解最近点对问题
double closestUtil(vector<Point>& points, int left, int right) {
    // 如果点的数量较小，使用暴力法计算
    if (right - left <= 3) {
        return bruteForce(points, left, right);
    }
    // 找到中点
    int mid = left + (right - left) / 2;
    Point midPoint = points[mid];
    // 递归计算左右子集的最小距离
    double dl = closestUtil(points, left, mid);
    double dr = closestUtil(points, mid + 1, right);
    // 取左右子集的最小值
    double d = min(dl, dr);
    // 构建跨越中间区域的 strip
    vector<Point> strip;
    for (int i = left; i <= right; ++i) {
        if (abs(points[i].x - midPoint.x) < d) {
            strip.push_back(points[i]);
        }
    }
    // 计算 strip 中的最近点对
    return min(d, stripClosest(strip, d));
}
// 最近点对的主函数
double closest(vector<Point>& points) {
    sort(points.begin(), points.end(), compareX);  // 按 x 坐标排序
    return closestUtil(points, 0, points.size() - 1);
}
int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    double result = closest(points);
    printf("%.4lf\n", result);
    return 0;
}
