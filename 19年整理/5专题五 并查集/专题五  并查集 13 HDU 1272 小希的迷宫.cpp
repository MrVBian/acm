#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 100010;

int flag;
int arr[maxn];
int par[maxn];
int vst[maxn];

void init() {
    for(int i = 0; i < maxn; ++i){
        par[i] = i;
        vst[i] = 0;
    }
}

int Find(int x) {
    if(par[x] == x)
        return x;
    return par[x] = Find(par[x]);
}

void Union(int x, int y) {
    int xx = Find(x);
    int yy = Find(y);
    if(xx == yy)
        flag = 1;
    par[xx] = yy;
}

int main() {
    int x, y;
    while(~scanf("%d%d", &x, &y)) {
        if(x == -1 && y == -1)
            break;
        if(!x && !y){
            printf("Yes\n");
            continue;
        }
        init();
        Union(x, y);
        vst[x] = vst[y] = 1;
        while(~scanf("%d%d", &x, &y)) {
            if(!x && !y)
                break;
            vst[x] = vst[y] = 1;
            if(!flag)
                Union(x, y);
        }

        if(flag) {
            printf("No\n");
            continue;
        }

        int ans = 0;

        for(int i = 0; i < maxn; ++i)
            if( vst[i] && par[i] == i)
                ans ++;

        if(ans == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
