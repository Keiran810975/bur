#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int n;
int s[100110], t[100110];
int f[2][100110]; // 只保留两行

void dp() {
    for (int i = 0; i < n; i++) {
        int cur = i % 2;     // 当前行
        int prev = 1 - cur;  // 上一行
        for (int j = 0; j < n; j++) {
            if (s[i] == t[j]) {
                f[cur][j + 1] = f[prev][j] + 1;
            } else {
                f[cur][j + 1] = max(f[prev][j + 1], f[cur][j]);
            }
        }
    }
    printf("%d\n", f[(n - 1) % 2][n]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    dp();
    return 0;
}
