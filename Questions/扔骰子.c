#include<stdio.h>
int main(){
    int n,a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        if((a==0&&(b>=6&&b<=18))||((a==1||a==4)&&(b>=4&&b<=12))||(a==2||a==5||a==8)&&(b==2||b==3||b==5||b==6)||(b==0)&&(a==3||a==6||a==9||a==12)){
            printf("Yes\n");
        }
        else
        printf("No\n");
    }

    return 0;
}