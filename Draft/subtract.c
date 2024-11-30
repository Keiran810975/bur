#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
char a[100],b[100];
int c[100],d[100],e[100];
int main(){
    scanf("%s%s",a,b);
    int l1=strlen(a),l2=strlen(b);
    int ff;
    if(l1<l2||((strcmp(a,b)<0)&&l1==l2)){
        for(int i=0;i<l1;i++)d[i]=a[l1-i-1]-'0';
        for(int i=0;i<l2;i++)c[i]=b[l2-i-1]-'0';
        ff=1;
    }
    else{
        for(int i=0;i<l1;i++)c[i]=a[l1-i-1]-'0';
        for(int i=0;i<l2;i++)d[i]=b[l2-i-1]-'0';
        ff=0;
    }
    int ll;
    if(l1>l2)ll=l1;
    else ll=l2;
    //for(int i=0;i<ll;i++)printf("%d",c[i]);printf("\n");
    //for(int i=0;i<ll;i++)printf("%d",d[i]);printf("\n");
    for(int i=0;i<ll;i++){
        c[i]=c[i]-d[i];
        if(c[i]<0){
            c[i+1]-=1;
            c[i]+=10;
        }
    }
    //for(int i=0;i<ll;i++)printf("%d",c[i]);printf("\n");
    while(c[ll-1]==0&&ll>1)ll--;
    if(ff==1)printf("-");
    for(int i=0;i<ll;i++)printf("%d",c[ll-1-i]);
    printf("\n");
    return 0;
}