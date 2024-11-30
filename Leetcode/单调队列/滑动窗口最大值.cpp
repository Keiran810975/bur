#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> q; 
    for (int i = 0; i < nums.size(); i++) {
        // 1. 入
        while (!q.empty() && nums[q.back()] <= nums[i]) {
            q.pop_back(); // 维护 q 的单调性
        }
        q.push_back(i); // 入队
        // 2. 出
        if (i - q.front() >= k) { // 队首已经离开窗口了
            q.pop_front();
        }
        // 3. 记录答案
        if (i >= k - 1) {
            // 由于队首到队尾单调递减，所以窗口最大值就是队首
            ans.push_back(nums[q.front()]);
        }
    }
    return ans;
}
int main(){

    return 0;
}