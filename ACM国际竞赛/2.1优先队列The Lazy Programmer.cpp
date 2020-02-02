#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
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

const int maxn = 100100;

struct node{
    ll a, b, d;
    bool operator < (const node &tmp) const{
        return a < tmp.a;
    }
}arr[maxn];

typedef node record;

priority_queue<record> q;
int n;

//priority_queue<int, vector<int>, greater<int> > small;

void init(){
    record p;
    rd(n);
    _for(i, 0, n){
        scl(arr[i].a);
        scl(arr[i].b);
        scl(arr[i].d);
    }
}

bool cmp(record a, record b){
    return a.d < b.d;
}

int main(){
    init();
    long double ans = 0;
    sort(arr, arr + n, cmp);
//    for(int i = 0; i<n; i++){
//        pr(arr[i].d);
//        en;
//    }
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        q.push(arr[i]);
        sum += arr[i].b;    //任务需要天数
        while (sum > arr[i].d && !q.empty()) {  //需要花费金额加速
            record tmp = q.top();
            q.pop();
//            pr(tmp.a);
//            en;
            if(sum - arr[i].d >= tmp.b){
                sum -= tmp.b;
                ans += (double) tmp.b / tmp.a;
//                printf("1:%d\n",ans);
            }else{
                ans +=  (double) (sum - arr[i].d) / tmp.a;
                tmp.b -= (sum - arr[i].d);
                sum = arr[i].d;
//                printf("2:%d\n",ans);
                q.push(tmp);
            }
        }
    }
    printf("%.2llf",ans);
}

