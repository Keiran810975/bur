#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int r;
int a[1010][1010];
int cache[1010][1010];
int main() {
    memset(cache, 0, sizeof(cache));
    scanf("%d", &r);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = r - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            if (i == r - 1) {
                cache[i][j] = a[i][j];  
            } else {
                cache[i][j] = a[i][j] + max(cache[i + 1][j], cache[i + 1][j + 1]);
            }
        }
    }
    printf("%d\n", cache[0][0]);
    return 0;
}
