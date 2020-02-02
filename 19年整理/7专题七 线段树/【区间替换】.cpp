// 区间替换
#define max(a,b) (a>b)?a:b  
#define min(a,b) (a>b)?b:a  
#define lson l , m , rt << 1  
#define rson m + 1 , r , rt << 1 | 1  
#define LL long long  
const int maxn = 100100;  
  
int lazy[maxn<<2];  
int sum[maxn<<2];  
  
void PushUp(int rt) { //由左孩子、右孩子向上更新父节点  
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];  
}  
void PushDown(int rt,int m) { //向下更新  
    if (lazy[rt]) { //懒惰标记  
        lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];  
        sum[rt<<1] = (m - (m >> 1)) * lazy[rt];  
        sum[rt<<1|1] = ((m >> 1)) * lazy[rt];  
        lazy[rt] = 0;  
    }  
}  
void build(int l,int r,int rt) { //建树  
    lazy[rt] = 0;  
    if (l== r) {  
        scanf("%d",&sum[rt]);  
        return ;  
    }  
    int m = (l + r) >> 1;  
    build(lson);  
    build(rson);  
    PushUp(rt);  
}  
void update(int L,int R,int c,int l,int r,int rt) { //更新  
    if (L <= l && r <= R) {  
        lazy[rt] = c;  
        sum[rt] = c * (r - l + 1);  
        return ;  
    }  
    PushDown(rt, r - l + 1);  
    int m = (l + r) >> 1;  
    if (L <= m) update(L, R, c, lson);  
    if (R > m) update(L, R, c, rson);  
    PushUp(rt);  
}  
LL query(int L,int R,int l,int r,int rt) {  
    if (L <= l && r <= R) {  
        return sum[rt];  
    }  
    PushDown(rt, r - l + 1);  
    int m = (l + r) >> 1;  
    LL ret = 0;  
    if (L <= m) ret += query(L, R, lson);  
    if (m < R) ret += query(L, R, rson);  
    return ret;  
}  
int main() {  
    int  n, m;  
    char str[5];  
    while(scanf("%d%d",&n,&m)) {  
        build(1, n, 1);  
        while (m--) {  
            scanf("%s",str);  
            int a, b, c;  
            if(str[0]=='T') {  
                scanf("%d%d%d",&a,&b,&c);  
                update(a, b, c, 1, n, 1);  
            } else if(str[0]=='Q') {  
                scanf("%d%d",&a,&b);  
                cout<<query(a,b,1,n,1)<<endl;  
            }  
        }  
    }  
    return 0;  
}  
