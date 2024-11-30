#include<iostream>
#include<bits/stdc++.h>
using namespace std;
char s[5005];
int t;
int l;
int ca[5005][5005];
int dfs(int i,int j){
    if(i>=j)return 0;
    if(ca[i][j]!=-1)return ca[i][j];
    if(s[i]==s[j]){
        int b=dfs(i+1,j-1);
        ca[i][j]=b;
        return b;   
    }
    int b=min(dfs(i+1,j),dfs(i,j-1))+1;
    ca[i][j]=b;
    return b;
}

int f[5100][5100];
void dp(){
    //memset(f,0,sizeof(f));
    for (int len = 2; len <= l; len++) {  
            for (int i = 0; i + len - 1 < l; i++) {
                int j = i + len - 1; 
                if (s[i] == s[j]) {
                    f[i][j] = f[i+1][j-1];  
                } else {
                    f[i][j] = min(f[i+1][j], f[i][j-1]) + 1; 
                }
            }
        }
    printf("%d\n",f[0][l-1]+l);
}
int main(){
    cin>>t;
    while(t--){
        //memset(ca,-1,sizeof(ca));
        scanf("%d%s",&l,s);
        // int res=dfs(0,l-1);
        // printf("%d\n",res+l);
        dp();
    }
    
    return 0;
}