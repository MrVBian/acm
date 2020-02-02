#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<cmath>
using namespace std;
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define _ref(i,a,b) for(int i=(a);i<=(b);i++)
typedef double db;
typedef long long ll;

map<string,int>a;
//×¢ÊÍµÄÊÇpair
//pair<string,int>a[13];

//pair<string ,int> init(){
//    a[1]=make_pair("cat",1);
//    return a[1];
//}

void init(){
    a.insert(make_pair("cat",1));
    a.insert(make_pair("ox",2));
    a.insert(make_pair("tiger",3));
    a.insert(make_pair("rabbit",4));
    a.insert(make_pair("dragon",5));
    a.insert(make_pair("snake",6));
    a.insert(make_pair("horse",7));
    a.insert(make_pair("sheep",8));
    a.insert(make_pair("monkey",9));
    a.insert(make_pair("rooster",10));
    a.insert(make_pair("dog",11));
    a.insert(make_pair("pig",12));
}

int main(){
    int t;
    scanf("%d",&t);
    init();
//    cout<<a[1].first<<endl;
//    cout<<a[1].second<<endl;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        if(s1.compare(s2)==0)
            cout<<12<<endl;
        else{
            if((a[s1]<a[s2]))
               cout<<a[s2]-a[s1]<<endl;
            else
                cout<<12-a[s1]+a[s2]<<endl;

        }
    }
}
