#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

typedef long long ll;

const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;

struct edge{
    int to, w, next;
};

edge e[maxn];
int head[maxn];
int vst[maxn];
ll d[maxn];
int t, n, m;
int x[maxn], y[maxn], v[maxn];

void add(int i, int u, int v, int w){
    e[i].to = v;
    e[i].w = w;
    e[i].next = head[u];
    head[u] = i;
}

void spfa(int s){
    for(int i = 0; i <= n; ++i){
        vst[i] = 0;
        d[i] = inf;
    }
    vst[s] = 1;
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int k = q.front();
        q.pop();
        vst[k] = 0;
        for(int j = head[k]; j != -1; j = e[j].next){
            if(d[e[j].to] > d[k] + e[j].w){
                d[e[j].to] = d[k] + e[j].w;
                if(!vst[e[j].to]){
                    vst[e[j].to] = 1;
                    q.push(e[j].to);
                }
            }
        }
    }
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        memset(head, -1, sizeof(head));
        memset(e, 0, sizeof(e));
        for(int i = 0; i < m; ++i){
            scanf("%d%d%d", &x[i], &y[i], &v[i]);
            add(i, x[i], y[i], v[i]);
        }
        ll ans = 0;
        spfa(1);
        for(int i = 1; i <= n; ++i){
            ans += d[i];
        }
        memset(head, -1, sizeof(head));
        for(int i = 0; i < m; ++i){
            add(i, y[i], x[i], v[i]);
        }
        spfa(1);
        for(int i = 1; i <= n; ++i){
            ans += d[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
