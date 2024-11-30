#include<stdio.h>
#include<math.h>
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int m=2*k+1;
    int num[50000001];
    int j=0,len=0;
    while(n){num[j]=n%m;n=n/m;j++;}
    for(int i=0;i<j;i++){
        if(num[i]>k){
            num[i+1]+=1;num[i]=-(pow(m,i+1)-num[i]*(pow(m,i)))/(pow(m,i));
        }
    }
    for(int i=len;i>0;i--){
        if(num[i]<0)printf("-%c",'A'+abs(num[i])-1);
        else printf("%d",num[i]);
    }

    return 0;
}
