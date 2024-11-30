#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 计算曼哈顿距离
int manhattan_distance(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int min_manhattan_distance(vector<pair<int, int>>& points) {
    // 存储变换后的点集合
    vector<pair<int, pair<int, int>>> transformed_points;
    
    // 将点进行四种变换
    for (auto& point : points) {
        int x = point.first, y = point.second;
        transformed_points.push_back({x + y, {x, y}});
        transformed_points.push_back({x - y, {x, y}});
        transformed_points.push_back({-x + y, {x, y}});
        transformed_points.push_back({-x - y, {x, y}});
    }

    // 对变换后的点按照第一个坐标进行排序
    sort(transformed_points.begin(), transformed_points.end());

    // 最小曼哈顿距离初始化为一个很大的值
    int min_dist = INT_MAX;

    // 遍历相邻的点，计算最小曼哈顿距离
    for (int i = 1; i < transformed_points.size(); i++) {
        // 获取两个点的原始坐标
        pair<int, int> p1 = transformed_points[i - 1].second;
        pair<int, int> p2 = transformed_points[i].second;
        
        // 计算曼哈顿距离并更新最小值
        min_dist = min(min_dist, manhattan_distance(p1, p2));
    }

    return min_dist;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<pair<int, int>> points(n);
        
        // 输入点的坐标
        for (int i = 0; i < n; i++) {
            cin >> points[i].first >> points[i].second;
        }

        // 调用函数计算最小曼哈顿距离
        int result = min_manhattan_distance(points);
        
        // 输出结果
        cout << result << endl;
    }

    return 0;
}
