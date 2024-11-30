#include <iostream>
#include <vector>

using namespace std;

vector<int> findPath(int n) {
    vector<int> path;
    while (n > 1) {
        path.push_back(n);  // 记录当前糖果数
        if ((n - 1) % 2 == 0) {
            n = (n - 1) / 2;  // 倒推 x = (n - 1) / 2
        } else if ((n + 1) % 2 == 0) {
            n = (n + 1) / 2;  // 倒推 x = (n + 1) / 2
        } else {
            return {-1};  // 无法倒推回 1，输出 -1
        }
    }
    path.push_back(1);  // 最终糖果数为 1
    return path;
}

int main() {
    int n;
    cin >> n;
    
    if (n == 1) {
        cout << 1 << endl;  // 如果 n 为 1，直接输出
        return 0;
    }

    vector<int> result = findPath(n);
    
    if (result[0] == -1) {
        cout << -1 << endl;  // 无法倒推回 1
    } else {
        for (int i = result.size() - 1; i >= 0; --i) {
            cout << result[i] << " ";  // 反向输出路径
        }
        cout << endl;
    }

    return 0;
}
