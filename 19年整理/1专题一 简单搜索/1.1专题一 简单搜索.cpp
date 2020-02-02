#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cstdio>

using namespace std;

const int maxn = 110;
int t, n, m;
int mp[maxn][maxn][maxn];
int vst[maxn][maxn][maxn];
int sz,sx,sy,ez,ex,ey;
int step[6][3] = {{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};

struct  Point{
    int x,y,z;
    int d;
    Point(int zz, int xx, int yy, int dis){
        z = zz;
        x = xx;
        y = yy;
        d = dis;
    }
    Point(){}
};

bool check(int z, int x, int y){
    if(z < 0 || z >= t || x < 0 || x >= n || y < 0 || y >= m || mp[z][x][y] == '#')
        return false;
    return true;
}

int ans;

void bfs(){
    queue<Point> q;
    q.push(Point(sz,sx,sy,0));
    while(!q.empty()){
        Point p = q.front();
        q.pop();
        if(p.z == ez && p.x == ex && p.y == ey){
            ans = p.d;
            printf("Escaped in %d minute(s).\n", ans);
            return;
        }
        for(int i = 0; i < 6; ++i){
            int cur_z = p.z + step[i][0];
            int cur_x = p.x + step[i][1];
            int cur_y = p.y + step[i][2];
            if(!vst[cur_z][cur_x][cur_y] && check(cur_z, cur_x, cur_y)){
                vst[cur_z][cur_x][cur_y] = 1;
                q.push(Point(cur_z,cur_x,cur_y, p.d+1));
            }
        }
    }
    printf("Trapped!\n");
}

int main(){
    while(~scanf("%d%d%d", &t, &n, &m)){
        if(!t || !n || !m)
            return 0;
        getchar();
        memset(vst, 0, sizeof(vst));
        for(int k = 0; k < t; ++k){
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < m; ++j){
                    scanf("%c", &mp[k][i][j]);
                    if(mp[k][i][j] == 'S'){
                        sz = k;
                        sx = i;
                        sy = j;
                    }
                    if(mp[k][i][j] == 'E'){
                        ez = k;
                        ex = i;
                        ey = j;
                    }
                }
                getchar();
            }
            if(k != t-1)
                getchar();
        }
        ans = 0;
        bfs();
    }
    return 0;
}