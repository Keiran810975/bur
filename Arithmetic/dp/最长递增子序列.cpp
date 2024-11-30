//每件物品可以重复选
//**Dilworth定理：最少的不上升子序列的个数就是最长上升子序列的长度。**
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int arr[1000];
int n;
int f[1000];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(arr[i]>arr[j]){
                f[i]=max(f[i],f[j]);
            }
        }
        f[i]+=1;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,f[i]);
    }
    printf("%d\n",ans);

    return 0;
}