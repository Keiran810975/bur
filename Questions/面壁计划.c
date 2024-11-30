#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char s[1000];
char aaa[2000];
char temp[1000];
char bbb[1000];
int main(){
    scanf("%s",s);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<strlen(s);j++){
            temp[j]=s[strlen(s)-j-1];
        }
        for(int j=0;j<strlen(s);j++){
            aaa[j]=s[j];
        }
        for(int j=strlen(s);j<=2*strlen(s);j++){
            aaa[j]=temp[j-strlen(s)];
        }
        int flag=0;
        for(int i=0;i<strlen(s);i++){
            if(aaa[2*i]<aaa[2*i+1]){
                flag=1;break;
            }
            if(aaa[2*i]>aaa[2*i+1]){
                flag=2;break;
            }
        }
        if(flag==1)for(int i=0;i<strlen(s);i++)s[i]=aaa[2*i];
        else if(flag==2) for(int i=0;i<strlen(s);i++)s[i]=aaa[2*i+1];
    }
    printf("%s",s);
    return 0;
}