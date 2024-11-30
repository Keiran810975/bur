int a[100010],dif[100010];
void pre()
{
for(int i = 1;i <= n;i++)
dif[i] = a[i] - a[i - 1];
}
void modify(int l,int r,int a)//在区间l,r上加上a
{
a[l] += a,a[r + 1] -= a;
}
void solve()//最终的a数组
{
for(int i = 1;i <= n;i++)
a[i] = a[i - 1] + dif[i];
}