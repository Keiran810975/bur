    #include<iostream>
    #include<bits/stdc++.h>
    using namespace std;
    const int mod=998244353;
    int n,k;
    int m;
    bool aa[1000010];
    int ca[1000010][2];
    //flag代表是否选择第k关 
    int dfs(int i,int flag){
        if(i==1){
            if(aa[1])return k-1;
            return k;
        }
        if(ca[i][flag]!=-1)return ca[i][flag];
        if(aa[i]){
            if(k==1){
                ca[i][flag]=0;
            }
            else if(!flag)ca[i][flag]=(dfs(i-1,0)*(k-2)+dfs(i-1,1)*(k-1))%mod;
            else{
                ca[i][flag]=0;
            }
        }else{
            if(k==1){
                ca[i][flag]=0;
            }
            else if(!flag)ca[i][flag]=(dfs(i-1,0)*(k-2)+dfs(i-1,1)*(k-1))%mod;
            else{
                ca[i][flag]=dfs(i-1,0)%mod;
            }
        }
        return ca[i][flag];
    }
    int main(){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=m;i++){
            int x;
            scanf("%d",&x);
            aa[x]=true;
        }
        memset(ca,-1,sizeof(ca));
        int res;
        res=(dfs(n,0)+dfs(n,1))%mod;
        printf("%d\n",res);
        return 0;
    }