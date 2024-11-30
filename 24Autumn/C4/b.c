#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct game{
    long long s,t,e;
}game;
int cmp(const void *a,const void *b){
    game *aa=(game *)a;
    game *bb=(game *)b;
    return aa->e-bb->e;
}
game g[100010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lld%lld",&g[i].s,&g[i].t);
            g[i].e=g[i].s+g[i].t;
        }
        qsort(g,n,sizeof(game),cmp);
        long long cnt=1;
        int flag=0;
        for(int i=1;i<n;i++){
            if(g[i].s>=g[flag].e){
                cnt++;
                flag=i;
            }else{
                continue;
            }
        }
        printf("%lld\n",cnt);

    }
    return 0;
}