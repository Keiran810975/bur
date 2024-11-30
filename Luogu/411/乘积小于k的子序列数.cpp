#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
int nums[114514];
int k;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>k;
    int ans=0;
    int l=0;
    if(k<1){
        cout<<0;
    }else{
        int prod=1;
        for(int r=0;r<n;r++){
            prod*=nums[r];
            while(prod>=k){
                prod/=nums[l];
                l++;
            }
            ans+=r-l+1;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}