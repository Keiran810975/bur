#include<iostream>
#include<bits/stdc++.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
int arr[1500];
int n;
int bitReverse(int num, int logN) {
    int reversed = 0;
    for (int i = 0; i < logN; ++i) {
        reversed = (reversed << 1) | (num & 1);
        num >>= 1;
    }
    return reversed;
}
int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int logN=log2(n);
    for (int i = 0; i < n; i++) {
        int rev = bitReverse(arr[i], logN);
        printf("%d ", rev);
    }
    printf("\n");

    return 0;
}
