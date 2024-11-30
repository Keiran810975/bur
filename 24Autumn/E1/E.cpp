#include<bits/stdc++.h>
using namespace std;
int cnt,tot=10000000,ans,p,n;
inline int Rand() {
	return rand()%100;
}
int main() {
	srand(time(NULL));
	scanf("%d%d",&n,&p);
	for(int i=1;i<=tot;i++) {
		if(cnt==n) ans++,cnt=0;
		else if(Rand()>=p) cnt+=1;
		else ans++,cnt=0;
	}
	printf("%.3lf",1.0*ans/tot);
	return 0;
}
