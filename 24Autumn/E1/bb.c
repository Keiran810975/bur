#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int a[1000005];
int bucket[1000005];
int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        bucket[a[i]]++;
    }
    //把bucket数组的前缀和算出来
    for(int i=1;i<=1000000;i++){
        bucket[i]+=bucket[i-1];
    }
    while (q--) {
        int d, k;
        scanf("%d %d", &d, &k);
        int cnt=0;
        long long l=(long long)d*k;
        long long r=(long long)d*(k+1)-1;
        if(l>1000000)printf("0\n");  
        else if(r>1000000){
            r=1000000;
            cnt=bucket[r]-bucket[l>0?l-1:0];
            printf("%d\n", cnt);
        }  
        else{
            cnt=bucket[r]-bucket[l>0?l-1:0];
            printf("%d\n", cnt);
        }
        
    }
    return 0;
}
