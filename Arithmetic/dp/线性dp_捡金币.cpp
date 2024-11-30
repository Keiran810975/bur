#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	int t,x,y;
}a[10010];
ll n,k,dp[10010];
int main(){
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		ll x,y,z;cin>>x>>y>>z;
		a[i].t=x;a[i].x=y;a[i].y=z;
	}
	for(int i=1;i<=k;i++){
		dp[i]=1;
		for(int j=1;j<i;j++){
			int z=abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y);
			if(a[j].t+z<=a[i].t)dp[i]=max(dp[i],dp[j]+1);
		}
	}
    ll ans=0;
	for(int i=1;i<=k;i++)ans=max(ans,dp[i]);
	cout<<ans;
	return 0;
}