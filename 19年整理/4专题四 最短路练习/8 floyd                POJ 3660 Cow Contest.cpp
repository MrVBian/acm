#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn = 210;

int n, m;
int G[maxn][maxn];
int ans[maxn];

//传递闭包
void floyd(){
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(G[i][k] && G[k][j])//检测i、j之间是否有路
                    G[i][j] = 1;
            }
        }
    }
}

int main(){
    while(~scanf("%d%d", &n, &m)){
        memset(G, 0, sizeof(G));
        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < m; ++i){
            int x, y;
            scanf("%d%d", &x, &y);
            G[x][y] = 1;
        }

        floyd();

        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(G[i][j] || G[j][i])
                    ans[i] ++;
            }
        }

        int cot = 0;
        for(int i = 1; i <= n; ++i){
            if(ans[i] == n-1)
                cot++;
        }
        printf("%d\n", cot);
    }
    return 0;
}
