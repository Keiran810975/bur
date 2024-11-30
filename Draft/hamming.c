#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct letter{
    char name[50];
    int dis;
}letter;
letter ff[100];
int hamming(char *a,char *b){
    int l=strlen(a);
    int cnt=0;
    for(int i=0;i<l;i++){
        if(a[i]!=b[i])cnt++;
    }
    return cnt;
}
int cmp(const void *x,const void *y){
    letter xx = *(letter*)x;
    letter yy = *(letter*)y;
    if(xx.dis>yy.dis)return 1;
    if(xx.dis<yy.dis)return -1;
    if(xx.dis==yy.dis){
        if(strcmp(xx.name,yy.name)>0)return 1;
        if(strcmp(xx.name,yy.name)<0)return -1;
        return 0;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    char base[50];scanf("%s",base);
    for(int i=0;i<n-1;i++){
        char s[50];
        scanf("%s",s);
        strcpy(ff[i].name,s);
        ff[i].dis=hamming(base,s);
    }
    qsort(ff,n-1,sizeof(letter),cmp);
    for(int i=0;i<n-1;i++){
        printf("%s ",base);
        printf("%s %d\n",ff[i].name,ff[i].dis);
    }
    return 0;
}