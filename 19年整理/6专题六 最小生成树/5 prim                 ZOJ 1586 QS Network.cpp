#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int verNum = 1500;
const int inf = 0x3f3f3f3f;

int n;
int val[verNum];
int G[verNum][verNum];
int vst[verNum];
int d[verNum];
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

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        sum = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &val[i]);
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                int v;
                scanf("%d", &v);
                if(i == j)
                    G[i][j] = 0;
                else
                    G[i][j] = v+val[i]+val[j];
            }
        }
        Prim(1);
        printf("%d\n", sum);
    }
    return 0;
}
