#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class student{
    public:
    int id;
    string name;
    student(){}
    student(int id,string name){
        this->id=id; this->name=name;
    }
};
int main(){
    map<int ,student> stu;// 构造一个map存储student对象
    map<int ,string> mm;
    mm.insert(pair<int ,string>(3,"Keiran"));//3是键，keiran是值
    mm.insert(map<int ,string>::value_type(4,"Shit"));;//另一种方法
    map<int ,string>::value_type vv(1,"John");
    mm.insert(vv);//先构造valuetype
    
    mm[2]="Fff";//另一种方法

    return 0;
}