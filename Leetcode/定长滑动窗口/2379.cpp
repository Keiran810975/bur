#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int minimumRecolors(string blocks, int k) {
    int n=blocks.length();
    int cnt=0;
    int maxc=0;
    for(int i=0;i<n;i++){
        if(blocks[i]=='B')cnt++;
        if(i<k-1)continue;
        maxc=max(maxc,cnt);
        if(blocks[i-k+1]=='B')cnt--;
    }
    return k-maxc;
}
int main(){

    return 0;
}