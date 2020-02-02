#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;
const int maxn = 110;
const int inf = 0x3f3f3f3f;

int n, m;
int G[maxn][maxn];
int vst[maxn];
int d[maxn];
int sum;

void Prim(int s) {
    for(int i = 0; i <= n; ++i) {
        vst[i] = 0;
        d[i] = G[s][i];
    }
    vst[s] = 1;
    for(int i = 0; i < n-1; ++i) {
        int Min = inf;
        int k = s;
        for(int j = 1; j <= n; ++j) {
            if(!vst[j] && Min > d[j]) {
                Min = d[j];
                k = j;
            }
        }
        vst[k] = 1;
        sum += Min;
        for(int j = 1; j <= n; ++j) {
            if(!vst[j] && d[j] > G[k][j]) {
                d[j] = G[k][j];
            }
        }
    }
}

int main() {
    int v;
    while(~scanf("%d", &n)){
        sum = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                scanf("%d", &v);
                G[i][j] = v;
            }
        }
        Prim(1);
        printf("%d\n", sum);
    }
    return 0;
}
