#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;
const int maxn = 200005;

int par[maxn];
ll d[maxn];
int ans;

int Find(int x){
    if(x != par[x]){
        int k = par[x];
        par[x] = Find(par[x]);
        d[x] += d[k];
    }
    return par[x];
}

void init(int n){
    memset(d,0,sizeof(d));
    for(int i = 0; i <= n; i++)
        par[i] = i;
}

void Union(int x, int y, int v){
    int xx = Find(x);
    int yy = Find(y);
    if(xx == yy){
        if(d[x] + v != d[y])
            ans++;
    }
    else{
        par[yy] = xx;
        d[yy] = d[x] - d[y]  + v;
    }
}

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        ans = 0;
        init(n);
        int x, y, v;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &x, &y, &v);
            x -= 1;
            Union(x, y, v);
        }
        printf("%d\n", ans);
    }
    return 0;
}
