#include<bits/stdc++.h>
using namespace std;
int x;
inline void calc(int x) {
	if(x==1) {cout<<1<<" ";return ;}
	if((x+1)%4==0) calc((x-1)>>1);
	else calc((x+1)>>1);
	cout<<x<<" ";
}
int main() {
	cin>>x;	
	if(x&1) calc(x);
	else cout<<"-1";
	return 0;
}

