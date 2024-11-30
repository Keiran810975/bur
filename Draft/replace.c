#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
char a[10000];char b[10000];
char ch[10000];
char temp[10000];
void replace(){
    scanf("%s%s",a,b);
    FILE* op=fopen("filein.txt","r");
    FILE *ou=fopen("fileout.txt","w");
    while((fgets(ch,10000,op))!=NULL){
        int l=strlen(ch);
        int ll=strlen(a);
        for(int i=0;i<l;i++){
            int cnt=0;
            int k=0;
            for(int j=i;j<i+ll;j++){
                if(tolower(ch[j])==tolower(a[k])){
                    cnt++;
                    k++;
                }
                else{
                    break;
                }
            }
            if(cnt==ll){
                    strcpy(temp,ch+i+ll);
                    ch[i]='\0';
                    strcat(ch,b);
                    strcat(ch,temp);
                }
            cnt=0;k=0;
        }
        fputs(ch,ou);
    }
}
int main(){
    replace();

    return 0;
}