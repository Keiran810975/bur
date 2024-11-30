#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        int t=temperatures[i];
        while(!st.empty()&&t>temperatures[st.top()]){
            int j=st.top();
            st.pop();
            ans[j]=i-j;
        }
        st.push(i);
    }
    return ans;
}
int main(){

    return 0;
}