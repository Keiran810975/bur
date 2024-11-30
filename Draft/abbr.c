#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
char s[300];
char f[300];
int main(){
    gets(s);
    int j=0;
    int l=strlen(s);
    for(int i=0;i<l;i++){
        if(s[i]==' '||s[i]=='\n')f[j++]=s[i];
        else if(s[i]+1!=s[i+1])f[j++]=s[i];
        else{
            f[j++]=s[i];
            if(s[i+1]+1!=s[i+2]){
                f[j++]=s[i+1];
                i++;
                continue;
            }
            else{
                f[j++]='-';
                i++;
                while(s[i]+1==s[i+1])i++;
                f[j++]=s[i];
            }
        }
    }
    printf("%s",f);
    return 0;
}