#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
char a[1000],b[1000];
void expand(char a[],char b[]){
    int len=strlen(a);int j=0;
    for(int i=0;i<len;i++){
        if(a[i]=='-'){
            if(a[i+1]>a[i-1]&&(((a[i-1]>='a'&&a[i-1]<='z')&&(a[i+1]>='a'&&a[i+1]<='z'))||((a[i-1]>='A'&&a[i-1]<='Z')&&(a[i+1]>='A'&&a[i+1]<='Z'))||((a[i-1]>='0'&&a[i-1]<='9')&&(a[i+1]>='0'&&a[i+1]<='9')))){
                char k;
                for(k=a[i-1]+1;k<=a[i+1]-1;k++){
                b[j]=k;j++;
                }
            }
            else{
                b[j]='-';j++;
            }
        }
        else{
            b[j]=a[i];j++;
        }
    }
    printf("%s",b);
}
int main(){
    scanf("%s",a);
    expand(a,b);
    return 0;
}