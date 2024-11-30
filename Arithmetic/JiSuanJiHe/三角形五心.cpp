#include <iostream>
#include <cmath>
using namespace std;

struct point {
    double x, y;
};

// 辅助函数：两点之间的中点
point midpoint(const point& a, const point& b) {
    return {(a.x + b.x) / 2, (a.y + b.y) / 2};
}

// 辅助函数：两点之间的距离
double distance(const point& a, const point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// 重心 (Centroid)：三角形顶点的平均值
point centroid(const point& a, const point& b, const point& c) {
    return {(a.x + b.x + c.x) / 3, (a.y + b.y + c.y) / 3};
}

// 垂心 (Orthocenter)：三条高的交点
point orthocenter(const point& a, const point& b, const point& c) {
    // 求出两个高的斜率并找到它们的交点
    double m1 = -(b.x - c.x) / (b.y - c.y); // 高AC对应的斜率
    double m2 = -(a.x - c.x) / (a.y - c.y); // 高AB对应的斜率

    // 高AC的直线方程：y = m1 * (x - a.x) + a.y
    // 高AB的直线方程：y = m2 * (x - b.x) + b.y
    double x = ((m1 * a.x - m2 * b.x) + (b.y - a.y)) / (m1 - m2);
    double y = m1 * (x - a.x) + a.y;

    return {x, y};
}

// 外心 (Circumcenter)：三角形外接圆的圆心
point circumcenter(const point& a, const point& b, const point& c) {
    // 中垂线1：AB的中点和垂直斜率
    point midAB = midpoint(a, b);
    double slopeAB = -(b.x - a.x) / (b.y - a.y);

    // 中垂线2：BC的中点和垂直斜率
    point midBC = midpoint(b, c);
    double slopeBC = -(c.x - b.x) / (c.y - b.y);

    // 求两条中垂线的交点
    double x = ((slopeAB * midAB.x - slopeBC * midBC.x) + (midBC.y - midAB.y)) / (slopeAB - slopeBC);
    double y = slopeAB * (x - midAB.x) + midAB.y;

    return {x, y};
}

//找外心的另一种方法
point circumcenter2(point A, point B, point C) {
    // 使用行列式法计算外心
    double a1=2*(B.x-A.x);
    double b1=2*(B.y-A.y);
    double c1=B.x*B.x+B.y*B.y-A.x*A.x-A.y*A.y;
    double a2=2*(C.x-B.x);
    double b2=2*(C.y-B.y);
    double c2=C.x*C.x+C.y*C.y-B.x*B.x-B.y*B.y;
    point O;
    O.x=((c1*b2)-(c2*b1))/(a1*b2-a2*b1);
    O.y=((a1*c2)-(a2*c1))/(a1*b2-a2*b1);
    return O;
}

// 内心 (Incenter)：三角形内切圆的圆心
point incenter(const point& a, const point& b, const point& c) {
    // 边的长度
    double ab = distance(a, b);
    double bc = distance(b, c);
    double ca = distance(c, a);

    // 用边长加权平均计算内心
    return {(ab * c.x + bc * a.x + ca * b.x) / (ab + bc + ca),
            (ab * c.y + bc * a.y + ca * b.y) / (ab + bc + ca)};
}

// 旁心 (Excenter)：任意旁心的圆心（例如相对AB边）
point excenter(const point& a, const point& b, const point& c) {
    // 边的长度
    double ab = distance(a, b);
    double bc = distance(b, c);
    double ca = distance(c, a);

    // 用旁切边权重计算旁心
    return {(-ab * c.x + bc * a.x + ca * b.x) / (-ab + bc + ca),
            (-ab * c.y + bc * a.y + ca * b.y) / (-ab + bc + ca)};
}

int main() {
    point a = {0, 0};
    point b = {4, 0};
    point c = {0, 3};

    point g = centroid(a, b, c);
    point h = orthocenter(a, b, c);
    point o = circumcenter(a, b, c);
    point i = incenter(a, b, c);
    point e = excenter(a, b, c);

    cout << "Centroid: (" << g.x << ", " << g.y << ")\n";
    cout << "Orthocenter: (" << h.x << ", " << h.y << ")\n";
    cout << "Circumcenter: (" << o.x << ", " << o.y << ")\n";
    cout << "Incenter: (" << i.x << ", " << i.y << ")\n";
    cout << "Excenter: (" << e.x << ", " << e.y << ")\n";

    return 0;
}
