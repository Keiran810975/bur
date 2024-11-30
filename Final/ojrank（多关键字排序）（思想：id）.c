//还有C8的E题
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char name[100010][20];double score[100010];int time[100010];int id[100010];
#define eps 1e-6
int cmp(const void *p,const void *q){
    int a=(*(int *)p);
    int b=(*(int *)q);
    double aa=score[a];double bb=score[b];
    if(aa-bb>eps)return -1;
    if(aa-bb<-eps)return 1;
    int aaa=time[a],bbb=time[b];
    if(aaa>bbb)return 1;
    if(aaa<bbb)return -1;
    return 0;
}
int main(){
    int i=0;
    while(scanf("%s%lf%d",name[i],&score[i],&time[i])!=EOF){
        i++;
    }
    
    for(int j=0;j<i;j++)id[j]=j;
    qsort(id,i,sizeof(int),cmp);
    for(int j=0;j<i;j++){
        printf("%10s %8.2lf %10d\n",name[id[j]],score[id[j]],time[id[j]]);
    }
    return 0;
}