#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
    int head;
    int tail;
}node;
node fff[200];
int cmp(const void *x,const void *y){
    node xx = *(node*)x;
    node yy = *(node*)y;
    if(xx.head>yy.head)return 1;
    if(xx.head<yy.head)return -1;
    return 0;
}
node ans[200];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&fff[i].head,&fff[i].tail);
    }
    qsort(fff,n,sizeof(node),cmp);
    //for(int i=0;i<n;i++)printf("%d %d\n",fff[i].head,fff[i].tail);
    int j=0;
    ans[0]=fff[0];
    for(int i=1;i<n;i++){
        if(fff[i].head-ans[j].tail<=1&&fff[i].tail>ans[j].tail){
            ans[j].tail=fff[i].tail;
        }
        else if(fff[i].head<=ans[j].tail&&fff[i].tail<=ans[j].tail)continue;
        else if(fff[i].head-ans[j].tail>1){
            j++;
            ans[j]=fff[i];
        }
    }
    for(int i=0;i<=j;i++){
        printf("%d %d\n",ans[i].head,ans[i].tail);
    }
    return 0;
}