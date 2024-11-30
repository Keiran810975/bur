#include <stdio.h>
#define N 5000005

int nextRand() {
    static unsigned int rnd_num = 0x80000001;
    static int mod = 1e5 + 3;

    rnd_num ^= rnd_num >> 10;
    rnd_num ^= rnd_num << 9;
    rnd_num ^= rnd_num >> 25;
    return rnd_num % mod;
}

int a[N];

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        long long bucket[100010]={0};
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            a[i] = nextRand();
            bucket[a[i]]++;
        }
        //把bucket数组的前缀和算出来
        for(int i=1;i<100010;i++){
            bucket[i]+=bucket[i-1];
        } 
        
        long long ans = 0;
        for(int i=1;i<=n;i++){
            ans+=a[i]*(bucket[a[i]-1]+1LL);
        }
        printf("%lld\n", ans);
        
    }
    return 0;
}