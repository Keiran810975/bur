#include<stdio.h>
int main() {
int y,m,d,ans = 0;
scanf("%d%d%d",&y,&m,&d);//输入年月日
int a[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
if(y%4==0&&y%100!=0||y%400==0) a[2]++;
for(int i = 1;i<m;i ++) {
ans += a[i];
}
ans += d;
printf("%d",ans);
}