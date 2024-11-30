#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// 大数乘法
vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> result(a.size() + b.size(), 0);
    
    // 进行乘法操作
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            result[i + j] += a[i] * b[j];
            if (result[i + j] >= 10) { // 处理进位
                result[i + j + 1] += result[i + j] / 10;
                result[i + j] %= 10;
            }
        }
    }
    
    // 去除多余的前导0
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    
    return result;
}

// 计算 2^P 的大数表示
vector<int> power(int base, int exponent) {
    vector<int> result = {1}; // 初始化为 1
    vector<int> baseBigInt = {base}; // 基数是2
    
    while (exponent > 0) {
        if (exponent % 2 == 1) { // 如果指数是奇数
            result = multiply(result, baseBigInt); // 将结果乘以当前基数
        }
        baseBigInt = multiply(baseBigInt, baseBigInt); // 基数平方
        exponent /= 2; // 指数减半
    }
    
    return result;
}

// 打印大数，从高位到低位
void printBigInt(const vector<int>& number) {
    for (auto it = number.rbegin(); it != number.rend(); ++it) {
        cout << *it;
    }
}

// 主函数
int main() {
    int P;
    cin >> P;

    // 计算 2^P
    vector<int> number = power(2, P);
    
    // 减去1
    number[0] -= 1; // 处理最低位减1
    for (int i = 0; i < number.size(); ++i) {
        if (number[i] < 0) { // 处理借位
            number[i] += 10;
            number[i + 1] -= 1;
        }
    }
    while (number.size() > 1 && number.back() == 0) {
        number.pop_back(); // 去除最高位的0
    }

    // 输出位数
    cout << number.size() << endl;

    // 输出最后500位，不足则补零
    if (number.size() < 500) {
        cout << setw(500) << setfill('0'); // 补零输出
        printBigInt(number);
        cout << endl;
    } else {
        for (int i = 0; i < 500; i += 50) {
            for (int j = 0; j < 50; ++j) {
                cout << number[number.size() - 500 + i + j];
            }
            cout << endl;
        }
    }

    return 0;
}
