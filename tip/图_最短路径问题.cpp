#include<bits/stdc++.h>
using namespace std;

//无权图的单源最短路径算法
// T = O( |V| + |E| )
// BFS
void unWeighted(Vertex S)
{
    queue<int> q.push(S);
    while(!q.empty()){
        v=q.pop();
        for( V 的每个邻接点 W )
            if( dist[W]==-1 ){
                dist[W]=dist[V]+1;
                path[W]=V;//栈输出
                q.push(W);
            }
    }
}

//有权图的单源最短路算法
dist[]=INFINITE;
path[]=-1
void Dijkstra(Vertex S)
{
    while(1){
        V=未收录顶点中disk最小者;
        if( 这样的 V 不存在 )
            break;
        collected[V]=true;
        for( V 的每个邻接点 W )
            if( collected[W]==false )
                if( dist[V] + E<V,W>  < dist[W] ){
                    dist[W] = dist[V] + E<V,W>;
                    path[W] = V;
                }
    }
}


//Prim算法  稠密图划算
//让一棵小树长大
//T = O ( |V|² )
//城市铺电缆问题
void Prim()
{
    MST={s};
    while(1){
        V=未收录顶点中dist最小者;
        if( 这样的V不存在 )
            break;
        将V收录进MST;
        for( V的每个邻接点W )
            if( W未被收录 )
                if( E(V,W) < dist[W] ){
                    dist[W] = E(V,W);
                    parent[W] = V;
                }
    }
    if( MST中收的顶点不到|V|个 )
        Error（"生成树不存在"）;
}


//Kruskal算法  稀疏图划算
//将森林合并成树
//T = O ( |E|Log|E| )
void Kruskal(Graph G)
{
    MST={ };
    while( MST 中不到 |V| -1 条边 && E中还有边 ) {
        从 E 中取一条权重最小的边 E(V,W);//最小堆
        将 E(V,W) 从 E 中删除;
        if( E(V,W) 不在 MST 中构成回路)//并查集
            将 E(V,W) 加入 MST;
        else
            彻底无视 E(V,W)；
    }
    if( MST 中不到 |V| -1 条边 )
        Error("生成树不存在");
}




//多源最短路算法
#define N 10
// T = O( |V|³ )
void Floyd()
{
    int i,j,k;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++){
            D[i][j]=G[i][j];//G原图
            path[i][j]=-1;
    }
    for(k=0;k<N;k++)
        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
                if(D[i][k]+D[k][j]<D[i][j]){
                    D[i][j]=D[i][k]+D[k][j];
                    path[i][j]=k;//递归输出
                }
}

int main()
{
    ;
}
