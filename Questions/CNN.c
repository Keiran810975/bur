#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int a[40][40];int b[40][40];int c[40][40];
int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(int i=0;i<m-n+1;i++){
        for(int j=0;j<m-n+1;j++){
            for(int k=i;k<i+n;k++){
                for(int l=j;l<j+n;l++){
                    c[i][j]+=b[k][l]*a[k-i][l-j];
                }
            }
        }
    }
    for(int i=0;i<m-n+1;i++){
        for(int j=0;j<m-n+1;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }


    return 0;
}