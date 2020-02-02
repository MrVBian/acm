#include<iostream>
#include<string>
#include<windows.h>
//#pragma GCC diagnostic error "-std=c++11"
using namespace std;

int main()
{

    string s = "asdssfghjkl";
    char a1;
    string::iterator it;
    string::const_iterator cit;
    string::size_type n;

    s.append("zxcv");  //s="asdssfghjklzxcv",参数必须为string类型 不可为char。
    s.assign("qwert"); //s="qwert"，相当于赋值操作，赋以新值 ，参数不可为char。
    a1 = s.at(0);      //a1='q' 下标操作
    a1 = s.back();     //a1='t'   返回最后一个字符
    it = s.begin();    //返回字符串起始位置的迭代器，cit = s.begin(); 正确
    a1=it[0];          //s ="qwert"， a1='q'，a=cit[0]; 正确
    it[3] = 'f';       //s ="qweft"，cit[3] = 'f';  错误

    n = s.capacity();       //s="qwert" n=15(win64 vs2013)
    /*
     给字符串分配内存的时候，并不是有多大长度分配多少的，考虑到append等操
     作，一次分配内存是比给他的字符串长度多的。这样在append的时候，就不用
     每次都分配内存了。除非append时，已分配内存不够了，会再次追加一次内存
     分配。当前已经分配的内存大小，就是capacity。字符串实际大小，就是
     size。这样做是为了提高字符串操作效率。capacity是容量，是可存放字符
     的个数。size是大小，是当前已存放字符的个数。capacity >= size， 具
     体capcacity大多少，具体的stl库实现决定。capacity是可增大的，如果当
     前size加上要加入的字符个数超过capacity，capacity就要增大，一般翻倍
     增长，具体取决于实现。
    */

    cit=s.cbegin();    //s="qweft"，返回字符串起始位置的const型迭代器
    a1 = cit[1];       // a1='w'
    /*
    1.iterator,const_iterator作用：遍历容器内的元素，并访问这些元素的
    值。iterator可以改元素值,但const_iterator不可改。跟C的指针有点像
    2.const_iterator 对象可以用于const vector 或非 const vector,它
    自身的值可以改(可以指向其他元素),但不能改写其指向的元素值. 如 cit[1]
    = 'o' 错误
    */

    cit = s.cend();   //cit = " "，返回字符串末尾的 const型迭代器
    s.clear();        //删除字符串里的所有字符

    s = "asdfg";
    int n1=s.compare("asdfg");     //n1=0  字符串比较
    int n2 = s.compare("sdfg");    //n1=-1
    int n3 = s.compare("ab");      //n1=1

    char* sdest;
    n=s.copy(sdest,1,0);    //会报unsafe的问题
    /*
    size_type copy( CharT* dest,  size_type count,  size_type
    pos = 0);
    参数:
    dest  pointer to the destination character string
    pos  position of the first character to include
    count  length of the substring
    返回值:
    copy的字符个数
    从string类型对象中至多复制count个字符到字符指针dest指向的空间中。默
    认从首字符开始，但是也可以指定，开始的位置（记住从0开始）。返回真正从对
    象中复制的字符。用户要确保p指向的空间足够保存n个字符。
    */


    string::const_reverse_iterator it2;
    it2=s.crbegin();  /*返回const翻转迭代器，将s先翻转，再取其begin。
    it2[2] = 'g';错误。it2=" "，相当于取到s的最后一个元素 ++是往s的前
    面取。*/

    a1 = it2[0];      //a1='g'
    a1 = it2[1];      //a1='f'
    it2 = s.crend();  /*返回const翻转迭代器，将s先翻转，再取其end。
    it2 = "asdfg"; char a3 = it2[0]; char a4 = it2[1]; 错误溢出。
    相当于取到s的第一个元素前一个。与cbegin cend 相反。*/

    const char* s1;
    s1=s.c_str();   /*s1="asdgf"，c_str()返回的是一个临时指针，不能
    对其进行操作，s中字符删除s1也就没了，s1是c字符串，末尾追加\0。*/
    /*
    const char* c;
    string s="1234";
    c = s.c_str();
    cout<<c<<endl; //输出：1234
    s="abcd";
    cout<<c<<endl; //输出：abcd
    c_str()返回一个客户程序可读不可改的指向字符数组的指针，不需要手动释放
    或删除这个指针。*/

    s1=s.data();  /*s1="asdfg"，与c_str()类似，但是返回的数组不以空
    字符终止。*/

    bool flag = s.empty();  //flag=false，返回bool型，为空返回true
    it=s.end();     //it=" "，返回迭代器指向s末尾。

    s.erase(2,2);   //s="asg"，从下标2开始删除2个，s = "asdfg";
    s.erase(s.begin(), s.begin() + 3);  //s="fg"，s = "asdfg";
    s.erase(4);   //s="asdf"，删除下标4的值，s = "asdfg";
    s.erase(s.begin() + 4);   //s="asdf"，删除下标4的值。
    s.erase(s.begin(), s.end());  //s=" "，s.end()是末尾元素下一个
    /*
    (1)erase(pos,n);
    删除从pos开始的n个字符，比如erase(0,1)就是删除第一个字符
    （2）erase(position);
    删除position处的一个字符(position是个string类型的迭代器)
    （3）erase(first,last);
    删除从first到last之间的字符（first和last都是迭代器）
    输入下标0，1，2...和迭代器s.begin(),s.begin()+1....A对应。
    */



    s = "asdfg";
    n = s.find("asdfg");  //n=0 查找 全匹配
    n=s.find(100);        //n=2，将100转为字符查找，d的ascii码为100
    n=s.find("dfg");      //n=4
    n = s.find("dfg");    //n=2
    n=s.find("dhh");      //n=string::npos=4294967295
    n = s.find("wer");    //n=string::npos=4294967295
    n=s.find('f');        //n=3
    n = s.find("f");      //n=3
    string as = "dfg";      //as='g'

    n = s.find_first_of("asdfg");  //n=0，查找包含子串中的任何字符， 返回第一个位置
    n = s.find_first_of(3);        //n=string::npos=4294967295
    n = s.find_first_of("dfg");    //n=4
    n = s.find_first_of("dfg");    //n=2
    n = s.find_first_of("dhh");    //n=2
    n = s.find_first_of("wer");    //n=string::npos=4294967295
    n = s.find_first_of('f');      //n=3，从pos开始查找字符第一次出现的位置
    n = s.find_first_of("f");      //n=3

    n = s.find_last_of("asdfg"); //n=4，查找包含子串中的任何字符，返回最后一个位置
    n = s.find_last_of(3);         //n=string::npos=4294967295
    n = s.find_last_of("dfg");     //n=4
    n = s.find_last_of("dfg");     //n=4
    n = s.find_last_of("dhh");     //n=2
    n = s.find_last_of("wer");     //n=string::npos=4294967295
    n = s.find_last_of('f');       //n=3
    n = s.find_last_of("f");       //n=3

    n = s.find_first_not_of("asdfg");//n=string::npos=4294967295，查找不包含子串中的任何字符，返回第一个位置。从当前串中查找第一个不在参数串中的字符出现的位置
    n=s.find_first_not_of(3);      //n=0
    n=s.find_first_not_of("dfg");  //n=0
    n = s.find_first_not_of("dfg");//n=0
    n=s.find_first_not_of("dhh");  //n=0
    n = s.find_first_not_of("wer");//n=0
    n=s.find_first_not_of('f');    //n=0
    n = s.find_first_not_of("f");  //n=0

    n = s.find_last_not_of("asdfg");//n=string::npos=4294967295，查找不包含子串中的任何字符，返回最后一个位置
    n=s.find_last_not_of(3);          //n=4
    n=s.find_last_not_of("dfg");      //n=3
    n = s.find_last_not_of("dfg");    //n=1
    n=s.find_last_not_of("dhh");      //n=4
    n = s.find_last_not_of("wer");    //n=4
    n=s.find_last_not_of('f');        //n=4
    n = s.find_last_not_of("f");      //n=4

    n = s.rfind("asdfg");  //n=0，反向查找，从pos开始从后向前查找字符c在当前串中的位置
    n=s.rfind(3);          //n=string::npos=4294967295
    n=s.rfind("dfg");      //n=4
    n = s.rfind("dfg");    //n=2
    n=s.rfind("dhh");      //n=string::npos=4294967295
    n = s.rfind("wer");    //n=string::npos=4294967295
    n=s.rfind('f');        //n=3
    n = s.rfind("f");      //n=3

    /*以上查找函数都被重载了4次：
    size_type find(const basic_string& s, size_type pos = 0)
     //从pos开始查找字符串s在当前串中的位置
    size_type find(const charT* s, size_type pos, size_type n)
     //从pos开始查找字符串s中前n个字符在当前串中的位置
    size_type find(const charT* s, size_type pos = 0)
     //从pos开始查找字符串s在当前串中的位置
    size_type find(charT c, size_type pos = 0)
     //从pos开始查找字符c在当前字符串的位置
    所有的查找函数都返回一个size_type类型，这个返回值一般都是所找到字符串
    的位置，如果没有找到，则返回string::npos。
    有一点需要特别注意，所有和string::npos的比较一定要用
    string::size_type来使用，不要直接使用int 或者unsigned int等类
    型。其实string::npos表示的是-1。
    */


    a1=s.front();//a1='a'，返回首字符，返回值为char/const char，不是string或迭代器
    string::allocator_type aa=s.get_allocator();  //返回本字符串的配置器

    s.insert(2,"z");              //s="aszdfg"
    s.insert(2, "qwegt", 3);      //s="asqwezdfg"。
    /*const string a1 = "zxc";  s.insert(2,a1);  //错误*/
    s.insert(2, "zxcv", 2, 2);    //s="ascvqwezdfg"
    /*
    string &insert(int p0, const char *s);
    string &insert(int p0, const char *s, int n);
    string &insert(int p0, const string &s);
    string &insert(int p0, const string &s, int pos, int n);
    //前4个函数在p0位置插入字符串s中pos开始的前n个字符

    string &insert(int p0, int n, char c);
    //此函数在p0处插入n个字符c
    iterator insert(iterator it, char c);
    //在it处插入字符c，返回插入后迭代器的位置
    void insert(iterator it, const_iterator first, const_iterator last);
    //在it处插入[first，last）之间的字符
    void insert(iterator it, int n, char c);
    //在it处插入n个字符c
    */


    n = s.length();    //n=11,s="ascvqwezdfg",返回字符串长度。
    n = s.max_size();  //s="ascvqwezdfg",n=4294967294,返回值是string所支持最大长度，一般也不会用到这么长的字符串。
    n=s.npos;  //n=4294967295

    string s11 = "qwe";
    string s22 = "asd";
    string ss = s11 + s22;    //ss=""qweasd""
    ss += "dfr";              //ss=""qweasddfr""
    //s11+=s22;               //错误
    //s11 = s22;              //错误   string 不能到const char*
    a1 = s[3];                //a1='v'

    s.pop_back();             //s="ascvqwezdf",删除最后一位

    a1 = 'm';
    s.push_back(a1);  //s=""ascvqwezdfm""    参数为char型


    string::reverse_iterator rit;
    string::const_reverse_iterator crit;

    rit=s.rbegin(); //s="ascvqwezdfm"，末尾为start，开始为end，迭代器从后往前递增
    a1=rit[3];      //s="ascvqwezdfm"  a1='z'
    rit[3] = 'n';   //rit=""  s="ascvqwendfm"    从后往前下标为三的变成了n
    crit = s.rbegin();  //crit=""   s="ascvqwendfm"
    a1 = crit[4];       //a1='e'    s="ascvqwendfm"
    //crit[3] = 'n';    //错误 不能改变const迭代器指向的值


    rit = s.rend();     //s="ascvqwendfm"   末尾为start  开始为end   rit=""
    //a1 = rit[3];      //报错 溢出
    // rit[3] = 'n';    //报错 溢出
    crit = s.rend();    //crit=""   s="ascvqwendfm"
    //a1 = crit[4];     //报错 溢出
    //crit[3] = 'n';    //错误 不能改变const迭代器指向的值

    string s33 = "mnbvcx";      //s="ascvqwendfm"
    const char * s44= "asdfg";  //s="ascvqwendfm"
    s.replace(2,3,s33); //s="asmnbvcxwendfm"，替换原字符串下标2开始长度3的字符
    s.replace(2, 3, s44);       //s="asasdfgvcxwendfm"
    s.replace(s.begin()+2,s.end()-2, s33);     //s="asmnbvcxfm"
    s.replace(s.begin() + 2, s.end() - 2, s44);//s="asasdfgfm"
    s.replace(2, 3, s33, 2, 3);    //s="asbvcfgfm"
    s.replace(2, 3, s44, 2, 3);    // s="asdfgfgfm"
    s.replace(2, 3, s44, 2);       // s="asasfgfm"
    s.replace(s.begin() + 2, s.end() - 2, s44,4);  //s="asasdffm"
    s.replace(2, 3, 4, 'c'); //s="asccccffm"
    s.replace(s.begin() + 2, s.end() - 2, 4, 'f');  //s="asfffffm"
    /*
    用法一：
      用str替换指定字符串从起始位置pos开始长度为len的字符
      string& replace (size_t pos, size_t len, const string&
      str);

    用法二：
      用str替换 迭代器起始位置 和 结束位置 的字符
      string& replace (const_iterator i1, const_iterator i2,
      const string& str);

    用法三：
      用substr的指定子串（给定起始位置和长度）替换从指定位置上的字符串
      string& replace (size_t pos, size_t len, const string&
      str, size_t subpos, size_t sublen);

    用法四：
      string转char*时编译器可能会报出警告，不建议这样做，用str替换从指定
      位置0开始长度为5的字符串。
      string& replace(size_t pos, size_t len, const char* s);

    用法五：
      string转char*时编译器可能会报出警告，不建议这样做，用str替换从指定
      迭代器位置的字符串
      string& replace (const_iterator i1, const_iterator i2,
      const char* s);

    用法六：
      string转char*时编译器可能会报出警告，不建议这样做，用s的前n个字符
      替换从开始位置pos长度为len的字符串
      string& replace(size_t pos, size_t len, const char* s,
      size_t n);

    用法七：
      string转char*时编译器可能会报出警告，不建议这样做，用s的前n个字符
      替换指定迭代器位置(从i1到i2)的字符串
      string& replace (const_iterator i1, const_iterator i2,
      const char* s, size_t n);

    用法八：
      用重复n次的c字符替换从指定位置pos长度为len的内容
      string& replace (size_t pos, size_t len, size_t n, char
      c);

    用法九：
      用重复n次的c字符替换从指定迭代器位置（从i1开始到结束）的内容
      string& replace (const_iterator i1, const_iterator i2,
      size_t n, char c);
   */


    n = s.size();     //n=8   s="asfffffm"
    s.reserve(2);  //指定 容器 能存储数据的个数
    s.resize(3);    //重新 指定 有效元素的个数 s="asf"
    n=s.size();     //n=3
    /*
    size() 指目前存在的元素数。            元素个数
    capacity() 指容器能存储 数据的个数      容器容量
    reserve()  指定容器能存储数据的个数
    resize()   重新指定有效元素的个数 ，区别于reserve()指定容量的大小
    当创建空容器时，容量(capacity)为 0;当用完时，增加原容量的 1/2 （各
    编译器 可能存在差异  vs2010是这样的，mingw则 增加原容量 ）--适用如
    vector这种 元素连续存储的容器， 如为list则不同。capacity 一般大于
    size的原因是为了避免 每次增加数据时都要重新分配内存，所以一般会 生成一
    个较大的空间，以便随后的数据插入。
    */

    s = "asdfgh";
    n=s.rfind("sdf",2);         //n=1
    n = s.rfind("serr");        //n=4294967295
    n = s.rfind("serr",2);      //n=4294967295
    n = s.rfind("serr", 2);     //n=4294967295
    n = s.rfind('s', 2);        //n=1
    n = s.rfind('s');           //n=1
    n = s.rfind("serr", 2,3);   //n=4294967295
    n = s.rfind("sdf", 2,2);    //n=1

    /*
    rfind全名reversefind,与find相。

    size_type rfind( const basic_string &str, size_type index
    );
    //返回最后一个与str中的某个字符匹配的字符，从index开始查找。如果没找
    到就返回string::npos。

    size_type rfind( const char *str, size_type index );
    //返回最后一个与str中的某个字符匹配的字符，从index开始查找。如果没找
    到就返回string::npos。

    size_type rfind( char ch, size_type index );
    //返回最后一个与ch匹配的字符，从index开始查找。如果没找到就返回
    string::npos。

    这里要注意与find不同的地方，rfind是从左往右数index个位置，这里作为基
    准index，然后从这里开始，从右往左数到第一次出现目标的位置。
    find是在基准index从左往右数。
    */


    s.shrink_to_fit();  //无返回值
    /*
    erase 改变了size，但并没有改变capacity，并未真正释放空间
    clear后 size==0，capacity不变，并未真正释放空间。
    vector<int>(vec).swap(vec) 使得vec的capacity()==size()，真正
    释放了空间。
    C++11中已经实现了shink_to_fit函数 替代swap，调用该请求可能会引起一
    次内存重分配，但不会对size产生影响，使得capacity()==size()。
    */



    ss = s.substr(3);    //s="asdfgh"，ss="fgh"，从s的下标3 的位置开始取到末尾
    ss = s.substr(3,4);  //ss="fgh"
    ss = s.substr(1, 4); //ss="sdfg"  从下标1开始取4个
    /*
    basic_string substr( size_type index, size_type num = npos
    );下标非迭代器
    substr()返回本字符串的一个子串，从index开始，长num个字符。
    如果没有指定，将是默认值 string::npos。这样，substr()函数将简单的返
    回从index开始的剩余的字符串。
    */

    s.swap(s);  //s="asdfgh"   用来交换两个string的值 无返回值
    s.swap(ss); //s="sdfg"   ss="asdfgh"
    system("pause");
}
