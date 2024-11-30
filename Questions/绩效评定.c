#include<stdio.h>
int main(){
    float n;
    int s[1001];
    scanf("%f",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    int r[1001];
    r[0]=1;
    for(int j=1;j<n;j++){
        if(s[j]==s[j-1])
        r[j]=r[j-1];
        else if(s[j]<s[j-1])
        r[j]=j+1;
    }
    for(int k=0;k<n;k++){
        if(r[k]<=n*0.1)
        printf("A ");
        else if(r[k]>n*0.1&&r[k]<=n*0.25)
        printf("B ");
        else if(r[k]>n*0.25&&r[k]<=n*0.6)
        printf("C ");
        else if(r[k]>n*0.6&&r[k]<=n*0.9)
        printf("D ");
        else if(r[k]>n*0.9)
        printf("E ");
    }

    return 0;
}