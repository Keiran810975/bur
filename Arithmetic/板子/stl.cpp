#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef struct stu{
    int id;
    int score;
};
// 自定义比较器
struct cmp {
    bool operator()(const stu& a, const stu& b) {
        return a.id > b.id; // 小根堆，id 较小的优先级高
    }
};
int main(){
    //优先队列
    priority_queue<int, vector<int>, greater<int>> pq;//小根堆
    priority_queue<int> pq2; // 大根堆
    priority_queue<stu, vector<stu>, cmp> pq3; // 自定义比较器
    pq.push(1);
    pq.pop();
    pq.size();
    pq.top();
    pq.empty();
    
    return 0;
}