#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
void ShellSort(int arr[],int n){
    int i,j,inc,key;//初始增量为n/2，之后每次除以二
    for(inc=n/2;inc>0;inc/=2){
        for(i=inc;i<n;i++){
            key=arr[i];
            for(j=i;j>=inc&&key<arr[j-inc];j-=inc){
                arr[j]=arr[j-inc];  
            }
            arr[j]=key;
        }
    }
}
int main(){
    int s[20];
    for(int i=0;i<6;i++)scanf("%d",&s[i]);
    ShellSort(s,6);
    int t=6;
    while(t--)printf("%d ",s[t]);
    return 0;
}