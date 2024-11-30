#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
void CountingSort(int arr[],int n){
    if(n<2)return;
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max)max=arr[i];
    }
    int *count=(int *)malloc(sizeof(int) * (max+1));
    memset(count,0,sizeof(int)*(max+1));
    for(int i=0;i<n;i++)count[arr[i]]++;
    for(int i=1;i<max+1;i++)count[i]+=count[i-1];
    int *output=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    for(int i=0;i<n;i++)arr[i]=output[i];
}
int main(){
    int s[20];
    for(int i=0;i<6;i++)scanf("%d",&s[i]);
    CountingSort(s,6);
    int t=6;
    while(t--)printf("%d ",s[t]);
    return 0;
}