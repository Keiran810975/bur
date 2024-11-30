#include<stdio.h>
#include<math.h>
int main(){
    int x;
    scanf("%d",&x);
    int y,z;
    if(x<3)
    printf("baka!");
    else{
        if(x%2!=0){
        y=(x*x-1)/2;
        z=(x*x+1)/2;
        printf("%d %d %d\n",x,y,z);
        }
        else if(x%2==0){
            y=x*x/4-1;
            z=x*x/4+1;
            printf("%d %d %d\n",x,y,z);
    }
    }
    

    return 0;
}