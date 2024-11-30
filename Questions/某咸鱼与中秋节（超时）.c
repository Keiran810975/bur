#include<stdio.h>
int a[1000001];
int main(){
    int n,l;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int m;
        scanf("%d%d",&m,&a[0]);
        int ccc=a[0];
        for(int j=1;j<m;j++){
            scanf("%d",&a[j]);
            ccc^=a[j];
        }
        if(ccc==0)
        printf("Congratulations!\n");
        else{
            for(l=0;l<m;l++){
                if(a[l]==ccc)
                break;
            }
            printf("Single Dog! %d\n",l+1);
        }

    }
    return 0;
}