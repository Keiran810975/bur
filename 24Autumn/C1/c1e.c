#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
//x的n次幂
int power(int x,int n){
    int ans=1;
    for(int i=0;i<n;i++){
        ans=(ans*x)%10007;
    }
    return ans;
}
int multi(int n,int a[],int x){
    int ans=a[0]%10007;
    int fff=1;
    for(int i=1;i<=n;i++){
        fff=(fff*x)%10007;
        ans=(ans+(a[i]%10007)*(fff)%10007)%10007;
    }
    return ans;
}
int a[30005],b[30005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int m;
    scanf("%d",&m);
    for(int i=0;i<=m;i++){
        scanf("%d",&b[i]);
    }
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",(multi(n,a,x)*multi(m,b,y))%10007);
    }
    return 0;
}