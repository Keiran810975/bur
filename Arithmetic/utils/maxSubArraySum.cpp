#include <iostream>

using namespace std;
int arr[200010];
int maxSoFar = -1e6;  // 用于保存最终的最大子段和
int maxEndingHere = 0;// 用于跟踪当前子段和
void maxSubArraySum(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        maxEndingHere += arr[i];  // 更新当前子段和

        if (maxEndingHere > maxSoFar) {
            maxSoFar = maxEndingHere;  // 如果当前子段和更大，则更新最终的最大子段和
        }

        if (maxEndingHere < 0) {
            maxEndingHere = 0;  // 如果当前子段和为负数，则重置为 0
        }
    }
}

int main() {
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    maxSubArraySum(arr, n);
    cout << maxSoFar << endl;

    return 0;
}
