#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int x;
    for(int j=0;j<n;j++){
        int sum=0;
        for(int i=1;i<=6;i++){
        scanf("%d",&x);
        if(x+sum>=48*i)
        sum=48*i;
        else
        sum+=x;
        }
        if(sum==288)
        printf("Success\n");
        else if(sum<288)
        printf("Failure %d\n",288-sum);
    }

    return 0;
}