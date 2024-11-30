#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10,INF=1e9;
int T,n,top,a[maxn],s[maxn],l[maxn],r[maxn];
inline int gint() {
	char ch=getchar();int s=0,f=1;
	while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) {s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
	return s*f;
}
int main() {
	T=gint();
	while(T--) {
		n=gint();
		for(int i=1;i<=n;i++) a[i]=gint();
		top=0;s[++top]=0;
		a[0]=INF+1;
		for(int i=1;i<=n;i++) {
			while(top&&a[s[top]]<=a[i]) top--;
			l[i]=s[top];
			s[++top]=i;
		}
		top=0;s[++top]=n+1;
		a[n+1]=INF+1;
		for(int i=n;i;i--) {
			while(top&&a[s[top]]<=a[i]) top--;
			r[i]=s[top];
			s[++top]=i;
		}
		ll ans=0;
		for(int i=1;i<=n;i++) ans+=r[i]-l[i]-2;
		printf("%lld\n",ans);
	}
	return 0;
}
