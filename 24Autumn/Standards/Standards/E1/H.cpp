#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int T,n,k,cnt,a[maxn],b[maxn];
inline int gint() {
	char ch=getchar();int s=0,f=1;
	while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) {s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
	return s*f;
}
int main() {
	T=gint();
	while(T--) {
		n=gint();k=gint();
		int cnt=0,p=0,l=0,r=n+1;
		for(int i=1;i<=k;i++) b[i]=0;
		for(int i=1;i<=n;i++) a[i]=gint();
		for(int i=1;i<=n;i++) {
			while(p<n&&cnt!=k) {
				p++;
				if(++b[a[p]]==1) cnt++;
			}
			if(cnt==k&&p-i<r-l) {
				r=p;
				l=i;
			}
			if(--b[a[i]]==0) cnt--;
		}
		if(r-l>=n) puts("N0");
		else printf("%d %d\n",l,r);
	}
	return 0;
}
