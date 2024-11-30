#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int> res(nums.size(),-1);//初始化结果数组，默认为-1
    stack<int> st;//单调栈 
    for(int i=0;i<nums.size();i++){
        while(!st.empty()&&nums[st.top()]<nums[i]){
            res[st.top()]=nums[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}
int main(){
    vector<int> nums={1,4,3,5,5,2,3,6};
    //for(int i=0;i<nums.size();i++)nums[i]+=5;
    vector<int> res=nextGreaterElement(nums);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}