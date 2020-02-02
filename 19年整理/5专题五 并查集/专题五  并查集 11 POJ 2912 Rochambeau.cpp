#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 10010;

struct Data{
    int x, y;
    int r;
}data[maxn];

int par[maxn], d[maxn], err[maxn];
int n, m;

int Find(int x){
    if(x != par[x]){
        int k = par[x];
        par[x] = Find(par[x]);
        d[x] = (d[x] + d[k]) % 3;
    }
    return par[x];
}

bool Union(int x, int y, int i, int j){
    int xx = Find(x);
    int yy = Find(y);
    if(xx == yy){
        if(d[x] != (d[y] + data[j].r) % 3){
            err[i] = j + 1;
            return true;
        }
    }
    else{
        par[xx] = yy;
        d[xx] = (d[y] - d[x] + 3 + data[j].r) % 3;
    }
    return false;
}


void init(int n){
    for(int i = 0; i < n; i++) {
        par[i] = i;
        d[i] = 0;
    }
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 0; i < m; i++){
            char ch;
            scanf("%d%c%d", &data[i].x, &ch, &data[i].y);
            if(ch == '=')   data[i].r = 0;
            else if(ch == '<') data[i].r = 1;
            else if(ch == '>') data[i].r = 2;
        }
        memset(err, -1, sizeof(err));
        for(int i = 0; i < n; i++){
            init(n);
            for(int j = 0; j < m; j++){
                int x = data[j].x;
                int y = data[j].y;
                if(i == x || i == y)
                    continue;
                if(Union(x, y, i, j))
                    break;
            }
        }
        int cnt = 0, ans1 = 0, ans2 = 0;
        for(int i = 0; i < n; i++){
            if(err[i] == -1){
                cnt ++;
                ans1 = i;
            }
            ans2 = max(ans2, err[i]);
        }
        if(cnt == 0)    printf("Impossible\n");
        else if(cnt > 1)    printf("Can not determine\n");
        else printf("Player %d can be determined to be the judge after %d lines\n", ans1, ans2);
    }
    return 0;
}
