#include <stdio.h>
int m,n,a[20][20],ans=2147438647;


void Search(int i,int j,int sum)
{
    sum+=a[i][j];
    if(i<m) Search(i+1,j,sum);
    if(j<n) Search(i,j+1,sum);
    if(i==m&&j==n&&sum<ans&&sum>0)
        ans=sum;
}


int main()
{
    int i,j;
    scanf("%d%d",&m,&n);
    for (i=1; i<=m; i++)
        for (j=1; j<=n; j++)
            scanf("%d",&a[i][j]);
    Search(1,1,0);
    if (ans==2147438647)
        ans=-1;
    printf("%d",ans);
    return 0;
}


//Problem Description
//给定M×N的矩阵，其中的每个元素都是-10到10之间的整数。你的任务是从左上角(1,1)走到右下角(M,N)，每一步只能够向右或者向下，并且不能够走出矩阵的范围。你所经过的方格里面的数字都必须被选取，请找出一条最合适的道路，使得在路上被选取的数字之和是尽可能小的正整数。
//Input
//输入第1行是两个整数M和N,(2<=M<=10,2<=N<=10)，分别表示矩阵的行和列的数目。接下来M行，每行包括N个整数，就是矩阵中的每一行的N个元素。
//Output
//输出只有一行，就是一个整数，表示所选道路上数字之和所能达到的最小正整数。如果不能达到任何正整数，输出-1。
//Sample Input
//2 2
//0 2
//1 0
//Sample Output
//1
