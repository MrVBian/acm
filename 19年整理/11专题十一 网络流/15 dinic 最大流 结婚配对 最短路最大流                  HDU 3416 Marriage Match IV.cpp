#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

#define ll long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int inf = 0x3f3f3f3f;
const int maxn = 1010;

struct node {
    int to;
    int w;
    int next;
} edge[maxn*100*2],e[maxn*200*5];

int ind,pre[maxn],vst[maxn],d[maxn],head[maxn],ind1;
int now[maxn],S,T;
int n,m;

void add1(int x,int y,int z) {
    e[ind1].to = y;
    e[ind1].w = z;
    e[ind1].next = head[x];
    head[x] = ind1 ++;
}
void spfa(int s) {
    for(int i = 1; i <= n; i++) {
        d[i] = inf;
        vst[i] = 0;
    }
    vst[s] = 1;
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int k = q.front();
        q.pop();
        vst[k] = 0;
        for(int i = head[k]; i != -1; i = e[i].next) {
            int t = e[i].to;
            if(d[t] > d[k] + e[i].w) {
                d[t] = d[k] + e[i].w;
                if(!vst[t]) {
                    vst[t] = 1;
                    q.push(t);
                }
            }
        }
    }
}

void add(int x,int y,int z) {
    edge[ind].to = y;
    edge[ind].w = z;
    edge[ind].next = pre[x];
    pre[x] = ind ++;
}

void dfs1(int rt) {
    vst[rt] = 1;
    if(rt == T)return ;
    for(int i = head[rt]; i != -1; i = e[i].next) {
        int t = e[i].to;
        if(now[rt] + d[t] + e[i].w == d[S]) {
            now[t] = now[rt] + e[i].w;
            add(rt,t,1);
            add(t,rt,0);
            if(!vst[t]) {
                dfs1(t);
            }
        }
    }
}

int bfs() {
    memset(vst,-1,sizeof(vst));
    queue<int>q;
    vst[S] = 0;
    q.push(S);
    while(!q.empty()) {
        int k = q.front();
        q.pop();
        for(int i = pre[k]; i != -1; i = edge[i].next) {
            int t = edge[i].to;
            if(vst[t] == -1 && edge[i].w) {
                vst[t] = vst[k] + 1;
                q.push(t);
            }
        }
    }
    if(vst[T] == -1)return 0;
    return 1;
}

int dfs(int rt,int low) {
    int used = 0;
    if(rt == T)return low;
    for(int i = pre[rt]; i != -1 && used < low; i = edge[i].next) {
        int t = edge[i].to;
        if(vst[t] == vst[rt] + 1 && edge[i].w) {
            int a = dfs(t,min(low-used,edge[i].w));
            used += a;
            edge[i].w -= a;
            edge[i^1].w += a;
        }
    }
    if(used == 0)vst[rt] = -1;
    return used;
}
int x[maxn*100],y[maxn*100],z[maxn*100];

void init(int flag) {
    ind1 = 0;
    memset(head,-1,sizeof(head));
    for(int i = 1; i <= m; i++) {
        if(!flag)
            add1(y[i],x[i],z[i]);
        else
            add1(x[i],y[i],z[i]);
    }
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; ++i) {
            scanf("%d%d%d", &x[i], &y[i], &z[i]);
        }
        init(0);
        scanf("%d%d",&S,&T);
        spfa(T);
        init(1);
        ind = 0;
        memset(now,0,sizeof(now));
        memset(pre,-1,sizeof(pre));
        dfs1(S);
        int ans = 0;
        while(bfs()) {
            while(1) {
                int a = dfs(S,inf);
                if(!a)break;
                ans += a;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

// https://blog.csdn.net/yuanjunlai141/article/details/50610598
