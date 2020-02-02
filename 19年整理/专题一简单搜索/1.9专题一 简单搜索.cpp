#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+10;
const int inf = 0x3f3f3f3f;
int n, m;
int sx, sy;
int fx, fy;
char G[maxn][maxn];
int vst[maxn][maxn];
int Time[maxn][maxn];
int curT[maxn][maxn];
int step[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

struct Point{
    int x, y;
    Point(int xx, int yy):x(xx),y(yy){}
    Point(){}
};

bool check(int x, int y){
    if(x<0 || x>=n || y<0 || y>=m || vst[x][y])
        return false;
    return G[x][y] == '.';
}

bool onBorder(int x, int y){
    if(x == 0 || x == n-1 || y == 0 || y == m-1)
        return true;
    return false;
}

void bfs_fire(queue<Point> fireQ){
    queue<Point> q;
    while(!fireQ.empty()){
        q.push(fireQ.front());
        fireQ.pop();
    }
    while(!q.empty()){
        Point p = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i){
            int cur_x = p.x + step[i][0];
            int cur_y = p.y + step[i][1];
            if(check(cur_x, cur_y)){
                vst[cur_x][cur_y] = 1;
                Time[cur_x][cur_y] = Time[p.x][p.y] + 1;
                q.push(Point(cur_x, cur_y));
            }
        }
    }
}

void bfs(){
    queue<Point> q;
    q.push(Point(sx, sy));
    curT[sx][sy] = 0;
    vst[sx][sy] = 1;
    while(!q.empty()){
        Point p = q.front();
        q.pop();
        if(onBorder(p.x, p.y)){
            printf("%d\n", curT[p.x][p.y]+1);
            return ;
        }
        for(int i = 0; i < 4; ++i){
            int cur_x = p.x + step[i][0];
            int cur_y = p.y + step[i][1];
            if(check(cur_x, cur_y)){
                if(curT[p.x][p.y] + 1 < Time[cur_x][cur_y]){
                    curT[cur_x][cur_y] = curT[p.x][p.y] + 1;
                    vst[cur_x][cur_y] = 1;
                    q.push(Point(cur_x, cur_y));
                }
            }
        }
    }
    printf("IMPOSSIBLE\n");
}

int main(){
    int t;
    ios::sync_with_stdio(false);
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                vst[i][j] = 0;
                Time[i][j] = inf;
                curT[i][j] = 0;
            }
        queue<Point> q;
        for(int i = 0; i < n; ++i){
            scanf("%s", G[i]);
            for(int j = 0; j < m; ++j){
                if(G[i][j] == 'J'){
                    sx = i;
                    sy = j;
                }
                if(G[i][j] == 'F'){
                    vst[i][j] = 1;
                    Time[i][j] = 0;
                    q.push(Point(i, j));
                }
            }
        }
        bfs_fire(q);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                vst[i][j] = 0;
        bfs();
    }
    return 0;
}