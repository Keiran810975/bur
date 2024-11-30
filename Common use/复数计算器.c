#include<stdio.h>
#include<math.h>
void print(double a,double b) {
if(b >= 0) {
printf("%.2lf+%.2lfi\n",a,b);
}
else{

printf("%.2lf%.2lfi\n",a,b);
}
return;
}
int main() {
double a,b,c,d;
char e;
while(scanf("%lf%lf%lf%lf %c",&a,&b,&c,&d,&e) != EOF) {
if(e == '+') {
print(a+c,b+d);
}
else if(e == '-') {
print(a-c,b-d);
}
else if(e == '*') {
print(a*c-b*d,b*c+a*d);
}
else {
if(c == 0 && d == 0) {
printf("??+??i\n");
}
else print((a*c+b*d)/(pow(c,2)+pow(d,2)),(b*c-
a*d)/(pow(c,2)+pow(d,2)));
}
}
return 0;
}