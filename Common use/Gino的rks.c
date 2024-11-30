#include<stdio.h>
#include<math.h>
int main(){
    double eps=1e-10;
    float m;
    float a,b,c,d;
    while (scanf("%lf%d%d%d%d", &m, &a, &b, &c, &d) != EOF){
        float acc=(1.00*a+0.65*b)/(a+b+c+d);
        float rks;
        if(acc>0.7-eps)
        rks=(((acc-0.55)/0.45)*((acc-0.55)/0.45))*m;
        if(acc<0.7)
        rks=0;
        printf("%.2f%c %.4f",100*a,'%',rks);


    }

    return 0;
}