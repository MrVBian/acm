#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

const int maxn = 1010;
const int inf = 0x3f3f3f3f;

int n;
int x[maxn], y[maxn];
double G[maxn][maxn];
double d[maxn];
int vst[maxn];

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
        for(int j = 0; j < n; ++j){
            if(!vst[j] &&  Min > d[j]){
                Min = d[j];
                k = j;
            }
        }
        vst[k] = 1;
        for(int j = 0; j < n; ++j){
            if(G[k][j])
                d[j] = min(d[j],  max(d[k], G[k][j]) );
        }
    }
}

int main(){
    int cot = 1;
    while(~scanf("%d",&n) && n){
        memset(G,0,sizeof(G));
        for(int i = 0; i < n; ++i){
            scanf("%d%d",&x[i],&y[i]);
        }
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                G[i][j] = G[j][i] = sqrt( (double)(x[i]-x[j]) * (double)(x[i]-x[j]) + 
                                          (double)(y[i]-y[j]) * (double)(y[i]-y[j]) );
            }
        }
        Dijkstra(0);
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",cot++,d[1]);
    }

    return 0;
}