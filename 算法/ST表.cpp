#include<bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define _ref(i,a,b) for(int i=(a);i<=(b);i++)
#define ms(a, b) memset(a, b, sizeof(a))
#define fill(a,v,n) memset((a),(v),sizeof(a[0])*(n))
#define copy(a,b,n) memcpy((a),(b),sizeof(a[0])*(n))
#define sc(x) scanf("%d", &x)
#define pr(x) printf("%d", (x))
#define scl(x) scanf("%lld", &x)
#define prl(x) printf("%lld", (x))
#define sp putchar(' ')
#define en putchar('\n')
#define ALL(x) (x.begin(),x.end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define IOS ios::sync_with_stdio(0);cin.tie(0);
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define MOD 1000000007
void _max(int &a, int b){a = max(a,b);}
void _min(int &a, int b){a = min(a,b);}

ll pw(ll a, ll b){ll res(1);while(b){if(b&1)res=res*a%MOD;a=a*a%MOD;b>>=1;}return res;}
ll gcd(ll a, ll b){ll t;while(b){t=a%b;a=b;b=t;}return a;}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
int len(ll x){int k=0;while(x){x/=10;k++;}return k;}
int len(int x){int k=0;while(x){x/=10;k++;}return k;}

const int infi = 2147483647;
const ll infl = 9223372036854775807ll;
const db PI = 3.14159265358979323846;

inline void rd(int &x){x = 0;char c = getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+(c&15),c=getchar();}
inline void llread(ll &x){char ch = getchar(); x = 0;for (; ch < '0' || ch > '9'; ch = getchar());for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';}

const int MAXN = 1e5 + 10;
int Max[MAXN][21];
int Min[MAXN][21];

int Query(int l,int r) {
    int k=log2(r-l+1);
    return max(Max[l][k],Max[r-(1<<k)+1][k]);//把拆出来的区间分别取最值
}

int lQuery(int l,int r) {
    int k=log2(r-l+1);
    return min(Min[l][k],Min[r-(1<<k)+1][k]);//把拆出来的区间分别取最值
}

int main() {
    int n, m;
    rd(n);
    rd(m);
    for(int i = 1; i <= n; i++) {
        rd(Max[i][0]);
        Min[i][0] = Max[i][0];
    }

//    for(int j = 1; j <= 21; j++)
    for(int j = 1; (1 << j) <= n; j++)
        for(int i = 1; i + (1 << j) - 1 <= n; i++) {
            Max[i][j] = max(Max[i][j-1], Max[i + (1 << (j - 1))][j - 1]);
            Min[i][j] = min(Min[i][j-1], Min[i + (1 << (j - 1))][j - 1]);
        }

    for(int i = 0; i < m; i++) {
        int l, r;
        rd(l);rd(r);
        int maxItem = Query(l,r);
        int minItem = lQuery(l,r);
        printf("maxItem:");
        pr(maxItem);sp;sp;
        printf("minItem");
        pr(minItem);en;
    }
}
