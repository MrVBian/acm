#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 110;
const int inf = 0x3f3f3f3f;

int t, m, n;
char mp[maxn][maxn];
int alens[maxn][maxn];
int time[maxn][maxn];
int step[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int G[maxn][maxn];

typedef pair<int,int> Point;

bool outBorder(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m)
        return true;
    return false;
}

void bfs(int x, int y){
    memset(time, -1, sizeof(time));// 置为-1代替了vst功能。
    queue<Point> q;
    q.push(make_pair(x, y));
    time[x][y] = 0;
    while(!q.empty()){
        Point p = q.front();
        q.pop();
        int xx = p.first;
        int yy = p.second;
        if(alens[xx][yy]){
            G[ alens[x][y] ][ alens[xx][yy] ] = time[xx][yy];
        }
        for(int i = 0; i < 4; ++i){
            int cur_x = xx + step[i][0];
            int cur_y = yy + step[i][1];// 代替了vst功能。
            if(time[cur_x][cur_y] != -1 || mp[cur_x][cur_y] == '#' || outBorder(cur_x, cur_y))
                continue;
            time[cur_x][cur_y] = time[xx][yy] + 1;
            q.push(make_pair(cur_x, cur_y));
        }
    }

}

bool vst[maxn];
int d[maxn];
int sum;

void Prim(int s, int n){
    for(int i = 0; i <= n; ++i){
        vst[i] = 0;
        d[i] = G[s][i];
    }
    vst[s] = 1;
    for(int i = 0; i < n-1; ++i){
        int Min = inf;
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
            if(!vst[j] && d[j] > G[k][j])
                d[j] = G[k][j];
        }
    }
}

int main(){
    scanf("%d", &t);
    while(t--){
        int cot = 0;
        sum = 0;
        memset(alens, -1, sizeof(alens));
        scanf("%d%d", &m, &n);
        gets(mp[0]);
        for(int i = 0; i < n; ++i){
            gets(mp[i]);
            for(int j = 0; j < m; ++j){
                if(mp[i][j] == 'S' || mp[i][j] == 'A'){
                    alens[i][j] = cot++;
                }
            }
        }
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(alens[i][j] != -1)
                    bfs(i, j);

        Prim(0, cot);
        printf("%d\n", sum);
    }
    return 0;
}
