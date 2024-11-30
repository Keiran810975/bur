#include<stdio.h>
int main(){
    int a,b,c,i;
    int flag;
    scanf("%d%d%d",&a,&b,&c);
    for(i=2;i<16;i++){
        flag=0;
        if((((a*b)/i)*10+((a*b)%i)==c)&&(a/100000%10<i)&&a/10000%10<i&&a/1000%10<i&&a/100%10<i&&a/10%10<i&&a%10<i&&(b/100000%10<i)&&b/10000%10<i&&b/1000%10<i&&b/100%10<i&&b/10%10<i&&b%10<i&&(c/100000%10<i)&&c/10000%10<i&&c/1000%10<i&&c/100%10<i&&c/10%10<i&&c%10<i){
            if(!((a==10&&i==9)||(b==10&&i==9)||(c==10&&i==9))){
                flag+=1;
                break;
            }
        }
    }
    if(flag==1)
    printf("%d\n",i);
    else if(flag==0)
    printf("%d\n",0);


    return 0;
}