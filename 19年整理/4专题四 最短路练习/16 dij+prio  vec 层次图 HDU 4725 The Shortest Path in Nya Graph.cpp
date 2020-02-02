#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 500500;
const int inf = 0x3f3f3f3f;

int t;
int n, m, c;
int d[maxn];
vector<pair<int, int> > G[maxn];

void dijkstra(int s){
     for(int i = 0; i <= n*3; ++i)
         d[i] = inf;
    priority_queue<pair<int, int> > q;
    q.push(make_pair(0, s));
    d[1] = 0;
    while(!q.empty()){
        int u = q.top().second;
        q.pop();
        for(int i = 0; i < G[u].size(); ++i){
            int v = G[u][i].first;
            int w = G[u][i].second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                q.push(make_pair(-d[v], v));
            }
        }
    }
}
// 假设1-n为实点，n+i*2-1为i点所在层的抽象入点,n+i*2为i点所在层的抽象出点。
// 抽象入点到层内各点距离为0，抽象出点到层内各点距离为0。
// 抽象出点到下一层抽象入点距离为c。
int main(){
    scanf("%d", &t);
    for(int T = 1; T <= t; ++T){
        for(int i = 0; i <= n*3; ++i)
            G[i].clear();
        scanf("%d%d%d", &n, &m, &c);
        for(int i = 1; i <= n; ++i){
            int v;
            scanf("%d", &v);
            G[n + v*2 - 1].push_back(make_pair(i, 0));
            G[i].push_back(make_pair(n + v*2, 0));
        }
        for(int i = 0; i < m; ++i){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(make_pair(v, w));
            G[v].push_back(make_pair(u, w));
        }
        for(int i = 1; i <= n; ++i){
            int u = n + i*2;
            if(i > 1)
                G[u].push_back(make_pair(u-3, c));
            if(i < n)
                G[u].push_back(make_pair(u+1, c));
        }
        dijkstra(1);
        printf("Case #%d: %d\n", T, d[n] >= inf ? -1 : d[n]);
    }
    return 0;
}