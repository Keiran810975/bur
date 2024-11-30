#include<iostream>
#include<bits/stdc++.h>
using namespace std;
char s[100];
int k;
int main(){
    scanf("%s",s);
    cin>>k;
    int n=strlen(s);
    int l=0,ans=0;
    int zeros=0,ones=0;
    for(int r=0;r<n;r++){
        if(s[r]=='0')zeros++;
        else ones++;
        while(zeros>k&&ones>k){
            if(s[l]=='0')zeros--;
            else ones--;
            l++;
        }
        ans+=r-l+1;
    }
    cout<<ans<<'\n';
    return 0;
}