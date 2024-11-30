#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<int>q1;//容器类型可以省略
    queue<int,list<int>>q2;//用list实现queue
    queue<int,deque<int>>q3;//用deque实现queue
    //不能用vector
    q1.push(1);//在队尾插入元素
    q1.push(2);
    q1.push(3);
    q1.pop();//pop出队头的元素
    cout<<q1.front()<<endl;//第一个元素
    cout<<q1.back()<<endl;//最后一个元素
    cout<<q1.size()<<endl;//返回队列中元素个数
    cout<<q1.empty()<<endl;//若队列空则返回true

    return 0;
}