#include<stdio.h>

#define MOD 1000000007
#define MAXN 2000 
long long fac[MAXN + 1], invfac[MAXN + 1];

long long qpow(long long a, long long b, long long p) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = res * a % p;
        }
        a = a * a % p;
        b /= 2;
    }
    return res;
}

long long C(int n, int m) {
    if (m > n || m < 0) return 0;
    return fac[n] * invfac[m] % MOD * invfac[n - m] % MOD;
}

int main() {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    invfac[MAXN] = qpow(fac[MAXN], MOD - 2, MOD);
    for (int i = MAXN - 1; i >= 0; i--) {
        invfac[i] = invfac[i + 1] * (i + 1) % MOD;
    }


    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        if (m < 2 * k||m>=n+k) {
            printf("0\n");
        } else {
            long long a = C(n, k);
            long long b = C(n - k, m-2*k)*(qpow(2,m-2*k, MOD))%MOD;
            long long ans = (a * (b))% MOD;
            printf("%lld\n", ans);
        }
    }
    return 0;
}
