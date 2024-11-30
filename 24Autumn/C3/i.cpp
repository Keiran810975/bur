#include <stdio.h>
#include <string.h>

int countSubsequences(const char *s) {
    int n = strlen(s);
    int count_a_before[n];  // 记录到每个位置为止的 'a' 的数量
    int count_a_after[n];   // 记录每个位置后面的 'a' 的数量
    int total_count = 0;

    // 初始化 count_a_before 和 count_a_after
    for (int i = 0; i < n; i++) {
        count_a_before[i] = (i > 0 ? count_a_before[i - 1] : 0) + (s[i] == 'a' ? 1 : 0);
    }

    for (int i = n - 1; i >= 0; i--) {
        count_a_after[i] = (i < n - 1 ? count_a_after[i + 1] : 0) + (s[i] == 'a' ? 1 : 0);
    }

    // 遍历字符串，寻找符合条件的 'u'
    for (int i = 0; i < n; i++) {
        if (s[i] == 'u') {
            int a_before = (i > 0) ? count_a_before[i - 1] : 0;
            int a_after = (i < n - 1) ? count_a_after[i + 1] : 0;
            total_count += a_before * a_after;
        }
    }

    return total_count;
}

int main() {
    char s[100001];  // 假设字符串的最大长度为 100000
    scanf("%s", s);
    printf("%d\n", countSubsequences(s));
    return 0;
}
