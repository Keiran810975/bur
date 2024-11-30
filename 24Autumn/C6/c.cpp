#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 大数乘法函数
string multiplyLargeNumbers(const string& num1, const string& num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    vector<int> result(len1 + len2, 0);
    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10; 
            result[i + j] += sum / 10; 
        }
    }
    string resultStr = "";
    for (int num : result) {
        if (!(resultStr.empty() && num == 0)) { 
            resultStr += (num + '0');
        }
    }
    return resultStr.empty() ? "0" : resultStr;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        string num1, num2;
        cin >> num1 >> num2; 
        string result = multiplyLargeNumbers(num1, num2);
        cout << result << '\n';
    }
    
    
    return 0;
}
