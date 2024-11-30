#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main(){
    int a[10]={3,6,4,1,9,10,7,5,2,8};
    for(int i=1;i<=10-1;i++){
        for(int j=0;j<=9-i;j++){
            int temp;
            if(a[j]>a[j+1]){
                temp=a[j];a[j]=a[j+1];a[j+1]=temp;
            }
        }
    }
    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }

    return 0;
}