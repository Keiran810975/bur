#include <stdio.h>

#define MOD 998244353

// 计算 (base^exp) % mod 的快速幂函数
long long power_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// 计算 N 值
long long calculate_N(int n, double p, long long mod) {
    long long N = 0;
    double prob = 1.0;

    for (int i = 1; i <= n; i++) {
        long long term = (long long)(i * prob) % mod; // 将浮点数结果转为整数再进行取模
        N = (N + term) % mod;
        prob *= (1 - p);  // 更新概率
    }

    return N;
}

int main() {
    int n;
    double p;
    
    // 输入 n 和 p
    scanf("%d %lf", &n, &p);

    // 计算 N
    long long N = calculate_N(n, p, MOD);

    if (N != 0) {
        // 使用费马小定理计算 q^-1, 即 N 的逆元
        long long q_inv = power_mod(N, MOD - 2, MOD);
        
        // p = 1，所以 r = p * q_inv % MOD
        long long r = (1 * q_inv) % MOD;

        // 输出最终的精确胜率 r
        printf("%lld\n", r);
    } else {
        printf("N 为 0，无法计算逆元。\n");
    }

    return 0;
}
