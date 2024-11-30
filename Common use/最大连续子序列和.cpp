#include<iostream>

using namespace std;
//最大连续子序列：是指序列中所有子序列中元素和最大的一个
//例如{-2,11，-4,13，-5.-2}中最大连续子序列为{11，-4,13}其和为20
//若所有k个元素都为负数，则定义其最大和为0，输出整个序列的首尾元素
int main() {
	//在输入元素的过程中，一直记录负数的个数。
	int n,neg_num=0;
	int data[100];
	int start = 0, sum = 0, maxStart = 0, maxEnd = 0, maxSum = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
			cin >> data[i];
			//判断负数的个数
			if (data[i] < 0) neg_num++;
	}
	
	if (neg_num == n) {//均为负数，直接输出
		cout << "0" <<" "<< data[0]<<" " << data[n - 1] << endl;
	}
	//若序列中存在非负数
	else if (neg_num != n) {
		for (int i = 0; i < n; i++) {
			if (sum < 0) {
				start = i;
				sum = 0;
			}
			sum = sum + data[i];
			if (sum > maxSum) {
				maxStart = start;
				maxSum = sum;
				maxEnd = i;
			}
		}
		cout << maxSum << " " << data[maxStart] << " " << data[maxEnd] << endl;
	}
	return 0;
}
