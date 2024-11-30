#include<iostream>
#include<bits/stdc++.h> // 包含所有标准库头文件（较重，建议替换为具体的头文件）
using namespace std;

#define ll long long // 定义 ll 为 long long 类型的简写

// 函数 distance：计算两点之间的欧几里得距离
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// 函数 dot：计算两向量的点积
double dot(double x1, double y1, double x2, double y2) {
    return x1 * x2 + y1 * y2;
}

// 函数 length：计算向量的长度（模）
double length(double x, double y) {
    return sqrt(x * x + y * y);
}

int main() {
    int t; // 测试用例数量
    cin >> t; // 输入测试用例数
    while (t--) { // 对每个测试用例执行以下代码
        double xA, yA, xP, yP, xQ, yQ;
        // 输入点 A 的坐标
        scanf("%lf%lf", &xA, &yA);
        // 输入线段 PQ 的两个端点 P 和 Q 的坐标
        scanf("%lf%lf%lf%lf", &xP, &yP, &xQ, &yQ);

        // 计算向量 PQ 和 PA
        double pqX = xQ - xP; // 向量 PQ 的 x 分量
        double pqY = yQ - yP; // 向量 PQ 的 y 分量
        double paX = xA - xP; // 向量 PA 的 x 分量
        double paY = yA - yP; // 向量 PA 的 y 分量

        // 计算线段 PQ 的长度平方（避免重复开方运算，提高效率）
        double pqLengthSquared = pqX * pqX + pqY * pqY;

        // 计算点 A 在直线 PQ 上的投影比例 t
        // t = (PA向量与PQ向量的点积) / (PQ向量的长度平方)
        double t = (paX * pqX + paY * pqY) / pqLengthSquared;

        double minDist; // 最短距离

        if (t < 0) {
            // 投影点在 P 外，最近点为 P
            minDist = distance(xA, yA, xP, yP);
        } else if (t > 1) {
            // 投影点在 Q 外，最近点为 Q
            minDist = distance(xA, yA, xQ, yQ);
        } else {
            // 投影点在线段 PQ 上，计算垂直距离
            double projX = xP + t * pqX; // 投影点的 x 坐标
            double projY = yP + t * pqY; // 投影点的 y 坐标
            minDist = distance(xA, yA, projX, projY);
        }
        // 输出最短距离，保留三位小数
        printf("%.3lf\n", minDist);
    }
    
    return 0;
}
