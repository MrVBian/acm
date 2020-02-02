/*

该DFS 框架以2D 坐标范围为例，来体现DFS 算法的实现思想。

*/

#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int maxn=100;
bool vst[maxn][maxn]; // 访问标记
int map[maxn][maxn]; // 坐标范围
int dir[4][2]={0,1,0,-1,1,0,-1,0}; // 方向向量，(x,y)周围的四个方向

bool CheckEdge(int x,int y) // 边界条件和约束条件的判断
{
	if(!vst[x][y] && ...) // 满足条件
		return 1;
	else // 与约束条件冲突
		return 0;
}

void dfs(int x,int y)
{
	vst[x][y]=1; // 标记该节点被访问过
	if(map[x][y]==G) // 出现目标态G
		{
            ...... // 做相应处理
            return;
		}
	for(int i=0;i<4;i++)
	{
		if(CheckEdge(x+dir[i][0],y+dir[i][1])) // 按照规则生成下一个节点
			dfs(x+dir[i][0],y+dir[i][1]);
	}
	return; // 没有下层搜索节点，回溯
}

int main()
{
    ......
    return 0;
}
