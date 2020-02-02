#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 310;
const int inf = 0x3f3f3f3f;

int n;
int vst[maxn];
int d[maxn];
int G[maxn][maxn];

void spfa(int s){
    queue<int> q;
    memset(vst, 0, sizeof(vst));
    for(int i = 1; i <= n; ++i){
        if(i == s)
            d[i] = inf;
        else{
            d[i] = G[s][i];
            q.push(i);
            vst[i] = 1;
        }
    }
    while(!q.empty()){
        int k = q.front();
        q.pop();
        vst[k] = 0;
        for(int j = 1; j <= n; ++j){
            if(d[j] > d[k] + G[k][j]){
                d[j] = d[k] + G[k][j];
                if(!vst[j]){
                    q.push(j);
                    vst[j] = 1;
                }
            }
        }
    }
}

int main(){
    while(~scanf("%d", &n)){
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                scanf("%d", &G[i][j]);
        spfa(1);
        int v1, v2, v3;
        v1 = d[n];
        v2 = d[1];
        spfa(n);
        v3 = d[n];
        int ans = min(v1, v2+v3);
        printf("%d\n", ans);
    }
    return 0;
}