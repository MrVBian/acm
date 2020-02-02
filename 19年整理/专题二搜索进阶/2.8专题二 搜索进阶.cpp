#include <bits/stdc++.h>

using namespace std;

const int maxn = 15;
const int inf = 0x3f3f3f3f;

int t, n, m;
int sx, sy, sz, ex, ey, ez;
char G[3][maxn][maxn];
bool vst[3][maxn][maxn];
int step[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

struct Point{
    int x, y, z;
    int d;
    Point(){}
    Point(int zz, int xx, int yy, int dd):z(zz),x(xx),y(yy),d(dd){}
};

bool check(int z, int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= m || G[z][x][y] == '*')
        return false;
    return true;
}

void bfs(){
    queue<Point> q;
    q.push(Point(sz, sx, sy, 0));
    vst[sz][sx][sy] = 1;
    while(!q.empty()){
        Point p = q.front();
        q.pop();
        if(p.z == ez && p.x == ex && p.y == ey && p.d <= t){
            cout<<"YES"<<endl;
            return ;
        }
        for(int i = 0; i < 4; ++i){
            int cur_x = p.x + step[i][0];
            int cur_y = p.y + step[i][1];
           // cout<<"*****"<<endl;
//            cout<<setw(4)<<cur_x<<setw(4)<<cur_y<<endl;
//            cout<<setw(4)<<check(p.z, cur_x, cur_y)<<setw(4)<<!vst[p.z][cur_x][cur_y]<<setw(4)<<(p.d<t)<<endl;
            if(check(p.z, cur_x, cur_y) && !vst[p.z][cur_x][cur_y] && p.d < t){
//                cout<<setw(4)<<p.z<<setw(4)<<p.x<<setw(4)<<p.y<<setw(4)<<p.d<<endl;
                if(G[p.z][cur_x][cur_y] == '#'){
                    if(G[1-p.z][cur_x][cur_y] != '*' && G[1-p.z][cur_x][cur_y] != '#'){
                        vst[p.z][cur_x][cur_y] = 1;
                        vst[1-p.z][cur_x][cur_y] = 1;
                        q.push(Point(1-p.z, cur_x, cur_y, p.d+1));
                    }
                }
                else{
                    vst[p.z][cur_x][cur_y] = 1;
                    q.push(Point(p.z, cur_x, cur_y, p.d+1));
                }
            }
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    int T;
    ios::sync_with_stdio(false);
    cin >> T;
    sx = sy = sz = 0;
    while(T--){
        cin >> n >> m >> t;
        for(int k = 0; k < 2; ++k)
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            cin >> G[k][i][j];
            vst[k][i][j] = 0;
            if(G[k][i][j] == 'P'){
                ez = k;
                ex = i;
                ey = j;
            }
        }
        bfs();
    }
    return 0;
}