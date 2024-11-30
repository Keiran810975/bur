#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
char a[100],b[100];
int c[100],d[100],e[100];
void rev(char *a){
    int l=strlen(a);
    char *left=a;
    char *right=a-1+l;
    while(left<right){
        char temp=*left;
        *left=*right;
        *right=temp;
        left++;right--;
    }
}
int main(){
    scanf("%s%s",a,b);
    rev(a);rev(b);
    int l1=strlen(a),l2=strlen(b);
    for(int i=0;i<l1;i++)c[i]=a[i]-'0';
    for(int i=0;i<l2;i++)d[i]=b[i]-'0';
    int jw=0;
    for(int i=0;i<100;i++){
        int x=c[i]+d[i];
        if(x>=10){
            e[i]=x%10+jw;
            jw=x/10;
            if(e[i]>=10){
                jw++;
                e[i]=e[i]%10;
            }
        }
        else{
            e[i]=x+jw;
            if(e[i]>=10){
                jw=1;
                e[i]=e[i]%10;
            }
            else{
                jw=0;
            }
        }
    }
    int j;
    for(j=99;j>=0;j--){
        if(e[j]!=0)break;
    }
    for(int i=j;i>=0;i--)printf("%d",e[i]);
    return 0;
}