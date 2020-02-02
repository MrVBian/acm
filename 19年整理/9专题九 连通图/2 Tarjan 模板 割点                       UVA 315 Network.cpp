#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 100010;
const int maxm = 200010;

struct edge {
    int u;
    int v;
    int next;
} e[2 * maxm];

int edge_num, head[maxn];

void add(int u, int v) {
    e[edge_num].u = u;
    e[edge_num].v = v;
    e[edge_num].next = head[u];
    head[u] = edge_num++;
}

int par[maxn];
int Find(int x) {
    return par[x] == x ? x : par[x] = Find(par[x]);
}
void Union(int x, int y) {
    int xx = Find(x);
    int yy = Find(y);
    if (xx != yy)
        par[xx] = yy;
}

int n, m;
int dfn[maxn], low[maxn], vst[maxn];

int fa[maxn];
int ans;
int tot;

void Tarjan(int u, int pre) {
    dfn[u] = low[u] = ++tot;
    vst[u] = 1;
    int son = 0;
    fa[u] = pre; //
    for (int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].v;
        if(v == pre)// 无向图割点，防止回溯。
            continue;
        if(!dfn[v]){
            son++;
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(u != pre && dfn[u] < low[v]){
                ans++;
            } else {
                Union(u, v);
            }

        }
        else if(vst[u])
            low[u] = min(low[u], dfn[v]);
    }
    vst[u] = 2;
}

void func(int u) {
    int xx = Find(u);
    int yy = Find(fa[u]);
    if (xx != yy) {
        ans--;
        par[xx] = yy;
    }
}

void LCA(int u, int v) {
    while (dfn[u] > dfn[v]) {
        func(u);
        u = fa[u];
    }

    while (dfn[v] > dfn[u]) {
        func(v);
        v = fa[v];
    }

    while (u != v) {
        func(u);
        func(v);
        u = fa[u];
        v = fa[v];
    }
}

int main() {
    int t = 1;
    while (~scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0)
            break;
        memset(head, -1, sizeof(head));
        edge_num = 0;
        int u, v;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
        }

        ans = tot = 0;
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(vst, 0, sizeof(vst));
        for (int i = 0; i <= n; ++i)
            par[i] = i;

        for(int i = 1; i <= n; ++i)
            if(!dfn[i])
                Tarjan(i, i);

        printf("Case %d:\n", t++);

        int q;
        scanf("%d", &q);
        for (int i = 0; i < q; ++i) {
            scanf("%d%d", &u, &v);
            if ( Find(u) != Find(v) )
                LCA(u, v);
            printf("%d\n", ans);
        }
        printf("\n");
    }
}
