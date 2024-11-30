#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int contain(string chars,char a){
    int n=chars.length();
    for(int i=0;i<n;i++){
        if(chars[i]==a)return i;
    }
    return -1;
}
int maximumCostSubstring(string s, string chars, vector<int>& vals) {
    int n=s.length();
    vector<int> f(n+1);
    int index=contain(chars,s[0]);
    if(index!=-1)f[0]=vals[index];
    else f[0]=s[0]-'a'+1;
    int ans=f[0];
    for(int i=1;i<n;i++){
        int k=contain(chars,s[i]);
        if(k!=-1){
            f[i]=max(0,f[i-1])+vals[k];
        }else{
            f[i]=max(0,f[i-1])+s[i]-'a'+1;
        }
        ans=max(ans,f[i]);
    }
    return max(ans,0);
    
}
int main(){

    return 0;
}