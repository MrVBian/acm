#include<algorithm>
#include<iostream>
#include<cstring>

using namespace std;

const int maxn = 110;
const int inf = 0x3f3f3f3f;
int m, n;
int G[maxn][maxn];
int vst[maxn];
int d[maxn];
int val[maxn];
int Rank[maxn];

bool check(int i){
    if(Rank[i] >= Rank[0] && Rank[i] - Rank[0] <= m)
        return true;
    return false;
}

int dijkstra(){
    for(int i = 0; i < maxn; ++i){
        vst[i] = 0;
        d[i] = inf;
    }
    for(int i = 1; i <= n; ++i)
        d[i] = val[i];

    for(int i = 0; i < n; ++i){
        int k = 0, Min = inf;
        for(int j = 1; j <= n; ++j){
            if(!vst[j] && Min > d[j]){
                Min = d[j];
                k = j;
            }
        }

        vst[k] = 1;
        if(!check(k))
            continue;
        for(int j = 1; j <= n; ++j){
            if(!vst[j] && check(j) && d[j] > d[k] + G[k][j])
                d[j] = d[k] + G[k][j];
        }

    }
    return d[1];
}

int main(){
    cin >> m >> n;
    for(int i = 0; i < maxn; ++i)
        for(int j = 0; j < maxn; ++j)
            G[i][j] = inf;

    for(int i = 1; i <= n; ++i){
        int k, t, v;
        G[i][i] = 0;
        cin >> val[i] >> Rank[i] >> k;
        while(k--){
            cin >> t >> v;
            G[t][i] = v;
        }
    }

    int ans = inf;
    for(int i = 1; i <= n; ++i){
        Rank[0] = Rank[i];
        ans = min(ans, dijkstra());
    }

    cout << ans << endl;

    return 0;
}