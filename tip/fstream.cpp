#include<iostream>
#include<fstream>
#include<sstream>

//ios::in         打开一个可读取文件
//ios::out        打开一个可写入文件
//ios::app        你写入的所有数据将被追加到文件的末尾，此方式使用ios::out
//ios::ate        你写入的所有数据将被追加到文件的末尾，此方式不使用ios::out
//ios::trunk      删除文件原来已存在的内容（清空文件）
//ios::nocreate   如果要打开的文件并不存在，那么以此参数调用open()函数将无法进行。
//ios::noreplace  如果要打开的文件已存在，试图用open()函数打开时将返回一个错误。
//ios::binary     以二进制的形式打开一个文件。

using namespace std;

//int main()
//{
//    ios::sync_with_stdio(false);
//    ifstream in("./test.txt");
//    string s;
//    int a[100];
//    int k=0;;
//    while(getline(in,s)){
//        stringstream stream(s);
//        while(stream>>a[k++])
//            ;
//        k--;
//    }
//    for(int i=0;i<k;i++)
//        cout<<a[i]<<' ';
//    ofstream out("./test.txt",ios::app);
//    out<<"\n你好\n";
//    in.close();
//    out.close();
//}

//ios::beg —— 可将它移动到文件首端
//ios::end —— 可将它移动到文件末端
//
//或者，你可以设定向前或向后跳转的字符数。例如，如果你要向定位到当前位置的5个字符以前，你应当写：
//File.seekg(-5);
//如果你想向后跳过40个字符，则应当写：
//File.seekg(40);
//同时，我必须指出，函数seekg()是被重载的，它也可以带两个参数。另一个版本是这样子的：
//File.seekg(-5,ios::end);


//  ios::beg： 文件开头
//  ios::cur： 文件当前位置
//  ios::end： 文件结尾
//  这两个函数一般用于二进制文件，因为文本文件会因为系统对字符的解释而可能与预想的值不同。
//  例：
//  file1.seekg(1234,ios::cur);//把文件的读指针从当前位置向后移1234个字节
//  file2.seekp(1234,ios::beg);//把文件的写指针从文件开头向后移1234个字节


int main()
{
    ifstream in("test.txt");
    if(!in.is_open())
        cout<<"未成功过打开文件"<<endl;
    ofstream out("test.txt");
    if(in.is_open())
        cout<<"成功过打开文件"<<endl;

    //fstream file("test.txt",ios::in | ios::out);
    fstream file("test.txt",ios::in | ios::app);
    file<<"Helloworld!";

    string s;
    file.seekg(ios::beg);
    file>>s;
    cout<<s;

    cout<<endl;
    file.seekg(4);
    file>>s;
    cout<<s;
    cout<<endl<<"顺序读：";
    file>>s;
    cout<<s;

    cout<<endl;
    file.seekg(ios::end);
    if(!file.eof())
        cout<<"未到文件末尾"<<endl;
    else
        cout<<"到达文件末尾"<<endl;

    in.close();
    out.close();
    file.close();


//    ofstream out("test.txt");
//    fstream File("test.txt",ios::in | ios::out);
//
//    File << "Hi!"; //将“Hi!”写入文件
//    static char str[10]; //当使用static时，数组会自动被初始化
//               //即是被清空为零
//
//
//    File.seekg(ios::beg); // 回到文件首部
//                  // 此函数将在后面解释
//    File >> str;
//    cout << str << endl;
//
//    out.close();
//    File.close();
}
