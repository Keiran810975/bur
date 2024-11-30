#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 5000
#define MAXW 10000

int max(int a, int b) {
    return a > b ? a : b;
}

typedef struct {
    int weight;
    int value;
} Item;

Item items[MAXN];
int dp_no_free[MAXW + 1], dp_with_free[MAXW + 1];

int cmp(const void *a, const void *b) {
    return ((Item *)b)->value - ((Item *)a)->value;
}
void solve() {
    int n, W, k;
    scanf("%d %d %d", &n, &W, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    qsort(items, n, sizeof(Item), cmp);
    memset(dp_no_free, 0, sizeof(dp_no_free));
    memset(dp_with_free, 0, sizeof(dp_with_free));
    for (int i = 0; i < n; i++) {
        for (int j = W; j >= items[i].weight; j--) {
            dp_no_free[j] = max(dp_no_free[j], dp_no_free[j - items[i].weight] + items[i].value);
        }
    }
    int result = dp_no_free[W];
    for (int freeCount = 1; freeCount <= k && freeCount <= n; freeCount++) {
        memcpy(dp_with_free, dp_no_free, sizeof(dp_no_free));

        int free_value_sum = 0;
        for (int i = 0; i < freeCount; i++) {
            free_value_sum += items[i].value;
        }

        for (int i = freeCount; i < n; i++) {
            for (int j = W; j >= items[i].weight; j--) {
                dp_with_free[j] = max(dp_with_free[j], dp_with_free[j - items[i].weight] + items[i].value);
            }
        }

        result = max(result, dp_with_free[W] + free_value_sum);
    }

    printf("%d\n", result);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
