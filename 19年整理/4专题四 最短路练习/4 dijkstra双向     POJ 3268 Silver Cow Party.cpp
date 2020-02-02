#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

#define ms(x,y) memset((x),(y),sizeof(x))
const int maxn = 1010;
const int inf = 0x3f3f3f3f;

int n,m,x;
int G[maxn][maxn];
int ans[maxn];
int vst[maxn];
int d[maxn];

void Dijkstra(int s){
    for(int i = 0; i <= n; ++i){
        vst[i] = 0;
        d[i] = inf;
    }
    vst[s] = 1;
    d[s] = 0;
    for(int i = 0; i < n-1; ++i){
        int Min = inf;
        int k = s;
        for(int j = 1; j <= n; ++j){
            if( !vst[j]&&Min > d[j]){
                Min = d[j];
                k = j;
            }
        }
        vst[k] = 1;
        for(int j = 1; j <= n; ++j){
            if( G[k][j] ){
                if( d[j] > d[k] + G[k][j] ){
                    d[j] = d[k] + G[k][j];
                }
            }
        }
    }
}

void reverse(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            swap(G[i][j], G[j][i]);
        }
    }
}

int main(){
    while(~scanf("%d%d%d", &n,&m,&x)){
        ms(G, 0);
        ms(ans, 0);
        int Max = 0;
        for(int i = 0; i < m; ++i){
            int p, q, v;
            scanf("%d%d%d", &p,&q,&v);
            if(G[p][q] == 0 || (G[p][q] && G[p][q] > v)){
                G[p][q] = v;
            }
        }
        Dijkstra(x);
        for(int i = 1; i <= n; ++i)
            ans[i] = d[i];
        reverse();
        Dijkstra(x);
        for(int i = 1; i <= n; ++i){
            ans[i] += d[i];
            Max = max(Max, ans[i]);
        }
        printf("%d\n", Max);
    }
    return 0;
}
