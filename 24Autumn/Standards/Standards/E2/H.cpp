#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int T,n,m,f[maxn][20],g[maxn];
char a[maxn],b[20]="a1145141919810";
int main() {
	scanf("%d",&T);m=strlen(b+1);
	while(T--) {
		scanf("%s",a+1);n=strlen(a+1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m&&i+j-1<=n;j++)
				f[i][j]=f[i][j-1]+(a[i+j-1]==b[j]);
		for(int i=1;i<=n;i++) g[i]=0;
		int ans=0;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m&&j<=i;j++)
				g[i]=max(g[i],g[i-j]+f[i-j+1][j]);
			ans=max(ans,g[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}