#include<stdio.h>
#include<complex.h>
int main() {
int T;
scanf("%d",&T);
while(T --) {
int x,y,ans1=0,ans2=0;
scanf("%d%d",&x,&y);
while(x != 0) {
ans1 ++;
x = (x-1)&x;
}
while(y != 0) {
ans2 ++;
y = (y-1)&y;
}
if(ans1==ans2) printf("branch\n");
else printf("in-order\n");
}
}