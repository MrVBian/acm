#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
#define INF INT_MAX
#define _for(i,a,b) for(int i=(a);i<(b);i++)
const int Vertex=6;
int dist[Vertex];
int MGraph[Vertex][Vertex]={ {INF,7,4,INF,INF,INF},  //测试MGraph
                            {7,INF,6,2,INF,4},
                            {4,6,INF,INF,9,8},
                            {INF,2,INF,INF,INF,7},
                            {INF,INF,9,INF,INF,1},
                            {INF,4,8,7,1,INF},
                          };

int Prim(int cur)
{
    int index=cur;
    int sum=0;
    cout<<index<<"  ";
    bool *visit=new bool[Vertex];
    visit[index]=true;
    _for(i,0,Vertex)
        dist[i]=MGraph[cur][i];//初始化初始顶点邻接点距离
    _for(i,1,Vertex){
        int Min=INF;
        _for(j,0,Vertex)
            if(!visit[j] && dist[j]<Min){
                Min=dist[j];
                index=j;
            }

        visit[index]=true;
        cout<<index<<"  ";
        sum+=Min;

        _for(j,0,Vertex)
            if(!visit[j] && dist[j]>MGraph[index][j])
                dist[j]=MGraph[index][j];//更新点距离,如果当前点的距离更近，就更新dist
    }
    cout<<endl;
    return sum;
}

int main()
{
    cout<<Prim(0);
}
