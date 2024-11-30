#include<stdio.h>
int main(){
    unsigned int n;
    int a[32];
    while(scanf("%u",&n)!=EOF){
        if(n>=0){
            for(int i=0;i<32;i++){
                a[i]=(n>>i)&1;
            }
        }
        else{
            n=(~n)+1;
            for(int i=0;i<32;i++){
                a[i]=(n>>1)&1;
            }
        }
        for(int k=0;k<32;k++){
            printf("%d",a[31-k]);
        }
        printf("\n");


    }
    return 0;
}