#include<stdio.h>
int main(){
    int a[10]={3,7,5,0,9,6,8,1,2,4};
    for(int i=1;i<10;i++){
        for(int j=i;j>0;j--){
            int temp,k=j;
            if(a[k]<a[k-1]){
                temp=a[k];a[k]=a[k-1];a[k-1]=temp;k--;
            }
            else break;
        }
    }
    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }

    return 0;
}