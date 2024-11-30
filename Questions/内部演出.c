#include<stdio.h>
#include<math.h>
int x[10001],y[10001];
int gcd(int q,int w){
    int gcd;
    for(gcd=q%w;gcd!=0;gcd=q%w){
        q=w;w=gcd;
    }
    gcd=w;return (gcd);
}
double s(int a,int b,int c,int d,int e,int f){
    double ss=(abs(a-c)*abs(d-b)+abs(e-a)*abs(f-b))/2;
    return (ss);
}
int main(void){
    int n;
    scanf("%d",&n);
    double area=0,sum=n;
    for(int i=0;i<n;i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    for(int i=0;i<n-1;i++){
        int ccc1=abs(x[i+1]-x[i]);
        int ccc2=abs(y[i+1]-y[i]);
        sum+=gcd(ccc1,ccc2);sum--;
    }
    for(int i=1;i<n-2;i++){
        area+=s(x[0],y[0],x[i],y[i],x[i+1],y[i+1]);
    }
    int answer=area-sum/2+1;
    printf("%d\n",answer);
    return 0;
}