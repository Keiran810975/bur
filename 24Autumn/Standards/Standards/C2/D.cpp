#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=4010;
int T,n;
int a[maxn],b[maxn];
ll c[maxn];
inline int gint() {
	char ch=getchar();int s=0,f=1;
	while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) {s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
	return s*f;
}
char s[maxn];
int main() {
	T=gint();
	while(T--) {
		scanf("%s",s);int n=strlen(s);
		for(int i=0;i<n;i++) {
			a[i]=s[i]-'0';
		}
		for(int i=n;i<=4001;i++) a[i]=0;
		scanf("%s",s);int m=strlen(s);
		for(int i=0;i<m;i++) {
			b[i]=s[i]-'0';
		}
		for(int i=0;i<n/2;i++) swap(a[i],a[n-i-1]);
		for(int i=0;i<m/2;i++) swap(b[i],b[m-i-1]);
		for(int i=m;i<=4001;i++) b[i]=0;
		for(int i=0;i<=4001;i++) c[i]=0;
		for(int k=0;k<=n+m;k++) {
			for(int i=0;i<=k;i++) {
				c[k]+=a[i]*b[k-i];
			}
		}
		for(int i=0;i<=n+m;i++) {
			c[i+1]+=c[i]/10;
			c[i]%=10;
		}
		bool flag=0;
		for(int i=4001;~i;i--) {
			if(c[i]!=0) {
				flag=1;
				for(int j=i;~j;j--) printf("%lld",c[j]);
				break;
			}
		}
		if(!flag) printf("0");
		puts("");
	}
	return 0;
}
