#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void tri(int i,int a,int b,int c){
    printf("Question %d:\n",i);
    if(a+b<=c||b+c<=a||a+c<=b)printf("no triangle\n");
    else{
        if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)printf("right triangle\n");
        if(a*a+b*b>c*c&&a*a+c*c>b*b&&b*b+c*c>a*a)printf("acute triangle\n");
        if(a*a+b*b<c*c||a*a+c*c<b*b||b*b+c*c<a*a)printf("obtuse triangle\n");
        if(a==b||b==c||a==c){
            if(a==b&&b==c&&a==c)printf("equilateral triangle\n");
            else printf("isosceles triangle\n");
        }
    }
}
int main(){
    int a,b,c,d,e,f,g,h,i,j;
    scanf("%d%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j); 
    tri(1,a,e,i);
    tri(2,b,g,j);
    tri(3,b,c,f);
    tri(4,h,i,j);
    tri(5,f,g,j);
    tri(6,c,d,h);
    tri(7,a,b,f);

    return 0;
}