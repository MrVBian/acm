#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1010;
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

char str[30][30];// 柱子可用次数
vector<pair<int, int> > point1, point2;// 柱子

int main(){
    int t, d;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; ++Case){
        init();
        scanf("%d%d", &n, &d);
        point1.clear();
        point2.clear();
        memset(str, 0, sizeof(str));
        // 0 -> 柱子入 -> 柱子出 -> tp
        int cot = 0;
        for(int i = 0; i < n; ++i){
            scanf("%s", str[i]);
            if(!i)  m = strlen(str[i]);
            for(int j = 0; j < m; ++j){
                if(str[i][j] == '0')
                    continue;
                point1.push_back({i, j});
            }
        }
        char ch[30];
        for(int i = 0; i < n; ++i){
            scanf("%s", ch);
            for(int j = 0; j < m; ++j){
                if(ch[j] == 'L'){
                    point2.push_back({i, j});
                    cot ++;
                }
            }
        }
        sp = 0;
        tp = 2 * n * m + 1;
        for(int i = 0; i < point1.size(); ++i){
            int x = point1[i].first, y = point1[i].second;
            add(x*m+y+1, n*m + x*m+y+1, str[x][y]-'0'); // 柱子入 - > 柱子出
            if( x-d < 0 || x+d >= n || y-d < 0 || y+d >= m ){
                add(n*m + x*m+y+1, tp, inf);// 柱子出 - > tp
            }
            for(int j = 0; j < point1.size(); ++j){
                if(i == j)
                    continue;
                int xx = point1[j].first, yy = point1[j].second;
                if(abs(x-xx) + abs(y-yy) <= d){
                    add(n*m + x*m+y+1, xx*m+yy+1, inf);// 柱子出 -> 柱子入
                }
            }
        }

        for(int i = 0; i < point2.size(); ++i){
            add(sp, point2[i].first * m + point2[i].second + 1, 1);// 0 -> 柱子入
        }
        int ans = cot - dinic();
        if(ans == 0)
            printf("Case #%d: no lizard was left behind.\n", Case);
        else if(ans == 1)
            printf("Case #%d: 1 lizard was left behind.\n", Case);
        else
            printf("Case #%d: %d lizards were left behind.\n", Case, ans);

    }

    return 0;
}
