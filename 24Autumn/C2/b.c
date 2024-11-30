#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int a[n+1];
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int max=0,max2=0;//最大和第二大
        for(int i=1;i<=n;i++){
            if(a[i]>max){
                max2=max;
                max=a[i];
            }else if(a[i]>max2){
                max2=a[i];
            }
        }
        printf("%d\n",max+max2);
    }
    return 0;
}