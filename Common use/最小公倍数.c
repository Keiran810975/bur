#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main(){
    int lcm(int a,int b){
        int gcd;int lcm=a*b;
        while((gcd=a%b)!=0){
            a=b;b=gcd;
        }
        gcd=b;
        lcm=lcm/gcd;
        return (lcm);
    }

    return 0;
}