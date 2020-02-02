#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#define ms(a,b) memset((a),(b),sizeof((a)))
using namespace std;
const int maxn = 1e6+10;

// https://www.cnblogs.com/DOLFAMINGO/p/7701642.html

struct Edge {
    int to, next;
} edge[maxn], edge0[maxn];  //edge为初始图， edge0为重建图
int tot, head[maxn], tot0, head0[maxn];

int index, dfn[maxn], low[maxn];
int top, Stack[maxn], instack[maxn];
int belong[maxn];
int fa[maxn], depth[maxn];  //fa用于重建图时记录当前节点的父亲节点，depth记录当前节点的深度
int sum_bridge;

//找到x最终所属的结合
int Find(int x) {
    return belong[x]==x?x:belong[x]=Find(belong[x]);
}

void addedge(int u, int v, Edge edge[], int head[], int &tot) {
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void Tarjan(int u, int pre) {
    dfn[u] = low[u] = ++index;
    Stack[top++] = u;
    instack[u] = true;
    for(int i = head[u]; i!=-1; i = edge[i].next) {
        int v = edge[i].to;
        if(v==pre) continue;
        if(!dfn[v]) {
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v]>dfn[u]) sum_bridge++;
        } else if(instack[v])
            low[u] = min(low[u], dfn[v]);
    }

    if(dfn[u]==low[u]) {
        int v;
        do {
            v = Stack[--top];
            instack[v] = false;
            belong[v] = u;  //把集合的编号设为联通分量的第一个点
        } while(v!=u);
    }
}

void build(int u, int pre) {
    fa[u] = pre;    //记录父亲节点
    depth[u] = depth[pre] + 1;  //记录深度
    for(int i  = head0[u]; i!=-1; i=edge0[i].next)
        if(edge0[i].to!=pre)    //防止往回走
            build(edge0[i].to, u);
}


int LCA(int u, int v) { //左一步右一步地找LCA
    if(u==v) return u;  //因为两个结点一定有LCA， 所以一定有u==v的时候

    //可能爬一步就爬了几个深度，因为中间的结点已经往上缩点了
    if(depth[u]<depth[v]) swap(u, v);   //深度大的往上爬
    sum_bridge--;
    int lca = LCA(Find(fa[u]), v);
    return belong[u] = lca;     //找到了LCA，在沿路返回的时候把当前节点的所属集合置为LCA的所属集合
}

void init() {
    tot = tot0 = 0;
    memset(head, -1, sizeof(head));
    memset(head0, -1, sizeof(head0));

    index = top = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(instack, 0, sizeof(instack));

    sum_bridge = 0;
}

int main() {
    int n, m, kase = 0;
    while(scanf("%d%d", &n, &m) && (n||m) ) {
        init();
        for(int i = 1; i<=m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            addedge(u, v, edge, head, tot);
            addedge(v, u, edge, head, tot);
        }

        Tarjan(1, 1);
        for(int u = 1; u<=n; u++)   //重建建图
            for(int i = head[u]; i!=-1; i = edge[i].next) {
                int tmpu = Find(u);
                int tmpv = Find(edge[i].to);
                if(tmpu!=tmpv)
                    addedge(tmpu, tmpv, edge0, head0, tot0);
            }

        depth[Find(1)] = 0;
        build(Find(1), Find(1));    //把无根树转为有根树

        int q, a, b;
        scanf("%d", &q);
        printf("Case %d:\n", ++kase);
        while(q--) {
            scanf("%d%d", &a, &b);
            LCA(Find(a), Find(b));
            printf("%d\n", sum_bridge);
        }
        printf("\n");
    }
}
