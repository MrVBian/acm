#include <iostream>
#include <stdio.h>

using namespace std;

const int maxn = 50010;
int par[maxn*3];
int n, m;
int ans;

void init(){
    for(int i = 0; i <= 3*n; ++i)
        par[i] = i;
}

int Find(int x){
    if(par[x] == x)
        return x;
    return par[x] = Find(par[x]);
}

void Union(int x, int y){
    par[Find(x)] = Find(y);
}

int main(){
    scanf("%d%d", &n, &m);
    ans = 0;
    init();
    for(int i = 0; i < m; ++i){
        int v, a, b;
        scanf("%d%d%d", &v, &a, &b);
        if(a < 1 || a > n || b < 1 || b > n){
            ans++;
            continue;
        }
        if(v == 2 && a == b){
            ans++;
            continue;
        }
        if(v == 1){
            if(Find(a) == Find(b+n) || Find(b) == Find(a+n))
                ans++;
            else{
                Union(a, b);
                Union(a+n, b+n);
                Union(a+2*n, b+2*n);
            }
        }
        else if(v == 2){
            if(Find(a) == Find(b) || Find(b) == Find(a+n))
                ans++;
            else{
                Union(a, b+n);
                Union(a+n, b+2*n);
                Union(a+2*n, b);
            }
        }
    }
    printf("%d", ans);
    return 0;
}
