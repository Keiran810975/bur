#include <iostream>
using namespace std;

//m:元素总个数
//set[]:原集合
//subset[]:子集
//index:数组索引
//subsetSize:子集大小

int xor_sum=0;
void generateSubset(int m,int set[],int subset[],int index,int subsetSize){
    if(index==m){
        int value=0;
        for (int i=0;i<subsetSize;++i){
            value+=(i+1)*subset[i];
        }
        xor_sum ^= value;
        return;
    }

    generateSubset(m,set,subset,index+1,subsetSize);

    subset[subsetSize]=set[index];
    generateSubset(m,set,subset,index+1,subsetSize+1);
}

int main(){
    int n=0;
    cin>>n;
    if(n>20) return 1;
    int a[30];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    int b[100000];
    generateSubset(n,a,b,0,0);
    cout<<xor_sum<<endl;
    return 0;
}