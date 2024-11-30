#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//思路：如果这一行选的元素和上一行的列号重叠了，那么就用上一行的次小路径
int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int first_min_sum = 0;
    int second_min_sum = 0;
    int first_min_index = -1;
    
    for (int i = 0; i < n; i++) {
        int cur_first_min_sum = INT_MAX;
        int cur_second_min_sum = INT_MAX;
        int cur_first_min_index = -1;
        
        for (int j = 0; j < n; j++) {
            int cur_sum = (j != first_min_index ? first_min_sum : second_min_sum) + grid[i][j];
            if (cur_sum < cur_first_min_sum) {
                cur_second_min_sum = cur_first_min_sum;
                cur_first_min_sum = cur_sum;
                cur_first_min_index = j;
            } else if (cur_sum < cur_second_min_sum) {
                cur_second_min_sum = cur_sum;
            }
        }
        first_min_sum = cur_first_min_sum;
        second_min_sum = cur_second_min_sum;
        first_min_index = cur_first_min_index;
    }
    return first_min_sum;
}

int main(){
    return 0;
}