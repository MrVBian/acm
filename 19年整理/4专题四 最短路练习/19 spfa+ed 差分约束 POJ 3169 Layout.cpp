#include <algorithm>
#include <iostream>
#include <string.h>
#include <queue>
#include <cstdio>

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
int cot[maxn];
ll d[maxn];
int t, n, m;

void add(int i, int u, int v, int w){
    e[i].to = v;
    e[i].w = w;
    e[i].next = head[u];
    head[u] = i;
}
bool spfa(int s){
    for(int i = 0; i <= n; ++i){
        vst[i] = 0;
        d[i] = inf;
        cot[i] = 0;
    }
    vst[s] = 1;
    d[s] = 0;
    cot[s] = 1;
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
                    cot[e[j].to] ++;
                    if(cot[e[j].to] > n)
                        return false;
                }
            }
        }
    }
    return true;
}
int main(){
    while(~scanf("%d%d%d", &n, &m, &t)){
        memset(head, -1, sizeof(head));
        memset(e, 0, sizeof(e));
        int x, y, z;
        for(int i = 0; i < m; ++i){
            scanf("%d%d%d", &x, &y, &z);
            add(i, x, y, z);
        }
        for(int i = m; i < m+t; ++i){
            scanf("%d%d%d", &x, &y, &z);
            add(i, y, x, -z);
        }
        if(spfa(1))
            printf("%d\n", d[n] == inf ? -2 : d[n]);
        else
            printf("-1\n");
    }
    return 0;
}