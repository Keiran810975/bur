#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int cap;
int w[150], v[150], num[150]; // 体积、价值和每种物品的数量限制
int n;             // 物品种类数
// 空间优化版动态规划
int ff[100100];
void dp2() {
    memset(ff,0,sizeof(ff));
    for (int i = 0; i < n; i++) {
        for (int j = cap; j >= 0; j--) {
            for (int k = 0; k <= num[i] && k * w[i] <= j; k++) {
                ff[j] = max(ff[j], ff[j - k * w[i]] + k * v[i]);
            }
        }
    }
    printf("%d\n", ff[cap]);
}

int main() {
    int t;
    cin>>t;
    while(t--){
        cin>>n>>cap;
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&num[i],&w[i],&v[i]);
        }
        dp2();
    }
    return 0;
}
