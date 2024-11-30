#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct stu{
    char name[20];
    int a,b,c,sum;
}stu;
int cmp(const void *a,const void *b){
    stu *aa=(stu *)a;
    stu *bb=(stu *)b;
    if(aa->sum!=bb->sum){
        return bb->sum-aa->sum;
    }else if(aa->a!=bb->a){
        return bb->a-aa->a;
    }else{
        return strcmp(aa->name,bb->name);
    }
}

stu studentss[100005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s%d%d%d",studentss[i].name,&studentss[i].a,&studentss[i].b,&studentss[i].c);
        studentss[i].sum=studentss[i].a+studentss[i].b+studentss[i].c;
    }
    // for(int i=0;i<n;i++){
    //     printf("%d\n",studentss[i].sum);
    // }
    qsort(studentss,n,sizeof(stu),cmp);
    for(int i=0;i<n;i++){
        printf("%s\n",studentss[i].name);
    }
    return 0;
}