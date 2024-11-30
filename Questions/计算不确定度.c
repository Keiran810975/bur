#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
double a[1001];
int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%lf",&a[i]);
    double xa=0;
    for(int i=0;i<n;i++)xa+=a[i];
    xa/=n;
    double u=0;
    for(int i=0;i<n;i++)u+=(a[i]-xa)*(a[i]-xa);
    u=sqrt(u/n/(n-1));
    printf("%.6lf\n%.6lf",xa,u);

    return 0;
}