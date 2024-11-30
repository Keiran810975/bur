#include <iostream>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

// 函数 orientation 计算三点 p, q, r 的方向关系
// 返回值：
// 0 -> 三点共线
// 1 -> 顺时针方向
// 2 -> 逆时针方向
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // 如果值为 0，三点共线
    return (val > 0) ? 1 : 2; // 大于 0 顺时针，小于 0 逆时针
}

// 函数 onSegment 判断点 q 是否在线段 pr 上
bool onSegment(Point p, Point q, Point r) {
    return q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
           q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y);
}

// 函数 isIntersect 判断两条线段 (a, b) 和 (c, d) 是否相交
bool isIntersect(Point a, Point b, Point c, Point d) {
    // 计算四种组合的方向
    int o1 = orientation(a, b, c);
    int o2 = orientation(a, b, d);
    int o3 = orientation(c, d, a);
    int o4 = orientation(c, d, b);

    // 一般情况：两条线段的方向不同，说明相交
    if (o1 != o2 && o3 != o4)
        return true;

    // 特殊情况：线段共线，检查是否有重叠部分
    if (o1 == 0 && onSegment(a, c, b)) return true; // c 在 ab 上
    if (o2 == 0 && onSegment(a, d, b)) return true; // d 在 ab 上
    if (o3 == 0 && onSegment(c, a, d)) return true; // a 在 cd 上
    if (o4 == 0 && onSegment(c, b, d)) return true; // b 在 cd 上

    return false; // 否则不相交
}

// 函数 isParallel 判断两条线段是否平行
bool isParallel(Point a, Point b, Point c, Point d) {
    // 平行的条件是所有点的方向关系相同
    return orientation(a, b, c) == orientation(a, b, d) && 
           orientation(c, d, a) == orientation(c, d, b);
}

//判断两条直线是否相交
bool lineParallel(Point a, Point b, Point c, Point d) {
    int x1 = b.x - a.x;
    int y1 = b.y - a.y;
    int x2 = d.x - c.x;
    int y2 = d.y - c.y;
    int cross = x1 * y2 - x2 * y1;
    return cross == 0;
}

int main() {
    int T; // 测试用例的数量
    cin >> T;
    while (T--) { // 对每个测试用例
        Point a, b, c, d; // 定义四个点，表示两条线段的端点
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y; // 输入点的坐标

        // 判断两条线段的关系
        if (isIntersect(a, b, c, d)) {
            cout << "intersect" << endl; // 如果相交，输出 "intersect"
        } else if (isParallel(a, b, c, d)) {
            cout << "parallel" << endl; // 如果平行，输出 "parallel"
        } else {
            cout << "neither" << endl; // 否则输出 "neither"
        }
    }

    return 0; // 程序结束
}
