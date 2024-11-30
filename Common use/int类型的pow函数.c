#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int p(int x,int n){
    int sum=1;
    for(int i=0;i<n;i++)sum=sum*x;
    return sum;
}
int main(){
    printf("%d",p(2,11));
    return 0;
}