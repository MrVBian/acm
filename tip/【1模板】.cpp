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

const int maxn=1e6+5;

void init(int n){
    for (int i = 0; i < n; ++i)
    {
        father[i]=i;
    }
}

int main(){

}

#define LOCAL_JUDGE

int main()
{
#ifdef LOCAL_JUDGE
    freopen("Text.txt", "r", stdin);
#endif // LOCAL_JUDGE


#ifdef LOCAL_JUDGE
    fclose(stdin);
#endif // LOCAL_JUDGE
    return 0;
}
