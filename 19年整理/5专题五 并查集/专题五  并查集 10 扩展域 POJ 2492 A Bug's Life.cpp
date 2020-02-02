#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

const int maxn = 2010;
int par[maxn<<1];
int t, m, n;
int flag;

int Find(int x){
    if(par[x] == x)
        return x;
    return par[x] = Find(par[x]);
}

void Union(int x, int y){
    par[Find(x)] = Find(y);
}

void init(){
    flag = 0;
    for(int i = 0; i <= n*2; ++i)
        par[i] = i;
}

int main(){
    scanf("%d", &t);
    for(int T = 1; T <= t; ++T){
        scanf("%d%d", &n, &m);
        init();
        int x, y;
        for(int i = 0; i < m; ++i){
            scanf("%d%d", &x, &y);
            int xx = Find(x);
            int yy = Find(y);
            if(xx == yy)
                flag ++;
            else{
                Union(x, y+n);
                Union(x+n, y);
            }
        }
        if(flag)
            printf("Scenario #%d:\nSuspicious bugs found!\n\n", T);
        else
            printf("Scenario #%d:\nNo suspicious bugs found!\n\n", T);
    }
}
