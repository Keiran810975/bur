#include<stdio.h>
int ccc[101];
int main(){

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        ccc[i]=x;
    }
    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            int temp,k=j;
            if(ccc[k]<ccc[k-1]){
                temp=ccc[k];ccc[k]=ccc[k-1];ccc[k-1]=temp;k--;
            }
            else break;
        }
    }
        int a;
    while(scanf("%d",&a)!=EOF){
        int flag=0;
        for(int i=0;i<n;i++){
            if(a==ccc[i]){
                printf("%d\n",i+1);flag=1;break;
            }  
        }
        if(flag==0)printf("-1\n");
    }

    return 0;
}