#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char s[1001];
int main(){
    scanf("%s",s);
    int len=strlen(s);
    int cnt=0;
    for(int i=0;i<len;i++){
        if(s[i]=='0')cnt++;
        if(cnt==4){
            s[i]='v';cnt=0;
        }
        if(s[i]!='0')cnt=0;
    }
    cnt=0;
    for(int i=0;i<len;i++){
        if(s[i]=='1')cnt++;
        else if(s[i]=='v'){
            if(cnt%2==0)s[i-3]='b';
            cnt=0;
        }
    }
    int ff=1,gg=1;
    for(int i=0;i<len;i++){
        if(s[i]=='1'||s[i]=='b'){
            if(ff==1)printf("+1 ");
            else if(ff==-1)printf("-1 ");
            ff*=-1;
        }
        else if(s[i]=='v'){
            if(gg==1)printf("+1 ");
            else if(gg=-1)printf("-1 ");
            gg*=-1;
        }
        else printf("0 ");
    }

    return 0;
}