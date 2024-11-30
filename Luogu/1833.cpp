#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int w[10010],v[10010],num[10010];
int main(){
    int a,c,b,d,n;
    scanf("%d:%d %d:%d %d",&a,&b,&c,&d,&n);
    int x=a*60+b,y=c*60+d;
    int cap=y-x;
    //cout<<cap<<endl;
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&w[i],&v[i],&num[i]);
        if(!num[i])num[i]=1e9;
    }
    int ff[10010];
    for (int i = 0; i < n; i++) {
        // 逆序遍历容量，防止重复使用物品
        for (int j = cap; j >= 0; j--) {
            // 每件物品最多选 num[i] 次
            for (int k = 0; k <= num[i] && k * w[i] <= j; k++) {
                ff[j] = max(ff[j], ff[j - k * w[i]] + k * v[i]);
            }
        }
    }
    printf("%d\n", ff[cap]);

    return 0;
}