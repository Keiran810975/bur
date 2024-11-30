#include<bits/stdc++.h>
#define Add(x,y) (x+y>=mod)?(x+y-mod):(x+y)
#define lowbit(x) x&(-x)
#define full(l,r,x) for(auto it=l;it!=r;it++) (*it)=x
#define open(s1,s2) freopen(s1,"r",stdin),freopen(s2,"w",stdout);
using namespace std;
typedef long long ll;
typedef double db;
const int N = 1005;
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')
          f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)
	  write(x/10);
	putchar(x%10+'0');
}
char ans[N][N];
void dfs(int n, int x, int y) {
    if (n == 0) {ans[x][y] = '#'; return ;}
    int l = pow(3, n - 1);
    dfs(n - 1, x, y);
    dfs(n - 1, x + l, y);
    dfs(n - 1, x + 2 * l, y);
    dfs(n - 1, x, y + l);
    dfs(n - 1, x + 2 * l, y + l);
    dfs(n - 1, x, y + 2 * l);
    dfs(n - 1, x + l, y + 2 * l);
    dfs(n - 1, x + 2 * l, y + 2 * l);
}
int main() {
    memset(ans, '.', sizeof(ans));
    int n;
    cin >> n;
    dfs(n, 1, 1);
    for (int i = 1; i <= pow(3, n); i ++) {
        for (int j = 1; j <= pow(3, n); j ++)   
            cout << ans[i][j];
        cout << endl;
    }  
    return 0;
}
