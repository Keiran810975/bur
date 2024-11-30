#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int num[100];
void swap(int a[],int p,int q){
    int temp=a[q];
    a[q]=a[p];
    a[p]=temp;
}
void printArr(int a[],int n){
    for(int i=0;i<n;i++)printf("%d ",a[i]);
    printf("\n");
}
void permutation(int a[],int p,int q){
    if(p==q)printArr(a,q+1);
    else{
        for(int i=p;i<=q;i++){
            swap(a,p,i);
            permutation(a,p+1,q);
            swap(a,p,i);
        }
    }
}
int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)num[i]=i+1;
    permutation(num,0,n-1);
    return 0;
}