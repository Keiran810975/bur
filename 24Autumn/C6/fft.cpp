#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
// 定义类型方便复数计算
typedef complex<double> Complex;

// 计算旋转因子 W_N^m
Complex calculateTwiddleFactor(int N, int m) {
    double angle = -2.0 * M_PI * m / N; // 角度为负表示逆变换
    return Complex(cos(angle), sin(angle));
}

// 蝶形操作函数
void butterflyOperation(vector<Complex>& data, int N) {
    int halfSize = N / 2; // 每次操作的半边大小

    for (int m = 0; m < halfSize; ++m) {
        // 当前两个输入点
        Complex X0 = data[m];
        Complex X1 = data[m + halfSize];
        
        // 旋转因子
        Complex W = calculateTwiddleFactor(N, m);
        
        // 蝶形计算
        data[m] = X0 + W * X1;           // 和分量
        data[m + halfSize] = X0 - W * X1; // 差分量
    }
}

int main() {
    // 示例数据：4 点输入
    vector<Complex> data = {1.0, 2.0, 3.0, 4.0};

    cout << "Input data:" << endl;
    for (const auto& d : data) {
        cout << d << endl;
    }

    // 执行蝶形操作
    butterflyOperation(data, data.size());

    cout << "\nOutput data after butterfly operation:" << endl;
    for (const auto& d : data) {
        cout << d << '\n';
    }

    return 0;
}
