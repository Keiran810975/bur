#include"bits/stdc++.h"
#define maxn 205
typedef long long ll;
const ll mod = 1e9 + 7;
using namespace std;

inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0') {if(ch == '-') f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x *10 + ch -'0';ch = getchar();}
	return x * f;
}

struct matrix{
	int n,m;
	int mp[maxn][maxn];
	matrix() : n(), m(), mp(){}
	friend matrix operator * (matrix a, matrix b){
		matrix c;
		c.n = a.n, c.m = b.m;
		for(int i = 1; i <= a.n; i++){
			for(int j = 1; j <= b.m; j++){
				for(int k = 1; k <= a.m; k++){
					c.mp[i][j] = (c.mp[i][j] + 1LL * a.mp[i][k] * b.mp[k][j] % mod) % mod;
				}
			}
		}
		return c;
	}
}A, B, one;

matrix qpow(matrix a, int b){
	matrix ans = one, base = a;
	while(b){
		if(b & 1) ans = ans * base;
		base = base * base;
		b >>= 1;
	}
	return ans;
}

void solve(){
	int n = read(), m = read();
	A.n = A.m = B.n = B.m = n;
	one.n = one.m = n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++){
			one.mp[i][j] = i == j;
		}
	}
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
	A = A * B;
	matrix c = qpow(A, m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d%c", c.mp[i][j], j == n ? '\n' : ' ');
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
