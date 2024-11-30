#include<stdio.h>
int main(){
    int n,a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        if(100*a+b>=610&&100*a+b<=2220)
        printf("N\n");
        else
        printf("E\n");
    }

    return 0;
}