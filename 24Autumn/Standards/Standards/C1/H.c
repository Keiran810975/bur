#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long ans = 0, kk;
long long arr[100005], tmp[100005];

void merge_sort(long long arr[], long long l, long long r){
	if (l >= r)  return;      //如果只有一个数字或没有数字，则无需排序
	long long mid = (l + r) / 2;
	merge_sort(arr, l, mid);       //分解左序列   
	merge_sort(arr, mid + 1, r);   //分解右序列  
	long long k = l, i = l, j = mid + 1, p = i;
	while (i <= mid && j <= r) //合并
	{
		while(p <= mid && arr[p] <= kk * arr[j]) p++;
		if (arr[i] > arr[j]){
			tmp[k++] = arr[j++];
			ans += mid - p + 1;
		}
		else
		{
			tmp[k++] = arr[i++];		
		}
	}
	while (i <= mid) tmp[k++] = arr[i++];   //复制左边子序列剩余
	while (j <= r) tmp[k++] = arr[j++];    //复制右边子序列剩余
	for (i = l; i <= r; i++) arr[i] = tmp[i];
}

int main(){
	long long n;
	scanf("%lld %lld", &n, &kk);
	int i = 0;
	for(i = 0; i < n; i++){
		scanf("%lld", &arr[i]);
	}
	merge_sort(arr, 0, n - 1);
	printf("%lld", ans);
	return 0;
} 
