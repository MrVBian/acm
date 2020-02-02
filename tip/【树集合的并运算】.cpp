#include<iostream>
using namespace std;

typedef struct{
    int Data;
    int Parent;
}SetType;

int Find(SetType s[],int n,int x)
{
    int i;
    for(i=0 ; i<n && s[i].Data!=x;i++)
        if(i>=n)
            return -1;
    for(;s[i].Parent>=0;i=s[i].Parent)  ;
    return i;
}

void Union(SetType s[],int n,int x1,int x2)
{
    int Root1,Root2;
    Root1=Find(s,n,x1);
    Root2=Find(s,n,x2);
    if(Root1!=Root2){//按秩归并------比规模
        if(s[Root2].Parent<s[Root1].Parent){
            s[Root2].Parent+=s[Root1].Parent;
            s[Root1].Parent=Root2;
        }
        else{
            s[Root1].Parent+=s[Root2].Parent;
            s[Root2].Parent=Root1;
        }
    }
}

void Create(SetType s[])
{
    int i=0;
    int n,m,k,Par;//n集合数  m元素数  k元素
    cout<<"请输入集合个数：";
    cin>>n;
    while(n--){
        int Tap=1;
        cout<<"请输入该集合元素个数：";
        cin>>m;
        cout<<"请输入元素的值：";
        while(m--){
            cin>>k;
            s[i].Data=k;
            if(Tap){
                Tap=0;
                Par=i;
                s[i++].Parent=-(m+1);
                continue;
            }
            s[i++].Parent=Par;
        }
    }
}

void Traversal(SetType s[],int n)
{
    for(int i=0;i<n;i++)
        cout<<"下标："<<i<<"  Data："<<s[i].Data<<"  Parent:"<<s[i].Parent<<endl;
}

int main()
{
    cout<<"创建集合"<<endl;
    SetType s[10];
    Create(s);
    Traversal(s,10);
    cout<<"合并两个元素对应的集合，请输入两个元素：";
    int m,n;
    cin>>m>>n;
    Union(s,10,m,n);
    Traversal(s,10);
}
