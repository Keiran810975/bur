#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int nextRand() {
    static unsigned int rnd_num = 0x80000001;
    static int mod = 1e5 + 3;

    rnd_num ^= rnd_num >> 10;
    rnd_num ^= rnd_num << 9;
    rnd_num ^= rnd_num >> 25;
    return rnd_num % mod;
}

const int N = 5e6 + 5;
int n,a[N];
ll b[100010];
int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
		memset(b,0,sizeof b);
        for (int i = 1; i <= n; i++) {
            a[i]=nextRand();
            b[a[i]]++;
		}
		ll ans=0;ll sum=b[0];
		for(int i=1;i<=100003;i++) {
			ans+=1ll*(sum+1)*i*b[i];
			sum+=b[i];
		}
		printf("%lld\n",ans);
    }
    return 0;
}
