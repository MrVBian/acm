#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

const int maxn = 2010;
int par[maxn<<1];
int d[maxn<<1];
int t, m, n;
map<int,int> mp;
int cot;

int Find(int x){
    if(x != par[x]){
        int k = par[x];
        par[x] = Find(par[x]);
        d[x] ^= d[k];
    }
    return par[x];
}

int flag;

void Union(int x, int y, int v = 1){
    int xx = Find(x);
    int yy = Find(y);
    if(xx != yy){
        par[xx] = yy;
        d[xx] = d[x] ^ d[y] ^ v;
    }
    else{
        if(!d[x] ^ d[y])
            flag ++;
    }
}

void init(){
    mp.clear();
    flag = 0;
    cot = 1;
    for(int i = 0; i <= n*2; ++i){
        par[i] = i;
        d[i] = 0;
    }
}

int main(){
    scanf("%d", &t);
    for(int T = 1; T <= t; ++T){
        scanf("%d%d", &n, &m);
        init();
        int x, y;
        for(int i = 0; i < m; ++i){
            scanf("%d%d", &x, &y);
            if(!mp[x])
                mp[x] = cot++;
            if(!mp[y])
                mp[y] = cot++;
            Union(mp[x], mp[y], 1);
        }
        if(flag)
            printf("Scenario #%d:\nSuspicious bugs found!\n\n", T);
        else
            printf("Scenario #%d:\nNo suspicious bugs found!\n\n", T);
    }
}
