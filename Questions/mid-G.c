#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int mm[10];
int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&mm[i]);
    }
    for(int i=1;i<=n;i++){
        int flag[10]={0};
        if(i>=1&&i<10){
            for(int j=1;j<=m;j++){
                if(i%mm[j]==0||i==mm[j])flag[j]=1;
            }
        }
        else if(i>=10&&i<100){
            for(int j=1;j<=m;j++){
                if((i)%mm[j]==0||i==mm[j]||(i/10)==mm[j])flag[j]=1;
            }
        }
        else if(i>=100&&i<1000){
            for(int j=1;j<=m;j++){
                if((i)%mm[j]==0||i==mm[j]||(i/10)==mm[j]||(i/10/10)==mm[j])flag[j]=1;
            }
        }
        else if(i>=1000&&i<10000){
            for(int j=1;j<=m;j++){
                if((i)%mm[j]==0||i==mm[j]||(i/10/10)==mm[j]||(i/10/10/10)==mm[j])flag[j]=1;
            }
        }
        else if(i>=10000&&i<100000){
            for(int j=1;j<=m;j++){
                if((i)%j==0||i==mm[j]||(i/10)==mm[j]||(i/10/10)==mm[j]||(i/10/10/10)==mm[j]||(i/10/10/10/10)==mm[j]||(i/10/10/10/10/10)==mm[j])flag[j]=1;
            }
        }
        int cnt=0;
        for(int k=1;k<=m;k++){
            if(flag[k]!=0)cnt+=1;
        }
        if(cnt==0)printf("count out");
        else for(int k=1;k<=m;k++){
            if(flag[k]!=0)printf("%d",k);
        }
        printf("\n");
    }

    return 0;
}   