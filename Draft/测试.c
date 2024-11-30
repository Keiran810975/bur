#include<stdio.h>

//这个是函数，先不执行，只有在main函数里调用了，才会运行函数里的东西
int f(int b[],int n){//b[]和n是参数
    int i,nR;
    nR=1;
    for(i=0;i<=n;i++)
        nR=nR*b[i];//循环n+1次(这里的n和b是上面的参数，在调用的时候传入)，每次循环nR都乘b[i](代表数组b的第i项)
    return nR;//返回值
}
int main(){
    int nX,a[]={2,3,4,5,6,7,8,9};
    nX=f(a,3);//这里调用了函数f，括号里的a和3就是参数，对应了b和n，因为函数返回值是nR，所以函数算出来的nR，就赋值给nX
    printf("%d\n",nX);//打印
    return 0;

}