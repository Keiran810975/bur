#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void hanoi(int n,char a,char b,char c);

void move(int i,char from,char to);
int main(){
    char a,b,c;
    scanf("%c %c %c",&a,&b,&c);
    getchar();
    int n;
    scanf("%d",&n);
    hanoi(n,a,b,c);  

    return 0;
}
void hanoi(int n,char from,char via,char to){
    if(n==1){
        move(n,from,to);
        return;
    }
    hanoi(n-1,from,to,via);
    move(n,from,to);
    hanoi(n-1,via,from,to);
}
void move(int i,char from,char to){
    printf("Eika moved Koishi %02d form the %c to the %c\n",i,from,to);
}
