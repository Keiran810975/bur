#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
long long aa[500];
long long sum(int a,int b,int c,int l){
    if(!l)return 1;
    if(l<0)return 0;
    if(aa[l]!=-1)return aa[l];
    aa[l]= sum(a,b,c,l-a)+sum(a,b,c,l-b)+sum(a,b,c,l-c);
    return aa[l];
}
int main(){
    int a,b,c,l;
    while(~scanf("%d%d%d%d",&a,&b,&c,&l)){
        for(int i=0;i<500;i++)aa[i]=-1;
        printf("%lld\n",sum(a,b,c,l));
    }
    return 0;
}

#include <stdio.h>
int f[30][30][30];
int B(int a, int b, int c)
{
if (a <= 0 || b <= 0 || c <= 0)
return 1;
else if (a > 25 || b > 25 || c > 25)
return B(25, 25, 25);
else
{
if (f[a][b][c])
return f[a][b][c];
else if (a < b && b < c)
f[a][b][c] = B(a, b, c - 1) + B(a, b - 1, c - 1) - B(a, b - 1, c);
else
f[a][b][c] = B(a - 1, b, c) + B(a - 1, b - 1, c) + B(a - 1, b, c - 1)
- B(a - 1, b - 1, c - 1);
}
return f[a][b][c];
}
int main()
{
int T, a, b, c;
scanf("%d", &T);
while (T--)
{
scanf("%d%d%d", &a, &b, &c);
printf("%d\n", B(a, b, c));
}
return 0;
}