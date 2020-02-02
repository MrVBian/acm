#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>

using namespace std;

const int maxn = 110;

int n;
int dfn[maxn], low[maxn], vst[maxn];
int belong[maxn];//belong[i]表示i属于缩点后的哪个节点
int cnt;
int out[maxn], in[maxn];
int tot;

struct Edge {
    int v;
    int next;
} edge[maxn*maxn];

int edgecount;
int head[maxn];

void init() {
    edgecount = 0;
    memset(head, -1, sizeof(head));
}

void add(int u, int v) {
    edge[++edgecount].v = v;
    edge[edgecount].next = head[u];
    head[u] = edgecount;
}

stack<int> s;
void Tarjan(int u) { //从节点x开始搜索
    dfn[u] = low[u] = ++tot;
    vst[u] = 1;//为1表示在队列里面
    s.push(u);
    for(int k = head[u]; k != -1; k = edge[k].next) {
        int v = edge[k].v;
        if(!dfn[v]) { //还未访问过
            Tarjan(v);
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

int main() {
    int v;
    while(~scanf("%d", &n)) {
        init();
        for(int u=1; u<=n; u++) {
            while(scanf("%d",&v) && v!=0)
                add(u,v);
        }
        tot = 0;
        cnt = 0;//缩点后的点数
        for(int i = 0; i <= n; ++i) {
            dfn[i] = low[i] = 0;
            in[i] = out[i] = 0;
            vst[i] = 0;
        }
        for(int i = 1; i <= n; ++i) {
            if(dfn[i] == 0)
                Tarjan(i);
        }
        for(int u = 1; u <= n; ++u) {
            for(int k = head[u]; k != -1; k = edge[k].next) {
                int v = edge[k].v;
                if(belong[u] != belong[v]) {
                    out[belong[u]]++;   // 缩点belong[u]的出度
                    in[belong[v]]++;    // 缩点belong[v]的入度
                }

            }
        }

        int ans1 = 0;
        int ans2 = 0;
        for(int i = 1; i <= cnt; ++i) {
            if(in[i] == 0)ans1++;
            if(out[i] == 0)ans2++;
        }
        ans2 = max(ans1, ans2);
        if(cnt == 1)printf("1\n0\n");
        else printf("%d\n%d\n", ans1, ans2);
    }
    return 0;
}
