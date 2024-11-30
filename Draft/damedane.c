#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct stuff{
    int id;
    char name[50];
    char pro[50];
    int level;
}stuff;
int rank(char *s){
    if(strcmp(s,"sniper")==0)return 1;
    if(strcmp(s,"defender")==0)return 2;
    if(strcmp(s,"guard")==0)return 3;
    if(strcmp(s,"vanguard")==0)return 4;
    if(strcmp(s,"specialist")==0)return 5;
    if(strcmp(s,"supporter")==0)return 6;
    if(strcmp(s,"medic")==0)return 7;
    if(strcmp(s,"caster")==0)return 8;
}
int cmp1(const void *x,const void *y){
    stuff xx = *(stuff*)x;
    stuff yy = *(stuff*)y;
    if(rank(xx.pro)>rank(yy.pro))return 1;
    if(rank(xx.pro)<rank(yy.pro))return -1;
    if(rank(xx.pro)==rank(yy.pro)){
        if(xx.id>yy.id)return 1;
        if(xx.id<yy.id)return -1;
        return 0;
    }
}
int cmp2(const void *x,const void *y){
    stuff xx = *(stuff*)x;
    stuff yy = *(stuff*)y;
    if(xx.level>yy.level)return 1;
    if(xx.level<yy.level)return -1;
    if(xx.level==yy.level){
        if(xx.id>yy.id)return 1;
        if(xx.id<yy.id)return -1;
        return 0;
    }
}
int cmp3(const void *x,const void *y){
    stuff xx = *(stuff*)x;
    stuff yy = *(stuff*)y;
    if(xx.id>yy.id)return 1;
    if(xx.id<yy.id)return -1;
    return 0;
}
stuff ff[1500];
int main(){
    int m,n;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d%s%s%d",&ff[i].id,ff[i].name,ff[i].pro,&ff[i].level);
    }
    //for(int i=0;i<n;i++)printf("%d %s %s %d\n",ff[i].id,ff[i].name,ff[i].pro,ff[i].level);
    printf("__\n");
    printf("%d\n",rank(ff[3].pro));
    qsort(ff,n,sizeof(stuff),cmp1);
    for(int i=0;i<n;i++)printf("%d %s %s %d\n",ff[i].id,ff[i].name,ff[i].pro,ff[i].level);
    qsort(ff,n,sizeof(stuff),cmp2);
    for(int i=0;i<n;i++)printf("%d %s %s %d\n",ff[i].id,ff[i].name,ff[i].pro,ff[i].level);
    qsort(ff,n,sizeof(stuff),cmp3);
    for(int i=0;i<m;i++){
        int a,x,y;
        char p[50];
        scanf("%d%s%d%d",&a,p,&x,&y);
        int cnt=0;
        int ans[100];
        int k=0;
        for(int j=0;j<n;j++){
            if(strcmp(p,ff[j].pro)==0&&ff[j].level>=x&&ff[j].level<=y){
                ans[k++]=ff[j].id;
                cnt++;
                if(cnt==a)break;
            }
        }
        if(cnt==a){
            for(int j=0;j<k;j++)printf("%d ",ans[j]);
            printf("\n");
        }else{
            printf("DAMEDANE\n");
        }
    }
    return 0;
}