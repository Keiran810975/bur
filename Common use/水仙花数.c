//输入一个范围[l,r]，输出范围内所有水仙花数，若没有，则输出no
#include <stdio.h>
int main()
{
int start, end, i = 0, a, b, c, size = 0;
while (scanf("%d %d", &start, &end) == 2)
{
for (i = start; i <= end; i++)
{
a = i / 100;
b = i / 10 % 10;
c = i % 10;
//total = pow(c, 3) + pow(a, 3) + pow(b, 3);
if ((a*a*a + b*b*b + c*c*c) == i) //满足水仙花条件
{
if (size == 0) //size=0输出第一个水仙花数
{
printf("%d", i);
}
else //size++输出第二。。第n个水仙花数
{
printf(" %d", i);
}
size++; //个数++；
}
}
if (size == 0) //范围内个数为0，则说明没有满足条件的
{
printf("no");
}
printf("\n");
}
return 0;
}