#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// int wei(int num){
//     int cnt=0;
//     while(num!=0){
//         num=num/2;
//         cnt++;
//     }
//     return cnt;
// }
int main() {
    int n;
    cin >> n;
    int k = log2(n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        int rev = 0;
        for (int j = 0; j < k; ++j) {
            rev = (rev << 1) | ((i >> j) & 1);
        }
        printf("%d ",arr[rev]);
    }
    printf("\n");

    return 0;
}
