#include<stdio.h>
int main(){
    char level;
    scanf("%c",&level);
    int n=level-'A'+1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<n-i;j++){
            printf(" ");
        }
        for(int j=0;j<i;j++){
            printf("%c",'A'+j);
        }
        for(int j=i-2;j>=0;j--){
            printf("%c",'A'+j);
        }
        printf("\n");
    }
    for(int i=n-1;i>0;i--){
        for(int j=0;j<n-i;j++){
            printf(" ");
        }
        for(int j=0;j<i;j++){
            printf("%c",'A'+j);
        }
        for(int j=i-2;j>=0;j--){
            printf("%c",'A'+j); 
        }
        printf("\n");
    } 
    return 0;
}