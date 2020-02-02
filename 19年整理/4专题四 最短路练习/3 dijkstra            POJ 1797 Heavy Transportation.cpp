#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define ms(x,y) memset( (x), (y), sizeof(x) )
const int maxn = 1010;
const int inf = 0x3f3f3f3f;
int t, n, m;
int G[maxn][maxn];
int vst[maxn];
int d[maxn];

void Dijkstra(int s){
    for(int i = 0; i <= n; ++i){
        d[i] = 0;
        vst[i] = 0;
    }
    d[s] = inf;
    vst[s] = 1;
    for(int i = 0; i < n-1; ++i){
        int Max = 0;
        int k = s;
        for(int j = 1; j <= n; ++j){
            if(!vst[j] && Max < d[j]){
                Max = d[j];
                k = j;
            }
        }
        vst[k] = 1;
        for(int j = 1; j <= n; ++j){
            if(G[k][j]){
                d[j] = max(d[j], min(d[k], G[k][j]));
            }
        }
    }
}

int main(){
    scanf("%d", &t);
    for(int p = 1 ; p <= t; ++p){
        ms(G, 0);
        scanf("%d%d",&n,&m);
        for(int i = 0;i < m; ++i){
            int x,y,v;
            scanf("%d%d%d",&x,&y,&v);
            if(G[x][y] == 0 || (G[x][y] && G[x][y] < v  ))
                G[x][y] = G[y][x] = v;
        }
        Dijkstra(1);
        printf("Scenario #%d:\n%d", p,d[n]);
        if(p!=t)
            printf("\n\n");
    }
    return 0;
}
