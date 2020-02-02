#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 2010;
const int inf = 0x3f3f3f3f;

int n;
int G[maxn][maxn];
int vst[maxn];
int d[maxn];
int sum;
char s[maxn][10];

void Prim(int s){
    for(int i = 0; i <= n; ++i){
        vst[i] = 0;
        d[i] = G[s][i];
    }
    vst[s] = 1;
    for(int i = 0; i < n-1; ++i){
        int Min = inf;
        int k = s;
        for(int j = 0; j < n; ++j){
            if(!vst[j] && Min > d[j]){
                Min = d[j];
                k = j;
            }
        }
        vst[k] = 1;
        sum += Min;
        for(int j = 0; j < n; ++j){
            if(!vst[j] && d[j] > G[k][j])
                d[j] = G[k][j];
        }
    }
}

int main(){
    while(~scanf("%d", &n)){
        if(!n)
            break;
        sum = 0;
        for(int i = 0; i < n; ++i)
            scanf("%s", s[i]);
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                int v = 0;
                for(int k = 0; k < 7; ++k)
                    if(s[i][k] != s[j][k])
                        v++;
                G[i][j] = G[j][i] = v;
            }
        }
        Prim(1);
        printf("The highest possible quality is 1/%d.\n", sum);
    }
    return 0;
}
