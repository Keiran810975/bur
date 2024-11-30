#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int num[300],dev[300],time[300];
char name[300][100];
int id[300],ab[300];
int cmp(const void *p,const void *q){
    int a=(*(int *)p);
    int b=(*(int *)q);
    int aa=num[a],bb=num[b];
    if(aa>bb)return 1;
    if(aa<bb)return -1;
    return 0;
}
int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%s%d%d",&num[i],name[i],&dev[i],&time[i]);
        id[i]=i;
    }
    qsort(id,n,sizeof(int),cmp);
    int k=0;
    for(int i=0;i<n;i++){
        if(num[id[i]]==num[id[i+1]]&&dev[id[i]]!=dev[id[i+1]]){
            ab[k++]=id[i];
        }
    }
    for(int i=0;i<k;i++){
        if(i==0)printf("%d %s\n",num[ab[i]],name[ab[i]]);
        else{
            if(num[ab[i]]!=num[ab[i-1]])printf("%d %s\n",num[ab[i]],name[ab[i]]);
        }
    }
    return 0;
}