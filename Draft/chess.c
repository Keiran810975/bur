#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int bb[50][50]={3};
int sig=0;    int x,y;
void sc(){
    for(int i=4;i<23;i++){
        for(int j=4;j<23;j++){
            scanf("%d",&bb[i][j]);
        }
    }
}
void pl(){
    for(int i=4;i<23;i++){
        for(int j=4;j<23;j++){
            if(bb[i][j]==1&&bb[i+1][j]==1&&bb[i+2][j]==1&&bb[i+3][j]==1&&(bb[i-1][j]==0||bb[i+4][j]==0)){
                x=i-4;
                y=j-4;
                sig=1;
                break;
            }
            if(bb[i][j]==1&&bb[i+1][j+1]==1&&bb[i+2][j+2]==1&&bb[i+3][j+3]==1&&(bb[i-1][j-1]==0||bb[i+4][j+4]==0)){
                x=i-4;
                y=j-4;
                sig=1;
                break;
            }
            if(bb[i][j]==1&&bb[i][j+1]==1&&bb[i][j+2]==1&&bb[i][j+3]==1&&(bb[i][j-1]==0||bb[i][j+4]==0)){
                x=i-4;
                y=j-4;
                sig=1;
                break;
            }
            if(bb[i][j]==1&&bb[i-1][j+1]==1&&bb[i-2][j+2]==1&&bb[i-3][j+3]==1&&(bb[i+1][j-1]==0||bb[i-4][j+4]==0)){
                x=i-7;
                y=j-1;
                sig=1;
                break;
            }
        }
    }
    if(sig==1)return;
    for(int i=4;i<23;i++){
        for(int j=4;j<23;j++){
            if(bb[i][j]==2&&bb[i+1][j]==2&&bb[i+2][j]==2&&bb[i+3][j]==2&&(bb[i-1][j]==0||bb[i+4][j]==0)){
                x=i-4;
                y=j-4;
                sig=2;
                break;
            }
            if(bb[i][j]==2&&bb[i+1][j+1]==2&&bb[i+2][j+2]==2&&bb[i+3][j+3]==2&&(bb[i-1][j-1]==0||bb[i+4][j+4]==0)){
                x=i-4;
                y=j-4;
                sig=2;
                break;
            }
            if(bb[i][j]==2&&bb[i][j+1]==2&&bb[i][j+2]==2&&bb[i][j+3]==2&&(bb[i][j-1]==0||bb[i][j+4]==0)){
                x=i-4;
                y=j-4;
                sig=2;
                break;
            }
            if(bb[i][j]==2&&bb[i-1][j+1]==2&&bb[i-2][j+2]==2&&bb[i-3][j+3]==2&&(bb[i+1][j-1]==0||bb[i-4][j+4]==0)){
                x=i-7;
                y=j-1;
                sig=2;
                break;
            }
        }
    }
}
int main(){
    sc();
    pl();
    //printf("%d\n",bb[0][0]);
    if(sig!=0)printf("%d:%d,%d\n",sig,x+1,y+1);
    else printf("No\n");
    return 0;
}