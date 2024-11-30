#include <stdio.h>
int a[100];
int main()
{
int n,flag,l,r,mid,i,x;
scanf("%d",&n);//数组大小n
for(i=0;i<n;i++)
scanf("%d",&a[i]); //数组a[n]
while(~scanf("%d",&x)) //查找x，属于数组输出yes，否则输出no
{
flag=0;
l=0;
r=n-1;
while(l<=r)
{
mid=(l+r)/2;
if(a[mid]==x)
{
flag=1;
break;
}
else if(a[mid]<x)
l=mid+1;
else
r=mid-1;
}
if(flag==0)
printf("no\n");
else
printf("yes\n");
}
return 0;
}