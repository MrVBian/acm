#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

typedef  long long LL;
const int inf = 0x3f3f3f3f;
const LL maxn = 110;

int n, m;
double G[maxn][maxn];
struct node {
    double x, y;
} point[maxn];
double getDis(int x1, int y1, int x2, int y2) {
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

bool vst[maxn], flag[maxn];
int pre[maxn];

double zhuliu(int s) {
    for(int i = 0; i <= n; ++i) {
        vst[i] = 0;
        flag[i] = 0;
    }
    double ans = 0;
    while(true) {
        // 1找最小入边
        for(int i = 1; i <= n; ++i)
            if(i != s && !flag[i]) {
                G[i][i] = inf, pre[i] = i;
                for(int j = 1; j <= n; ++j)
                    if(!flag[j] && G[j][i] < G[pre[i]][i])
                        pre[i] = j;
                if(pre[i] == i) return -1;// 图不连通，不存在树形图
            }
        // 2找环
        int i;
        for(i = 1; i <= n; ++i) {
            if(i != s && !flag[i]) {
                int j = i, cnt = 0;
                while(j != s && pre[j]!=i && cnt <= n)
                    j = pre[j], ++cnt;
                if(j == s || cnt > n) continue;
                break;
            }
        }
        if(i > n) {
            for(int i = 1; i <= n; ++i)
                if(i != s && !flag[i])
                    ans += G[pre[i]][i];
            return ans;
        }

        int j = i;

        for(int i = 0; i <= n; ++i)
            vst[i] = 0;

        do {
            ans += G[pre[j]][j], j = pre[j], vst[j] = flag[j] = true;
        } while(j != i);
        flag[i] = false;

        for(int k = 1; k <= n; ++k)
            if(vst[k]) {
                for(int j = 1; j <= n; ++j)
                    if(!vst[j]) {
                        if(G[i][j] > G[k][j])
                            G[i][j] = G[k][j];
                        if(G[j][k] < inf && G[j][k]-G[pre[k]][k] < G[j][i])
                            G[j][i] = G[j][k] - G[pre[k]][k];
                    }
            }
    }
    return ans;
}

int main() {
    int x, y;
    while(scanf("%d%d", &n, &m)!=EOF) {
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= n; ++j){
                G[i][j] = inf;
            }
        }
        for(int i = 1; i <= n; ++i)
            scanf("%lf%lf", &point[i].x, &point[i].y);
        for(int i = 1; i <= m; ++i) {
            scanf("%d%d", &x, &y);
            G[x][y] = getDis(point[x].x, point[x].y, point[y].x, point[y].y);
        }
        double ans = zhuliu(1);
        if(ans==-1)
            printf("poor snoopy\n");
        else
            printf("%.2f\n",ans);
    }
    return 0;
}
