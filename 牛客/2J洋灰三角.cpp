#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;

const int maxn=3;
const int maxm=3;
int n,k,p;

struct Matrix{
    int n,m;
    ll a[maxn][maxm];
    void clear(){
        n=m=0;
        memset(a,0,sizeof(a));
    }
    Matrix operator *(const Matrix &b) const{
        Matrix tmp;
        tmp.clear();
        tmp.n=n;tmp.m=b.m;
        for(int i=0;i<n;i++)
            for(int j=0;j<b.m;j++)
                for(int k=0;k<m;k++)
                    tmp.a[i][j]+=(a[i][k])*(b.a[k][j]);
        return tmp;
    }
};
//f[n] sum[n-1]  p
//
//k   1    0
//
//0   1    0
//
//1   0    1
//
//f[n+1]   sum[n]  p

int Pow(int a1,int a2){

    Matrix s;
    s.clear();
    s.n=s.m=3;
    s.a[0][0]=1;s.a[0][1]=1;s.a[0][2]=1;
    s.a[1][1]=1;s.a[2][0]=1;

    Matrix ans;
    ans.clear();
    ans.n=1;
    ans.m=3;
    ans.a[0][0]=a2;
    ans.a[0][1]=a1;
    ans.a[0][2]=a1;

    while(m){
        if(m&1)
            ans=ans*s;
        s=s*s;
        m>>=1;
    }
    return ans.a[0][1];
}

int main()
{
    cin>>n>>k>>p;
    if(n<2)
        cout<<1<<endl;
    else
        Pow(n-1);
}


链接：https://www.nowcoder.com/acm/contest/136/J
来源：牛客网

//题目描述
//    洋灰是一种建筑材料，常用来筑桥搭建高层建筑，又称，水泥、混凝土。
//    WHZ有很多铸造成三角形的洋灰块，他想把这些洋灰三角按照一定的规律放到摆成一排的n个格子里，其中第i个格子放入的洋灰三角数量是前一个格子的k倍再多p个，特殊地，第一个格子里放1个。
//    WHZ想知道把这n个格子铺满需要多少洋灰三角。
//输入描述:
//第一行有3个正整数n，k，p。
//输出描述:
//输出一行，一个正整数，表示按照要求铺满n个格子需要多少洋灰三角，由于输出数据过大，你只需要输出答案模1000000007(1e9+7)后的结果即可。
//示例1
//输入
//复制
//3 1 1
//输出
//复制
//6
//说明
//洋灰三角铺法：1 2 3，总计6个
//示例2
//输入
//复制
//3 2 2
//输出
//复制
//15
//说明
//洋灰三角铺法：1 4 10，总计15个
//示例3
//输入
//复制
//3 3 3
//输出
//复制
//28
//说明
//洋灰三角铺法：1 6 21，总计28个
//备注:
//对于100%的测试数据：
//1 ≤ n ≤ 1000000000
//1 ≤ k,p ≤ 1000
