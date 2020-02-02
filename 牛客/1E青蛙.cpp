#include <iostream>
#include <algorithm>
using namespace std;
int map[300][300];
int book[300];
int ans[300];
int sum = 999, m, n;
void dfs(int k, int total)
{
	if (total >= sum)
		return;
	if(total>(m-k+sum))
        return;
	ans[k]=min(ans[k],total);
	if (k == m)
	{
		sum = min(sum, total);
		return;
	}
	for (int i = 1; i <= m; i++)
	{
		if (map[k][i] != 0 && book[i] == 0)
		{
            book[i] = 1;
			if((total + map[k][i])<ans[i])
			dfs(i,total + map[k][i]);
			book[i] = 0;
		}
	}
}
int main()
{
	int a, b;
	scanf("%d%d", &m, &n);
	sum=m;
	for(int i=0;i<=m;i++)
        ans[i]=9999;
	map[0][1]=1;
	map[1][0]=1;
	for (int i = 2; i < 240; i++)
	{
		map[i - 1][i] = 1;
		map[i][i - 1] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		map[a][b] = 1;
	}
	book[1] = 1;
	dfs(1, 1);
	printf("%d\n", sum);
	return 0;
}
