#include"bits/stdc++.h"
#define inf 0x7fffffff
#define maxn 5005
using namespace std;
typedef long long ll;
const int mod = 998244353;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int f[maxn], g[maxn];

void solve(){
	int n = read();
	printf("%d\n", f[n]);
}

int main()
{	
	int n = 5000;
	f[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < i; j++){
			g[i] = (g[i] + 1ll * f[j] * f[i - j - 1]) % mod;
		}
		for(int j = 0; j < i; j++){
			f[i] = (f[i] + 1ll * f[j] * g[i - j]) % mod;
		}
	}
	int t = read();
	while(t--){
		solve();
	}
	
}
