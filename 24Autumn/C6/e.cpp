#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
int gcdd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int gcd = gcdd(b, a % b, x, y);
    int temp = x;
    x = y;
    y = temp - (a / b) * y;
    return gcd;
}

int modInverse(int a, int b) {
    int x, y;
    int gcd = gcdd(a, b, x, y);
    if (gcd != 1) {
        return -1;
    } else {
        return (x % b + b) % b;
    }
}

signed main() {
    int a, b;
    cin>>a>>b;
    int inverse = modInverse(a, b);
    if (inverse != -1) {
        printf("%lld\n", inverse);
    }
    return 0;
}
