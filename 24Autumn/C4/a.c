#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int n,k;
int w[1010],v[1010];
double y[1010];
double dp[1010][1010];
int cmp(const void *a,const void *b){
    return *(double*)a-*(double*)b;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d%d",&w[i],&v[i]);
        y[i]=v[i]*1.0/w[i];
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=k;j>=0;j--){
    //         for(int h=0;h<=w[i]&&h*y[i]<=j;h++){

    //         }
    //     }
    // }
    //按照y[i]排序y和w
    qsort(y,n,sizeof(double),cmp);
    double ans=0;
    while(ans<=k){
        ans+=y[n-1];
    }

    return 0;
}