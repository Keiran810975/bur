#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int n;
int st[10];
int arr[10];
void permutation(int x){
    if(x>n){
        for(int i=1;i<=n;i++){
            printf("%5d ",arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++){
        if(st[i]==0){
            st[i]=1;
            arr[x]=i;
            permutation(x+1);
            st[i]=0;
            //arr[x]=0;
        }
    }
}
int main(){
    scanf("%d",&n);
    permutation(1);
    return 0;
}