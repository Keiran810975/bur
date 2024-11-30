#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll p,q;
const int mod=998244353;
inline int gint() {
	char ch=getchar();int s=0,f=1;
	while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) {s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
	return s*f;
}
inline ll qp(ll base,ll p) {
	ll res=1;
	while(p) {
		if(p&1) res=res*base%mod;
		base=base*base%mod;p>>=1;
	}
	return res;
}
inline ll Inv(ll base) {return qp(base,mod-2);}
int main() {
	n=gint();p=1ll*gint()*Inv(100)%mod;q=1-p;
	//1/((q-q^n)/(1-q)+q^n+1)
	printf("%lld\n",(Inv(((q-qp(q,n))%mod+mod)%mod*Inv(p)%mod+qp(q,n)+1)%mod+mod)%mod);
	return 0;
}
