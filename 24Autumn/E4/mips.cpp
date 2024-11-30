#include <stdio.h>
#define length (500)

int a[length] = {1};

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int jinwei = 0;
        for (int j = 0; j < length; j++) {
            int temp = a[j] * i + jinwei;
            jinwei = temp / 10;
            a[j] = temp % 10;
        }
    }
    int k = length - 1;
    while (!a[k]) { 
        k--;
    }
    while (k >= 0) 
        printf("%d", a[k--]);
    return 0;
}