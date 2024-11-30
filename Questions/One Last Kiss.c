#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char s[11000];
int main(){
    while(scanf("%s",s)!=EOF){
        for(int i=0;i<strlen(s);i++){
            if(s[i]>='A'&&s[i]<='Z')s[i]-=('A'-'a');
        }
        int cnt=0;int max;
        for(int i=0;i<=strlen(s)-4;i++){
            if(s[i]=='k'&&s[i+1]=='i'&&s[i+2]=='s'&&s[i+3]=='s'){
                max=i;
                cnt++;
            }
        }
        printf("%d ",cnt);
        if(cnt==0)printf("-1\n");
        else printf("%d\n",max);
    }
    
    return 0;
}