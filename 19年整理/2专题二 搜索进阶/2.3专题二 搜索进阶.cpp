#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
bool mp[maxn][maxn], Time[maxn][maxn][1010];
bool vst[maxn][maxn][1010];
int ans;
int step[5][2] = {-1,0, 1,0, 0,1, 0,-1,0,0};
int n, m, k, d;

struct Point1{
    int x, y, t, v;
    int dir;
    Point1(int xx, int yy, int tt, int vv, int direction):x(xx),y(yy),t(tt),v(vv),dir(direction){}
    Point1(){}
};
Point1 ta[maxn];

struct Point2{//角色
    int x, y, t;
    Point2(int xx, int yy, int tt):x(xx),y(yy),t(tt){}
    Point2(){}
};

bool check(int x, int y){   //x y 可以取n m
    if(x < 0 || x > n || y < 0 || y > m || mp[x][y])
        return false;
    return true;
}

void pre_set(){
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= m; ++j)
            for(int t = 0; t <= d; ++t)
                Time[i][j][t] = vst[i][j][t] = 0;
    for(int i = 0; i<k; i++)    //枚举城堡
        for(int j = 0; j<=d; j += ta[i].t)    //模拟一颗子弹
            for(int t = 1; ; t++){   //枚举路程
                int x = ta[i].x + step[ta[i].dir][0]*t;
                int y = ta[i].y + step[ta[i].dir][1]*t;
                if( !check(x, y) )
                    break;
                if(t%ta[i].v==0)    //到达整点时刻，更新hav数组
                    Time[x][y][j+t/ta[i].v] = true;
            }
}

void bfs(){
    queue<Point2> q;
    Point2 p = Point2(0, 0, 0);
    vst[0][0][0] = true;
    q.push(p);
    while(!q.empty()){
        p = q.front();
        q.pop();
        if(p.t > d){  //累死了
            ans = -1;
            return ;
        }
        if(p.x == n && p.y == m){    //顺利回营
            ans = p.t;
            return ;
        }
        for(int i = 0; i<5; i++){
            int x = p.x + step[i][0];
            int y = p.y + step[i][1];
            int t = p.t + 1;
            if(check(x, y) && !Time[x][y][t] && !vst[x][y][t]){
                vst[x][y][t] = 1;
                q.push(Point2(x, y, t));
            }
        }
    }
}

int main(){
    while(scanf("%d%d%d%d",&n,&m,&k,&d)!=EOF){
        for(int i = 0; i <= n; ++i)
            for(int j = 0; j <= m; ++j)
                mp[i][j] = 0;
        char ch[3];
        ans = -1;
        for(int i = 0; i<k; i++){
            int x, y, z, w, dir;
            scanf("%s%d%d%d%d", ch, &z, &w, &x, &y);
            if(ch[0] == 'N')      dir = 0;
            else if(ch[0] == 'S') dir = 1;
            else if(ch[0] == 'E') dir = 2;
            else if(ch[0] == 'W') dir = 3;
            ta[i] = Point1(x, y , z, w, dir);
            mp[x][y] = 1;
        }
        pre_set();
        bfs();
        if(ans==-1)
            puts("Bad luck!");
        else
            printf("%d\n", ans);
    }
}