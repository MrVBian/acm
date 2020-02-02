#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>

using namespace std;

const int maxn = 1010;
const int inf = 0x3f3f3f3f;

int n;
int x[maxn], y[maxn];
double G[maxn][maxn];
int vst[maxn];
double d[maxn];

void spfa(int s){
   queue<int> q;
   q.push(s);
   for(int i = 0; i < n; ++i){
       vst[i] = 0;
       d[i] = inf;
   }
   vst[s] = 1;
   d[s] = 0;
   while(!q.empty()){
        int k = q.front();
        q.pop();
        vst[k] = 0;
        for(int j = 0; j < n; ++j){
            if( d[j] > max(d[k], G[k][j]) ){
                d[j] = max(d[k], G[k][j]);
                if(vst[j] == 0){
                    vst[j] = 1;
                    q.push(j);
                }
            }
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
        spfa(0);
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",cot++,d[1]);
    }

    return 0;
}
