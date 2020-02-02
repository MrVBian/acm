#include<iostream>
#include<cstring>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;

/*
结构体：Matrix
成员变量：
	int n,m			矩阵大小
	int a[][]		矩阵内容
重载运算符：+、-、*
成员函数：
	void clear()	清空矩阵
*/

const int MAXN=1010;
const int MAXM=1010;

struct Matrix{
    int n,m;
    int a[MAXN][MAXM];
    void clear(){
        n=m=0;
        memset(a,0,sizeof(a));
    }
    Matrix operator + (const Matrix &b) const{
        Matrix tmp;
        tmp.n=n; tmp.m=m;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                tmp.a[i][j]=a[i][j]+b.a[i][j];
        return tmp;
    }
    Matrix operator - (const Matrix &b) const{
        Matrix tmp;
        tmp.n=n; tmp.m=m;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                tmp.a[i][j]=a[i][j]-b.a[i][j];
        return tmp;
    }
    Matrix operator * (const Matrix &b) const{
        Matrix tmp;
        tmp.clear();
        tmp.n=n; tmp.m=b.m;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                for (int k=0; k<m; k++)
                    tmp.a[i][j]+=a[i][k]*b.a[k][j];
        return tmp;
    }
};

/*
    Gauss 消元
    O(n³)
    输入:  a       方程组对应的矩阵
           n       未知数个数
           l,ans   存储解，l[]表示是否为自由元
    输出:  解空间的维数
    EPS:   精度
*/
inline int solve(double a[][MAXN], bool l[], double ans[], const int& n){
    int res=0,r=0;
    for (int i=0; i<n; i++)
        l[i]=false;
    for (int i=0; i<n; i++){
        for (int j=r; j<n; j++)
            if (fabs(a[j][i]>eps)){
                for (int k=i; k<=n; k++)
                    swap(a[j][k], a[r][k]);
                break;
            }
        if (fabs(a[r][i]<EPS)){
            ++res;
            continue;
        }
        for (int j=0; j<n; j++)
            if (j!=r && fabs(a[j][i])>EPS){
                double tmp=a[j][i]/a[r][i];
                for (int k=i; k<=n; k++)
                    a[j][k]-=tmp*a[r][k];
            }
        l[i]=true,r++;
    }
    for (int i=0; i<n; i++)
        if (l[i])
            for (int j=0; j<n; j++)
                if (fabs(a[j][i]>0))
                    ans[i]=a[j][n]/a[j][i];
    return res;
}
