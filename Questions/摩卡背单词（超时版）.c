#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    char a[n][10];
    scanf("%s",a[0]);
    printf("Moca memorized a new word!");
    for(int i=1;i<n;i++){
        int jud=0;
        scanf("%s",a[i]);
        for(int j=0;j<i;j++){
            if(strcmp(a[i],a[j])==0)jud+=1;
            
        }
        if(jud>=1)printf("Moca has already memorized this word!\n");
        else if(jud==0)printf("Moca memorized a new word!\n");
    }

    return 0;
}