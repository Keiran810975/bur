#include<iostream>
#include<bits/stdc++.h>
using namespace std;

char s[1100];   
int f[1100][1100];

int main(){
    scanf("%s",s);
    int n=strlen(s);
    for(int l=1;l<=n-1;l++){
        for(int i=0;i+l<n;i++){
            int j=i+l;
            if(s[i]==s[j]){
                f[i][j]=f[i+1][j-1];
            }else{
                f[i][j]=min(f[i+1][j],f[i][j-1])+1;
            }
        }
    }
    printf("%d\n",f[0][n-1]);

}