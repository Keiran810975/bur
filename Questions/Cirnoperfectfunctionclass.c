#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int ff[100][100][100];
int f(int a,int b,int c){
    if(a<=0||b<=0||c<=0)return 1;
    if(a>25||b>25||c>25)return f(25,25,25);
    if(ff[a][b][c])return ff[a][b][c];
    else if(a<b&&b<c){
        ff[a][b][c]=f(a,b,c-1)+f(a,b-1,c-1)-f(a,b-1,c);
        return ff[a][b][c];
    }
    else ff[a][b][c]=f(a-1,b,c)+f(a-1,b-1,c)+f(a-1,b,c-1)-f(a-1,b-1,c-1);
    return ff[a][b][c];
}
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        printf("%d\n",f(a,b,c));
    }
    return 0;
}