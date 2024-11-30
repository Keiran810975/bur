#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main(){
    int a[10]={3,5,4,1,7,0,8,9,2,6};int min;
    for(int i=0;i<9;i++){
        int temp;
        min=i;
        for(int j=i+1;j<10;j++){
            if(a[min]>a[j])min=j;
        }
        temp=a[min];a[min]=a[i];a[i]=temp;
        
    }
    for(int i=0;i<10;i++)printf("%d ",a[i]);

    return 0;
}