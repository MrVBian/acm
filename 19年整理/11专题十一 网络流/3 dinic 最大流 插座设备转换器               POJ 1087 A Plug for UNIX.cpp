#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1e3+100;
const int maxm = 1e6+100;

int n, m, t;
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

map<string, int> Hash;
char str1[30],str2[30];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cot = 0;
    string ch1, ch2;
    cin >> n;
    sp = 0, tp = 500;
    init();
    for(int i = 1; i <= n; ++i){// 插座
        cin >> ch1;
        if(Hash[ch1] == 0){
            Hash[ch1] = ++cot;
            add(Hash[ch1], tp, 1);
        }
    }
    cin >> m;
    for(int i = 1; i <= m; ++i){
        cin >> ch2 >> ch1;
        Hash[ch2] = ++cot;// 设备
        add(sp, Hash[ch2], 1);
        if(!Hash[ch1])// 插座
            Hash[ch1] = ++cot;
        add(Hash[ch2], Hash[ch1], 1);
    }
    cin>>t;
    for(int i = 1; i <= t; ++i){
        cin >> ch1 >> ch2;
        if(!Hash[ch1])// 插座
            Hash[ch1] = ++cot;
        if(!Hash[ch2])// 插座
            Hash[ch2] = ++cot;
        add(Hash[ch1], Hash[ch2], inf);
    }

    int ans = dinic();
    cout<<m - ans<<endl;

    return 0;
}
