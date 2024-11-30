#include<stdio.h>
#include<math.h>
int a[5][100010];
long long Ack(int m,int n) {
if(m == 0) return n+1;;
if(n == 0) return Ack(m-1,1);
return Ack(m-1,Ack(m,n-1));
}
int main(){
int t;
scanf("%d",&t);
while(t --) {
int m,n;
scanf("%d%d",&m,&n);
printf("%lld\n",Ack(m,n));
}
return 0;
}