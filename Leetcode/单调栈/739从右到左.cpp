#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n=temperatures.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        int t=temperatures[i];
        while(!st.empty()&&t>=temperatures[st.top()]){
            st.pop();
        }
        if(!st.empty()){
            ans[i]=st.top()-i;
        }
        st.push(i);
    }
    return ans;
}
int main(){

    return 0;
}