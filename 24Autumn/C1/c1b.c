
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int x[5500];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int r=0,anss=0;
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			if (i == 0) {
				x[1] = a;
				r++;
			}
			else {
				int temp = anss;
				while (x[temp] > a) {
					temp--;
					r++;
				}
				x[temp + 1] = a;
				r += temp;
                r++;
			}
			anss++;
		}
		printf("%d\n", r);
	}
	return 0;
}