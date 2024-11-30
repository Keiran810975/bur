#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int l[1000001];int r[1000001];int id[1000001];int ll[1000001],rr[1000001];
int cmp(const void *p,const void *q){
    int a=(*(int *)p);
    int b=(*(int *)q);
    int aa=l[a],bb=l[b];
    if(aa>bb)return 1;
    if(aa<bb)return -1;
    return 0;
}
int main(){
    int i=0;
    while(scanf("%d%d",&l[i],&r[i])!=EOF){
        i++;
    }
    for(int j=0;j<i;j++)id[j]=j;
    qsort(id,i,sizeof(int),cmp);
    int k=0;ll[0]=l[id[0]];rr[0]=r[id[0]];
    //printf("%d",ll[0]);
    for(int j=1;j<i;j++){
        if(rr[k]>=l[id[j]]&&rr[k]<=r[id[j]]){
            rr[k]=r[id[j]];
        }
        else if(rr[k]<l[id[j]]){
            k++;
            ll[k]=l[id[j]];rr[k]=r[id[j]];
        }
        //printf("%d %d\n",ll[k],rr[k]);
    }
    
    for(int j=0;j<=k;j++){
        printf("%d %d\n",ll[j],rr[j]);
    }

    return 0;
}