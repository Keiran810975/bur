#include<stdio.h>
int a[500001];
int b[500001];
int main(){
    int n,m;
    int sum,avg;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i+1]=b[i]+a[i];
    }
    int max=0;
    for(int i=0;i<n-m;i++){
        for(int j=m;j<2*m;j++){
            
            sum=b[i+j]-b[i];
            avg=(sum+j/2)/j;
            if(avg>max)
            max=avg;
            
        }
    }
    printf("%d\n",max);

    return 0;
}