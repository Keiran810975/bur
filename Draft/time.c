#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct stu{
    char id[50];
    int time;
    double finaltime;
    int cnt;//´ò¿¨´ÎÊı
}stu;
stu ff[1500];
int swit(char *s){
    int l=strlen(s);
    int num=0;
    for(int i=0;i<l;i++){
        num=num*10+s[i]-'0';
    }
    return num;
}
int bmd(char *s){
    if(s[0]=='B')return 1;
    if(s[0]=='M')return 2;
    if(s[0]=='D')return 3;
}
int cmp(const void *x,const void *y){
    stu xx = *(stu*)x;
    stu yy = *(stu*)y;
    if(bmd(xx.id)>bmd(yy.id))return 1;
    if(bmd(xx.id)<bmd(yy.id))return -1;
    if(bmd(xx.id)==bmd(yy.id)){
        if(xx.finaltime<yy.finaltime)return 1;
        if(xx.finaltime>yy.finaltime)return -1;
        return 0;
    }
}
int main(){
    int j=0;
    // char s[10]="06";
    // printf("%d",swit(s));
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char s[50];
        scanf("%s",s);
        int sig=0;
        int index;
        for(int k=0;k<j;k++){
            if(strcmp(s,ff[k].id)==0){
                sig=1;
                index=k;
                break;
            }
        }
        if(sig==1)ff[index].cnt+=1;
        else if(sig==0){
            ff[j].cnt=1;
            strcpy(ff[j].id,s);
        }

        char a[10],b[10],c[10],d[10],e[10],f[10];
        scanf("%s%s%s%s%s%s",a,b,c,d,e,f);
        int tt=-(3600*swit(a)+60*swit(b)+swit(c)-3600*swit(d)-60*swit(e)-swit(f));
        if(sig==1){
            ff[index].time+=tt;
        }
        else if(sig==0){
            ff[j].time=tt;
            j++;
        }
    }
    for(int i=0;i<j;i++){
        ff[i].finaltime=(double)ff[i].time/3600;
    }
    // for(int i=0;i<j;i++){
    //     printf("%s %d %.2lf\n",ff[i].id,ff[i].cnt,ff[i].finaltime);
    // }
    qsort(ff,j,sizeof(stu),cmp);
    for(int i=0;i<j;i++){
        printf("%s %d %.2lf\n",ff[i].id,ff[i].cnt,ff[i].finaltime);
    }
    return 0;
}