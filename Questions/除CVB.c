#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        char c;
        c=getchar();
        if(c!='C'&&c!='V'&&c!='B'){
            printf("%c",c);
        }

    }


    return 0;
}