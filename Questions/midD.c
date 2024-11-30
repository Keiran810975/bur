#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
    unsigned int x,y,z;
    while((scanf("%u%u%u",&x,&y,&z))!=EOF){
        unsigned int a=x^y,b=x^z,c=y^z;
        int m=0,n=0,p=0;
        for(int i=0;i<32;i++){
            if(((1<<i)&a)==(1<<i))m+=1;
            if(((1<<i)&b)==(1<<i))n+=1;
            if(((1<<i)&c)==(1<<i))p+=1;
        }
        int max;
        max=(m>n)?(m):(n);
        if(p>max)max=p;
        printf("%d\n",max);

    }
    return 0;
}