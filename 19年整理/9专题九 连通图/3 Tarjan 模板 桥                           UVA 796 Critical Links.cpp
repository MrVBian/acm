#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;
// Tarjan算法   复杂度O(n+m)
const int maxn = 10010;//点数
const int maxm = 100010;//边数
struct Edge {
    int to, next;
    bool cut;
} edge[maxm];
int head[maxn], cnt;
int low[maxn], dfn[maxn];
int tot, bridge;
bool vst[maxn], cut[maxn];

void add(int u, int v) {
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].cut = 0;
    head[u] = cnt++;
}

stack<int> s;
void Tarjan(int u, int pre) {
    low[u] = dfn[u] = ++tot;
    s.push(u);
    vst[u] = 1;
    for(int k = head[u]; ~k; k = edge[k].next) {
        int v = edge[k].to;
        if(v == pre)
            continue; //忽略直接相连的边
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

void solve(int n) {
    for(int i = 1; i <= n; i++)
        if(!dfn[i])
            Tarjan(i, i);

    printf("%d critical links\n", bridge);
    vector<pair<int,int> > ans;

    for(int u = 1; u <= n; ++u)
        for(int v = head[u]; ~v; v = edge[v].next)
            if(edge[v].cut && edge[v].to > u)
                ans.push_back( make_pair(u, edge[v].to) );
    sort(ans.begin(), ans.end());
    for(int i = 0; i <ans.size(); ++i)
        printf("%d - %d\n", ans[i].first-1, ans[i].second-1);
    printf("\n");
}

void init() {
    cnt = 0;
    tot = bridge= 0;
    memset(head, -1, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(vst, 0, sizeof(vst));
    memset(low, 0, sizeof(low));
}

int main() {
    int n, a, b, m;
    while(~scanf("%d",&n)) {
        init();
        for(int j = 0; j < n; ++j) {
            scanf("%d (%d)", &a, &m);
            a++;
            for(int i = 0; i < m; ++i) {
                scanf("%d", &b);
                b++;
                if(b <= a)
                    continue;
                add(a,b);
                add(b,a);
            }
        }
        solve(n);
    }
    return 0;
}
