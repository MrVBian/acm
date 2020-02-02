//迪杰斯特拉算法
#include <iostream>
using namespace std;
#include<string>

#define MaxInt 32767                    					//表示极大值，即∞
#define MVNum 100                       					//最大顶点数
typedef char VerTexType;              						//假设顶点的数据类型为字符型
typedef int ArcType;                  						//假设边的权值类型为整型

int *Dist=new int[MVNum];	                    			//用于记录最短路的长度
int *S=new int[MVNum];          							//标记顶点是否进入S集合
string *Path=new string[MVNum];									//用于记录最短路顶点的前驱


//------------图的邻接矩阵-----------------
typedef struct AMGraph{
	VerTexType vexs[MVNum];            						//顶点表
	ArcType arcs[MVNum][MVNum];      						//邻接矩阵
	int vexnum,arcnum;                						//图的当前点数和边数
}AMGraph;

int LocateVex(AMGraph G , VerTexType v){
	//确定点v在G中的位置
	for(int i = 0; i < G.vexnum; ++i)
		if(G.vexs[i] == v)
			return i;
   return -1;
}

void CreateUDN(AMGraph &G){
    //采用邻接矩阵表示法，创建无向网G
	int i , j , k;
	cout <<"请输入总顶点数，总边数，以空格隔开:";
    cin >> G.vexnum >> G.arcnum;							//输入总顶点数，总边数
	cout << endl;

	cout << "输入点的名称:，如a" << endl;

    for(i = 0; i < G.vexnum; ++i){
		cout << "请输入第" << (i+1) << "个点的名称:";
		cin >> G.vexs[i];                        			//依次输入点的信息
	}
	cout << endl;
    for(i = 0; i < G.vexnum; ++i)                			//初始化邻接矩阵，边的权值均置为极大值MaxInt
		for(j = 0; j < G.vexnum; ++j)
			if(i==j)
				G.arcs[i][j]=0;
			else
			    G.arcs[i][j] = MaxInt;
	cout << "输入边依附的顶点及权值，如a b 7" << endl;
	for(k = 0; k < G.arcnum;++k){							//构造邻接矩阵
		VerTexType v1 , v2;
		ArcType w;
		cout << "请输入第" << (k + 1) << "条边依附的顶点及权值:";
		cin >> v1 >> v2 >> w;								//输入一条边依附的顶点及权值
		i = LocateVex(G, v1);  j = LocateVex(G, v2);		//确定v1和v2在G中的位置，即顶点数组的下标
		G.arcs[i][j] = w;									//边<v1, v2>的权值置为w
		G.arcs[j][i] = G.arcs[i][j];						//置<v1, v2>的对称边<v2, v1>的权值为w
	}
}
int MinEdge(AMGraph G,int *Dist){
	//返回权值最小的点
	int i;
	int index = -1;
	int min = MaxInt;
	for(i = 0 ; i < G.vexnum ; ++i){
		if(Dist[i] != 0 && min > Dist[i]){
			min = Dist[i];
			index = i;
		}
	}
	return index;
}
void ShortestPath_DIJ(AMGraph G, int v0){
    //用Dijkstra算法求有向网G的v0顶点到其余顶点的最短路径
	int i;
	for(i=0;i<G.vexnum;i++){
		Dist[i]=G.arcs[v0][i];
		if(Dist[i]!=MaxInt&&Dist[i]!=0)
			Path[i]=Path[i]+G.vexs[v0]+G.vexs[i];
		else
			Path[i]="";
	}
	S[0]=v0;
	Dist[v0]=0;
	int num=1;
	while(num<G.vexnum){
		int k=MinEdge(G,Dist);//在Dist中查找最小值元素
		cout<<Dist[k]<<"\t"<<Path[k]<<endl;
		S[num++]=k;//将新生成的终点加入集合S
		for(i=0;i<G.vexnum;i++)   //修改数组Dsit和Path
			if(Dist[i]>Dist[k]+G.arcs[k][i]){
				Dist[i]=Dist[k]+G.arcs[k][i];
				Path[i]=Path[k]+G.vexs[i];
			}
		Dist[k]=0;   //置顶点k为已生成终点标记
	//for(i=0;i<G.vexnum;i++)//此时Dist的值
	//	cout<<Dist[i]<<"\t";
	//cout<<endl;
	}

}
void DisplyG(AMGraph G){
		//显示图G
	int i,j;
	cout << "图G的邻接矩阵如下："<<endl;
	for(i = 0 ; i < G.vexnum ; ++i){
		for(j = 0; j < G.vexnum; ++j){
			if(j != G.vexnum - 1){
				if(G.arcs[i][j] != MaxInt)
					cout << G.arcs[i][j] << "\t";
				else
					cout << "∞" << "\t";
			}
			else{
				if(G.arcs[i][j] != MaxInt)
					cout << G.arcs[i][j] <<endl;
				else
					cout << "∞" <<endl;
			}
		}
	}
	cout << endl;
}
void DisplayPath(AMGraph G , string *Path,int num_destination){
	//for(int i=0;i<G.vexnum;i++)  //显示打印各条最短路径
	//cout << Path[i]<< endl;
	cout << Path[num_destination]<< endl;
}


void main()
{
	cout << "************迪杰斯特拉算法**************" << endl << endl;
	AMGraph G;
	int i , j ,num_start , num_destination;
	VerTexType start , destination;
	CreateUDN(G);
	cout <<endl;
	cout << "*****无向网G创建完成！*****" << endl;
	DisplyG( G);
	cout << "请依次输入起始点、终点名称：";
	cin >> start >> destination;
	num_start = LocateVex(G , start);
	num_destination = LocateVex(G , destination);
	ShortestPath_DIJ(G , num_start);
	cout << endl <<"最短路径为：";
	DisplayPath(G , Path,num_destination);
}

