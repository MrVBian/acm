#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
const int maxn = 510;
const int inf = 0x3f3f3f3f;

int n, m;
double G[maxn][maxn];
int vst[maxn];
double d[maxn];
double sum;
vector<pair<int,int> > point;

void Prim(int s){
    for(int i = 0; i <= n; ++i){
        vst[i] = 0;
        d[i] = G[s][i];
    }
    vst[s] = 1;
    for(int i = 0; i < n-1; ++i){
        double Min = inf;
        int k = s;
        for(int j = 0; j < n; ++j){
            if(!vst[j] && Min > d[j]){
                Min = d[j];
                k = j;
            }
        }
        vst[k] = 1;
        sum += Min;
        for(int j = 0; j < n; ++j){
            if(!vst[j] && d[j] > G[k][j]){
                d[j] = G[k][j];
            }
        }
    }
}

double dis(int x1, int y1, int x2, int y2){
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        point.clear();
        scanf("%d%d", &m, &n);
        sum = 0;
        for(int i = 0; i < n; ++i){
            int x, y;
            scanf("%d%d", &x, &y);
            point.push_back(make_pair(x, y));
        }
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                double v = dis(point[i].first, point[i].second, point[j].first, point[j].second);
                G[i][j] = G[j][i] = v;
            }
        }
        Prim(0);
        sort(d, d+n);
        printf("%.2f\n", d[n-m]);

    }
    return 0;
}
