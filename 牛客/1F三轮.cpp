#include<bits/stdc++.h>
using namespace std;

#define INF 19260817

int n,m;
int ans;

int dp[50001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        for(int j=x;j<=m;j++){
            dp[j]+=dp[j-x];
            if(dp[j]>=INF)
                dp[j]-=INF;
        }
    }
    for(int i=1;i<=m;i++)
        (ans+=dp[i])%=INF;
    cout<<ans;
}


//题目描述
//小k有一个三轮，它最多可以装105大小的东西
//小k有n种商品，他要准备出摊了
//每种商品体积为vi，都有105件
//输出凑成1~m的体积的总方案数
//输出可能会很大，请对大质数19260817取模
//输入描述:
//第一行两个整数n,m，
//接下来n行，每行一个数代表vi
//输出描述:
//一个数ans表示总方案数
//示例1
//输入
//2 8
//1
//3
//输出
//17
//说明
//从1~m体积的方案数分别为：
//1
//1
//2
//2
//2
//3
//3
//3
//备注:
//不要忘记取模！！！
//n,m,vi <= 50000

