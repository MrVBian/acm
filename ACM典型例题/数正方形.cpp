#include<iostream>
#include<cstdio>
using namespace std;

int mp[251][251];
int dp[251][251];
int num[251];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%1d",&mp[i][j]);
    for(int i=n;i>=1;i--)
        for(int j=n;j>=1;j--){
            if(mp[i][j])
                dp[i][j]=min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]))+1;
            for(int k=2;k<=dp[i][j];k++)
                num[k]++;
        }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++)
//            cout<<mp[i][j]<<' ';
//        cout<<endl;
//    }

//    cout<<endl<<endl;
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++)
//            cout<<dp[i][j]<<' ';
//        cout<<endl;
//    }

    for(int i=2;i<=n;i++)
        if(num[i])
            cout<<i<<' '<<num[i]<<endl;
}


//晓萌有一个N×N的的棋盘，中间有N2个正方形的1×1的格子，他随机在棋盘上撒上一些棋子（假设全部正好落在各个格子里）。他希望知道，当前的棋盘上有多少个不包含棋子的，由至少四个1×1的格子组成的正方形（正方形之间可以有重叠的部分）。
//输入第1行为棋盘的边长N，第2行-第N+1组成一个每行有N个数字的棋盘，其中数字0表示这个格子内有棋子，1表示这个格子内没有棋子。(2≤N≤250)
//输出包括多行，每行包括两个用空格分隔的数字，分别表示可以找到的正方形的边长和这种边长的正方形的个数。
//样例输入
//6
//101111
//001111
//111111
//001111
//101101
//111001
//样例输出
//2 10
//3 4
//4 1
