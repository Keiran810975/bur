#include<stdio.h>
int main(){
    int m;
    scanf("%d",&m);
    int i,x,y;
    int ccc1[12]={0},ccc2[12]={0},ccc3[12]={0};
    double ts[m];
    while(scanf("%d%d%d",&i,&x,&y)!=EOF){
        if(x==1){
        ccc3[i]+=1;
        if(y)
        ccc1[i]+=x;
        }
        else if((x==2||x==3)){
        ccc2[i]+=1;
        if(y)
        ccc1[i]+=x;
        }
    }
    for(int j=0;j<m;j++){
        if(ccc2[j]+ccc3[j]==0)
        printf("NULL\n");
        else{
        ts[j]=((ccc1[j])/2.00/(1.00*ccc2[j]+0.44*ccc3[j]))*100.00;
        printf("%.2f%%\n",ts[j]);
        }
        
    }

    return 0;
}