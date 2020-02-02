#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 1005;
const int maxm = 10005;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u,v,cost;
};
Edge edge[maxm];
int pre[maxn], id[maxn], visit[maxn], in[maxn], pos;

int zhuliu(int root,int n,int m) {
    int res = 0,u,v;
    while(true) {
        for(int i = 0; i < n; i ++) {
            in[i] = inf;
        }
        for(int i = 0; i < m; i ++) {
            if(edge[i].u != edge[i].v && edge[i].cost < in[edge[i].v]) {
                pre[edge[i].v] = edge[i].u;
                in[edge[i].v] = edge[i].cost;
                if(edge[i].u == root) pos = i; // 找根
            }
        }
        for(int i = 0; i < n; i ++) {
            if(i != root && in[i] == inf)
                return -1;
        }
        int tn = 0;
        memset(id,-1,sizeof (id));
        memset(visit,-1,sizeof(visit));
        in[root] = 0;
        for(int i = 0; i < n; i ++) {
            res += in[i];
            v = i;
            while(visit[v] != i && id[v] == -1 && v != root) {
                visit[v] = i;
                v = pre[v];
            }
            if(v != root && id[v] == -1) {
                for(u = pre[v]; u != v; u = pre[u])
                    id[u] = tn;
                id[v] = tn ++;
            }
        }
        if(tn == 0) break;
        for(int i = 0; i < n; i ++) {
            if(id[i] == -1)
                id[i] = tn ++;
        }
        for(int i = 0; i < m; i ++) {
            v = edge[i].v;
            edge[i].u = id[edge[i].u];
            edge[i].v = id[edge[i].v];
            if(edge[i].u != edge[i].v)
                edge[i].cost -= in[v];
            //else swap(edge[i],edge[-- m]);
        }
        n = tn;
        root = id[root];
    }
    return res;
}

int main() {
    int n,m;
    while(~scanf("%d%d",&n,&m)) {
        int sum = 0;
        for(int i = 0; i < m; i ++) {
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].cost);
            sum += edge[i].cost;
            edge[i].u ++;
            edge[i].v ++;
        }
        sum ++;
        for(int i = 0; i < n; i ++) {
            edge[i + m].u = 0;
            edge[i + m].v = i + 1;
            edge[i + m].cost = sum;
        }
        int ans = zhuliu(0,n + 1,n + m);
        if(ans == -1 || ans >= 2 * sum ) printf("impossible\n");
        else printf("%d %d\n",ans - sum,pos - m);
        printf("\n");
    }
    return 0;
}
