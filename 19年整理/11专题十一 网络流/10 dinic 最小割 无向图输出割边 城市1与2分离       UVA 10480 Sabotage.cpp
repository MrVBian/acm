#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn = 100100;
const int maxm = 300000;

struct node {
    int v, w, ne;
} ed[maxm];
int n, m, cnt;
int head[maxn], dis[maxn], cur[maxn];
void init() {
    cnt = 0;
    memset(head, -1, sizeof(head));
}
void add(int u, int v, int w) { //加边
    ed[cnt].v = v;
    ed[cnt].w = w;
    ed[cnt].ne = head[u];
    head[u] = cnt++;
    ed[cnt].v = u;
    ed[cnt].w = w;
    ed[cnt].ne = head[v];
    head[v] = cnt++;
}
int bfs(int sp, int tp) { //建分层图
    queue<int>q;
    memset(dis, 0, sizeof(dis));
    dis[sp] = 1;
    q.push(sp);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == tp)return 1;
        for (int s = head[u]; ~s; s = ed[s].ne) {
            int v = ed[s].v;
            if (dis[v] == 0 && ed[s].w > 0) {
                if (dis[v] == 0 && ed[s].w > 0) {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    return dis[tp] != 0;
}
int dfs(int sp, int tp, int flow) { //寻找增广路
    int ret = flow, a;
    if (sp == tp || flow == 0)return flow;
    for (int &s = cur[sp]; ~s; s = ed[s].ne) {
        int v = ed[s].v;
        if (dis[v] == dis[sp] + 1 && (a = dfs(v, tp, min(ret, ed[s].w)))) {
            ed[s].w -= a;
            ed[s ^ 1].w += a;
            ret -= a;
            if (!ret)break;
        }
    }
    if (ret == flow)dis[sp] = 0;
    return flow - ret;
}
int dinic(int sp, int tp) {
    int ans = 0;
    while (bfs(sp, tp)) {
        for (int s = 0; s <= n; s++)// 遍历  任意点至任到任意点优化
            cur[s] = head[s];
        ans += dfs(sp, tp, inf);
    }
    return ans;
}

int a[maxn], b[maxn];

int main() {
    int t;
    int sp = 0, tp = 0;
    while(~scanf("%d%d", &n, &m)) {
        if(!n && !m)
            break;
        init();
        int x, y, z;
        for(int i = 1; i <= m; ++i){
            scanf("%d%d%d", &x, &y, &z);
            add(x, y, z);
            a[i] = x;
            b[i] = y;
        }
        int ans = dinic(1, 2);
        for(int i = 1; i <= m; ++i){
            if( (!dis[ a[i] ] && dis[ b[i] ] ) || (dis[ a[i] ] && !dis[ b[i] ] )  ){
                printf("%d %d\n", a[i], b[i]);
            }
        }
        printf("\n")
    }
}
