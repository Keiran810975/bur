#include<stdio.h>
int main(){
    int arr[8],z,gcd;
    for(int i=1;i<8;i++){
          scanf("%d",&z);
          arr[i]=z;
          }
    int max=arr[1];
    for(int j=0;j<8;j++){
        if(arr[j]>max){
            max=arr[j];
        }
    }
    gcd=max;
    while(!(arr[8]%gcd==0&&arr[1]%gcd==0&&arr[2]%gcd==0&&arr[3]%gcd==0&&arr[4]%gcd==0&&arr[5]%gcd==0&&arr[6]%gcd==0&&arr[7]%gcd==0)){
        gcd-=1;
    }
    int sum=0;
    for(int k=1;k<8;k++){
        sum=sum+arr[k]/gcd;
    }
    printf("%d",sum);




    return 0;
}