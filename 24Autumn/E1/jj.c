#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int lor(int p,int q){
    int dis=0;
    //memset(routine,0,sizeof(routine));
    int j=0;
    while(p>q){
        if(p>q){
            p=p-q;
            dis++;
        }else{
            q=q-p;
            dis++;
        }
    }
    //for(int i=0;i<j;i++)printf("%d ",routine[i]);
    //("$%d,%d\n",p,q);
    //printf("$%d\n",q);
    return dis;
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
            int mod=p/q;
            int x=p%q;
            int y=q-x;
            int xx=q;
            y+=mod*q;
            printf("%d %d\n",xx,y);
            
        }
    }
    return 0;
}