#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define LL long long
LL a[N][N], b[N][N], s[N][N];
int nxt[1000005];
void getnxt(string s){
    int i=0,j=-1;
    nxt[0]=-1;
    int len=s.length();
    while(i<len){
        if(s[i]==s[j]||j==-1){
            i++;
            j++;
            nxt[i]=j;
        }
        else
            j=nxt[j];
    }
}
int getnum(string s){
    int len=s.length();
    getnxt(s);
    if(len%(len-nxt[len])==0)
        return len/(len-nxt[len]);
    return 1;
}
string str;
int main(){
    while(cin >> str){
        int len = str.length();
        LL ans = 0;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(s, 0, sizeof(s));
        for(int i = 0;i < len;i++)
            for(int j = i;j < len;j++){
                a[i][j] = getnum(str.substr(i, j-i+1));
                //这里可以优化一下，使得复杂度是真正的O(N^2)
                b[i][a[i][j]]++;
            }
        for(int i = len-1;i >= 0;i--){
            for(int j = 0;j < len;j++){
                if(i == len-1) s[i][j] = b[i][j];
                else s[i][j] = s[i+1][j] + b[i][j];
            }
        }
        for(int i = 0;i < len-1;i++)
            for(int j = i;j < len-1;j++){
                int p = a[i][j];
                ans += s[j+1][p];
            }
        printf("%lld\n", ans);
    }
}


//在注册百度帐号的时候，由于帐号数量巨大，常会遇到账户名冲突的情况。如果希望设置的用户名（比如 jsk）已经被占用，那么就会将初始的用户名重复一遍（此时用户名为 jskjsk），再检查 jskjsk 是否被占用，如果被占用则会再重复一遍初始的用户名（即为 jskjskjsk），直到没有冲突为止。
//每个用户名都有一个幸运值
//PP
//P，对应用户名的最大冲突次数。现在想从一长串字符中选出两个不相交的子串分别用作用户名，并且希望两个用户名的幸运值相等。请计算一共有多少种符合要求的选取方案。注意，在原串中位置不同但值相等的字符串被认为是不同的字符串，并且每个方案中两个用户名没有先后顺序。
//输入格式
//输入为一行，输入一个长度为
//len(len≥1)len(len \geq 1)
//len(len≥1) 的只包含小写字母a-z的字符串
//SS
//S。
//对于简单版本：
//len≤50len \leq 50
//len≤50；
//对于中等版本：
//len≤1000len \leq 1000
//len≤1000；
//对于困难版本：
//len≤100000len \leq 100000
//len≤100000。
//输出格式
//输出一行，输出一个整数，表示可从串
//SS
//S 中选出多少对幸运值相同的不相交子串。
//样例输入1
//aaaa
//样例输出1
//7
//样例输入2
//abcd
//样例输出2
//15
