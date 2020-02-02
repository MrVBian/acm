#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define _ref(i,a,b) for(int i=(a);i<=(b);i++)
#define ms(a, b) memset(a, b, sizeof(a))
#define fill(a,v,n) memset((a),(v),sizeof(a[0])*(n))
#define sc(x) scanf("%d", &x)
#define pr(x) printf("%d", (x))
#define IOS ios::sync_with_stdio(0);cin.tie(0);
typedef double db;
typedef long long ll;
typedef unsigned long long ull;

#define MOD 1000000007
void _max(int &a, int b){a = max(a,b);}
void _min(int &a, int b){a = min(a,b);}

ll pw(ll a, ll b){ll res(1);while(b){if(b&1)res=res*a%MOD;a=a*a%MOD;b>>=1;}return res;}
ll gcd(ll a, ll b){ll t;while(b){t=a%b;a=b;b=t;}return a;}
const int infi = 2147483647;
const ll infl = 9223372036854775807ll;
const db PI = 3.14159265358979323846;

inline void rd(int &x)
{
    x = 0;
    char c = getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=x*10+(c&15),c=getchar();
}

const int vertex=100010;
const int arcNum=500010;
struct node{
    int u,v;;
    ll w;
};
node edge[arcNum];
ll parent[vertex];

bool cmp(node a,node b){
    return a.w<b.w;
}
int find(int v){
    if(parent[v]==-1)   return v;
    return parent[v]=find(parent[v]);
    //return parent[v]=parent[v]==-1?v:find(parent[v]);
}

ll Kruskal(int ver)
{
    ms(parent,-1);
    int n=0;
    ll sum=0;
    int vex1,vex2;
    _for(i,0,ver){
        vex1=edge[i].u;
        vex2=edge[i].v;
        vex1=find(vex1);
        vex2=find(vex2);
        if(vex1!=vex2){
            parent[vex2]=vex1;
            n++;
            sum+=edge[i].w;
        }
        if(n==ver-1)
            return sum;
    }
    return sum;
}


int main(){
    int n,m,u,v,w;
    rd(n);rd(m);
    _for(i,0,m){
        rd(u);rd(v);rd(w);
        //parent[i]=i;
        edge[i].u=u;
        edge[i].v=v;
        edge[i].w=w;
    }
    sort(edge,edge+m,cmp);
//    _for(i,0,m){
//        printf("%d  %d  %lld\n",edge[i],edge[i].v,edge[i].w);
//    }
    ll ans=Kruskal(m);
    printf("%lld",ans);
}

//链接：https://www.nowcoder.com/acm/contest/136/H
//来源：牛客网
//胡队长带领HA实验的战士们玩真人CS，真人CS的地图由一些据点组成，现在胡队长已经占领了n个据点，为了方便，将他们编号为1-n，为了隐蔽，胡队长命令战士们在每个据点出挖一个坑，让战士们躲在坑里。由于需要在任意两个点之间传递信息，两个坑之间必须挖出至少一条通路，而挖沟是一件很麻烦的差事，所以胡队长希望挖出数量尽可能少的沟，使得任意两个据点之间有至少一条通路，顺便，尽可能的∑d[i][j]使最小（其中d[i][j]为据点i到j的距离）。
//输入描述:
//第一行有2个正整数n，m，m表示可供挖的沟数。
//接下来m行，每行3个数a,b,v，每行描述一条可供挖的沟，该沟可以使a与b连通，长度为v。
//输出描述:
//输出一行，一个正整数，表示要使得任意两个据点之间有一条通路，至少需要挖长的沟。（数据保证有解）
//示例1
//输入
//2 2
//1 2 1
//1 2 3
//输出
//1
//示例2
//输入
//3 3
//1 2 3
//2 3 4
//1 3 5
//输出
//7
//备注:
//对于100%的测试数据：
//1 ≤ n ≤ 100000
//1 ≤ m ≤ 500000
//1 ≤ v ≤ 10000
//
