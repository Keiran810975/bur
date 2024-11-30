#include <stdio.h>
#include <stdlib.h>

void findLeftGreater(int* arr, int n, int* result) {
    int* stack = (int*)malloc(n * sizeof(int)); 
    int top = -1;
    for (int i = 0; i < n; i++) {
        while (top != -1 && arr[stack[top]] <= arr[i]) {
            --top;
        }
        if (top == -1) {
            result[i] = -1;
        } else {
            result[i] = stack[top];
        }
        stack[++top] = i;
    }

    free(stack);
}

void findRightGreater(int* arr, int n, int* result) {
    int* stack = (int*)malloc(n * sizeof(int)); 
    int top = -1; 

    for (int i = n - 1; i >= 0; i--) {
        while (top != -1 && arr[stack[top]] <= arr[i]) {
            --top;
        }
        if (top == -1) {
            result[i] = -1;
        } else {
            result[i] = stack[top];
        }
        stack[++top] = i;
    }

    free(stack);
}
int arr[300010];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }

        int* leftResult = (int*)malloc(n * sizeof(int));
        int* rightResult = (int*)malloc(n * sizeof(int));

        findLeftGreater(arr, n, leftResult);
        findRightGreater(arr, n, rightResult);
        // for(int i=0;i<n;i++)printf("%d ",leftResult[i]);printf("\n");
        // for(int i=0;i<n;i++)printf("%d ",rightResult[i]);printf("\n");
        long long res=0;
        for(int i=0;i<n;i++){
            res+=i-leftResult[i]-1;
        }
        for(int i=0;i<n;i++){
            if(rightResult[i]==-1){
                res+=n-1-i;
            }else{
                res+=rightResult[i]-i-1;
            }
        }
        printf("%lld\n",res);
        free(leftResult);
        free(rightResult);
    }
    

    

    

    return 0;
}
