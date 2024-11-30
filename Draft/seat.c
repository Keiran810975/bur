#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct stu{
    int num;
    char name[100];
    int seat;
}stu;
void swapStruct(stu *x,stu *y){
    struct stu temp=*x;
    *x=*y;
    *y=temp;
}
stu list[500];
int p[500];
int main(){
    int n;scanf("%d",&n);
    FILE* op=fopen("in.txt","r");
    FILE* ou=fopen("out.txt","w");
    int k=0;
    while(fscanf(op,"%d%s%d",&list[k].num,list[k].name,&list[k].seat)!=EOF){
        k++;
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(list[j].seat>list[j+1].seat){
                swapStruct(&list[j],&list[j+1]);
            }
        }
    }
    int m=list[n-1].seat;
    int min=(m<n)?m:n;
    //printf("%d\n",min);
    int last=n-1;
    //for(int i=0;i<n;i++)printf("%d ",list[i].seat);
    for(int i=0;i<n;i++){
        p[list[i].seat]++;
    }
    for(int i=1;i<=min;i++){
        if(p[i]==0){
            list[last--].seat=i;
            min=(list[last].seat<n)?list[last].seat:n;
        }
    }
    //printf("\n");
    //for(int i=0;i<n;i++)printf("%d ",list[i].seat);
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(list[j].seat==list[j+1].seat){
                if(list[j].num>list[j+1].num)swapStruct(&list[j],&list[j+1]);
            }
            else if(list[j].seat>list[j+1].seat){
                swapStruct(&list[j],&list[j+1]);
            }
        }
    }
    last=n-1;
    m=list[last].seat;
    for(int i=0;i<n;i++){
        if(list[i].seat==list[i+1].seat){
            list[i+1].seat=++m;
        }
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(list[j].num>list[j+1].num){
                swapStruct(&list[j],&list[j+1]);
            }
        }
    }
    for(int i=0;i<n;i++){
        fprintf(ou,"%d %s %d\n",list[i].num,list[i].name,list[i].seat);
    }
    return 0;
}