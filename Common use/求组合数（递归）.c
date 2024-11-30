#include<stdio.h>
long long T[15];
long long comb_num(int, int);
int main()
{
int m, n, comb, i;
T[1] = 1;
for(i=2; i<=15; i++)
T[i] = i*T[i-1]; // 存储 n!
printf("input m, n (m>=n): ");
scanf("%d%d", &m, &n);
printf("%lld\n", comb_num(m, n));
return 0;
}
long long comb_num(int m, int n)
{
if ( m < n )
return 0;
if ( 1 == n )
return m;
if ( n == m || 0 == n)
return 1;
return T[m]/(T[n]*T[m-n]); // 打表法
}