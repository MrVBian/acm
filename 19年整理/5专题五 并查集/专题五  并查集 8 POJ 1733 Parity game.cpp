#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
const int maxn = 5010;

map<int,int> mp;//离散化
int par[maxn*2];
int d[maxn*2];
int ans;
int cot;

int Find(int x){
    if(x != par[x]){
        int k = par[x];
        par[x] = Find(par[x]);
        d[x] ^= d[k];
    }
    return par[x];
}

void init(int n){
    memset(d, 0, sizeof(d));
    for(int i = 0; i < maxn*2; i++)
        par[i] = i;
}

void Union(int x, int y, int v){
    int xx = Find(x);
    int yy = Find(y);
    if(xx == yy){
        if((d[x] ^ v) != d[y])
            ans++;
    }
    else{
        par[yy] = xx;
        d[yy] = (d[x] ^ d[y] ^ v);
    }
}

int main(){
    int n, m;
    mp.clear();
    scanf("%d%d", &n, &m);
    ans = 0;
    cot = 1;
    init(n);
    int x, y, v;
    int res = -1;
    char ch[10];
    for(int i = 0; i < m; i++){
        scanf("%d%d%s", &x, &y, ch);
        if(res != -1)
            continue;
        if(ch[0] == 'e')
            v = 0;
        else
            v = 1;
        if(!mp[x-1])//将区间改为(x,y]
            mp[x-1] = cot++;
        if(!mp[y])//离散化
            mp[y] = cot++;

        Union(mp[x-1], mp[y], v);

        if(ans && res == -1){
            res = i;
        }
    }
    printf("%d\n", res == -1 ? m : res);
    return 0;
}
