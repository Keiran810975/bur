#include<stdio.h>
#include<math.h>
#define eps 1e-9
int equal(double a,double b) {
if(a <= b + eps &&a >= b - eps) return 1;
return 0;
}
int main() {
double a,b,c,d;
scanf("%lf%lf%lf",&a,&b,&c);
if(a < 0) {
a = -a;
b = -b;
c = -c;
}
d = pow(b,2)-4*a*c;
if(equal(a,0.0)) printf("Not a quadratic");
else if(equal(d,0.0)) {
printf("Two equal roots:%10.5lf",(-b)/(2*a));
}
else if(d > 0) {
printf("Two unequal real roots:%.6lf,%.6lf",((-b-sqrt(d))/(2*a)),(-
b+sqrt(d))/(2*a));
}
else printf("Two conjugate complex roots:%.5lf+%.5lfi %.5lf-%.5lfi",(-
b)/(2*a),sqrt(-d)/(2*a),(-b)/(2*a),sqrt(-d)/(2*a));
return 0;
}