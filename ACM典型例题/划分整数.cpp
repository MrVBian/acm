#include<bits/stdc++.h>
using namespace std;
long long dp[301][301];
int main()
{
    for(int i=1;i<=300;i++)
        for(int j=1;j<=300;j++){
            if(i==1||j==1)
                dp[i][j]=1;
            else if(j>i)
                dp[i][j]=dp[i][i];
            else if(i==j)
                dp[i][i]=dp[i][j-1]+1;
            else
                dp[i][j]=dp[i][j-1]+dp[i-j][j];
        }
    int m,n;
    cin>>m>>n;
    cout<<dp[m][n];
}

//蒜头君特别喜欢数学。今天，蒜头君突发奇想：如果想要把一个正整数
//nn
//n 分解成不多于
//kk
//k 个正整数相加的形式，那么一共有多少种分解的方式呢？
//蒜头君觉得这个问题实在是太难了，于是他想让你帮帮忙。
//输入格式
//共一行，包含两个整数
//n(1≤n≤300)n(1 \leq n \leq 300)
//n(1≤n≤300) 和
//k(1≤k≤300)k(1 \leq k \leq 300)
//k(1≤k≤300)，含义如题意所示。
//输出格式
//一个数字，代表所求的方案数。
//样例输入
//5 3
//样例输出
//5

//对于样例，
//5 有 5 种不大于3 个数的相加方式， 分别是：
//5=5
//5= 4 + 1
//5= 3 + 2
//5= 3 + 1 + 1
//5= 2 + 2 + 1


//5 2
//5 1
//3 2
//
//
//2 3   1 4
//1 2   3
//
//
//7 2
//7 1
//5 2
//
//
//1 6  2 5  3 4
//1 4  2 3  5
