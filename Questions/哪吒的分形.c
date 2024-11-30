#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
void fri(int a,int b,int c){
    if(a==1)printf("1");

    else{
        if((b<=3*(1<<(a-2))-1)&&(b>(1<<(a-2))-1)&&(c<=3*(1<<(a-2))-1)&&(c>(1<<(a-2))-1))printf(" ");
        else fri(a-1,b%(1<<(a-1)),c%(1<<(a-1)));
        return;
    }
}
int main(){
    int a;scanf("%d",&a);
    int b,c;
    for(int b=0;b<(1<<(a+1));b++){
        for(int c=0;c<(1<<(a+1));c++){
            fri(a+1,b,c);
        }
        printf("\n");
    }
    return 0;
}