#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;
const int maxn = 1e3 + 100;
const int maxm = 1e6 + 100;
const int inf = 0x3f3f3f3f;

int n, m;
int par[maxn];

struct Edge {
    int to, w, next;
    bool cut;
} edge[maxm];
int head[maxm], cnt;
int low[maxm], dfn[maxm];
int tot, bridge;
bool vst[maxm], cut[maxm];

void add(int u, int v, int w) {
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    edge[cnt].cut = 0;
    head[u] = cnt++;
}

stack<int> s;
void Tarjan(int u, int pre) {
    low[u] = dfn[u] = ++tot;
    s.push(u);
    vst[u] = 1;
    int num = 0;
    for(int k = head[u]; ~k; k = edge[k].next) {
        int v = edge[k].to;
        if(v == pre && !num){// 忽略直接相连的边 可以访问重边
            num ++;
            continue;
        }
        if(!dfn[v]) {
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
            //桥
            //一条无向边(u,v)是桥，当且仅当(u,v)为树枝边，且满足DFS(u)<Low(v)。
            if(dfn[u] < low[v]) {
                bridge++;
                edge[k].cut = edge[k^1].cut = 1;
            }
        } else if(vst[u])
            low[u] = min(low[u], dfn[v]);
    }
    vst[u] = 0;
    s.pop();
}

int Find(int x){
    if(par[x] == x)
        return x;
    return par[x] = Find(par[x]);
}

void Union(int x, int y){
    int xx = Find(x);
    int yy = Find(y);
    if(xx != yy)
        par[xx] = yy;
}

void init(){
    for(int i = 0; i <= n; ++i)
        par[i] = i;
    while(!s.empty())
        s.pop();
    cnt = 0;
    tot = bridge = 0;
    memset(head, -1, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(vst, 0, sizeof(vst));
    memset(low, 0, sizeof(low));
}

int main(){
    while(~scanf("%d%d", &n, &m)){
        if(!n && !m)
            break;
        int x, y, z;
        init();
        for(int i = 1; i <= m; ++i){
            scanf("%d%d%d", &x, &y, &z);
            add(x, y, z);
            add(y, x, z);
            Union(x, y);
        }
        int flag = 0;
        for(int i = 1; i <= n; ++i){
            if(Find(i) != Find(y)){
                flag = 1;
                continue;
            }
        }
        if(flag){
            printf("0\n");
            continue;
        }
        for(int i = 1; i <= n; ++i)
            if(!dfn[i])
                Tarjan(i, i);
        if(bridge == 0){
            printf("-1\n");
            continue;
        }

        int ans = inf;
        for(int u = 1; u <= n; ++u)
            for(int v = head[u]; ~v; v = edge[v].next)
                if(edge[v].cut)
                    ans = min(ans, edge[v].w);
        printf("%d\n", ans == 0 ? 1 : ans);

    }
    return 0;
}
