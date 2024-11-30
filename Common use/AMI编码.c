#include<stdio.h>
#include<string.h>
int main(){
    char s;
    int cnt=2;
    while((s=getchar())!=EOF){
        if(s=='1'){
            if(cnt%2==0)
            printf("+1 ");
            else
            printf("-1 ");
            cnt+=1;
        }
        else if(s=='0')
        printf("0 ");
    }

    return 0;
}