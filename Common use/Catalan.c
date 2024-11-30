#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int ccc(int n){
    if(n==0)return (1);
    else if(n==1)return (1);
    else if(n==2)return (2);
    else if(n>=3){
        int sum=0;
        for(int i=0;i<=n-1;i++){
            sum+=ccc(i)*ccc(n-1-i);
        }
        return (sum);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    for(int j=0;j<t;j++){
        int n;
        scanf("%d",&n);
        printf("%d\n",ccc(n));
    }

    return 0;
}