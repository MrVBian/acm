#include<cstdio>
#include<malloc.h>

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;//定点数
    int Ne;//边数
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data[MaxVertexNum];//存顶点的数据
};
typedef PtrToGNode MGraph;


//MGraph初始化
typedef int Vertex;
MGraph CreateGraph(int VertexNum)
{
    Vertex V,W;
    MGraph Graph;
    Graph=(MGraph)malloc(sizeof(struct GNode));
    Graph->Nv=VertexNum;
    Graph->Ne=0;

    for(V=0;V<Graph->Nv;V++)
        for(W=0;W<Graph->Nv;W++)
            Graph->G[V][W]=0;

    return Graph;
}


//向MGraph中插入边
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1,V2;//有向边<V1,V2>
    WeightType Weight;//权重
};
typedef PtrToENode Edge;


void InsertEdge(MGraph Graph.Edge E)
{
    Graph->G[E->V1][E->V2]=E->Weight;
    //若是无向图，还要插入边<V2,V1>
    Graph->G[E->V2][E->V1]=E->Weight;
}


//完整地建立一个MGraph
MGraph BuildGraph()
{
    MGraph Graph;

    Edge E;
    Vertex V;
    int Nv,i;

    scanf("%d",&Nv);
    Graph=CreateGraph(Nv);
    scanf("%d",&(Graph->Ne));
    if( Graph->Ne!= 0 ){
        E=(Edge)malloc(sizeof(struct ENode));
        for(i=0;i<Graph-<Ne;i++){
            scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
            InsertEdge(Graph,E);
        }
    }

    //如果顶点有数据的话，读入数据
    for(V=0;V<Graph->Nv;V++)
        scanf(" %c",&(Graph->Data[V]));

    return Graph;
}


//精简
int G[MAXN][MAXN],Nv,Ne;
void BuildGraph()
{
    int i,j,v1,v2,w;
    /*CreateGraph()*/
    scanf("%d",&Nv);
    for(i=0;i<Nv;i++)
        for(j=0;j<Nv;j++)
            G[i][j]=0;
    scanf("%d",&Ne);
    for(i=0;i<Ne;i++){
        scanf("%d %d %d",&v1,&v2,&w);
        /*InsertEdge*/
        G[v1][v2]=w;
        G[v2][v1]=w;
    }
}


typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
    DataType Data;//存顶点的数据
}AdjList[MaxVertexNum];

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
    Vertex AdjV;//邻接点下标
    WeightType Weight;//边权重
    PtrToAdjVNode Next;
};


typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    AdjList G;//邻接表
};
typedef PtrToGNode LGraph;


