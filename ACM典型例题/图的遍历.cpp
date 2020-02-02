#include <iostream>
using namespace std;
void BFS(Vertex V)
{
    visited[V]=true;
    Enqueue(V,Q);
    while(!IsEmpty(Q)){
        V=Dequeue(Q);
        for( V 的每个邻接点 W ){
            visited[W]=true;
            Enqueue(W,Q);
        }
    }
}

void DFS(Vertex V)
{
    visited[V]=true;
    for( V 的每个邻接点 W ){
        if( !visited[W] )
            DFS( W );
    }
}
