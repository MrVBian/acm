#include <bits/stdc++.h>

using namespace std;

const int maxn = 25;
int G[maxn][maxn];
int vst[maxn];
int ans[maxn];
int t;
int n;

void dfs(int x, int cot){
    if(x == n && cot == 20){
        printf("%d:  %d ", t++, n);
        for(int i = 0; i <= 19; ++i){
            if(i)
                printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
        return ;
    }

    for(int i = 1; i <= 20; ++i){
        if(!vst[i] && G[x][i]){
            vst[i] = 1;
            ans[cot] = i;
            dfs(i, cot+1);
            vst[i] = 0;
        }
    }
}


int main(){
    for(int i = 1; i <= 20; ++i){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        G[i][x] = G[i][y] = G[i][z] = 1;
    }
    t = 1;
    while(~scanf("%d", &n)){
        if(!n)
            return 0;
        for(int i = 1; i <= 20; ++i){
            vst[i] = 0;
            ans[i] = 0;
        }
        for(int i = 1; i <= 20; ++i){
            if(G[n][i]){
                ans[0] = i;
                vst[i] = 1;
                dfs(i, 1);
                vst[i] = 0;
            }
        }
    }
    return 0;
}
