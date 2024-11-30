#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N];
int n,k;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=i;j>=1;j--){
            if(a[i]-a[j]<=k){
                sum+=a[j];
            }else break;
        }
        ans=max(ans,sum);
    }
    cout<<ans<<"\n";
}
