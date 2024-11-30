#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
double f(double w){
    return (w*exp(w));
}
int main(){
    double x;scanf("%lf",&x);
    double mid,eps=1e-8,l=-1.0,r=10.0;
    mid=(l+r)/2;
    while(r-l>eps){
        if(f(mid)>x)r=mid;
        else l=mid;
        mid=(l+r)/2;
    }
    printf("%.6lf\n",mid);

    return 0;
}