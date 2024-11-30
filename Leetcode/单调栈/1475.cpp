#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> finalPrices(vector<int>& prices) {
    int n=prices.size();
    vector<int> mono(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        int t=prices[i];
        while(!st.empty()&&t<prices[st.top()]){
            st.pop();
        }
        if(!st.empty()){
            mono[i]=st.top();
        }
        st.push(i);
    }
    vector<int> ans=prices;
    for(int i=0;i<n;i++){
        if(mono[i]){
            ans[i]-=prices[mono[i]];
        }
    }
    return ans;
}
int main(){

    return 0;
}