#include <queue>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn = 205;
int n, m;
int cot[maxn];
int d[maxn];
int cir[maxn];
int vst[maxn];
int head[maxn];
int val[maxn];
struct node {
    int to, w;
    int next;
    void Node(int x, int y, int z) {
        to = x;
        w = y;
        next = z;
    }
} e[40005];
void init(int n, int m) {
    memset(cot, 0, sizeof(cot));
    memset(d, inf, sizeof(d));
    memset(vst, 0, sizeof(vst));
    memset(cir, 0, sizeof(cir));
    memset(head, -1, sizeof(head));
}
void dfs(int x) {
    cir[x] = 1;
    for(int i = head[x]; i != -1; i = e[i].next) {
        if(!cir[e[i].to]) {
            dfs(e[i].to);
        }
    }
}
void spfa(int s) {
    d[1] = 0;
    cot[s] = 1;
    int pre, nex;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        pre = q.front();
        q.pop();
        vst[pre] = 0;
        if(cir[pre]) continue;     //
        for(int i = head[pre]; i != -1; i = e[i].next) {
            nex = e[i].to;
            if(cir[nex]) continue; //不加会T
            if(d[nex] > d[pre] + e[i].w) {
                d[nex] = d[pre] + e[i].w;
                if(!vst[nex]) {
                    vst[nex] = 1;
                    q.push(nex);
                    if(++cot[nex] >= n) {
                        dfs(nex);
                    }
                }
            }
        }
    }
}
int mul(int x) {
    return x*x*x;
}
int main() {
    int N;
    int u, v;
    int Case = 1;
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &val[i]);
        }
        scanf("%d", &m);
        init(n, m);
        for(int i = 1; i <= m; i++) {
            scanf("%d %d", &u, &v);
            e[i].Node(v, mul(val[v]-val[u]), head[u]);
            head[u] = i;
        }
        spfa(1);
        int Q, q[205];
        scanf("%d", &Q);
        for(int i = 0; i < Q; i++) {
            scanf("%d", &q[i]);
        }
        printf("Case %d:\n", Case++);
        for(int i = 0; i < Q; i++) {
            if(d[q[i]] < 3 || d[q[i]] == inf)
                printf("?\n");
            else if(cir[q[i]]) printf("?\n");
            else printf("%d\n", d[q[i]]);
        }
    }
    return 0;
}