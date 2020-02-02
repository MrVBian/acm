#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1e3+100;
const int maxm = 1e6+100;

int n, m;//点数、边数
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
    while(~scanf("%d %d", &n, &m)) {
        int c;
        init();
        sp = 0, tp = m * 2 + 1;
        for(int i = 1; i <= m; i++) {
            scanf("%d", &c);
            add(i, i + m, c); // i -> i+m
            int flag = 1;
            for(int j = 1; j <= n; j++) {
                scanf("%d", &infw[i][j]);
                if(infw[i][j] == 1) {
                    flag = 0;
                }
            }
            if(flag) { // sp 连边到所有接收 "0000..." 或 "若干个0及若干个2" 的机器，容量为无穷大
                add(sp, i, inf); // 0 -> i
            }
            flag = 1;
            for(int j = 1; j <= n; j++) {
                scanf("%d", &ofw[i][j]);
                if(ofw[i][j] == 0) {
                    flag = 0;
                }
            }
            if(flag) { // 能产出成品的节点，连边到T，容量无穷大。
                add(i + m, tp, inf); // i+m -> m*2+1
            }
            for(int j = 1; j < i; j++) { // 产出节点连边到能接受其产品的接收节点，容量无穷大
                flag = 1;
                for(int k = 1; k <= n; k++) {
                    if(infw[j][k] == 1 && ofw[i][k] == 0 || infw[j][k] == 0 && ofw[i][k] == 1) {
                        flag = 0;
                        break;
                    }
                }
                if(flag) {
                    add(i + m, j, inf); // i+m -> j
                }
                flag = 1;
                for(int k = 1; k <= n; k++) {
                    if(infw[i][k] == 1 && ofw[j][k] == 0 || infw[i][k] == 0 && ofw[j][k] == 1) {
                        flag = 0;
                        break;
                    }
                }
                if(flag) {
                    add(j + m, i, inf); // j+m -> i
                }
            }
        }
        int ans = dinic();
        int sum = 0;

        for(int i = 1; i <= m; i++) {
            for(int p = pre[i + m]; p; p = mp[p].next) {
                if(mp[p].v != i && mp[p].v != sp && mp[p].v != tp && mp[p].cap != inf) {
                    sum++;
                }
            }
        }
        printf("%d %d\n", ans, sum);
        for(int i = 1; i <= m; i++) {
            for(int p = pre[i + m]; p; p = mp[p].next) {
                if(mp[p].v != i && mp[p].v != sp && mp[p].v != tp && mp[p].cap != inf) {
                    printf("%d %d %d\n", i, mp[p].v, inf - mp[p].cap);
                }
            }
        }
    }
    return 0;
}
