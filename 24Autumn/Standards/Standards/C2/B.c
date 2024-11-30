#include <stdio.h>

typedef long long ll;

int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		
		ll a, m1, m2;
		m1 = m2 = 0;
		int i;
		for (i = 0; i < n; ++i) {
			scanf("%lld", &a);
			if (a >= m1) {
				m2 = m1;
				m1 = a;
			} else if (a >= m2) {
				m2 = a;
			}
		}
		printf("%lld\n", m1 + m2);
	}
	return 0;
}
