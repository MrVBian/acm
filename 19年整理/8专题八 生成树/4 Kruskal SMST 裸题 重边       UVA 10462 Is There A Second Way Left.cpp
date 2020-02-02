#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define ms(x, n) memset(x,n,sizeof(x));
typedef  long long LL;
const int inf = 1 << 30;
const LL maxn = 1100;

int n, m;
struct Edge {
    int u, v, w;
    Edge(int uu, int vv, int ww) {
        u = uu, v = vv, w = ww;
    }
    Edge() {}
} es[maxn * maxn];

int par[maxn], rak[maxn];
void init(int n) {
    for(int i = 0; i <= n; i++)
        par[i] = i, rak[i] = 0;
}
int Find(int x) {
    if(x == par[x])
        return x;
    else
        return par[x] = Find(par[x]);
}

bool cmp(const Edge &a, const Edge &b) {
    return a.w < b.w;
}

int maxD[maxn][maxn];  //MST中从i->j的最大权值
bool vst[maxn * maxn];
vector<int> mst[maxn]; //该点是否已经在MST中
int sum, csum;

int Kruskal() {
    sort(es + 1, es + 1 + m, cmp);
    init(n);
    ms(maxD, 0);
    ms(mst, 0);
    ms(vst, 0);
    for(int i = 0; i <= n; ++i)
        mst[i].push_back(i);

    sum = 0;
    int k = 0;
    for(int i = 1; i <= m; ++i) {
        int u = Find(es[i].u);
        int v = Find(es[i].v);
        int w = es[i].w;
        if(Find(u) != Find(v)) {
            sum += w;
            vst[i] = true;
            for(int j = 0; j < mst[u].size(); ++j)
                for(int k = 0; k < mst[v].size(); ++k)
                    maxD[ mst[u][j] ][ mst[v][k] ] = maxD[ mst[v][k] ][ mst[u][j] ] = w;
            par[u] = v;
            for(int j = 0; j < mst[u].size(); ++j)
                mst[v].push_back(mst[u][j]);    //单向存储即可
            if(++k == n-1) break;
        }

    }
//    cout << sum << endl;
    if(k != n-1) return -1;
    csum = inf;
    for(int i = 1; i <= m; ++i)
        if(!vst[i])
            csum = min(csum, sum + es[i].w - maxD[es[i].u][es[i].v]);
    return csum;
}


int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t){
        cin >> n >> m;
        for(int i = 1; i <= m; ++i)
            cin >> es[i].u >> es[i].v >> es[i].w;

        int ret = Kruskal();
        cout << "Case #" << t << " : ";
        if(ret == -1) cout << "No way\n";
        else if(csum==inf) cout << "No second way\n";
        else cout << csum << endl;
    }
    return 0;
}
