int a[100010],pre[100010];
void pre()
{
for(int i = 1;i <= n;i++)
pre[i] = pre[i - 1] + a[i];
}
int query(int l,int r)//计算l到r区间和
{
return pre[r] - pre[l - 1];
}