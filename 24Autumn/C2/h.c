#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int x[2000010],y[2000010];
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        x[i]=n-i+1;
    }
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            char c;
            scanf(" %c",&c);
            if(c=='L'){
                x[n+1]=x[n]-1;
                y[n+1]=y[n];
                n++;
                //printf("")
            }
            else if(c=='R'){
                x[n+1]=x[n]+1;
                y[n+1]=y[n];
                n++;
                //printf("##%d %d\n",x[n],y[n]);
            }
            else if(c=='U'){
                x[n+1]=x[n];
                y[n+1]=y[n]+1;
                n++;
            }
            else{
                x[n+1]=x[n];
                y[n+1]=y[n]-1;
                n++;
            }
        }
        else if(op==2){
            //printf("%d^\n",n);
            int k;
            scanf("%d",&k);
            printf("%d %d\n",x[n-k+1],y[n-k+1]);
        }
    }
    return 0;
}