#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1e5+100;
const int maxm = 1e5+100;

int n, m;
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

const int cot = 1024+10;
int type[cot];

int main(){
    while(~scanf("%d%d", &n, &m)){
        init();
        memset(type, 0, sizeof(type));
        // 0 - > 人 - > 星球 - > tp
        sp = 0;
        tp = cot + m + 1;
        int v;
        for(int i = 1; i <= n; ++i){
            int res = 0;
            for(int j = 0; j < m; ++j){
                scanf("%d", &v);
                res += (v<<j);
            }
            type[res]++;
        }
        for(int i = 1; i < cot; ++i){
            if(type[i] > 0){
                add(sp, i, type[i]);// 0 -> 人
                for(int j = 0; j < m; ++j){
                    if( (i >> j)&1 ){
                        add(i, cot+j+1, inf);// 人 -> 星球
                    }
                }
            }
        }
        for(int i = 1; i <= m; ++i){
            scanf("%d", &v);
            add(cot+i, tp, v);// 星球 - > tp
        }
        int ans = dinic();
        if( n == ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
