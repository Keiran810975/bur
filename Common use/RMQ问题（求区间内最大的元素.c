//给定长度为N的序列，M个询问，每次询问两个数字A,B，要求求出属于A到B这段区间内的最大数。
#include<stdio.h>
#define max(a,b) a>b?a:b
int a[200010];
int dp[200010][32];
int RMQ(int l,int r)
{
int k=0;
while(1<<(k+1)<=r-l+1)
k++;
return max(dp[l][k],dp[r-(1<<k)+1][k]);
}
int main()
{
int n,m,l,r,i,j;
scanf("%d",&n);
for(i=1;i<=n;i++)
scanf("%d",&a[i]);
for(i=1;i<=n;i++)
dp[i][0]=a[i];
for(j=1;(1<<j)<=n;j++)
for(i=1;i+(1<<j)-1<=n;i++)
dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
scanf("%d",&m);
for(i=0;i<m;i++)
{
scanf("%d %d",&l,&r);
printf("%d\n",RMQ(l,r));
}
return 0;
}