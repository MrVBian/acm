#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
typedef  long long LL;

const int inf = 0x3f3f3f3f;
const LL maxn = 110;

int n, m;
int G[maxn][maxn];

int d[maxn];
bool vst[maxn];
int maxD[maxn][maxn];   //MST中从i->j的最大权值
int pre[maxn];          //某一点父节点
bool mst[maxn][maxn];   //该点是否已经在MST中
typedef pair<int, int> P;

int Prim(int s) {
    for(int i = 0; i <= n; ++i){
        d[i] = inf;
        pre[i] = s;
        vst[i] = 0;
        for(int j = 0; j <= n; ++j){
            maxD[i][j] = 0;
            mst[i][j] = 0;
        }
    }
    priority_queue<P, vector<P>, greater<P> > q;
    q.push(P(d[s] = 0, s));
    int sum = 0;
    while(!q.empty()) {
        P cur = q.top();
        q.pop();
        int k = cur.second;
        if(vst[k])
            continue;
        vst[k] = 1;
        sum += d[k];
        mst[k][pre[k]] = mst[pre[k]][k] = 1; //加入到MST中
        for(int j = 1; j <= n; ++j) {
            if(vst[j] && j != k)        // 更新全部结点的maxD
                maxD[k][j] = maxD[j][k] = max(maxD[pre[k]][j], d[k]);
            if(!vst[j] && G[k][j] < d[j]) {
                d[j] = G[k][j];
                pre[j] = k;                     // 更新父节点
                q.push(P(d[j], j));
            }
        }
    }
    return sum;
}

int SMST(){
    int res = inf;
    for(int i = 1; i <= n; ++i){
        for(int j = i+1; j <= n; ++j){
            if(!mst[i][j] && G[i][j] != inf){
                res = min(res, G[i][j] - maxD[i][j]);
            }
        }
    }
    return res;
}

int main() {
    int T, x, y, z;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j){
            G[i][j] = inf;
        }

        for(int i = 1; i <= m; ++i) {
            scanf("%d%d%d", &x, &y, &z);
            G[x][y] = G[y][x] = z;
        }

        int ans = Prim(1);
        int res = SMST();

        printf("%d %d\n", ans, ans+res);
    }

    return 0;
}