#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int out[1001];
int main(){
    int n,k,q;
    scanf("%d%d%d",&n,&k,&q);
    int flag=q-1;
    for(int i=0;i<n;i++){
        if(flag==n+1)flag=1;
        for(int j=0;j<k;j++){
            flag++;
            if(flag==n+1)flag=1;
            while(out[flag]!=0){
                flag++;
                if(flag==n+1)flag=1;
            }
            if(flag==n+1)flag=1;
        }
        out[flag]+=1;
    }
    printf("%d",flag);

    return 0;
}