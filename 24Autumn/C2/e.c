#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
//矩阵乘法
void mul(int n,long long a[][n],long long b[][n],long long c[][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[i][j]=0;
            for(int k=0;k<n;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
    }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        long long a[n][n];
        long long b[n][n];
        long long c[n][n];
        memset(c,0,sizeof(c));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%lld",&a[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%lld",&b[i][j]);
            }
        }
        mul(n,a,b,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%lld ",c[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}