#include <stdio.h>

const long long MOD = 1000000007;
long long mod_pow(long long x, long long y, long long mod) {
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        y /= 2;
    }
    return res;
}
long long factorial(int n) {
    if (n == 0) return 1;
    long long res = 1;
    for (int i = 1; i <= n; i++) {
        res = (res * i) % MOD;
    }
    return res;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        if ((m - 2 * k >= 0) && (n + k - m >= 0) && (k >= 0)) {
            long long numerator = factorial(n);
            long long denom1 = factorial(k);
            long long denom2 = factorial(m - 2 * k);
            long long denom3 = factorial(n + k - m);
            long long denominator = ((denom1 * denom2 % MOD) * denom3) % MOD;
            denominator = mod_pow(denominator, MOD - 2, MOD);  // 费马小定理求逆元
            long long power_of_two = mod_pow(2, m - 2 * k, MOD);
            long long result = (numerator * power_of_two % MOD) * denominator % MOD;
            printf("%lld\n", result);
        } else {
            printf("0\n");
        }
    }
    return 0;
}
