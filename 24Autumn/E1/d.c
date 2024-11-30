#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int a[n];
        int min1 = 1000000005, min2 = 1000000005;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), cmp);
        min1=a[0];
        for(int i=1;i<n;i++){
            if(a[i]%min1!=0){
                min2=a[i];
                break;
            }
        }
        //printf("%d %d\n", min1, min2);
        //if(min2==1000000005)min2=min1;
        int sig = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % min1 != 0 && a[i] % min2 != 0) {
                sig = 1;
                break;
            }
        }
        
        

        if (sig == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
