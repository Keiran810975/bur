#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool strc(string s,string t){
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]==t[i])continue;
        if(s[i]>t[i])return true;
        return false;
    }
    return false;
}
string shortestBeautifulSubstring(string s, int k) {
    string tmp;
    int n=s.length();
    int l=0;
    int minLen=INT_MAX;
    string ans="";
    int cnt=0;
    for(int r=0;r<n;r++){
        int sig=0;
        if(s[r]=='1'){
            cnt++;
            sig=1;
        }
        if(sig&&cnt==k){
            while(s[l]=='0')l++;
            tmp=s.substr(l,r-l+1);
            if(tmp.length()<minLen){
                ans=tmp;
                minLen=tmp.length();
            }else if(tmp.length()==minLen){
                if(!strc(tmp,ans)){
                    ans=tmp;
                }
            }
        }
        else if(cnt>k){
            while(s[l]!='1'){
                l++;
            }
            l++;
            while(s[l]=='0')l++;
            cnt--;
            tmp=s.substr(l,r-l+1);
            if(tmp.length()<minLen){
                ans=tmp;
                minLen=tmp.length();
            }else if(tmp.length()==minLen){
                if(!strc(tmp,ans)){
                    ans=tmp;
                }
            }
        }
    }
    return ans;
}
int main(){

    return 0;
}