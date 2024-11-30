#include<stdio.h>
#include<math.h>
long long b[1000010];
int a[1000010];
int main() {
int m,n;
scanf("%d%d",&m,&n);
for(int i = 1;i <= n;i ++) {
scanf("%d",&a[i]);
b[i] = b[i-1] + a[i];
}
for(int i = 0;i < m;i ++) {
int l,r;
scanf("%d%d",&l,&r);
printf("%lld\n",(b[r]-b[l-1])/(r-l+1));
}
return 0;
}