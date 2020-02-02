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
const LL maxn = 110;

int N;
vector<int> G[maxn];
int low[maxn], dfn[maxn];
int par[maxn], indx;
bool isCut[maxn];
void Tarjan(int u, int pa) {
    par[u] = pa;
    dfn[u] = low[u] = indx++;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(dfn[v]==-1) {
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else if(pa != v) //特判重边, 即v也是u的父亲
            low[u] = min(low[u], dfn[v]);
    }
}
void solve() {
    int rootCnt = 0;
    Tarjan(1, 0);
    for(int v = 2; v <= N; ++v) {
        int u = par[v];
        if(u==1) ++rootCnt; //统计根节点子树的数目
        else if(low[v]>=dfn[u])
            isCut[u] = true;
    }
    if(rootCnt>1)
        isCut[1] = true;
}
void init() {
    ms(G, 0);
    ms(dfn, -1);
    ms(par, 0);
    ms(isCut, 0);
    ms(low, -1);
    indx = 0;
}
int main() {
    int a, b;
    while(cin >> N, N) {
        init();
        while(cin >> a, a) {
            while(getchar()!='\n') {
                cin >> b;
                G[a].push_back(b);
                G[b].push_back(a);
            }
        }
        solve();
        int ans = 0;
        for(int i = 1; i <= N; ++i)
            if(isCut[i]) ++ans;
        cout << ans << endl;
    }

    return 0;
}
