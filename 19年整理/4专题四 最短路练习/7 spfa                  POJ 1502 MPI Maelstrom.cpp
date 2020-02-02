#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

const int maxn = 210;
const int inf = 0x3f3f3f3f;

int n;
int G[maxn][maxn];
int vst[maxn];
int d[maxn];

void spfa(int s){
    for(int i = 0; i <= n; ++i){
        vst[i] = 0;
        d[i] = inf;
    }
    vst[s] = 1;
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int k = q.front();
        q.pop();
        vst[k] = 0;
        for(int j = 1; j <= n; ++j){
            if(d[j] > d[k] + G[k][j]){
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
    while(~scanf("%d", &n)){
        memset(G, 0, sizeof(G));
        char ch[12];
        for(int i = 2; i <= n; ++i){
            for(int j = 1; j <= i-1; ++j){
                scanf("%s", ch);
                if(ch[0] != 'x'){
                    G[i][j] = atoi(ch);
                    G[j][i] = G[i][j];
                }
                else{
                    G[i][j] = G[j][i] = inf;
                }
            }
        }

/*
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                printf("%4d", G[i][j]);
            }
            printf("\n");
        }
*/

        spfa(1);
        int Max = 0;
        for(int i = 1; i <= n; ++i){
            Max = max(Max, d[i]);
        }
        printf("%d\n", Max);
    }
    return 0;
}
