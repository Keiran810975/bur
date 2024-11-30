#include<stdio.h>
int main(){
    int i,j,k,l,aa,bb,cc,dd;
    scanf("%d%d%d%d",&i,&j,&k,&l);
    for(int a=0;a<5;a++){
        for(int b=0;b<5;b++){
            for(int c=0;c<5;c++){
                for(int d=0;d<5;d++){
                    if(((a+1*c)%5+(b+1*d)%5)%5==i&&
                    ((a+1*c)%5+(4*(b+1*d))%5)%5==j&&
                    ((a+4*c)%5+(2*(b+4*d)))%5==k&&
                    ((a+4*c)%5+(3*(b+4*d)))%5==l){
                        aa=a;
                        bb=b;
                        cc=c;
                        dd=d;
                    }
                }
            }
        }
    }
    printf("%d %d %d %d",aa,bb,cc,dd);

    return 0;
}