#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long ll;

const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;

typedef pair<int,int> P;
struct edge{
    int to, w, next;
};

edge e[maxn];
int head[maxn];
ll d[maxn];
int n, m;

void add(int i, int u, int v, int w){
    e[i].to = v;
    e[i].w = w;
    e[i].next = head[u];
    head[u] = i;
}

void spfa(int s){
    for(int i = 0; i <= n; ++i)
        d[i] = inf;
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P> > q;
    q.push(P(0, s));
    while(q.size()){
        P k = q.top();
        q.pop();
        int first = k.first;
        int second = k.second;
        if(d[second] < first)
            continue;
        for(int j = head[second]; j != -1; j = e[j].next){
            if(d[e[j].to] > d[second] + e[j].w){
                d[e[j].to] = d[second] + e[j].w;
                q.push(P(d[e[j].to], e[j].to));
            }
        }
    }
}

int main(){
    while(~scanf("%d%d", &n, &m)){
        memset(head, -1, sizeof(head));
        int x, y, v;
        for(int i = 0; i < m; ++i){
            scanf("%d%d%d", &x, &y, &v);
            add(i, x, y, v);
        }
        ll ans = 0;
        spfa(1);
        printf("%lld\n", d[n]);
    }
    return 0;
}