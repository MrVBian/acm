#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<windows.h>

#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define _ref(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

int main()
{
//empty() 堆栈为空则返回真
//pop() 移除栈顶元素
//push() 在栈顶增加元素
//size() 返回栈中元素数目
//top() 返回栈顶元素
//clear() 清空当前的vector

    stack<int> s;
    _for(i,0,10)
        s.push(i);

    if(!s.empty())
        cout<<"栈s不是空的"<<endl;
    cout<<"栈s中元素的个数为："<<s.size()<<endl;
    while(!s.empty()){
        cout<<" "<<s.top();
        s.pop();
    }
    cout<<endl;
    if(s.empty())
        cout<<"栈s现在为空"<<endl;

    system("pause");

//empty() 判断队列是否为空，返回类型为bool
//size() 返回队列中元素的个数
//front() 返回队列队首元素
//back() 返回队列队尾元素
//push(ele) 将元素ele插入到队尾
//pop 队首元素出队

    queue<int> q;
    _for(i,0,10)
        q.push(i);
    if(!q.empty())
        cout<<"队列不是空的"<<endl;
    cout<<"队列q的长度为："<<q.size()<<endl;
    cout<<"队列q的最后一个元素："<<q.back()<<endl;
    _for(i,0,10){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    if(q.empty())
        cout<<"队列是空的"<<endl;

    system("pause");

//c.clear() 移除容器中所有数据。
//c.empty() 判断容器是否为空。
//c.erase(pos) 删除pos位置的数据
//c.erase(beg,end) 删除[beg,end)区间的数据
//c.front() 传回第一个数据。
//c.insert(pos,elem) 在pos位置插入一个elem拷贝
//c.pop_back() 删除最后一个数据。
//c.push_back(elem) 在尾部加入一个数据。
//c.resize(num) 重新设置该容器的大小
//c.size() 回容器中实际数据的个数。
//c.begin() 返回指向容器第一个元素的迭代器
//c.end() 返回指向容器最后一个元素的迭代器

    vector<int> v;
    _for(i,0,10)
        v.push_back(i);
    _for(i,0,v.size())
        cout<<v[i]<<" ";
    cout<<endl;
    cout<<"使用迭代器获取数据"<<endl;
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(vector<int>::iterator it=v.begin();it!=v.end();)
        v.erase(it);
    if(v.empty())
        cout<<"向量v为空"<<endl;
    return 0;

}
