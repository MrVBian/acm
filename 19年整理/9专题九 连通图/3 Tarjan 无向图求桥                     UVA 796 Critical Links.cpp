#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define ms(x, n) memset(x,n,sizeof(x));
typedef  long long LL;
const int inf = 1<<30;
const LL maxn = 11000;

int N, head[maxn], ecnt;
struct node {
    int u, v;
    int next;
} es[maxn*10];
void addEdge(int u, int v) {
    es[ecnt].v = v;
    es[ecnt].next = head[u];
    head[u] = ecnt++;
}
int low[maxn], dfn[maxn];
int par[maxn], indx;

typedef pair<int, int> P;
vector<P> ans;
bool cmp(node a, node b) {
    return a.u < b.u;
}

void Tarjan(int u, int pa) {
    par[u] = pa;
    dfn[u] = low[u] = ++indx;
    bool flag = false;
    for(int i = head[u]; i != -1; i = es[i].next) {
        int v = es[i].v;
       if(v==pa && !flag) { //判重边
           flag = true;
           continue;
       }
        if(!dfn[v]) {
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else if(pa != v)
            low[u] = min(low[u], dfn[v]);
    }
}
void init() {
    ms(es, 0);
    ms(low, 0);
    ms(dfn, 0);
    ms(par, 0);
    ms(head, -1);
    ans.clear();
    indx = 0, ecnt = 0;
}

int main() {
    int u, tn, v;
    while(scanf("%d",&N)!=EOF) {
        init();
        for(int i = 1; i <= N; ++i) {
            scanf("%d (%d)",&u,&tn);
            while(tn--) {
                scanf(" %d",&v);
                if(v <= u) continue; //减少重边
                addEdge(u, v);
                addEdge(v, u);
            }
        }

        for(int i = 0; i < N; ++i)
            if(!dfn[i])
                Tarjan(i, -1);


//一条边(u,v)是桥当且仅当满足(u,v)为树枝边，且low[v]>dfn[u]
        for(int v = 0; v < N; ++v) {
            int u = par[v];
            if(u!=-1 && dfn[u] < low[v]) {// u!=-1不是根即树枝边。
                if(v < u) ans.push_back(P(v, u)); //小的在前
                else ans.push_back(P(u, v));
            }
        }

        sort(ans.begin(), ans.end());
        printf("%d critical links\n",ans.size());
        for(int i = 0; i < (int)ans.size(); ++i)
            printf("%d - %d\n",ans[i].first,ans[i].second);
        printf("\n");
    }

    return 0;
}
