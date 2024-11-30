#include<stdio.h>
#include<math.h>
int main(){
    int t;
    long long int x,y;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%lld",&x);
        if((x&1)==1&&(x>>1)&1==0)
        y=3;
        else if((x&1)==1&&(x>>1)&1==1)
        y=1;
        else{
        long long int ccc=x;
        while(ccc%2==0){
            ccc=ccc-ccc/2;
        }
        if(ccc==1)
        y=x+1;
        else{
            int j;
            for(j=0;;j++){
                int n=(x>>j)&1;
                if(n==1);
                break;
            }
            y=pow(2,j);
        }
        }
        printf("%lld",y);

        }
    

    return 0;
}