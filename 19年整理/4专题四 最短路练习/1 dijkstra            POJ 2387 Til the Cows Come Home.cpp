#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1010;
int G[maxn][maxn];
int vst[maxn];
int d[maxn];
int m, n;

void Dijkstra(int s){
    for(int i = 1; i <= n; ++i){
        d[i] = inf;
        vst[i] = 0;
    }
    d[s] = 0;
    vst[s] = 1;
    for(int i = 0; i < n-1; ++i){
        int Min = inf;
        int k = s;
        for(int j = 1; j <= n; ++j){
            if(!vst[j] && Min > d[j]){
                Min = d[j];
                k = j;
            }
        }
        vst[k] = 1;
        for(int j = 1; j <= n; ++j){
            if(G[k][j])
                if(!vst[j] && d[j] > d[k]+G[k][j]){
                    d[j] = d[k] + G[k][j];
                }
        }
    }
}

int main(){
    while(~scanf("%d %d", &m, &n)){
        memset(G, 0, sizeof(G));
        for(int i = 0; i < m; ++i){
            int x, y, v;
            scanf("%d%d%d", &x, &y, &v);
            if( G[x][y] == 0 || (G[x][y] && v < G[x][y]) ){
                G[x][y] = v;
                G[y][x] = v;
            }
        }
        Dijkstra(1);
        printf("%d\n", d[n]);
    }
    return 0;
}
