#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int cmp(const void *p,const void *q){
    if(*(int *)p<*(int *)q)return -1;
    if(*(int *)p>*(int *)q)return 1;
    return 0;
}
int main(){
    qsort(//数组名，个数，sizeof（），cmp//)
    return 0;
}