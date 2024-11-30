#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    char a,b,c,d;
    int ccc[500001]={0};
    int rank;
    for(int i=0;i<n;i++){
        getchar();
        scanf("%c%c%c%c",&a,&b,&c,&d);
        rank=26*26*26*(a-97)+26*26*(b-97)+26*(c-97)+d-97;
        if(ccc[rank]==1)
        printf("Moca has already memorized this word!\n");
        else
        printf("Moca memorized a new word!\n");
        ccc[rank]=1;
    }

    return 0;
}