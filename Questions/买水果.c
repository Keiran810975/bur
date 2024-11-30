#include<stdio.h>
int main(){
    int n,x,a,b,c=0,d=0,u,v;//x余额  a，b水果店苹果香蕉数量；c，d手里的苹果，香蕉；
    scanf("%d%d%d%d",&n,&x,&a,&b);
    for(int i=0;i<n;i++){
        scanf("%d%d",&u,&v);
        if(v==0){
            if(u==0){
                if(x>=3&&a>=1){
                    printf("Ok!\n");
                    x-=3;
                    a-=1;
                    c+=1;
                }
                else
                printf("Failed!\n");
            }
            if(u==1){
                if(c>=1){
                    printf("Ok!\n");
                    c-=1;
                }
                else
                printf("Failed!\n");
            }
        }
        if(v==1){
            if(u==0){
                if(x>=2&&b>=1){
                    printf("Ok!\n");
                    x-=2;
                    b-=1;
                    d+=1;
                }
                else
                printf("Failed!\n");
            }
            if(u==1){
                if(d>=1){
                    printf("Ok!\n");
                    d-=1;
                }
                else
                printf("Failed!\n");
            }
        }

    }
    printf("%d %d %d",a,b,x);

    return 0;
}