#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool h[1000];
int lengthOfLongestSubstring(string s) {
    int n=s.length();
    if(n==1)return 1;
    int l=0;
    h[s[l]]=true;
    int cnt=0;
    int maxc=0;
    for(int r=1;r<n;r++){
        if(h[s[r]]){
            while(s[l]!=s[r]){
                h[s[l]]=false;
                l++;
            }
            l++;
        }
        h[s[r]]=true;
        cnt=r-l+1;
        maxc=max(maxc,cnt);
    }
    return maxc;
}
int main(){
    cout<<lengthOfLongestSubstring("a");
    return 0;
}