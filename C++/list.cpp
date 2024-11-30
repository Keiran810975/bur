#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<deque>
#include<list>
using namespace std;
int main(){
   list<int> a;
   //头尾操作
   a.push_front(1);
   a.pop_front();
   a.push_back(2);
   a.pop_back();
   a.push_front(114);
   a.push_back(1919810);
   int s=a.front();//返回第一个结点
   int f=a.back();//最后一个
   cout<<s<<endl;
   a.front()=111;
   a.back()=222;//赋值
    return 0;
}