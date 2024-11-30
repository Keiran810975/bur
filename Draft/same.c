#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct shit{
    char num[20];
    char id;
    char tin[50];
    char tout[50];
}shit;
shit journal[1500];
shit tt[1500];
int cmp(const void *x,const void *y){
    shit xx = *(shit*)x;
    shit yy = *(shit*)y;
    if(strcmp(xx.num,yy.num)<0)return 1;
    if(strcmp(xx.num,yy.num)>0)return -1;
    if(strcmp(xx.num,yy.num)==0){
        if(xx.id>yy.id)return 1;
        if(xx.id<yy.id)return -1;
        return 0;
    }
}
int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s %c %s %s",journal[i].num,&journal[i].id,journal[i].tin,journal[i].tout);
    }
    char target[20];
    scanf("%s",target);
    qsort(journal,n,sizeof(shit),cmp);
    int j=0;
    for(int i=0;i<n;i++){
        if(strcmp(journal[i].num,target)==0)tt[j++]=journal[i];
    }
    //for(int i=0;i<j;i++)printf("%s\n",tt[i].tin);
    shit ans[1000];
    int g=0;
    for(int i=0;i<n;i++){
        for(int k=0;k<j;k++){
            if(strcmp(journal[i].tin,tt[k].tout)<=0&&strcmp(journal[i].tout,tt[k].tin)>=0&&journal[i].id==tt[k].id&&strcmp(journal[i].num,tt[k].num)!=0){
                ans[g++]=journal[i];
                //printf("%s %c\n",journal[i].num,journal[i].id);
            }
        }
    }
    printf("%s %c\n",ans[0].num,ans[0].id);
    for(int i=1;i<g;i++){
        if(ans[i].id==ans[i-1].id&&strcmp(ans[i].num,ans[i-1].num)==0){
            continue;
        }else{
            printf("%s %c\n",ans[i].num,ans[i].id);
        }
    }
    return 0;
}