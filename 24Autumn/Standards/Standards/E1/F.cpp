#include<bits/stdc++.h>
using namespace std;
const int N = 2e3+10;
const int p = 1e9+7;
#define ll long long
ll c[N][N];
ll pw[N];
int n,m,k;
void init(){	
    pw[0]=1;
	for(int i=0;i<N;i++){
        if(i)pw[i]=pw[i-1]*2%p;
        for(int j=0;j<=i;j++){
            if(j==0)c[i][j]=1;
			else c[i][j]=(c[i-1][j]+c[i-1][j-1])%p;
        }		
    }
}
int main(){
    init();
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        if(m<2*k||m-2*k>n-k){
            cout<<"0\n";
            continue;
        }
        ll ans=c[n][k]*c[n-k][m-2*k]%p;
        ans=ans*pw[m-2*k]%p;
        cout<<ans<<"\n";
    }
}
