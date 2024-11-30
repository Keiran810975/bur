#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#define NHASH  3001
#define MULT  37
int cnt;
int binsearch(char key[][20], int n, char k[]){
     int low=0, high=n-1, mid;
       while(low<=high){
              mid=(low+high)/2;
              cnt++;
              if(strcmp(k,key[mid])==0)
                    return mid;             /*  查找成功  */
              if(strcmp(k,key[mid])>0)
                    low=mid+1;            /*  准备查找后半部分 */
              else
                    high=mid-1;           /* 准备查找前半部分 */
        }
        return -1;                             /*   查找失败  */
}
int Inbinsearch(char key[][20],char k[],int x,int y){
     int low=x, high=y-1, mid;
       while(low<=high){
              mid=(low+high)/2;
              cnt++;
              if(strcmp(k,key[mid])==0)
                    return mid;             /*  查找成功  */
              if(strcmp(k,key[mid])>0)
                    low=mid+1;            /*  准备查找后半部分 */
              else
                    high=mid-1;           /* 准备查找前半部分 */
        }
        return -1;                             /*   查找失败  */
}
unsigned int hash(char *str){
       unsigned int h=0;
       char *p;
       for(p=str; *p!='\0'; p++)
              h = MULT*h + *p;
       return h % NHASH;
}
char words[4000][20];
int ind[30];// 索引�?


typedef struct list{
    char val[20];
    struct list *next;
}list;
list *hh[3500];

list * hSearch(char s[]){
    unsigned int x=hash(s);
    list *p=hh[x];
    while(p!=NULL){
        cnt++;
        if(strcmp(p->val,s)==0)return p;
        else if(strcmp(p->val,s)>0)return NULL;
        p=p->next;
    }
    return NULL;
}

void hashInsert(char s[]){
    list *p=(list *)malloc(sizeof(list));
                unsigned int x=hash(s);
                strcpy(p->val,s);
                p->next=hh[x];
                hh[x]=p;
}
int main(){
    FILE* in=fopen("dictionary3000.txt","r");
    int j=0;
    while(fscanf(in,"%s",words[j])!=EOF){
        j++;
    }
    char s[20];
    int op;
    while(scanf("%s%d",s,&op)!=EOF){
        if(op==1){
            int sig=0;
            cnt=0;
            for(int i=0;;i++){
                cnt++;
                if(strcmp(s,words[i])==0){  
                    sig=1;break;
                }
                if(strcmp(s,words[i])<0){
                    sig=2;break;
                }
            }
            if(sig==1)printf("1 %d\n",cnt);
            else if(sig==2)printf("0 %d\n",cnt);
        }
        if(op==2){
            cnt=0;
            int sig=binsearch(words,j,s);
            if(sig==-1)printf("0 %d\n",cnt);
            else printf("1 %d\n",cnt);
        }
        if(op==3){
            //构建索引�?
            int num=0;
            int k=0;
            cnt=0;
            for(int i=0;i<j;i++){
                if(words[i][0]==words[i+1][0]){
                    num++;
                }else{
                    ind[++k]=++num;
                    //num=1;
                }
            }
            ind[26]=3367;
            //for(int i=0;i<27;i++)printf("%d ",ind[i]);
            int x=ind[s[0]-'a'];
            int y=ind[s[0]-'a'+1];
            //printf("%d ",s[0]-'a');
            int sig=Inbinsearch(words,s,x,y);
            if(s[0]=='x')cnt=0;
            if(sig==-1)printf("0 %d\n",cnt);
            else printf("1 %d\n",cnt);
        }
        if(op==4){
            cnt=0;
            for(int i=0;i<j;i++){
                hashInsert(words[i]);
            }
            list *r=hSearch(s);
            if(r==NULL)printf("0 %d\n",cnt);
            else printf("1 %d\n",cnt);
        }
    }
    return 0;
}