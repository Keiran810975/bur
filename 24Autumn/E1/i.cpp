#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int T; // 读取数据组数
    cin >> T;
    
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> t(n + 1); // 存储每条鱼的种类编号
        for (int i = 1; i <= n; ++i) {
            cin >> t[i];
        }

        // 使用一个 map 存储每种鱼的坐标集合
        map<int, set<int>> typeMap;
        set<int> remaining; // 存储所有还没有被吃掉的鱼鱼坐标
        
        for (int i = 1; i <= n; ++i) {
            typeMap[t[i]].insert(i); // 把每条鱼的坐标放到对应种类的集合中
            remaining.insert(i);      // 初始时所有鱼鱼都还没有被吃掉
        }
        
        vector<int> result; // 存储猫猫吃鱼的顺序
        int currentPos = k; // 猫猫第一次吃鱼的坐标

        while (!remaining.empty()) {
            result.push_back(currentPos); // 记录猫猫吃掉当前坐标的鱼
            int currentType = t[currentPos]; // 当前鱼的种类

            // 从剩余的鱼鱼集合中移除当前的鱼
            remaining.erase(currentPos);
            typeMap[currentType].erase(currentPos);

            // 猫猫下一次要吃的鱼的坐标
            int nextPos = -1;

            // 如果还有当前种类的鱼，找到最近的同类鱼
            if (!typeMap[currentType].empty()) {
                auto it = typeMap[currentType].lower_bound(currentPos);
                
                // 找到距离最近的同类鱼
                if (it != typeMap[currentType].end()) {
                    nextPos = *it;
                }
                if (it != typeMap[currentType].begin()) {
                    auto prevIt = prev(it);
                    if (nextPos == -1 || abs(*prevIt - currentPos) <= abs(nextPos - currentPos)) {
                        nextPos = *prevIt;
                    }
                }
            }

            // 如果没有同类的鱼，找到距离最近的鱼
            if (nextPos == -1) {
                auto it = remaining.lower_bound(currentPos);
                
                // 找到距离最近的鱼
                if (it != remaining.end()) {
                    nextPos = *it;
                }
                if (it != remaining.begin()) {
                    auto prevIt = prev(it);
                    if (nextPos == -1 || abs(*prevIt - currentPos) <= abs(nextPos - currentPos)) {
                        nextPos = *prevIt;
                    }
                }
            }

            currentPos = nextPos; // 更新下一次猫猫要吃的鱼的坐标
        }

        // 输出猫猫吃鱼的顺序
        for (int i = 0; i < result.size(); ++i) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }

    return 0;
}
