#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int m,a,ccc=0;
        scanf("%d",&m);
        for(int j=0;j<m;j++){
            scanf("%d",&a);
            ccc^=a;
        }
        if(ccc==0)
        printf("Congratulations!\n");
        else
        printf("Single Dog! %d\n",ccc);
    }
    return 0;
}