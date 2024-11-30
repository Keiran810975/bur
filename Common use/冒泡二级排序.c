#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int tem[2010],num[2010],score[2010];
int check[100000000];
int main()
{
int n=0,j,i;
while(scanf("%d %d",&num[n],&score[n])!=EOF)//先按score降序，再按num升序
{
tem[n]=n;
n++;
}
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(score[tem[i]]<score[tem[j]])
{
tem[i]=tem[i]^tem[j];
tem[j]=tem[i]^tem[j];
tem[i]=tem[i]^tem[j];
}
}
}
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(score[tem[i]]==score[tem[j]]&&num[tem[i]]>num[tem[j]])
{
tem[i]=tem[i]^tem[j];
tem[j]=tem[i]^tem[j];
tem[i]=tem[i]^tem[j];
}
}
}
for(i=0;i<n;i++)
{
if(check[num[tem[i]]]==0)
{
printf("%d %d\n",num[tem[i]],score[tem[i]]);
check[num[tem[i]]]++;
}
}
return 0;
}