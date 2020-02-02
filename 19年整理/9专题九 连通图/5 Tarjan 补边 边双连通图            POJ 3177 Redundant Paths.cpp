#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>

using namespace std;

const int maxn = 1e5+10;

int n, m;
int dfn[maxn], low[maxn], vst[maxn];
int belong[maxn];//belong[i]表示i属于缩点后的哪个节点
int cnt;
int tot;
int degree[maxn];

struct Edge {
    int v;
    int next;
} edge[maxn * 2];

int edgecount;
int head[maxn];

void init() {
    edgecount = 0;
    memset(head, -1, sizeof(head));
    memset(degree, 0, sizeof(degree));
}

void add(int u, int v) {
    edge[++edgecount].v = v;
    edge[edgecount].next = head[u];
    head[u] = edgecount;
}

stack<int> s;
void Tarjan(int u, int pre) { //从节点x开始搜索
    dfn[u] = low[u] = ++tot;
    vst[u] = 1;//为1表示在队列里面
    s.push(u);
    for(int k = head[u]; k != -1; k = edge[k].next) {
        int v = edge[k].v;
        if(v == pre) // 双连通分量，不能回走
            continue;
        if(!dfn[v]) { //还未访问过
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else if(vst[v]) { //被访问过，还在队列里
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(low[u] == dfn[u]) {
        int x;
        ++cnt;
        while(1) {
            x = s.top();
            s.pop();
            vst[x] = 0;
            belong[x] = cnt;
            if(x == u)
                break;
        }
    }
}

const int Hash = 5010;
bool mp[Hash*Hash];

int main() {
    scanf("%d%d", &n, &m);
    init();
    int x, y;
    for(int i = 0; i < m; ++i){
        scanf("%d%d", &x, &y);
        int v = x * Hash + y; // 去重边
        if( mp[v] )
            continue;
        mp[x*Hash+y] = 1;
        add(x, y);
        add(y, x);
    }
    tot = 0;
    cnt = 0;// 缩点后的点数
    for(int i = 0; i <= n; ++i) {
        dfn[i] = low[i] = 0;
        vst[i] = 0;
    }
    for(int i = 1; i <= n; ++i) {
        if(dfn[i] == 0)
            Tarjan(i, i);
    }
    for(int u = 1; u <= n; ++u) {
        for(int k = head[u]; k != -1; k = edge[k].next) {
            int v = edge[k].v;
            if(belong[u] != belong[v]) {
                degree[belong[u]] ++;   // u v | v u 重复出现
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= cnt; ++i)
        if(degree[i] == 1)
            ans++;

    printf("%d\n", (ans+1)/2 );

    return 0;
}
