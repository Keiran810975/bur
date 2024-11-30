#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int min=a<b ? (a<c ? a:c):(b<c ? b:c);
    printf("阿三大苏打实打实大苏打%d\n",min);
    return 0;
}