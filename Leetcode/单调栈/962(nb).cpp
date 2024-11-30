#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxWidthRamp(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (st.empty() || nums[st.top()] > nums[i]) {
            st.push(i);
        }
    }
    int res = 0;
    for (int j = n - 1; j >= 0; j--) {
        while (!st.empty() && nums[j] >= nums[st.top()]) {
            res = max(res, j - st.top());
            st.pop();
        }
    }
    return res;
}
int main(){

    return 0;
}