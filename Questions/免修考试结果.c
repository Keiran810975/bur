#include<stdio.h>
int main(){
    int y,s;
    while(scanf("%d%d",&y,&s)!=EOF){
        if(y==2023){
            if(s>=85)
            printf("%d\nYou can choose whether to take the course or not.\n",s);
            else
            printf("You have to take the course.\n");
        }
        else{
            if(s>=60)
            printf("%d\n",s);
            else
            printf("You have to take the course.\n");
        }
    }

    return 0;
}