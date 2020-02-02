#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>

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

void tarjan(int u, int last, int vsttime) {
    dfn[u] = low[u] = vsttime;
    vst[u] = 1;
    fa[u] = last;
    for (int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].v;

        if (vst[v] == 1 && v != last)
            low[u] = min(low[u], dfn[v]);

        if (!vst[v]) {
            tarjan(v, u, vsttime + 1);
            low[u] = min(low[u], low[v]);
            if (dfn[u] < low[v]) {
                ans++;
            } else {
                Union(u, v);
            }
        }
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
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
        }

        ans = 0;
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(vst, 0, sizeof(vst));
        for (int i = 0; i <= n; i++)
            par[i] = i;

        tarjan(1, 0, 1);

        printf("Case %d:\n", t++);

        int q;
        scanf("%d", &q);
        for (int i = 0; i < q; i++) {
            scanf("%d%d", &u, &v);
            if (Find(u) != Find(v))
                LCA(u, v);
            printf("%d\n", ans);
        }
        printf("\n");
    }
}
