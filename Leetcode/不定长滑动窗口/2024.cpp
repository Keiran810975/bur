#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxConsecutiveAnswers(string answerKey, int k) {
    int t=k;
    int l=0;
    int max1=0;
    int n=answerKey.length();
    for(int r=0;r<n;r++){
        if(answerKey[r]=='F'){
            t--;
        }
        if(t<0){
            while(answerKey[l]!='F'){
                l++;
            }
            l++;
            t++;
        }
        max1=max(max1,r-l+1);
    }
    l=0;
    t=k;
    int max2=0;
    for(int r=0;r<n;r++){
        if(answerKey[r]=='T'){
            t--;
        }
        if(t<0){
            while(answerKey[l]!='T'){
                l++;
            }
            l++;
            t++;
        }
        max2=max(max2,r-l+1);
    }
    return max(max1,max2);
}
int main(){

    return 0;
}