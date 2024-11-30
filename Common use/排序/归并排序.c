#include <stdio.h>
#include <stdlib.h>
// 将a[s...m]和a[m+1...e]两个有序子序列归并为有序
// 归并后的序列存放数组b中 
void merge(int a[], int s, int m, int e)
{
  int i,j,k;
  // 申请临时空间存放有序序列 
  int *b = (int *)malloc(sizeof(int)*(e-s+1));
  
  for(i=m+1,k=0,j=s; j<=m && i<=e; ++k)
  {
    if(a[j] <= a[i])
      b[k] = a[j++];
    else
      b[k] = a[i++];
  }
  while(j<=m) 
  {
    b[k] = a[j];
    k++;
    j++;
  }
  while(i<=e)
  {
    b[k] = a[i];
    k++;
    i++;
  }
  // 排序完成后，复制到原数组a
  for(i=s,k=0; i<=e; i++,k++) 
    a[i] = b[k];
  free(b);
}
// 对a[s...e]序列进行归并排序 
void msort(int a[], int s, int e)
{
  if (s<e)
  {
    // 将整个序列一分为二 
    int m = (s+e)/2;
    msort(a,s,m);
    msort(a,m+1,e);
    merge(a,s,m,e);
  }
}
void merge_sort(int a[], int length)
{
  msort(a,0,length-1);
}
int main(void)
{
    int a[10] = {4,3,1,2,6,5,0,9,8,7};
    merge_sort(a,10);
    int i;
    for(i=0; i<10; i++)
      printf("%d ", a[i]);
    return 0;
}