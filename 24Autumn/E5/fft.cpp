#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef complex<double> Complex;

// 计算FFT的递归函数
void fft(vector<Complex>& a) {
    int n = a.size();
    if (n <= 1) return;

    // 分治法：将序列分成两部分，分别进行FFT
    vector<Complex> even(n / 2), odd(n / 2);
    for (int i = 0; i < n / 2; ++i) {
        even[i] = a[2 * i];
        odd[i] = a[2 * i + 1];
    }

    // 递归计算FFT
    fft(even);
    fft(odd);

    // 合并结果
    for (int k = 0; k < n / 2; ++k) {
        Complex t = exp(Complex(0, -2.0 * M_PI * k / n)) * odd[k];
        a[k] = even[k] + t;
        a[k + n / 2] = even[k] - t;
    }
}

// 用于显示复数结果的函数
void printComplexVector(const vector<Complex>& a) {
    for (const auto& c : a) {
        cout << c.real() << " + " << c.imag() << "i" << endl;
    }
}

int main() {
    // 创建一个简单的信号：两个频率成分的正弦波
    int N = 8;  // 需要变换的点数（长度必须是2的幂次）
    vector<Complex> signal(N);

    // 生成简单的信号
    for (int i = 0; i < N; ++i) {
        signal[i] = Complex(cos(2 * M_PI * i / N), 0);
    }

    // 打印原始信号
    cout << "Original Signal:" << endl;
    printComplexVector(signal);

    // 执行FFT变换
    fft(signal);

    // 打印FFT结果
    cout << "\nFFT Result:" << endl;
    printComplexVector(signal);

    return 0;
}
