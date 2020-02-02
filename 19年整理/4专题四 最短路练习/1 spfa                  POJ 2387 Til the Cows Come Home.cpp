#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>

using namespace std;

const int maxn = 1010;
const int inf = 0x3f3f3f3f;
int n, m;
int G[maxn][maxn];
int d[maxn];
int vst[maxn];

void spfa(int s){
   queue<int> q;
   for(int i = 0; i <= n; ++i){
       d[i] = inf;
   }
   d[s] = 0;
   memset(vst, 0, sizeof(vst));
   vst[s] = 1;
   q.push(s);
   while(!q.empty()){
       int k = q.front();
       vst[k] = 0;
       q.pop();
       for(int j = 1; j <= n; ++j){
           if(G[k][j])
           if(d[j] > d[k]+G[k][j]){
               d[j] = d[k] + G[k][j];
               if(!vst[j]){
                   vst[j] = 1;
                   q.push(j);
               }
           }
       }
   }
}

int main(){
    while(~scanf("%d %d", &m, &n)){
        memset(G, 0, sizeof(G));
        for(int i = 0; i < m; ++i){
            int x, y, v;
            scanf("%d %d %d", &x, &y, &v);
            if(!G[x][y] || (G[x][y] && G[x][y] > v) ){
                G[x][y] = G[y][x] = v;
            }
        }
        spfa(1);
        printf("%d\n", d[n]);
    }
    return 0;
}