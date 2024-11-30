#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int routine[1000001];
int lor(int p,int q){
    memset(routine,0,sizeof(routine));
    int j=0;
    while(p>q){
        if(p>q){
            p=p-q;
            routine[j++]=1;
        }else{
            q=q-p;
            routine[j++]=2;
        }
    }
    q=q-p;
    routine[j++]=2;
    //for(int i=0;i<j;i++)printf("%d ",routine[i]);
    //("$%d,%d\n",p,q);
    for(int i=j-1;i>=0;i--){
        if(routine[i]==1){
            q+=p;
        }else if(routine[i]==2){
            p+=q;
        }
    }
    //printf("$%d\n",q);
    return q;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int p,q;
        scanf("%d%d",&p,&q);
        if(p<q){
            printf("%d %d\n",q,q-p);
        }else if(q==1){
            printf("%d %d\n",q,p+q);
        }else{
            int x=q;
            int y=lor(p,q);
            printf("%d %d\n",x,y);
            
        }
    }
    return 0;
}