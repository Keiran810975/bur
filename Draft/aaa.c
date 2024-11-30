#include<stdio.h>

int fuck(int m,int a[],int b[]){
    int ans=0;
    for(int i=0;i<m;i++){
        ans+=a[i]*b[i];
    }
    return ans;
}
int main(){
    int x[]={1,2,3,4,5};
    int y[]={2,3,4,5,6,7,8};
    printf("%d\n",fuck(4,x,y));

    return 0;

}