#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char s[10001];char *ad[10001];
int cmp(const void *p,const void *q){
    if(strcmp(*(char **)p,*(char **)q)>0)return 1;
    if(strcmp(*(char **)p,*(char **)q)<0)return -1;
    return 0;
}
int main(){
    scanf("%s",s);
    int k;scanf("%d",&k);
    for(int i=0;i<strlen(s);i++){
        ad[i]=s+i;
    }
    qsort(ad,strlen(s),sizeof(char *),cmp);
    printf("%s",ad[k-1]);
    return 0;
}