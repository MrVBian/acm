#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn = 1e4;
const int inf = 0x3f3f3f3f;

struct node{
    int to;
    int w;
    int next;
}e[maxn];

int head[maxn], cnt, n;
int d[maxn], vst[maxn];

void add(int u,int to,int w){
    e[cnt].to = to;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

struct Node{
    int u;
    int dis;
    Node(){}
    Node(int uu, int dd){
        u = uu;
        dis = dd;
    }
    bool friend operator <(Node a,Node b){
        return a.dis>b.dis;
    }
};

void dijkstra(int s){
    memset(d, inf, sizeof(d));
    d[s]=0;
    priority_queue<Node> q;
    q.push(Node(s, d[s]));
    while(!q.empty()){
        int k = q.top().u;//到起点距离最短还没有确定的那个点出队
        q.pop();
        vst[k] = 1;//当前这个节点的最短距离确定标记为1
        for(int i = head[k]; ~i; i = e[i].next){
            int to = e[i].to;
            int w = e[i].w;
            if(!vst[to] && d[k] + w < d[to]){
                d[to] = d[k] + w;
                q.push(Node(to, d[to]));
            }
        }
    }
}
int main(){
    memset(head, -1, sizeof(head));
    int t, u, to, w;
    scanf("%d%d", &t, &n);
    for(int i = 0; i < t; ++i){
        scanf("%d%d%d", &u, &to, &w);
        add(u, to, w);
        add(to, u, w);
    }
    dijkstra(1);
    cout<<d[n]<<endl;
    return 0;
}
