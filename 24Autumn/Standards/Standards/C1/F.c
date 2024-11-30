#include<stdio.h>

#define N 200010

int t;
int a[N], b[N], c[N];
int x[N], y[N], z[N];
int n, m, k;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; i++) {
            scanf("%d", &x[i]);
        }
        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }
        for(int i = 0; i < m; i++) {
            scanf("%d", &y[i]);
        }
        int i = 0, j = 0;
        k = 0;
        while(i < n && j < m) {
            if(x[i] < y[j]) {
                c[k] = a[i];
                z[k] = x[i];
                k++;
                i++;
            }
            else if(x[i] > y[j]) {
                c[k] = b[j];
                z[k] = y[j];
                k++;
                j++;
            }
            else {
                c[k] = a[i] + b[j];
                z[k] = x[i];
                k++;
                i++;
                j++;
            }
        }
        while(i < n) {
            c[k] = a[i];
            z[k] = x[i];
            k++;
            i++;
        }
        while(j < m) {
            c[k] = b[j];
            z[k] = y[j];
            k++;
            j++;
        }
        printf("%d\n", k);
        for(int i = 0; i < k; i++) {
            printf("%d ", c[i]);
        }
        printf("\n");
        for(int i = 0; i < k; i++) {
            printf("%d ", z[i]);
        }
        printf("\n");
    }
    return 0;
}
