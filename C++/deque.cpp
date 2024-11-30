#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<deque>
using namespace std;
int main(){
    //双端队列
   //deque和vector操作基本一样,多两个函数
   //deque.push_front();
   //deque.pop_front();
   deque<int> a={1,2,3,4};
   a.push_front(114);
   deque<int>::iterator it;
   for(it=a.begin();it!=a.end();it++)cout<<*it<<" ";
   cout<<endl;
   a.pop_front();
   for(it=a.begin();it!=a.end();it++)cout<<*it<<" ";
   cout<<endl;
    return 0;
}