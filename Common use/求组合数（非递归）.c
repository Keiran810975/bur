#include <stdio.h>
int comb_num(int, int);
int main()
{
int m, n, comb;
scanf("%d%d", &m, &n);
comb = comb_num(m, n);
printf("%d\n", comb);
return 0;
}
int comb_num(int m, int n)
{
if (n == 0 || m == n)
return 1;
if ( m < n )
return 0;
if ( n == 1 )
return m;
return comb_num(m-1, n) + comb_num(m-1, n-1);
}