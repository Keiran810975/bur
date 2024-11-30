#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int> res(nums.size(),-1);//初始化结果数组，默认为-1
    stack<int> st;//单调栈 
    for(int i=0;i<nums.size();i++){
        while(!st.empty()&&nums[st.top()]<nums[i]){
            res[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    return res;
}
vector<int> d;
vector<int> c;
vector<int> nge;
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        d.push_back(x);
        c.push_back(y);
    }
    nge=nextGreaterElement(d);
    for(int i=0;i<q;i++){
        int r,q;
        cin>>r>>q;
        while(1){
            if(q<=c[r-1]){
                cout<<r<<endl;
                break;
            }
            q-=c[r-1];
            //printf("^%d^\n",nge[r-1]);
            if(nge[r-1]!=-1)r=nge[r-1]+1;
            else {
                cout<<0<<endl;
                break;
            }
        }
    }
    return 0;
}