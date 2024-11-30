#include<stdio.h>
int main(){
    int n,num1=0,sum1,num2=0,sum2;
    scanf("%d",&n);
    int arr1[n];
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        arr1[i]=x;

    }
    int arr2[n];
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        arr2[i]=x;
    }
    if(arr1[0]==10)
    num1+=1;
    if(num1>=1)
    sum1=arr1[0]+2*arr1[1];
    else
    sum1=arr1[0]+arr1[1];
    if(arr1[1]==10)
    num1+=1;
    for(int j=2;j<n;j++){
        if(num1>=1)
        sum1+=2*arr1[j];
        else
        sum1+=arr1[j];
    }
        
    if(arr2[0]==10)
    num2+=1;
    if(num2>=1)
    sum2=arr2[0]+2*arr2[1];
    else
    sum2=arr2[0]+arr2[1];
    if(arr2[1]==10)
    num2+=1;
    for(int j=2;j<n;j++){
        if(num2>=1)
        sum2+=2*arr2[j];
        else
        sum2+=arr2[j];
    }
    printf("%d %d\n",sum1,sum2);
    if(sum1>sum2)
    printf("violet\n");
    if(sum1<sum2)
    printf("Lilsio\n");
    else
    printf("Let's play again!\n");

    return 0;
}