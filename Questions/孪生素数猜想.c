#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>//判断素数
int pr(int m){
    int i;
    if(m==1)return 0;
    for(i=2;i<=sqrt(m);i++){
        if(m%i==0)return 0;
    }
    return 1;
}
int main(){
    int a,b,sum=0;
    scanf("%d%d",&a,&b);
    for(int j=a;j<b-2;j++){
        if(pr(j)==1&&pr(j+2)==1){
            printf("%d %d\n",j,j+2);sum++;
        }
    }
    printf("%d\n",sum);

    return 0;
}