#include<cstdio>
#include<string.h>
#include<cmath>
#include<algorithm>

using namespace std;

const int maxn = 1010;

double G[maxn][maxn];
int x[maxn];
int y[maxn];
int n;
void Floyd(){
    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                G[i][j] = min(G[i][j], max(G[i][k], G[k][j]));
            }
        }
    }
}

int main(){
    int cot = 1;
    while(~scanf("%d", &n) && n){
        memset(G, 0, sizeof(G));
        for(int i = 0; i < n; ++i){
            scanf("%d%d", &x[i], &y[i]);
        }
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                G[i][j] = G[j][i] = sqrt((double)(x[i]-x[j]) * (double)(x[i]-x[j]) + (double)(y[i]-y[j]) * (double)(y[i]-y[j]) );
            }
        }
        Floyd();
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n", cot++, G[0][1]);
    }
    return 0;
}
