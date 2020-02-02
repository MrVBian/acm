
/**
求割点
一个顶点u是割点，当且仅当满足(1)或(2)
(1) u为树根，且u有多于一个子树。
(2) u不为树根，且满足存在(u,v)为树枝边(或称 父子边，即u为v在搜索树中的父亲)，使得 dfn(u)<=low(v)。
（也就是说 V 没办法绕过 u 点到达比 u dfn要小的点）
注：这里所说的树是指，DFS下的搜索树*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

#define N 10010
int dfn[N];  ///代表最先遍历到这个点的时间
int low[N];///这个点所能到达之前最早的时间点
int Father[N];///保存这个节点的父亲节点
int n,Time;
vector<vector<int> >G;

void init() {
    G.clear();
    G.resize(n+1);
    memset(low,0,sizeof(low));
    memset(dfn,0,sizeof(dfn));
    memset(Father,0,sizeof(Father));
    Time=0;
}

void Tarjan(int u,int fa) {
    low[u]=dfn[u]=++Time;
    Father[u]=fa;
    int len=G[u].size(), v;
    for(int i=0; i<len; i++) {
        v=G[u][i];
        if(!dfn[v]) {
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
        } else if(fa!=v)
            low[u]=min(dfn[v],low[u]);
    }
}

void solve() {
    int Rootson=0,ans=0;  ///根节点儿子的数量
    bool Cut[N]= {false}; ///标记数组，判断这个点是否是割点


    Tarjan(1,0);ge'dian

    for(int i=2; i<=n; i++) {
        int v=Father[i];
        if(v==1)  ///也是就说 i的父亲是根节点
            Rootson++;
        else if(dfn[v]<=low[i])  ///判断是否满足条件（2）
            Cut[v]=true;
    }
    for(int i=2; i<=n; i++) {
        if(Cut[i])
            ans++;
    }
    if(Rootson>1)  ///满足条件（1）
        ans++;
    printf("%d\n",ans);
}

int main() {
    while(scanf("%d",&n),n) {
        int a,b;
        char ch;
        init();
        while(scanf("%d",&a),a) {
            while(scanf("%d%c",&b,&ch)) {
                G[a].push_back(b);
                G[b].push_back(a);
                if(ch=='\n')
                    break;
            }
        }
        solve();
    }
    return 0;
}
