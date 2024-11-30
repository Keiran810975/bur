#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
void pr(vector<int>a){   //vector作为函数参数
    for(int i=0;i<a.size();i++)cout<<a[i]<<" ";
    cout<<endl;
}
int main(){
    vector<int> sss;//定义vector
    int aaa[]={1,2,3,4,5};
    vector<int> v1(aaa,aaa+5);//(数组首地址,数组尾地址+1)即将[aaa,aaa+5)传到v1里
    vector<int> v2(3,10);//存储3个10
    for(int i=0;i<3;i++)cout<<v2[i]<<" ";
    cout<<endl;//换行符
    vector<int> v3(v1);//v1copy至v3
    vector<int> v4=v1;//这样也行

    vector<int> a,b,c,d;
    a.assign(aaa,aaa+5);//把aaa赋值给vector a
    pr(a);

    b.assign(a.begin(),a.end());//传a的首地址，和尾地址的下一个
    c.assign(4,9);//4个9
    b.swap(c);//交换b，c
    pr(b);
    a.empty();//判断a是否为空，空返回0

    a.resize(10);//把a的size变成10，空元素默认是0
    pr(a);

    a.resize(3);
    pr(a);

    a.resize(10,7);//a的size变成10，空位赋值为7
    pr(a);
    for(int i=0;i<a.size();i++)cout<<a.at(i)<<" ";//vector.at()和vector[]一样，但越界会报错
    cout<<endl;

    a.push_back(555);//在末尾插入元素
    pr(a);
    a.pop_back();//末尾删除
    pr(a);
    a.insert(a.begin()+3,114);//在地址3处插入一个114
    pr(a);
    a.insert(a.begin()+5,3,19);//插入3个19
    pr(a);
    a.insert(a.begin()+2,b.begin(),b.end());
    pr(a);

    //迭代器
    vector<int>::iterator it;
    it=a.begin();
    for(it=a.begin();it!=a.end();it++)cout<<*it<<" ";
    cout<<endl;
    return 0;
}