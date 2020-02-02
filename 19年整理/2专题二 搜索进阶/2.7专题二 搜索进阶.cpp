#include <bits/stdc++.h>

using namespace std;

const int maxn = 810;
int n, m, t;
char mp[maxn][maxn];
int vst[maxn][maxn];
int step[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

struct Point{
    int x, y;
    Point(int xx,int yy):x(xx),y(yy){}
    Point(){}
};
Point s, e, z[2];

bool check(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m || mp[x][y] == 'X')
        return false;
    for(int i = 0; i < 2; ++i)//利用曼哈顿距离判断是否会被鬼抓到
        if(abs(x-z[i].x)+abs(y-z[i].y) <= 2*t)
            return false;
    return true;
}

void bfs(){
    queue<Point> qs, qe;
    qs.push(s);
    qe.push(e);
    vst[s.x][s.y] = 1;
    vst[e.x][e.y] = 2;
    while(!qs.empty() || !qe.empty()){
        t++;
        for(int i = 0; i < 3; ++i){//3步
            int cot = qs.size();
            while(cot--){
                Point p = qs.front();
                qs.pop();
                if(!check(p.x, p.y))
                    continue;
                for(int j = 0; j < 4; ++j){
                    int cur_x = p.x + step[j][0];
                    int cur_y = p.y + step[j][1];
                    if(!check(cur_x, cur_y))
                        continue;
                    if(vst[cur_x][cur_y] != 1){
                        if(vst[cur_x][cur_y] == 2){
                            printf("%d\n", t);
                            return;
                        }
                        vst[cur_x][cur_y] = 1;
                        qs.push(Point(cur_x, cur_y));
                    }
                }
            }
        }
//        for(int i = 0; i < n; ++i){
//            for(int j = 0; j < m; ++j)
//                printf("%4d", vst[i][j]);
//            printf("\n");
//        }
        int cot = qe.size();
        while(cot--){
            Point p = qe.front();
            qe.pop();
            if(!check(p.x, p.y))
                continue;
            for(int j = 0; j < 4; ++j){
                int cur_x = p.x + step[j][0];
                int cur_y = p.y + step[j][1];
                if(!check(cur_x, cur_y))
                    continue;
                if(vst[cur_x][cur_y] != 2){
                    if(vst[cur_x][cur_y] == 1){
                        printf("%d\n", t);
                        return;
                    }
                    vst[cur_x][cur_y] = 2;
                    qe.push(Point(cur_x, cur_y));
                }
            }
        }
    }
    printf("-1\n");
}

int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--){
        scanf("%d%d", &n, &m);
        int cot = 0;
        for(int i = 0; i < n; ++i){
            scanf("%s", mp[i]);
            for(int j = 0; j < m; ++j){
                if(mp[i][j] == 'M')
                    s = Point(i, j);
                else if(mp[i][j] == 'G')
                    e = Point(i, j);
                else if(mp[i][j] == 'Z')
                    z[cot++] = Point(i, j);
            }
        }
        t = 1;
        for(int i = 0; i <= n; ++i)
            for(int j = 0; j <= m; ++j)
                vst[i][j] = 0;
        if(!check(s.x, s.y) && !check(e.x, e.y)){
            printf("-1\n");
            continue;
        }
        t = 0;
        bfs();
    }
    return 0;
}