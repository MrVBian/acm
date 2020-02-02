#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;
const int maxn = 800;
const int inf = 0x3f3f3f3f;

int n, m;
int G[maxn][maxn];
int vst[maxn];
int d[maxn];
int sum;
vector<pair<int,int> > point;
int path[maxn];

void Prim(int s) {
    for(int i = 0; i <= n; ++i) {
        vst[i] = 0;
        d[i] = G[s][i];
    }
    vst[s] = 1;
    for(int i = 0; i < n-1; ++i) {
        int Min = inf;
        int k = s;
        for(int j = 1; j <= n; ++j) {
            if(!vst[j] && Min > d[j]) {
                Min = d[j];
                k = j;
            }
        }
        vst[k] = 1;
        sum += Min;
        if(Min){
            printf("%d %d\n", path[k], k);
        }
        for(int j = 1; j <= n; ++j) {
            if(!vst[j] && d[j] > G[k][j]) {
                d[j] = G[k][j];
                path[j] = k;
            }
        }
    }
}

int dis(int x1, int y1, int x2, int y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main() {
    int x, y;
    scanf("%d", &n);
    sum = 0;

    for(int i = 0; i <= n; ++i) {
        path[i] = 1;
        for(int j = 0; j <= n; ++j) {
            G[i][j] = inf;
        }
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d%d", &x, &y);
        point.push_back(make_pair(x, y));
    }
    scanf("%d", &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &x, &y);
        G[x][y] = G[y][x] = 0;
    }

    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            if(G[i+1][j+1]) {//死于下标
                int v = dis(point[i].first, point[i].second, point[j].first, point[j].second);
                G[i+1][j+1] = G[j+1][i+1] = v;//死于下标
            }
        }
    }

    Prim(1);
    return 0;
}
