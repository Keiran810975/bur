#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
    int n=calories.size();
    int cnt=0;
    int scores=0;
    for(int i=0;i<n;i++){
        cnt+=calories[i];
        if(i<k-1)continue;
        if(cnt>upper)scores++;
        else if(cnt<lower)scores--;
        cnt-=calories[i-k+1];
    }
    return scores;
}
int main(){

    return 0;
}