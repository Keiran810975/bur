#include<stdio.h>
#include<math.h>
int main(){
    int t;
    scanf("%d",&t);
    int n;
    double a,b;
    
    for(int i=0;i<t;i++){
        double sum1=0,sum2=0;
        scanf("%d",&n);
        for(double j=0;j<n;j++){

            sum1+=(pow(-1,j))/(2*j+1);
            sum2+=1/((2*j)+1)/((2*j)+1);
        }
        b=sqrt(8*sum2);
        a=4*sum1;
        double x=a-b; 
        printf("%.6lf\n",fabs(x));
    }


    return 0;
}