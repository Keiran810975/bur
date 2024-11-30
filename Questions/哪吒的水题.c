#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
double s(double x);
int main(){
    double a,b,c,d,m,n;scanf("%lf%lf%lf%lf",&a,&b,&c,&d);scanf("%lf%lf",&m,&n);
    double s(double x){
        double y=0;
    y+=m*sqrt(b*b+(a-x)*(a-x));y+=n*sqrt(d*d+(c-x)*(c-x));
    return y;
    }
    double mid1,mid2,eps=1e-10;
    double l=a,r=c;
    mid1 = (2*l+r)/3;
    mid2 = (l+2*r)/3;
    while(r-l>eps) {
        if(s(mid1) > s(mid2)) {
    	l=mid1;
    }
    else {
    	r=mid2;
    }
    mid1 = (2*l+r)/3;
    mid2 = (l+2*r)/3;
    
}
printf("%.3lf %.3lf",mid1,s(mid1));

    return 0;
}