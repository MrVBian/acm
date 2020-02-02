#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>

using namespace std;

const int maxn = 1010;
const int inf = 0x3f3f3f3f;

int n, m;
int G[maxn][maxn];
int vst[maxn];
int d[maxn];

void spfa(int s){
    for(int i = 1; i <= n; ++i){
        vst[i] = 0;
        d[i] = 0;
    }
    d[s] = inf;
    queue<int> q;
    q.push(s);
    vst[s] = 1;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        vst[k] = 0;
        for(int j = 1; j <= n; ++j){
            if(d[j] < min(d[k], G[k][j])){
                d[j] = min(d[k], G[k][j]);
                if(vst[j] == 0){
                    vst[j] = 1;
                    q.push(j);
                }
            }
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    for(int p = 1; p <= t; ++p){
        memset(G,0,sizeof(G));
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; ++i){
            int x,y,v;
            scanf("%d%d%d", &x,&y,&v);
            if(G[x][y] == 0 || (G[x][y] && G[x][y] < v) )
                G[x][y] = G[y][x] = v;
        }
        spfa(1);
        printf("Scenario #%d:\n%d", p, d[n]);
        if( p!= t  )
            printf("\n\n");
    }
    return 0;
}
