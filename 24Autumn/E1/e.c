#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
int main(){
    srand(time(NULL));
    int n,p;
    scanf("%d%d",&n,&p);
    int rounds=1000000;
    int cnt=0;//连跪次数
    double win=0,lose=0;
    while(rounds--){
        //生成1-100的随机数 
        int a=rand()%100+1;
        if(a>p){
            lose++;
            cnt++;
        }else{
            win++;
            cnt=0;
        }
        if(cnt==n){
            rounds--;
            win++;
            cnt=0;
        }
    }
    double ans=win/(win+lose);
    ans=round(ans*1000)/1000;
    printf("%.3lf\n",ans);
    return 0;
}