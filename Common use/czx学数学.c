#include<stdio.h>
int flag[10]={0};
int main(){
    int a[5000000];
    int a,b,rem,cnt=0,i;
    scanf("%d%d",&a,&b);
    if(a<b){
        rem=a;
        for(i=1;flag[rem]==0;i++){
            a[i]=(10*rem)/b;rem=(10*rem)%b;flag[a[i]]+=1;
        }int j=i;
        for(;j>0;j--){
            if(a[j]==a[i]);
            cnt=i-j;break;
        }
        int mm=j;
    }
    for(int k=0;k<mm;k++){
        printf("%d",a[k]);
    }

    return 0;
}