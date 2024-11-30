//输入t，a，b，求a/b。当t=1，向下取整。当t=2，向上取整。
#include<stdio.h>
#include<math.h>
int main() {
int t;
double a,b;
scanf("%d %lf %lf",&t,&a,&b);
if(t==1)
printf("%d",(int)floor(a/b));
else
printf("%d",(int)ceil(a/b));
return 0;
}