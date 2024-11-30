#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
char s[100];
char sec[100];
char ch;
void f(){
    int cnt[30]={0};
    int l=strlen(s);
    int j=0;
    for(int i=0;i<=l;){
        if(cnt[s[i]-'a']==0){
            sec[j]=s[i];j++;
            cnt[s[i]-'a']++;
        }
        else{
            i++;
        }
    }
    int k=0;
    for(int i=j-1;i<26;){
        //printf("%d ",cnt['z'-'a'-k]);
        if(cnt['z'-'a'-k]==0){
            sec[i]='z'-k;
            i++;
        }
        k++;
    }
    //for(int i=0;i<26;i++)printf("%d ",cnt[s[i]-'a']);
    //printf("%d\n",'z'-'a'-k);
    printf("%s",sec);
}
void ominous(){
    FILE* op=fopen("encrypt.txt","r");
    FILE *ou=fopen("output.txt","w");
    if(NULL==op||NULL==ou)printf("fail\n");
    while((ch=fgetc(op))!=EOF){
        char sss='a';
        int i;
        for(i=0;i<26;i++){
            if(ch!=sss)sss+=1;
            else{
                fputc(sec[sss-'a'],ou);
                break;
            }
        }
        if(i==26)fputc(ch,ou);
    }
    fclose(op);
    fclose(ou);
    op=NULL;
    ou=NULL;
}
int main(){
    scanf("%s",s);
    f();
    ominous();
    return 0;
}