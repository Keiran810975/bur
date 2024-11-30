#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    float sum=0;
    float b[10];
    int x,pass=0,ak=0,ac=0;
    int a[10]={30,20,10,10,10,10,5,5,5,5};
    for(int i=0;i<n;i++){
        int ccc=0,AC=0;
        for(int j=0;j<10;j++){
            scanf("%d",&x);
            b[j]=x;
            sum+=x;
            ccc+=b[j]; 
            if(a[j]==b[j])
            AC+=1;   
        }
        if(ccc>=60)
        pass+=1;
        if(ccc==110){
            ak+=1;
            sum-=10;
        }
        if(AC==0)
        ac+=1;
    }
    printf("%.2f\n",sum/n);
    printf("%d\n%d\n%d\n",pass,ak,ac);
    

    return 0;
}