#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int a[100010],b[100010];
int x[100010],y[100010];
int ab[200010],xy[200010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        for(int i=0;i<n;i++)scanf("%d",&x[i]);
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;i++)scanf("%d",&b[i]);
        for(int i=0;i<m;i++)scanf("%d",&y[i]);
        int max=m>n?m:n;
        int i=0,j=0,k=0;
        while(i < n && j < m) {
            if(x[i] < y[j]) {
                ab[k] = a[i];
                xy[k++] = x[i++];
            }
            else if(x[i] > y[j]) {
                ab[k] = b[j];
                xy[k++] = y[j++];
            }
            else {
                ab[k] = a[i] + b[j++];
                xy[k++] = x[i++];
            }
        }
        while(i < n) {
            ab[k] = a[i];
            xy[k++] = x[i++];
        }
        while(j < m) {
            ab[k] = b[j];
            xy[k++] = y[j++];
        }
        printf("%d\n",k);
        for(int i=0;i<k;i++)printf("%d ",ab[i]);
        printf("\n");
        for(int i=0;i<k;i++)printf("%d ",xy[i]);
        printf("\n");
    }
    return 0;
}