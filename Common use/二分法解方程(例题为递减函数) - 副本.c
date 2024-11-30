#include<stdio.h>
#include<math.h>
double f(double x) {
return exp(-sqrt( x/10 ))/log(x/10);//函数方程
}
double Sol(double val,double u,double v) {
double mid = (u + v)/2;
if(v - u <= 0.000005) return mid;
if(f(mid) < val) return Sol(val,u,mid);
if(f(mid) > val) return Sol(val,mid,v);
return mid;
}
int main() {
double y;
scanf("%lf",&y);
printf("%.5lf",Sol(y,10,30));
return 0;
}
/*
如果没有确定边界，则需要先找到初始边界
求区间内元素平均值（前缀和)
冒泡二级排序
while(f(left)*f(right)>=0)
{
if(f(left)==0)
{
printf("%.5f",left);
return 0;
}
else if(f(right)==0)
{
printf("%.5f",right);
return 0;
}
left*=2;
right*=2;
}