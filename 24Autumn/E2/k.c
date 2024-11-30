#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
#define inf 0x3f3f3f3f
ll dis(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
typedef struct {
    ll x, y, t;
} coin;

ll max(ll a, ll b) {
    return a > b ? a : b;
}
//比较coin->t
int cmp(const void *a, const void *b) {
    return ((coin *)a)->t - ((coin *)b)->t;
}
signed main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        ll n;
        scanf("%lld", &n);
        coin c[n+1];
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld", &c[i].x, &c[i].y, &c[i].t);
        }
        ll f[n+1];
        f[0] = 0;
        ll ans=0;
        c[0].x=c[0].y=c[0].t=0;
        qsort(c+1, n, sizeof(coin), cmp);
        for(int i=1;i<=n;i++){
            f[i]=-inf;
            for(int j=0;j<i;j++){
                if(dis(c[i].x,c[i].y,c[j].x,c[j].y)<=c[i].t-c[j].t){
                    f[i]=max(f[i],f[j]+1);
                }
            }
            ans=max(ans,f[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}