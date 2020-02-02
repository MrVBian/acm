#include<bits/stdc++.h>
#include<vector>
#include<set>
#include<fstream>
#include<sstream>

#define _for(i,a,b) for(int i=a;i<b;i++)
#define _ref(i,a,b) for(int i=1;i<=b;i++)

using namespace std;

template<typename T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(int i=0;i<v.size();i++) os<<v[i]<<' ';
    return os;
}

template<typename T>
ostream& operator<<(ostream& os,const set<T>& v){
    for(typename set<T>::iterator it=v.begin();it!=v.end();it++) os<<*it<<' ';
    return os;
}

void finditemk(int *a,int n,int item)
{
    int i,j;
    i=j=0;
    int sum=a[0];
    while(i<=j&&j<n){
        if(sum>=n){
            if(sum==n)  cout<<i<<"--"<<j<<endl;
            sum-=a[i],i++;}
        else{
            j++,sum+=a[j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

///////////////////////////////////////////////////////////////////////////////////////
//ios::in         打开一个可读取文件
//ios::out        打开一个可写入文件
//ios::app        你写入的所有数据将被追加到文件的末尾，此方式使用ios::out
//ios::ate        你写入的所有数据将被追加到文件的末尾，此方式不使用ios::out
//ios::trunk      删除文件原来已存在的内容（清空文件）
//ios::nocreate   如果要打开的文件并不存在，那么以此参数调用open()函数将无法进行。
//ios::noreplace  如果要打开的文件已存在，试图用open()函数打开时将返回一个错误。
//ios::binary     以二进制的形式打开一个文件。
////////////////////////////////////////////////////////////////////////////////////////

    ifstream in("text.txt");
    string s;
    int a[100];
    int k=0;
    while(getline(in,s)){
        stringstream stream(s);
        while(stream>>a[k++])
            ;
        k--;
    }

    ofstream out("text.txt",ios::app);
    out<<"\n你好\n";
    in.close();
    out.close();
}
