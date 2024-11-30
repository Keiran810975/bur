#include<stdio.h>
#include<math.h>
int main(){
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    double d=b*b-4*a*c;
    if(a==0.00){
        if(b==0.00&&c!=0.00)
        printf("No real root");
        if(b==0.00&&c==0.00)
        printf("infinite solutions");
        if(b!=0.00)
        printf("%.2f",-(c/b));
    }

    else{
    if(d<0)
    printf("No real root\n");
    if(d==0)
    printf("%.2f",-(b/2.00/a));
    if(d>0){
        if(a>0)
        printf("%.2f %.2f",(-b-sqrt(d))/2/a,(-b+sqrt(d))/2/a);
        if(a<0)
        printf("%.2f %.2f",(-b+sqrt(d))/2/a,(-b-sqrt(d))/2/a);

    }
    
    }
    return 0;
}