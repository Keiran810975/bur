#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y, id;
    long long cnt; // 用于存储跨区间查询时的结果
};

vector<Point> points;  // 原始点集
vector<Point> tmp;     // 临时数组用于归并排序
vector<int> segTree;   // 线段树

// 线段树的 build 函数
void build(int node, int start, int end) {
    if (start == end) {
        // 初始化为 0，表示没有点
        segTree[node] = 0;
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
    }
}

// 线段树更新函数：将 idx 位置的值更新为 val
void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        // 叶节点，直接更新
        segTree[node] += val;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        // 重新计算父节点的值
        segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
    }
}

// 线段树查询函数：查询范围 [1, idx] 的和
int query(int node, int start, int end, int L, int R) {
    if (R < start || L > end) {
        // 区间 [L, R] 完全不在 [start, end] 范围内
        return 0;
    }
    if (L <= start && end <= R) {
        // 区间 [start, end] 完全包含在 [L, R] 范围内
        return segTree[node];
    }
    // 否则，查询左右子树
    int mid = (start + end) / 2;
    int leftSum = query(2 * node, start, mid, L, R);
    int rightSum = query(2 * node + 1, mid + 1, end, L, R);
    return leftSum + rightSum;
}

// CDQ 分治函数，l 到 r 是处理的点的范围
void CDQ(int l, int r, int n) {
    if (l >= r) return;

    int mid = (l + r) / 2;
    CDQ(l, mid, n);
    CDQ(mid + 1, r, n);

    int i = l, j = mid + 1, k = l;

    // 归并排序时处理跨区间问题
    while (i <= mid && j <= r) {
        if (points[i].y <= points[j].y) {
            update(1, 1, n, points[i].y, 1); // 将左半部分的点加入线段树
            tmp[k++] = points[i++];
        } else {
            // 对右半部分的点进行查询，计算左边有多少个 y < 当前点的 y
            points[j].cnt += query(1, 1, n, 1, points[j].y - 1);
            tmp[k++] = points[j++];
        }
    }

    // 处理剩余的左半部分
    while (i <= mid) {
        update(1, 1, n, points[i].y, 1);
        tmp[k++] = points[i++];
    }

    // 处理剩余的右半部分
    while (j <= r) {
        points[j].cnt += query(1, 1, n, 1, points[j].y - 1);
        tmp[k++] = points[j++];
    }

    // 恢复线段树，防止影响后续计算
    for (i = l; i <= mid; i++) {
        update(1, 1, n, points[i].y, -1);
    }

    // 归并排序的结果存回原数组
    for (i = l; i <= r; i++) {
        points[i] = tmp[i];
    }
}

int main() {
    int n;
    cin >> n;
    
    points.resize(n + 1);
    tmp.resize(n + 1);
    segTree.resize(4 * n + 1);  // 线段树的大小是 4n

    // 输入点集
    for (int i = 1; i <= n; i++) {
        cin >> points[i].x >> points[i].y;
        points[i].id = i;  // 保留每个点的原始位置
        points[i].cnt = 0; // 初始化跨区间计数为 0
    }

    // 按 x 坐标排序，为了分治
    sort(points.begin() + 1, points.end(), [](Point &a, Point &b) {
        return a.x < b.x;
    });

    // 建立线段树
    build(1, 1, n);

    // CDQ 分治
    CDQ(1, n, n);

    // 统计满足条件的点对数
    long long result = 0;
    for (int i = 1; i <= n; i++) {
        result += points[i].cnt;
    }

    // 输出结果
    cout << result << endl;

    return 0;
}
