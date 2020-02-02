#include <stdio.h>
#include <string.h>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 20;
const int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct Point {
    int x, y;
    Point() {}
    Point(int a, int b) { x = a; y = b; }
};
int m, n, d[N][N], tmp;
char g[N][N];

void init() {
    memset(g, 0, sizeof(g));
    tmp = 0;

    scanf("%d%d%*c", &m, &n);

    for (int i = 0; i < m; i++) {
        gets(g[i]);
        for (int j = 0; j < n; j++)
            if (g[i][j] == '#')
                tmp++;
    }
}

int bfs(int x1, int y1, int x2, int y2) {
    memset(d, INF, sizeof(d));

    d[x1][y1] = d[x2][y2] = 0;

    Point k, c;
    
    queue<Point> q;
    q.push(Point(x1, y1));
    q.push(Point(x2, y2));

    while ( !q.empty() ) {
        k = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            c.x = k.x + dir[i][0]; c.y = k.y + dir[i][1];
            if (c.x < 0 || c.x >= m || c.y < 0 || c.y >= n) continue;
            if (g[c.x][c.y] != '#') continue;

            if (d[c.x][c.y] > d[k.x][k.y] + 1) {
                d[c.x][c.y] = d[k.x][k.y] + 1;
                q.push(c);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) if (g[i][j] == '#') {
            ans = max(ans, d[i][j]);
        }
    }
    return ans;
}


int solve() {
    if (tmp <= 2) return 0;
    int ans = INF;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) if (g[i][j] == '#') {
            for (int k = 0; k < m; k++) {
                for (int t = 0; t < n; t++) {
                    if (k == i && t <= j) continue;
                    if (g[k][t] == '#')
                        ans = min(ans, bfs(i, j, k, t));
                }
            }
        }
    }
    return ans == INF ? -1 : ans;
}

int main () {
    int cas;
    scanf("%d", &cas);
    for (int i = 1; i <= cas; i++) {
        init();
        printf("Case %d: %d\n", i, solve());
    }
    return 0;
}