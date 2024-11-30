#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const double PI = acos(-1);

//FFT
void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) {
            j ^= bit;
        }
        j ^= bit;
        if (i < j) {
            swap(a[i], a[j]);
        }
    }

    for (int len = 2; len <= n; len <<= 1) {
        double angle = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(angle), sin(angle));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; ++j) {
                cd u = a[i + j];
                cd v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (cd& x : a) {
            x /= n;
        }
    }
}
int main() {
    int n;
    cin >> n;
    int N = 1 << n; // 2^n
    vector<int> coeffs(N);
    for (int i = 0; i < N; ++i) {
        cin >> coeffs[i];
    }

    vector<cd> poly(N);
    for (int i = 0; i < N; ++i) {
        poly[i] = coeffs[i];
    }
    fft(poly, false);

    double z_real = 0, z_imag = 0;
    for (int k = 0; k < N; ++k) {
        double cos_k = cos(k);
        z_real += cos_k * poly[k].real();
        z_imag += cos_k * poly[k].imag();
    }
    
    cout << fixed << setprecision(2) << z_real << " " << z_imag << endl;
    return 0;
}
