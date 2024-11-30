#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int power(int k){
    int ans=1;
    for(int i=1;i<=k;i++){
        ans*=3;
    }
    return ans;
}
void magic(int k,int x,int y){
    if(k==0){
        printf("#");
        return;
    }
    int p=power(k-1);
    if(x>p&&x<=2*p&&y>p&&y<=2*p){
        printf(".");
        return;
    }
    else if(x<=p&&y<=p)magic(k-1,x,y);
    else if(x<=p&&y>p&&y<=2*p)magic(k-1,x,y-p);
    else if(x<=p&&y>2*p)magic(k-1,x,y-2*p);
    else if(x>p&&x<=2*p&&y<=p)magic(k-1,x-p,y);
    else if(x>p&&x<=2*p&&y>p&&y<=2*p)magic(k-1,x-p,y-p);
    else if(x>p&&x<=2*p&&y>2*p)magic(k-1,x-p,y-2*p);
    else if(x>2*p&&y<=p)magic(k-1,x-2*p,y);
    else if(x>2*p&&y>p&&y<=2*p)magic(k-1,x-2*p,y-p);
    else if(x>2*p&&y>2*p)magic(k-1,x-2*p,y-2*p);
    


}
int main(){
    int k;
    scanf("%d",&k);
    int p=power(k);
    for(int i=1;i<=p;i++){
        for(int j=1;j<=p;j++){
            magic(k,i,j);
        }
        printf("\n");
    }
    return 0;
}