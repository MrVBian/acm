#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int maxn = 1500;
const int inf = 0x3f3f3f3f;

int n;
int val[maxn];
int G[maxn][maxn];
int vst[maxn];
int d[maxn];
int sum;

void Prim(int s){
    for(int i = 1; i <= n; ++i){
        vst[i] = 0;
        d[i] = G[s][i];
    }
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
        sum += Min;
        for(int j = 1; j <= n; ++j){
            if(!vst[j] && d[j] > G[k][j])
                d[j] = G[k][j];
        }
    }
}

//因为该题一定连通，故而没有对G初始化inf
int main(){
    while(~scanf("%d", &n)){
        if(!n)
            break;
        sum = 0;
        for(int i = 1; i <= n*(n-1)/2; ++i){
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            G[x][y] = z;
            G[y][x] = z;
        }
        Prim(1);
        printf("%d\n", sum);
    }
    return 0;
}
