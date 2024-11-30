#include"bits/stdc++.h"
#define maxn 205
typedef long long ll;
// const ll mod = 1e9 + 7;
using namespace std;

inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0') {if(ch == '-') f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x *10 + ch -'0';ch = getchar();}
	return x * f;
}

ll qpow(ll a, ll b){
	ll ans = 1, base = a;
	while(b){
		if(b & 1) ans = ans * base;
		base = base * base;
		b >>= 1;
	}
	return ans;
}

struct matrix{
	int n,m;
	long long mp[maxn][maxn];
	matrix() : n(), m(), mp(){}
	friend matrix operator * (matrix a, matrix b){
		matrix c;
		for(int i = 1; i <= a.n; i++){
			for(int j = 1; j <= b.m; j++){
				for(int k = 1; k <= a.m; k++){
					c.mp[i][j] = c.mp[i][j] + 1LL * a.mp[i][k] * b.mp[k][j];
				}
			}
		}
		return c;
	}
}A, B;

void solve(){
	int n = read();
	A.n = A.m = B.n = B.m = n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++){
			A.mp[i][j] = read();
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++){
			B.mp[i][j] = read();
		}
	}
	matrix c = A * B;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%lld%c", c.mp[i][j], j == n ? '\n' : ' ');
		}
	}
}

int main(){
	int T = read();
	while(T--){
		solve();
	}
	return 0;
}
