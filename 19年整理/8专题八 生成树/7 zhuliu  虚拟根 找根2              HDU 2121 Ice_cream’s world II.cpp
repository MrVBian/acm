#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int MAXN = 1e3 + 10;
typedef long long LL;
int id[MAXN], vis[MAXN], pre[MAXN], pos;
LL INF = 1e17, d[MAXN];
struct node {
    int u, v, cost;
} edge[MAXN * MAXN];

LL zhuliu(int root, int V, int E) {
    LL res = 0;
    while(true) {
        for(int i = 0 ; i < V ; i++) {
            d[i] = INF;
        }
        for(int i = 0 ; i < E ; i++) {
            int u = edge[i].u, v = edge[i].v;
            if(u != v && d[v] > edge[i].cost) {
                d[v] = edge[i].cost;
                pre[v] = u;
                if(u == root) {
                    pos = i;    //记录位置    除了这里不一样 其他地方都是朱刘算法的模板
                }
            }
        }
        for(int i = 0 ; i < V ; i++) {
            if(d[i] == INF && i != root) {
                return -1;
            }
        }
        int cont = 0;
        memset(id, -1, sizeof(id));
        memset(vis, -1, sizeof(vis));
        d[root] = 0;
        for(int i = 0 ; i < V ; i++) {
            int v = i;
            res += d[i];
            while(id[v] == -1 && vis[v] != i && v != root) {
                vis[v] = i;
                v = pre[v];
            }
            if(id[v] == -1 && v != root) {
                for(int u = pre[v] ; u != v ; u = pre[u]) {
                    id[u] = cont;
                }
                id[v] = cont++;
            }
        }
        if(!cont) {
            break;
        }
        for(int i = 0 ; i < V ; i++) {
            if(id[i] == -1) {
                id[i] = cont++;
            }
        }
        for(int i = 0 ; i < E ; i++) {
            int u = edge[i].u, v = edge[i].v;
            edge[i].u = id[u];
            edge[i].v = id[v];
            if(id[u] != id[v]) {
                edge[i].cost -= d[v];
            }
        }
        V = cont;
        root = id[root];
    }
    return res;
}

int main() {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        LL sum = 0;
        for(int i = 0 ; i < m ; i++) {
            scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].cost);
            edge[i].u++, edge[i].v++;
            sum += edge[i].cost;
        }
        sum++;   //边权大于总权值
        for(int i = m ; i < n + m ; i++) {
            edge[i].u = 0;    //0为虚拟节点
            edge[i].v = i - m + 1;
            edge[i].cost = sum;
        }
        LL res = zhuliu(0, n + 1, n + m);     //n + 1 个点  n + m 条边
        if(res == -1 || res - sum >= sum) {    //要是res - sum < sum 的话就说明 0的出度为1  说明原图是连通图
            printf("impossible\n\n");
        } else {
            printf("%lld %d\n\n", res - sum, pos - m);
        }
    }
}
