#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;
const int maxn = 1e3 + 10;
int n, m;
int id[maxn], vis[maxn], pre[maxn];
int INF = 0x3f3f3f3f, d[maxn];
struct node {
    int u, v, cost;
} edge[maxn * maxn];

int zhuliu(int root, int V, int E) {
    int res = 0;
    while(true) {
        for(int i = 0 ; i < V ; i++) {
            d[i] = INF;
        }
        for(int i = 0 ; i < E ; i++) {
            int u = edge[i].u, v = edge[i].v;
            if(u != v && d[v] > edge[i].cost) {
                d[v] = edge[i].cost;
                pre[v] = u;
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

int x[maxn], y[maxn], z[maxn];
int X, Y, Z;

int main(){
    while(~scanf("%d%d%d%d",&n,&X,&Y,&Z)){
        if(!n && !X && !Y && !Z)
            break;
        m = 0;
        for(int i = 1; i <= n; ++i)
        scanf("%d%d%d", &x[i], &y[i], &z[i]);
        for(int i = 1; i <= n; ++i){
            int k, v;
            scanf("%d", &k);
            for(int j = 1; j <= k; ++j){
                scanf("%d", &v);
                edge[m].u = i;
                edge[m].v = v;
                edge[m].cost = ( abs(x[i] - x[v]) + abs(y[i] - y[v]) + abs(z[i] - z[v])) * Y;
                if(z[i] < z[v])
                    edge[m].cost += Z;
                m++;
            }
        }
        for(int i = 1; i <= n; ++i){
            edge[m].u = 0;
            edge[m].v = i;
            edge[m].cost = z[i] * X;
            m++;
        }
        int res = zhuliu(0, n + 1, m);     //n + 1 个点  m 条边
        printf("%d\n", res);
    }
}