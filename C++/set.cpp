#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    //set的元素不能重复，自动排序
    set<int> s;
    s.insert(1);
    s.insert(8);
    s.insert(3);
    s.insert(9);
    set<int>::iterator it;//构造迭代器
    for(it=s.begin();it!=s.end();it++)cout<<*it<<' ';
    cout<<'\n';
    set<int>::reverse_iterator it2;//反向迭代器
    for(it2=s.rbegin();it2!=s.rend();it2++)cout<<*it2<<' ';
    cout<<endl;

    set<int> f(s);//把s复制给f
    set<int> c;
    c=s;//s复制给c
    c.swap(s);//交换c和s
    c.clear();//清除c中元素
    it=s.begin();
    s.erase(it);//删除迭代器指向的元素，并把迭代器往下移
    s.erase(8);//删除指定值
    for(it=s.begin();it!=s.end();it++)cout<<*it<<' ';
    cout<<'\n';
    return 0;
}