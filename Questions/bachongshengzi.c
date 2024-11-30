#include<stdio.h>
int main(){
    int a,b,c,d,e,f,num=0;
    scanf("%d%d",&a,&b);
    scanf("%d%d",&c,&d);
    scanf("%d%d",&e,&f);
    for(int i=0;;i++){
        
        if(i%a==b&&i%c==d&&i%e==f){
            break;
        }
        num+=1;
    }
    printf("%d",num);

    return 0;
}