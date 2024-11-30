for (int i = 0; i < len; i++) { 
    if (s[i] >= '0' && s[i] <= '9') { 
        num = num * m + (s[i] - '0'); 
    } 
    else if (s[i] >= 'A' && s[i] <= 'Z') { 
        num = num * m + (s[i] - 'A' + 10); 
    } 
    } //m进制转十进制

#include <stdio.h>
int main(){
int x; //x为十进制数
scanf("%d",&x);
int a[100];
int count=0;
do{
a[count++]=x%2;
x=x/2;
}while(x!=0);//当商不为0时进行循环
for(int i=count-1;i>=0;i--){
printf("%d",a[i]);
}
return 0;
}
//十进制转2进制