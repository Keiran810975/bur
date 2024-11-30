//请通过这道题来感受一下动态规划的基本思想:
//在一场竞赛中有n道题目，每道题都会对应一个分值，你可以选择任意一道题作答，比如你选择了x分的
//题目，那么在作答完毕（假设一定可以得分）后，你将获得x分，但是这场比赛中分值等于x−1和x+1的
//其他题目就会消失，那么这场比赛中你最多可以得到多少分？
//输入第一个数为题目总数n，接下来为n个n个整数a1，a2，a3，表示各个题目的得分。输出你可以得到
//的最高分。
#include<stdio.h>
#include<limits.h>
int max(int a, int b){
return a > b ? a :b;
}
int a[100010],f[100010],b[100010];
int main()
{
int n,i,x=0,ans=0;
scanf("%d",&n);
for(i=1;i<=n;i++)
{
scanf("%d",&a[i]);
b[a[i]]++;
x=max(a[i],x);
}
f[1]=b[1];
for(i=2;i<=x;i++)
{
f[i]=max(f[i-1],f[i-2]+i*b[i]);
}
printf("%d",max(f[x],f[x-1]));
return 0;
}