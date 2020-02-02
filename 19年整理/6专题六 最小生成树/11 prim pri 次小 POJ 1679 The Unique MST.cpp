#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 110;

int n, m, G[maxn][maxn];
int d[maxn];
bool vst[maxn];
int maxD[maxn][maxn];   //MST中从i->j的最大权值
int pre[maxn];          //某一点父节点
bool mst[maxn][maxn];   //该点是否已经在MST中
typedef pair<int, int> P;

int Prim(int s) {
    for(int i = 0; i <= n; ++i){
        d[i] = inf;
        vst[i] = 0;
        pre[i] = s;
        for(int j = 0; j <= n; ++j){
            mst[i][j] = 0;
            maxD[i][j] = 0;
        }
    }
    priority_queue<P, vector<P>, greater<P> > q;
    q.push(P(d[s]=0, s));
    int sum = 0;
    while(!q.empty()) {
        P cur = q.top();
        q.pop();
        int k = cur.second;
        if(vst[k]) continue;
        vst[k] = 1;
        sum += d[k];
        mst[k][pre[k]] = mst[pre[k]][k] = true; //加入到MST中
        for(int j = 1; j <= n; ++j) {
            if(vst[k] && G[k][j] < inf)          //只更新MST中的
                maxD[k][j] = maxD[j][k] = max(maxD[pre[k]][k], d[k]);
            if(G[k][j] < d[j]) {
                d[j] = G[k][j];
                pre[j] = k;                     //更新父节点
                q.push(P(d[j], j));
            }
        }
    }
    return sum;
}

int main() {
    int T, x, y, z;
    scanf("%d", &T);
    while(T--) {
        memset(G, inf, sizeof(G));
        scanf("%d%d", &n, &m);
        while(m--) {
            scanf("%d%d%d", &x, &y, &z);
            G[x][y] = G[y][x] = z;
        }
        int ans = Prim(1);
        bool flag = false;  // 次小生成树是否等于最小生成树
        for(int u = 1; u <= n && !flag; ++u) {
            for(int v = 1; v <= n; ++v) {
                if(mst[u][v] || G[u][v]==inf)// 枚举所有未使用的边, 判断该边<i, j> 权值是否等于maxd[i][j]
                    continue;
                if(G[u][v] == maxD[u][v]) {// 边<i, j> 权值等于maxd[i][j]说明不唯一
                    flag = true;
                    break;
                }
            }
        }
        if(flag)
            printf("Not Unique!\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
