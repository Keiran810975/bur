#include<stdio.h>
int a[3000001];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    long long sum=0;
    int x;
    for(int i=0;i<n+1;i++){
        scanf("%d",&x);
        a[i]=x;
        sum+=a[i];
    }
    int temp;
    for(int j=0;j<=m+1;j++){
        for(int k=j;k<n+1;k++){
            if(a[j]<a[k]){
                temp=a[j];
                a[j]=a[k];
                a[k]=temp;
            }
            
        }
    }
    for(int i=0;i<m+1;i++){
        if(a[i]>6){
            sum-=a[i]-6;
        }
    }
    printf("%lld\n",sum);
    return 0;
}