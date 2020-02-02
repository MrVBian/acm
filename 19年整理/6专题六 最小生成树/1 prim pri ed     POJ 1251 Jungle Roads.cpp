//通过队列prime求解
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
#define Max 0x3f3f3f3f
using namespace std;
const int maxn = 30;
int mp[maxn][maxn];
bool vis[maxn];
vector<int> P[maxn];//P[i]表示i可以到达那些节点

typedef struct node {
    int s, e;
    int w;//起点,终点,权重
} node;

bool operator < (const node& a, const node &b) {
    return a.w > b.w;
}


bool Prim(int s,int n,int& ans) { //开始节点为s的通过Prime算法实现
    ans = 0;
    priority_queue<node> Q;
    memset(vis, 0, sizeof(vis));
    int Vcnt = 1;
    vis[s] = 1;
    node nn;
    while (Vcnt < n) { //表示vis结合中点的个数
        //将s对应的边放入Q当中
        for (int i = 0; i < P[s].size(); i++) {
            if (!vis[P[s][i]]) { //另一个顶点目前没有在集合中
                nn.s = s;
                nn.e = P[s][i];
                nn.w = mp[nn.s][nn.e];
                Q.push(nn);
            }
        }
        //从优先队列中挑选一个潜在的点
        while (!Q.empty() && vis[Q.top().e])
            Q.pop();
        if (Q.empty()) {
            ans = -1;
            return false;
        }
        //此时的队列首部的边已经是要加到最小生成树了
        nn = Q.top();
        Q.pop();
        //将边收入最小生成树
        vis[nn.e] = 1;
        Vcnt++;
        ans += nn.w;
        s = nn.e;//位新的边的放入做准备
    }

    return true;
}


int main() {
    int n;
    while (cin >> n&&n) {
        //图的初始化
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[i][j] = (i==j)?0:Max;
            }
            P[i].clear();
        }
        string s0,s1;
        int k, w;
        for (int i = 0; i < n - 1; i++) {
            cin >> s0 >> k;
            while(k--) {
                cin >> s1 >> w;
                int x = s0[0] - 'A';
                int y = s1[0] - 'A';
                //使用的是无方向边
                mp[x][y] = min(w,mp[x][y]);//防止数据出现问题
                P[x].push_back(y);
                mp[y][x] = min(w, mp[y][x]);//防止数据出现问题
                P[y].push_back(x);
            }
        }

        int ans = 0;
        if (Prim(0, n, ans)) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
