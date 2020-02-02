#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

const int maxn = 1e5+7;
const int inf = 0x3f3f3f3f;

vector<int> G[maxn];
stack<int> s;
int dfn[maxn], low[maxn], vst[maxn], belong[maxn], num[maxn];
int in[maxn],out[maxn];
int n, m, tot, cnt, msum;
void Tarjan(int x){
    dfn[x] = low[x] = ++tot;
    s.push(x);
    vst[x] = 1;
    for (int i = 0; i < G[x].size();i++){
        int v = G[x][i];
        if(!dfn[v]){
            Tarjan(v);
            low[x] = min(low[x], low[v]);
        }
        else if(vst[v]){
            low[x] = min(low[x], dfn[v]);
        }
    }
    if(dfn[x] == low[x]){
        cnt++;
        while (1){
            int now = s.top();
            s.pop();
            vst[now] = 0;
            num[cnt]++;
            belong[now] = cnt;
            if(now==x) break;
        }
    }
}

void init(){
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(vst, 0, sizeof(vst));
    memset(belong, 0, sizeof(belong));
    memset(num, 0, sizeof(num));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    for(int i = 1;i <= n; ++i)
        G[i].clear();
}

int main(){
    int t;
    int k = 1;
    scanf("%d",&t);
    while (t--){
        init();
        scanf("%d %d", &n, &m);
        for (int i = 0;i < m; ++i){
            int x, y;
            scanf("%d %d", &x, &y);
            G[x].push_back(y);
        }
        tot = 0, cnt = 0;
        for (int i = 1;i <= n; ++i){
            if(!dfn[i])
                Tarjan(i);
        }

        if(cnt == 1){
            printf("Case %d: -1\n", k++);
            continue;
        }

        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < G[i].size(); ++j) {
                int u = belong[i];
                int v = belong[ G[i][j] ];
                if(u != v){
                    out[u] ++;
                    in[v] ++;
                }
            }
        }
        msum = inf;
        for (int i = 1;i <= cnt; ++i){
            if(!out[i])
                msum = min(msum, num[i]);
            if(!in[i])
                msum = min(msum, num[i]);
        }
        ll ans = (long long) n * (n - 1);// 完全图的边数(n*(n-1))
        // 这个特殊的DAG与外界不能相连的边数,即该DAG里的顶点个数乘以除该DAG的顶点外的所有顶点数
        ans -= (long long) msum * (n - msum);
        printf("Case %d: %d\n", k++, ans - m);// 原来图本就存在的边数m
    }
    return 0;
}
