#include<stdio.h>
#include<math.h>
int main(){
    unsigned int a,b,c,d,e;
    scanf("%u%u",&a,&b);
    c=a&b;
    d=a^b;
    e=(c<<1)+d;
    int aa[32],bb[32],cc[32],dd[32],ee[32];
    for(int i=0;i<32;i++){
        aa[i]=(a>>i)&1;
        bb[i]=(b>>i)&1;
        cc[i]=(c>>i)&1;
        dd[i]=(d>>i)&1;
        ee[i]=(e>>i)&1;
    }
    for(int k=0;k<32;k++){
        printf("%d",aa[31-k]);
    }
    printf("\n");
    for(int k=0;k<32;k++){
        printf("%d",bb[31-k]);
    }
    printf("\n");
    for(int k=0;k<32;k++){
        printf("%d",cc[31-k]);
    }
    printf("\n");
    for(int k=0;k<32;k++){
        printf("%d",dd[31-k]);
    }
    printf("\n");
    for(int k=0;k<32;k++){
        printf("%d",ee[31-k]);
    }
    printf("\n");
    printf("%u\n",e);
    

    return 0;
} 