#include<iostream>
#include<string.h>
#include<stdio.h>
#include<queue>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1010;
int G[maxn][maxn];
int vst[maxn];
int d[maxn];
int m, n;


struct Node{
    int p, d;
    Node(){}
    Node(int pp, int dd):p(pp), d(dd){}
    friend bool operator<(Node a, Node b){
        if(a.p != b.p)
            return a.d > b.d;//优先小的出
        return a.d > b.d;//优先编号小的
    }
}p;

void Dijkstra(int s){
    for(int i = 1; i <= n; ++i){
        d[i] = inf;
        vst[i] = 0;
    }
    d[s] = 0;
    priority_queue<Node> q;
    q.push(Node(s, d[s]));
    while(!q.empty()){
        int k = q.top().p;
        q.pop();
        if(vst[k])
            continue;
        vst[k] = 1;//用过的点标记不用
        for(int j = 1; j <= n; ++j){
            if(!vst[j] && G[k][j] && d[j]> d[k]+G[k][j]){//注意需要判断G[k][j]边是否存在
                d[j] = d[k] + G[k][j];
                q.push(Node(j, d[j]));
            }
        }
    }
}

int main(){
    while(~scanf("%d %d", &m, &n)){
        memset(G, 0, sizeof(G));
        for(int i = 0; i < m; ++i){
            int x, y, v;
            scanf("%d%d%d", &x, &y, &v);
            if( G[x][y] == 0 || (G[x][y] && v < G[x][y]) ){
                G[x][y] = v;
                G[y][x] = v;
            }
        }
        Dijkstra(1);
        printf("%d\n", d[n]);
    }
    return 0;
}
