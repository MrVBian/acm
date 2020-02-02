#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main ()
{
    int a[] = {1,2,3,5,6};
    vector<int> v(a, a + sizeof(a)/sizeof(a[0]));

    //make_heap(v.begin(),v.end(),less<int>());
    //make_heap(v.begin(),v.end(),greater<int>());
    make_heap(v.begin(),v.end());
    cout << "initial max of heap   : " << v.front() << endl;

    pop_heap(v.begin(),v.end()); v.pop_back();
    cout << "max of heap after pop : " << v.front() << endl;

    v.push_back(7); push_heap(v.begin(),v.end());
    cout << "max of heap after push: " << v.front() << endl;

    sort_heap (v.begin(),v.end());

    cout << "sorted range :";
    for (unsigned i=0; i<v.size(); i++)
        cout << " " << v[i];
    return 0;
}

//#include <iostream>
//#include <queue>
//using namespace std;
//int main(){
//    priority_queue<int,vector<int>,less<int> >q;//使用priority_queue<int> q1;一样
//    for(int i=0;i<10;i++)
//		q1.push(i);
//    while(!q1.empty()){
//        cout<<q1.top()<< endl;
//        q1.pop();
//    }
//    return 0;
//}


//#include <iostream>
//#include <queue>
//using namespace std;
//int main(){
//    priority_queue<int,vector<int>,greater<int> >q;
//    for(int i=0;i<10;i++)
//		q.push(i);
//    while(!q.empty()){
//        cout<<q.top()<< endl;
//        q.pop();
//    }
//    return 0;
//}



//
//#include<queue>
//#include<iostream>
//#include<functional>
//#include<cmath>
//#include<cstdio>
//using namespace std;
//struct cmp{
//    bool operator()(int a,int b){
//        return a>b;  //想让其从小到大输出,return >
//    }
//};
//
//struct point{
//    int x,y;
//    void show(){
//        printf("(%d,%d)\n",x,y);
//    }
//};
//
//struct cmp2{
//    bool operator()(point a,point b){
//        return (abs(a.x)+abs(a.y))<(abs(b.x)+abs(b.y));
//    }
//};
//
//int main(){ //优先队列默认按照从大到小的顺序排列输出
//    freopen("cout.txt","w",stdout);
//    int a[5]={3,5,2,1,7};
//	priority_queue<int> v;
//    for( int i = 0; i < 5; i++ ) {
//       v.push(a[i]);
//    }
//    cout<<"v.size:"<<v.size()<<endl;
//    while( !v.empty() ) {
//       cout << v.top() << endl;
//       v.pop();
//    }
//    cout<<"v.size:"<<v.size()<<endl;
//    priority_queue<int,vector<int>,greater<int> > v2;
//    //priority_queue<int,vector<int>,less<int> > v; //less 降序 ,greater 升序
//
//    for( int i = 0; i < 5; i++ ) {
//       v2.push(a[i]);
//    }
//    cout<<"v2 从小到大输出：\n";
//    while( !v2.empty() ) {
//       cout << v2.top() << endl;
//       v2.pop();
//    }
//    priority_queue<int,vector<int>,cmp> v3;
//    for( int i = 0; i < 5; i++ ) {
//       v3.push(a[i]);
//    }
//    cout<<"自定义比较的V3输出:\n";
//     while( !v3.empty() ) {
//       cout << v3.top() << endl;
//       v3.pop();
//    }
//    cout<<"点输出优先级：与原点的曼哈顿距离。\n";
//    point p[5]={{0,9},{12,0},{3,4},{6,5},{3,7}};
//    priority_queue<point,vector<point>,cmp2> que;
//    //priority_queue<point> que; 复杂的类型需要写出专门的比较类(上面的cmp2)。
//    for(int i=0;i<5;i++)que.push(p[i]);
//     while( !que.empty() ) {
//       point tmp=que.top();
//       tmp.show();
//       que.pop();
//    }
//    return 0;
//}
