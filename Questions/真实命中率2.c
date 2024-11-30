#include<stdio.h>

int main()
{
    int m;
    int i,x,y;
    scanf("%d",&m);
    int ccc1[12]={0},ccc2[12]={0},ccc3[12]={0};
    double ts[m];
    while(scanf("%d%d%d",&i,&x,&y)!=EOF)
    {
        if(y==1) 
        ccc1[i-1]+=x;
        if(x!=1) 
        ccc2[i-1]++;
        else 
        ccc3[i-1]++;
    }
    for(int j=0;j<m;j++)
    {
        if(ccc2[j]+ccc3[j]==0) 
        printf("NULL\n");
        else
        {
            ts[j]=ccc1[j]/(2.00*(1.00*ccc2[j]+0.44*ccc3[j]))*100.00;
            printf("%.2f%%\n",ts[j]);
        }
    }
}