#include <bits/stdc++.h>

using namespace std;

const int maxn = 15;
const int inf = 0x3f3f3f3f;

int n, m;
int Three[11];
int G[maxn][maxn];
int dp[60000][11];
int digit[60000][11];

void init(){
    Three[0] = 1;
    for(int i = 1; i < 11; ++i)
        Three[i] = Three[i-1] * 3;
    for(int i = 0; i < Three[10]; ++i){
        int tmp = i;
        for(int j = 0; j < 10; ++j){
            digit[i][j] = tmp%3;
            tmp /= 3;
        }
    }
}

int main(){
    init();
    while(~scanf("%d%d", &n, &m)){
        for(int i = 0; i <= n; ++i)
            for(int j = 0; j <= n; ++j)
                G[i][j] = inf;
        for(int i = 0; i < Three[n]; ++i)
            for(int j = 0; j < n; ++j)
                dp[i][j] = inf;
        while(m--){
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            G[x-1][y-1] = G[y-1][x-1] = min(G[x-1][y-1], z);
        }
        for(int i = 0; i < n; ++i)
            dp[Three[i]][i] = 0;
        int ans = inf;
        for(int i = 0; i < Three[n]; ++i){
            bool flag = 1;
            for(int j = 0; j < n; ++j){
                if(digit[i][j] == 0)//只要三进制数中存在一个0，那么就说明还有点没有遍历完，就不能当做最终答案来求  
                    flag = 0;
                if(dp[i][j] != inf)
                    for(int k = 0; k < n; ++k)
                        if(G[j][k] != inf && digit[i][k] != 2)//注意这个digit[j][k]!=2,因为如果j状态在k点已经走过两次了显然是不能继续往下走的
                            dp[i+Three[k]][k] = min(dp[i+Three[k]][k], dp[i][j]+G[j][k]);
            }
            if(flag)
                for(int j = 0; j < n; ++j)//由于是3进制，不能方便的判断一串三进制数里面是否存在0
                    ans = min(ans, dp[i][j]);
        }
        if(ans >= inf)
            printf("-1\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}