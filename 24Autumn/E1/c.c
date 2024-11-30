#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int a[1010];
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int maxSum=0;
int sum=0;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),cmp);
    int min=a[0],max=a[0];
    int l=0;
    for(int r=0;r<n;r++){
        // min=min<a[r]?min:a[r];
        max=a[r];
        sum+=a[r];

        while(max-min>k){
            sum-=a[l];
            l++;
            min=a[l];
        }
        maxSum=maxSum>sum?maxSum:sum;
    }
    printf("%d",maxSum);
    
    return 0;
}