#include<stdio.h>
int max(int x,int y) {
if(x < y) return y;
return x;
}
int main() {
int T;
scanf("%d",&T);
while (T --) {
int n,ma = -1000000,ans = -1000000;
scanf("%d",&n);
for(int i = 1;i <= n;i ++) {
int t;
scanf("%d",&t);
ans = max(ans,ma - t);
ma = max(ma,t);
}
printf("%d\n",ans);
}
}