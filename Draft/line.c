#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct line{
    int x,y,m,n;
}line;
int t;
line ff[500];
int vis[500];
int first,second;
void swapStruct(line *x,line *y){
    struct line temp=*x;
    *x=*y;
    *y=temp;
}
void BubbleSort(line s[],int k){
    //struct book tt;
    for(int h=0;h<k-1;h++){
        for(int g=0;g<k-1;g++){
            if(s[g].x>s[g+1].x){
                swapStruct(&s[g],&s[g+1]);
            }
        }
    }
}
void sc(){
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d%d%d%d",&ff[i].x,&ff[i].y,&ff[i].m,&ff[i].n);
    }
    BubbleSort(ff,t);
}
void count(line s[],int t){
    int max=0;
    //vis[0]=1;
    for(int i=0;i<t;i++){
        //first=s[i].x,second=s[i].y;
        int a=s[i].m,b=s[i].n;
        int cnt=1;
        for(int j=i+1;j<t;j++){
            if(s[j].x==a&&s[j].y==b){
                cnt++;
                a=s[j].m,b=s[j].n;
                //vis[j]=1;
                //printf("%d %d\n",a,b);
            }
        }
        if(cnt>max){
            max=cnt;
            first=s[i].x,second=s[i].y;
        }
    }
    printf("%d %d %d\n",max,first,second);
}
int main(){
    sc();
    //for(int i=0;i<t;i++)printf("%d %d %d %d\n",ff[i].x,ff[i].y,ff[i].m,ff[i].n);
    count(ff,t);
    return 0;
}