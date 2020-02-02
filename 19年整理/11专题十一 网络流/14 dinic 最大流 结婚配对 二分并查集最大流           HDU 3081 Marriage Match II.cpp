#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;
const int maxn= 2020+5;
const int inf = 0x3f3f3f3f;

struct Edge {
    int from,to,cap,flow;
    Edge() {}
    Edge(int f,int t,int c,int flow):from(f),to(t),cap(c),flow(flow) {}
};

struct Dinic {
    int n,m,s,t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int d[maxn];
    bool vis[maxn];
    int cur[maxn];

    void init(int n,int s,int t) {
        this->n=n, this->s=s, this->t=t;
        edges.clear();
        for(int i=0; i<n; i++) G[i].clear();
    }

    void AddEdge(int from,int to,int cap) {
        edges.push_back( Edge(from,to,cap,0) );
        edges.push_back( Edge(to,from,0,0) );
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool BFS() {
        queue<int> Q;
        memset(vis,0,sizeof(vis));
        vis[s]=true;
        d[s]=0;
        Q.push(s);
        while(!Q.empty()) {
            int x= Q.front();
            Q.pop();
            for(int i=0; i<G[x].size(); ++i) {
                Edge& e=edges[G[x][i]];
                if(!vis[e.to] && e.cap>e.flow) {
                    vis[e.to]=true;
                    d[e.to]=d[x]+1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int DFS(int x,int a) {
        if(x==t || a==0) return a;
        int flow=0,f;
        for(int& i=cur[x]; i<G[x].size(); ++i) {
            Edge& e=edges[G[x][i]];
            if(d[e.to]==d[x]+1 && (f=DFS(e.to,min(a,e.cap-e.flow) ) )>0) {
                e.flow +=f;
                edges[G[x][i]^1].flow -=f;
                flow +=f;
                a-=f;
                if(a==0) break;
            }
        }
        return flow;
    }

    int max_flow() {
        int ans=0;
        while(BFS()) {
            memset(cur,0,sizeof(cur));
            ans +=DFS(s,inf);
        }
        return ans;
    }
} DC;

int par[maxn];
int Find(int x) {
    return par[x]==-1?x : par[x]=Find(par[x]);
}
void Union(int x,int y) {
    int xx = Find(x);
    int yy = Find(y);
    if(xx != yy) par[xx] = yy;
}

bool G[maxn][maxn];

bool solve(int n,int limit) {
    int src=0, dst=2*n+1;
    DC.init(n*2+2,src,dst);
    for(int i=1; i<=n; ++i)
        for(int j=n+1; j<=2*n; ++j)if(G[i][j])
                DC.AddEdge(i,j,1);
    for(int i=1; i<=n; i++) DC.AddEdge(src,i,limit);
    for(int j=n+1; j<=n*2; ++j) DC.AddEdge(j,dst,limit);

    return DC.max_flow() == n*limit;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n,m,f;
        scanf("%d%d%d",&n,&m,&f);
        memset(par,-1,sizeof(par));
        memset(G,0,sizeof(G));
        while(m--) {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u][v+n]=true;
        }
        while(f--) {
            int u,v;
            scanf("%d%d",&u,&v);
            Union(u,v);
        }
        for(int i=1; i<=n; i++)
            for(int j=i+1; j<=n; j++)
                if(Find(i) == Find(j))//属于同一个并查集的 就合并他们的所有与男生的关系
                    for(int k=n+1; k<=n*2; ++k) {
                        G[i][k] = G[j][k] = (G[i][k] || G[j][k]);
                    }

        int l=0, r=n, ans = 0;
        while(l <= r) {
            int mid = (l+r)/2;
            if(solve(n,mid)){
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
