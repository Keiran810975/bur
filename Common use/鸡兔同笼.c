#include<stdio.h>
int main()
{
int h,f;
scanf("%d%d",&h,&f);//h表示头的数量，f表示腿的数量
printf("%d %d",h - (f-2*h) / 2,(f-2*h) / 2); //输出鸡的数量和兔的数量
return 0;
}