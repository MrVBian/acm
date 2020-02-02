//Çø¼äÔö¼õ
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define max(a,b) (a>b)?a:b
#define min(a,b) (a>b)?b:a
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define LL __int64
const int maxn = 100100;
using namespace std;

LL lazy[maxn<<2];
LL sum[maxn<<2];

void putup(int rt) {
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void putdown(int rt,int m) {
    if (lazy[rt]) {
        lazy[rt<<1] += lazy[rt];
        lazy[rt<<1|1] += lazy[rt];
        sum[rt<<1] += lazy[rt] * (m - (m >> 1));
        sum[rt<<1|1] += lazy[rt] * (m >> 1);
        lazy[rt] = 0;
    }
}

void build(int l,int r,int rt) {
    lazy[rt] = 0;
    if (l == r) {
        scanf("%I64d",&sum[rt]);
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    putup(rt);
}

void update(int L,int R,int c,int l,int r,int rt) {
    if (L <= l && r <= R) {
        lazy[rt] += c;
        sum[rt] += (LL)c * (r - l + 1);
        return ;
    }
    putdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, c, lson);
    if (m < R) update(L, R, c, rson);
    putup(rt);
}

LL query(int L,int R,int l,int r,int rt) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    putdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    LL ret = 0;
    if (L <= m) ret += query(L, R, lson);
    if (m < R) ret += query(L, R, rson);
    return ret;
}

int main() {
    int n, m;
    int a, b, c;
    char str[5];
    while(~scanf("%d%d", &n, &m)){
        build(1, n, 1);
        while (m--) {
            scanf("%s",str);
            if (str[0] == 'Q') {
                scanf("%d%d",&a,&b);
                printf("%I64d\n",query(a, b, 1, n, 1));
            } else if(str[0]=='C') {
                scanf("%d%d%d",&a,&b,&c);
                update(a, b, c, 1, n, 1);
            }
        }
    }
    return 0;
}
