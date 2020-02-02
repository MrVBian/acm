#include<cstring>
#include<iostream>
#include<iomanip>
using namespace std;

//dp
//
int dp[105][105];
int m,n;

int main()
{
    while(cin>>m>>n){
        //边界初始化 1
        for(int i=1;i<=m;i++)
            dp[i][0]=1;
        for(int i=1;i<=n;i++)
            dp[0][i]=1;

        for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }

//        for(int i=0;i<=m;i++){
//            for(int j=0;j<=n;j++)
//                cout<<setw(4)<<dp[i][j];
//            cout<<endl;
//        }
        if(m>1&&n>1)
            cout<<dp[m-1][n-1]<<endl;
        else if(m<=1)
            cout<<dp[m][n-1]<<endl;
        else
            cout<<dp[m-1][n]<<endl;
    }
}




//dfs

//int dp[105][105];
//int mp[105][105];
//int ans;
//int m,n;
//int step[][2]={{1,0},{0,1}};
//
//bool OutBorder(int x,int y)
//{
//    if(x<1||x>m||y<1||y>n)
//        return true;
//    return false;
//}
//
//void dfs(int b,int e)
//{
//    if(b==m&&e==n){
//        ans++;
//        return ;
//    }
//    for(int i=0;i<2;i++){
//        int cur_x=b+step[i][0];
//        int cur_y=e+step[i][1];
//        if(!OutBorder(cur_x,cur_y) && !mp[cur_x][cur_y]){
//            mp[cur_x][cur_y]=1;
//            dfs(cur_x,cur_y);
//            mp[cur_x][cur_y]=0;
//        }
//    }
//}
//
//int main()
//{
//    while(cin>>m>>n){
//        memset(mp,0,sizeof(mp));
//        mp[1][1]=1;
//        dfs(1,1);
//        cout<<ans<<endl;
//        ans=0;
//    }
//}


//m×n 的网格，一个机器人从左上角开始，走到右下角。
//
//请问，有多少条路径？
//
//注意：机器人每次只能向下或者向右移动一格，最终需要到达终点。
//
//输入格式
//每行输入两个整数 m,n(1 \leq m,n \leq 100)m,n(1≤m,n≤100)，中间以空格间隔开。输入以 EOF 结束。
//
//输出格式
//每行输出一个整数，表示独特路径的数量。
//
//样例输入
//3 7
//样例输出
//28
