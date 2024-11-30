#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
long long a[1001][1001];
int main(){
    int m,n;scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++){for(int j=0;j<n;j++){scanf("%lld",&a[i][j]);}}
    long long v=0,ii=0,o=0,l=0,e=0,t=0;
    for(int i=0;i<m-2;i++){
        for(int j=0;j<n-2;j++){
            if(a[i][j]+a[i][j+2]+a[i+1][j]+a[i+1][j+2]+a[i+2][j+1]>v)
            v=a[i][j]+a[i][j+2]+a[i+1][j]+a[i+1][j+2]+a[i+2][j+1];
            
            if(a[i][j+1]+a[i+1][j+1]+a[i+2][j+1]>ii)
            ii=a[i][j+1]+a[i+1][j+1]+a[i+2][j+1];
            
            if(a[i][j]+a[i][j+1]+a[i][j+1]+a[i+1][j]+a[i+1][j+2]+a[i+2][j]+a[i+2][j+1]+a[i+2][j+2]>o)
            o=a[i][j]+a[i][j+1]+a[i][j+1]+a[i+1][j]+a[i+1][j+2]+a[i+2][j]+a[i+2][j+1]+a[i+2][j+2];
            
            if(a[i][j]+a[i+1][j]+a[i+2][j]+a[i+2][j+1]+a[i+2][j+2]>l)
            l=a[i][j]+a[i+1][j]+a[i+2][j]+a[i+2][j+1]+a[i+2][j+2];
            
            if(a[i][j]+a[i][j+1]+a[i][j+1]+a[i+1][j]+a[i+1][j+1]+a[i+1][j+2]+a[i+2][j]+a[i+2][j+1]+a[i+2][j+2]>e)
            e=a[i][j]+a[i][j+1]+a[i][j+1]+a[i+1][j]+a[i+1][j+1]+a[i+1][j+2]+a[i+2][j]+a[i+2][j+1]+a[i+2][j+2];
            
            if(a[i][j]+a[i][j+2]+a[i][j+2]+a[i+1][j+1]+a[i+2][j+1]>t)
            t=a[i][j]+a[i][j+2]+a[i][j+2]+a[i+1][j+1]+a[i+2][j+1];
        }
    }
    //printf("%d %d %d %d %d %d ",v,ii,o,l,e,t);
    long long max=0;if(v>max)max=v;
    if(ii>max)max=ii;
    if(o>max)max=o;
    if(l>max)max=l;
    if(e>max)max=e;
    if(t>max)max=t;
    printf("%lld\n",max);
    if(max==v)printf("V");
    if(max==ii)printf("I");
    if(max==o)printf("O");
    if(max==l)printf("L");
    if(max==e)printf("E");
    if(max==t)printf("T");
    return 0;
}