#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 510;
const int maxm = 1e5+100;

int n, F, D;//点数、边数
int sp, tp;//原点、汇点

struct node {
    int u;
    int v, next;
    int cap;
}mp[maxm];

int pre[maxn], dis[maxn], cur[maxn];//cur为当前弧优化，dis存储分层图中每个点的层数（即到原点的最短距离），pre建邻接表
int cnt = 0;

void init() {  //不要忘记初始化
    cnt = 0;
    memset(pre, -1, sizeof(pre));
}

void add(int u, int v, int w) { //加边
    mp[cnt].u = u;
    mp[cnt].v = v;
    mp[cnt].cap = w;
    mp[cnt].next = pre[u];
    pre[u] = cnt++;

    mp[cnt].u = v;
    mp[cnt].v = u;
    mp[cnt].cap = 0;
    mp[cnt].next = pre[v];
    pre[v] = cnt++;
}

bool bfs() {  //建分层图
    memset(dis, -1, sizeof(dis));
    queue<int>q;
    while(!q.empty())
        q.pop();
    q.push(sp);
    dis[sp] = 0;
    int u, v;
    while(!q.empty()) {
        u = q.front();
        q.pop();
        for(int i = pre[u]; i != -1; i = mp[i].next) {
            v = mp[i].v;
            if(dis[v] == -1 && mp[i].cap > 0) {
                dis[v] = dis[u] + 1;
                q.push(v);
                if(v == tp)
                    break;
            }
        }
    }
    return dis[tp] != -1;
}

int dfs(int u, int cap) {//寻找增广路
    if(u == tp || cap == 0)
    return cap;
    int res = 0, f;
    for(int &i = cur[u]; i != -1; i = mp[i].next) {//
        int v = mp[i].v;
        if(dis[v] == dis[u] + 1 && (f = dfs(v, min(cap - res, mp[i].cap))) > 0) {
            mp[i].cap -= f;
            mp[i ^ 1].cap += f;
            res += f;
            if(res == cap)
                return cap;
        }
    }
    if(!res)
        dis[u] = -1;
    return res;
}

int dinic() {
    int ans = 0;
    while(bfs()) {
        for(int i = sp; i <= tp; i++)
            cur[i] = pre[i];
        ans += dfs(sp, inf);
    }
    return ans;
}

int infw[55][15];
int ofw[55][15];

int main(){
    scanf("%d %d %d", &n, &F, &D);
    int c;
    init();
    sp = 0, tp = F + n + n + D + 1;
    for(int i = 1; i <= F; ++i){
        add(sp, i, 1);
    }
    for(int i = 1; i <= D; ++i){
        add(F+n+n+i, tp, 1);
    }
    int k, kk, v;
    for(int i = 1; i <= n; ++i){
        add(F+i, F+n+i,1);
        scanf("%d%d", &k, &kk);
        while(k--){
            scanf("%d", &v);
            add(v, F+i, 1);
        }
        while(kk--){
            scanf("%d", &v);
            add(F+n+i, F+n+n+v, 1);
        }
    }

    int ans = dinic();
    int sum = 0;
    printf("%d\n", ans);

    return 0;
}
