#include <iostream>
using namespace std;
long long fastPower(long long base, long long exp, long long mod) {
    long long result = 1;  // 初始化结果为1
    base = base % mod;     // 处理base大于mod的情况

    while (exp > 0) {
        // 如果 exp 是奇数，将 base 乘到结果中
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }

        // exp 变为 exp/2
        exp = exp >> 1;

        // base 自身相乘
        base = (base * base) % mod;
    }

    return result;
}

int main() {
    long long base;
    long long exp;
    long long mod;
    cin >> base >> exp >> mod;

    printf("%lld^%lld mod %lld=%lld\n",base,exp,mod,fastPower(base, exp, mod));

    return 0;
}
