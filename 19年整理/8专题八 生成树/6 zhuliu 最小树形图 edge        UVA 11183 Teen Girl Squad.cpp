#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1010;
int mp[maxn][maxn];
int pre[maxn], belong[maxn], vst[maxn], in[maxn];

struct Edge {
    int from, to, val;
}edge[40010];

int zhuliu(int root, int n, int m) {
    int ret = 0, u, v;
    while(1) {
        // 1找最小入边
        for(int i=0; i<n; i++) in[i] = inf;
        for(int i=0; i<m; i++)
            if(edge[i].from != edge[i].to && edge[i].val < in[edge[i].to]) {
                pre[edge[i].to] = edge[i].from;
                in[edge[i].to] = edge[i].val;
            }
        for(int i = 0; i < n; ++i){
            if(i == root)
                continue;
            if(in[i] == inf)
                return inf;// 图不连通，不存在树形图
        }
        // 2找环
        int cnt = 0;// 缩点后节点个数
        memset(belong, -1, sizeof belong);
        memset(vst, -1, sizeof vst);
        in[root] = 0;
        for(int i=0; i < n; ++i) {// 先给环上的点编号
            ret += in[i];//注意：ret只在zhuliu开始时清空一次，在整个过程中都是累加的
            v = i;
            while(vst[v] != i && belong[v] == -1 && v != root) {// 如果没有环，会因为v == root而结束，有环时v会指向环的起点
                vst[v] = i;
                v = pre[v];
            }
            // 环之前的点筛除是靠前推到根节点，环之后的点筛除是靠前推到上一个环
            if(v != root && belong[v] == -1) {
                for(int u = pre[v]; u != v; u = pre[u])
                    belong[u] = cnt;
                belong[v] = cnt ++;
            }
        }
        if(cnt == 0)// 没有环了， 找到最小树形图！
            break;

        // 3缩点，重新编号
        for(int i = 0; i < n; ++i)
            if(belong[i] == -1)
                belong[i] = cnt++;
        for(int i = 0; i < m; ) {
            v = edge[i].to;
            edge[i].from = belong[edge[i].from];
            edge[i].to = belong[edge[i].to];
            // 对于单点到单点，环到单点的权值，因为已经在找环的时候累加过，所以这么减会把权值减成0，恰好符合要求——不然就重复相加了
            // 对于单点到环，或者环到环，因为该点的一条入边已经确定，且只能有一条，所以权值=原来的权值减去在环上的入边的权值
            // 这儿有一个隐含条件：环上的入边的权值一定小于环外入边的权值，如若不然，在求解in数组进而求环的时候，根本不会把这个环认为是环
            if(edge[i].from != edge[i].to) edge[i++].val -= in[v];
            else swap(edge[i], edge[--m]);
        }
        n = cnt;
        root = belong[root];
    }
    return ret;
}

int main() {
    int x, y, z, T, n, m;
    scanf("%d", &T);
    for(int Case = 1; Case <= T; ++Case) {
        memset(mp, inf, sizeof(mp));
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; ++i) {
            scanf("%d%d%d", &x, &y, &z);
            mp[x][y] = min(mp[x][y], z);// 去重
        }
        int top = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(mp[i][j] != inf) {
                    edge[top].from = i;
                    edge[top].to = j;
                    edge[top++].val = mp[i][j];
                }
        int ans = zhuliu(0, n, m);
        printf("Case #%d: ", Case);
        if(ans == inf) printf("Possums!\n");
        else printf("%d\n", ans);
    }
    return 0;
}
