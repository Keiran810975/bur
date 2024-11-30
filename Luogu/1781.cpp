#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string max="";
    int x=0;
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        int l=s.size();
        if(l>max.size()||(l==max.size()&&s>max)){
            max=s;
            x=i;
        }
    }
    cout<<x<<'\n'<<max<<endl;
    return 0;
}