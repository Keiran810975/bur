#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 100010;

int a[MAXN];
int mid[MAXN];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        priority_queue<int> maxHeap;                  
        priority_queue<int, vector<int>, greater<int>> minHeap; 
        mid[0] = a[0];
        maxHeap.push(a[0]);
        int m = (n + 1) / 2;
        for (int i = 1; i < m; i++) {
            int x = a[2 * i - 1];
            int y = a[2 * i];
            if (x <= mid[i - 1]) {
                maxHeap.push(x);
            } else {
                minHeap.push(x);
            }
            if (y <= mid[i - 1]) {
                maxHeap.push(y);
            } else {
                minHeap.push(y);
            }
            while (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }

            while (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            mid[i] = maxHeap.top();
        }

        for (int i = 0; i < m; i++) {
            cout << mid[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}
