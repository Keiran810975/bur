#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int mm[1000001];int nn[1001],sum[1001];
int main(){
    int n,d;int nn[1001];
    scanf("%d%d",&n,&d);
    scanf("%d",&sum[0]);
    for(int i=1;i<n;i++){
        scanf("%d",&nn[i]);
        sum[i+1]=sum[i]+nn[i];
    }
    int max=0;
    for(int i=0;i<n-d+1;i++){
        if(max<sum[i+d]-sum[i])max=sum[i+d]-sum[i];
    }
    printf("%d",max);

    return 0;
}