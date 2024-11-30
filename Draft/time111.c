#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct stu{
    char name[50];
    char id[50];
    int time;
}stu;
stu ff[150];
int cmp(const void *x,const void *y){
    stu xx = *(stu*)x;
    stu yy = *(stu*)y;
    if(strcmp(xx.name,yy.name)>0)return 1;
    if(strcmp(xx.name,yy.name)<0)return -1;
    return 0;
}
int cmp2(const void *x,const void *y){
    stu xx = *(stu*)x;
    stu yy = *(stu*)y;
    if(xx.time>yy.time)return 1;
    if(xx.time<yy.time)return -1;
    if(xx.time==yy.time){
        if(strcmp(xx.id,yy.id)>0)return 1;
        if(strcmp(xx.id,yy.id)<0)return -1;
        return 0;
    }
}
int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s%s%d",ff[i].name,ff[i].id,&ff[i].time);
    }
    qsort(ff,n,sizeof(stu),cmp);
    //printf("%%%\n");
    //for(int i=0;i<n;i++)printf("%s %s %d\n",ff[i].name,ff[i].id,ff[i].time);
    //printf("^%s\n",ff[9].name);
    int j=0;
    stu ans[150];
    ans[0]=ff[0];
    for(int i=1;i<n;i++){
        //printf("**%d**",i);
        if(strcmp(ff[i].name,ans[j].name)==0){
            ans[j].time+=ff[i].time;
        }
        else{
            j++;
            ans[j]=ff[i];
        }
    }
    j++;
    qsort(ans,j,sizeof(stu),cmp2);
    printf("$$$\n");
    for(int i=0;i<j;i++){
        printf("%s %s %d\n",ans[i].name,ans[i].id,ans[i].time);
    }
    return 0;
}