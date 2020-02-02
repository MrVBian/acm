#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;

int f[maxn];
int d[maxn];

int fa(int a){//路径压缩
    return f[a]==a?a:f[a]=fa(f[a]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)//建集合
        f[i]=i;
    for(int i=1;i<n;i++){
        int f1,f2;
        cin>>f1>>f2;
        if(f1!=1&&f2!=1)
        f1=fa(f1),f2=fa(f2),f[f2]=f1;
    }
    int ans=0;
    for(int i=1;i<=n;i++){//计算对应集合的解
        d[fa(i)]++;
        ans=max(ans,d[fa(i)]);
    }
    cout<<ans<<endl;
}
//题目描述
//    凤凰于飞，翙翙其羽，亦集爰止。
//                                        ——《诗经·卷阿》
//传说，凤凰是百鸟之王。有一天，凤凰要召开百鸟大会，百鸟国是一个由n个节点组成的树，每个节点有一只鸟，开会的节点定在1号节点。每只鸟可以花费1s通过一条边，由于每根树枝(边)的载重有限，只允许一只鸟同时通过。作为会议的策划师，HtBest想知道百鸟国的所有鸟在1点集合最少需要多少秒。
//输入描述:
//第一行有一个正整数n，表示百鸟国节点个数。
//接下来n-1行，第i行两个正整数ai,bi用空格隔开，表示树上节点ai,bi之间有一条边。
//输出描述:
//第一行一个整数，表示集合最少需要的时间。
//
//示例1
//输入
//3
//1 2
//2 3
//输出
//2
//
//
//示例2
//输入
//3
//1 2
//1 3
//输出
//1
//
//
//示例3
//输入
//4
//1 2
//2 3
//2 4
//输出
//3
//



