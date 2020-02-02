#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>

using namespace std;
typedef long long ll;
const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;

struct edge{
    int to,w,next;
};

int head[maxn];
edge e[maxn];
int vst[maxn];
ll d[maxn];
int t,m,n;
int x[maxn], y[maxn], v[maxn];
ll ans[maxn];

void add(int top, int x, int y, int v){
    e[top].next = head[x];
    head[x] = top;
    e[top].to = y;
    e[top].w = v;
}

void spfa(int s){
    for(int i = 0; i <= m; ++i){
        d[i] = inf;
        vst[i] = 0;
    }
    d[s] = 0;
    vst[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int k = q.front();
        q.pop();
        vst[k] = 1;
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
        memset(head, -1, sizeof(head));
        memset(e, 0, sizeof(e));
        memset(ans, 0, sizeof(ans));
        scanf("%d%d",&n,&m);
        for(int i = 0; i < m; ++i){
            scanf("%d%d%d", &x[i], &y[i], &v[i]);
            add(i,x[i],y[i],v[i]);
        }
        spfa(1);
        for(int i = 1; i <= n; ++i){
            ans[i] += d[i];
        }
        memset(head, -1, sizeof(head));
        for(int i = 0; i < m; ++i){
            add(i,y[i],x[i],v[i]);
        }
        spfa(1);
        for(int i = 1; i <= n; ++i){
            ans[i] += d[i];
        }
        ll res = 0;
        for(int i = 1; i <= n; ++i){
            res += ans[i];
        }
        printf("%lld\n", res);
    }
    return 0;
}
