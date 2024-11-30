#define _CRT_SECURE_NO_WARNINGS 1;
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
long long x, y;
int a[1010], b[1010];

int main()
{
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i <= m; i++) {
		scanf("%d", &b[i]);
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		scanf("%lld%lld", &x, &y);
		long long xx = 1, yy = 1;
		long long resx = 0, resy = 0;
		for (int i = 0; i <= n; i++) {
			resx = (resx + a[i] * xx+10007)%10007;
			xx = (xx*x)%10007;
		}
		for (int i = 0; i <= m; i++) {
			resy = (resy+b[i] * yy+10007)%10007;
			yy = (yy* y)%10007;
		}
		printf("%lld\n", (((resx) % 10007) * ((resy) % 10007)) % 10007);
	}
	return 0;
}