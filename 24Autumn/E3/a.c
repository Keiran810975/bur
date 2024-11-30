    #include<stdio.h>
    #include<math.h>
    #include<string.h>
    #include<ctype.h>
    #include<stdlib.h>
    #include<stdbool.h>
    int cmp(const void *a,const void *b){
        return *(int*)a-*(int*)b;
    }
    int a[100006];
    int main(){
        int t;
        scanf("%d",&t);
        while(t--){
            int n,m;
            scanf("%d%d",&n,&m);
            for(int i=0;i<n;i++){
                scanf("%d",&a[i]);
            }
            qsort(a,n,sizeof(int),cmp);
            int cnt=0;
            int l=0,r=n-1;
            while(1){
                if(l>r)break;
                if(l==r){
                    cnt++;
                    break;
                }
                if(a[l]+a[r]<=m){
                    cnt++;
                    l++;
                    r--;
                }else{
                    cnt++;
                    r--;
                }
            }
            printf("%d\n",cnt);
        }
        return 0;
    }