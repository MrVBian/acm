#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>

using namespace std;

const int maxn = 1000;
const int inf = 0x3f3f3f3f;
int t, n, m, w;
int G[maxn][maxn];
int d[maxn];
int cot[maxn];
int vst[maxn];

bool spfa(int s) {
    queue<int> q;
    for(int i = 0; i <= n; ++i) {
        d[i] = inf;
        vst[i] = 0;
        cot[i] = 0;
    }
    d[s] = 0;
    vst[s] = 1;
    cot[s] = 1;
    q.push(s);
    while(!q.empty()) {
        int k = q.front();
        vst[k] = 0;
        q.pop();
        for(int j = 1; j <= n; ++j) {
            if(G[k][j])
                if(d[j] > d[k]+G[k][j]) {
                    d[j] = d[k] + G[k][j];
                    if(!vst[j]) {
                        vst[j] = 1;
                        q.push(j);
                        cot[j] ++;
                        if(cot[j] > n)
                            return true;
                    }
                }
        }
    }
    return false;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        memset(G, 0, sizeof(G));
        scanf("%d%d%d", &n, &m, &w);
        int x, y, z;
        for(int i = 0; i < m; ++i) {
            scanf("%d%d%d", &x, &y, &z);
            if(G[x][y]){
                G[x][y] = min(G[x][y], z);
                G[y][x] = min(G[y][x], z);
            }
            else{
                G[x][y] = z;
                G[y][x] = z;
            }
        }
        for(int i = 0; i < w; ++i) {
            scanf("%d%d%d", &x, &y, &z);
            G[x][y] = -z;
        }
        if(spfa(1))
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
