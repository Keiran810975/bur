#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char s[200];int n[200];char temp[200]="";
int main(){
    scanf("%s",s);
    int cnt=0;int sum=0;
    for(int i=0;i<=strlen(s);i++){
        if(isdigit(s[i])){
            strncat(temp,&s[i],1);
        }
        else{
            if(strlen(temp)>0){
                n[cnt]=atoi(temp);
                cnt+=1;
                memset(temp,0,sizeof(temp));
            }
        }
    }
    int num=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='C'){
            if(s[i+1]>'9'||s[i+1]<'0')sum+=12;
            else {sum+=n[num]*12;num++;}
        }
        else if(s[i]=='H'){
            if(s[i+1]>'9'||s[i+1]<'0')sum+=1;
            else {sum+=n[num];num++;}
        }
        else if(s[i]=='O'){
            if(s[i+1]>'9'||s[i+1]<'0')sum+=16;
            else {sum+=n[num]*16;num++;}
        }
        else if(s[i]=='N'){
            if(s[i+1]>'9'||s[i+1]<'0')sum+=14;
            else {sum+=n[num]*14;num++;}
        }
    }
    printf("%d",sum);


    return 0;
}