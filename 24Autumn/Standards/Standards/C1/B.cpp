#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+10;
int T,n,a[maxn];
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);int ans=0;
		for(int i=1,x;i<=n;i++) {
			scanf("%d",&x);
			int p=1;
			while(p<i&&a[p]<=x) p++;
			for(int j=i;j>p;j--) a[j]=a[j-1],ans++;
			a[p]=x;
			ans+=p;
		}
//		printf("%d\n",n*(n+1)/2);
		printf("%d\n",ans);
	}
	return 0;
}
