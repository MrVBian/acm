#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 110;
const int inf = 0x3f3f3f3f;

int n;
double G[maxn][maxn];
int vst[maxn];
double d[maxn];
double sum;
vector<pair<int, int> > point;

void Prim(int s){
    for(int i = 0; i < n; ++i){
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
            if(G[k][j])
            if(!vst[j] && d[j] > G[k][j])
                d[j] = G[k][j];
        }
    }
}

double dis(double x1, double y1, double x2, double y2){
    return sqrt( 1.0*(x1-x2)*(x1-x2) + 1.0*(y1-y2)*(y1-y2) );
}

void init(){
    sum = 0;
    point.clear();
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            G[i][j] = inf;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        init();
        for(int i = 0; i < n; ++i){
            int x, y;
            scanf("%d%d", &x, &y);
            point.push_back(make_pair(x, y));
        }
        for(int i = 0; i < point.size(); ++i){
            for(int j = i+1; j < point.size(); ++j){
                double v = dis(point[i].first, point[i].second, point[j].first, point[j].second);
                if( v >= 10.0 && v <= 1000.0){
                    G[i][j] = G[j][i] = v*100;
                }
            }
        }
        Prim(1);
        if(sum < inf)
            printf("%.1f\n", sum);
        else
            printf("oh!\n");
    }
    return 0;
}
