#include<stdio.h>
#include<math.h>
int main(){
    int y=0;
    unsigned int x;
    int b[32];
    for(int i=0;i<32;i++){
        scanf("%1u",&x);
        y=y|(x<<(31-i));
        b[i]=x;
    }
    int a[32];
    long long int sum=0;
    if(b[0]==0){
        for(int j=0;j<32;j++){
            a[j]=(y>>j)&1;
            sum+=a[j]*(pow(2,j));
        }
        printf("%lld",sum);

    }
    if(b[0]==1){
        y=1+(~y);
        for(int j=0;j<32;j++){
            a[j]=(y>>j)&1;
            sum+=a[j]*(pow(2,j));
        }
        printf("%lld",-sum);
    }

    return 0;
}