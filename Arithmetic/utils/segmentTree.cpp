#include <iostream>
using namespace std;

const int MAXN = 100005;   // 最大数组大小
long long tree[4 * MAXN];  // 线段树数组
long long lazy[4 * MAXN];  // 懒惰标记数组

// 线段树结构体
struct SegmentTree {
    int n;

    // 构造线段树
    void build(int node, int start, int end, int arr[]) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid, arr);
            build(2 * node + 2, mid + 1, end, arr);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    // 区间加操作
    void rangeUpdate(int node, int start, int end, int L, int R, int val) {
        if (lazy[node] != 0) {
            // 更新当前节点
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start > end || start > R || end < L) {
            return; // 不在更新范围内
        }

        if (start >= L && end <= R) {
            // 当前节点的区间完全包含在[L, R]范围内
            tree[node] += (end - start + 1) * val;
            if (start != end) {
                lazy[2 * node + 1] += val;
                lazy[2 * node + 2] += val;
            }
            return;
        }

        // 否则，递归更新左右子树
        int mid = (start + end) / 2;
        rangeUpdate(2 * node + 1, start, mid, L, R, val);
        rangeUpdate(2 * node + 2, mid + 1, end, L, R, val);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    // 区间查询操作
    long long rangeQuery(int node, int start, int end, int L, int R) {
        if (lazy[node] != 0) {
            // 处理当前的懒惰标记
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start > end || start > R || end < L) {
            return 0; // 不在查询范围内
        }

        if (start >= L && end <= R) {
            return tree[node]; // 当前区间完全包含在[L, R]范围内
        }

        int mid = (start + end) / 2;
        long long leftSum = rangeQuery(2 * node + 1, start, mid, L, R);
        long long rightSum = rangeQuery(2 * node + 2, mid + 1, end, L, R);
        return leftSum + rightSum;
    }
};

int main() {
    int n, m;
    cin >> n >> m; // 输入数组大小n和操作次数m

    int arr[MAXN]; // 定义数组
    for (int i = 0; i < n; ++i) {
        cin >> arr[i]; // 输入数组元素
    }

    SegmentTree segTree;
    segTree.n = n;
    segTree.build(0, 0, n - 1, arr); // 构建线段树

    for (int i = 0; i < m; ++i) {
        int op;
        cin >> op; // 输入操作类型（1: 区间加法，2: 区间查询）

        if (op == 1) {
            int L, R, k;
            cin >> L >> R >> k; // 输入区间 [L, R] 和加数 k
            segTree.rangeUpdate(0, 0, n - 1, L-1, R-1, k);
        } else if (op == 2) {
            int L, R;
            cin >> L >> R; // 输入区间 [L, R]
            cout << segTree.rangeQuery(0, 0, n - 1, L-1, R-1) << endl;
        }
    }

    return 0;
}
