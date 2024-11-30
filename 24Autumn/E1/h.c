#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        int a[n];
        int flag[k+1];
        int cnt=0;
        int sig=0;
        memset(flag,0,sizeof(flag));
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int l=0,r;
        int minLength=n+10;
        int ansL,ansR;
        for(r=0;r<n;r++){
            flag[a[r]]+=1;
            if(flag[a[r]]==1){
                cnt++;
            }
            while(cnt==k){
                if(r-l+1<minLength){
                    minLength=r-l+1;
                    ansL=l;
                    ansR=r;
                    sig=1;
                }
                flag[a[l]]-=1;
                if(flag[a[l]]==0){
                    cnt--;
                }
                l++;
            }
        }
        if(sig==1){
            printf("%d %d\n",ansL+1,ansR+1);
        }else{
            printf("N0\n");
        }
    }
    return 0;
}