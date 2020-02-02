#include <bits/stdc++.h>

using namespace std;

const int maxn = 210;
const int inf = 0x3f3f3f3f - 100;
struct Point{
    int x, y, d;
    Point(int xx, int yy, int dd):x(xx),y(yy),d(dd){}
    Point(){}
};
int n, m;
char mp[maxn][maxn];
bool vst[maxn][maxn];
int sx, sy;
int ex, ey;
int step[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
vector<Point> KCF;
int ds[maxn][maxn];
int de[maxn][maxn];

bool check(int x, int y){
    if(x<0 || x>=n || y<0 || y>=m || vst[x][y] || mp[x][y] == '#')
        return false;
    return true;
}

void bfsS(){
    queue<Point> q;
    q.push(Point(sx, sy, 0));
    vst[sx][sy] = 1;
    while(!q.empty()){
        Point p = q.front();
        q.pop();
        if(mp[p.x][p.y] == '@'){
            ds[p.x][p.y] = p.d;
        }
        for(int i = 0; i < 4; ++i){
            int cur_x = p.x + step[i][0];
            int cur_y = p.y + step[i][1];
            // cout<<p.x<<"    "<<p.y<<"    check:"<<check(cur_x, cur_y)<<"    mp:"<< (mp[cur_x][cur_y] != '#')<<endl;
            if(check(cur_x, cur_y)){
                q.push(Point(cur_x, cur_y, p.d+1));
                vst[cur_x][cur_y] = 1;
            }
        }
    }
}

void bfsE(){
    queue<Point> q;
    q.push(Point(ex, ey, 0));
    vst[ex][ey] = 1;
    while(!q.empty()){
        Point p = q.front();
        q.pop();
        if(mp[p.x][p.y] == '@'){
            de[p.x][p.y] = p.d;
        }
        for(int i = 0; i < 4; ++i){
            int cur_x = p.x + step[i][0];
            int cur_y = p.y + step[i][1];
            // cout<<p.x<<"    "<<p.y<<"    check:"<<check(cur_x, cur_y)<<"    mp:"<< (mp[cur_x][cur_y] != '#')<<endl;
            if(check(cur_x, cur_y)){
                q.push(Point(cur_x, cur_y, p.d+1));
                vst[cur_x][cur_y] = 1;
            }
        }
    }
}

int main(){
    while(cin>>n>>m){
        KCF.clear();
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                cin>>mp[i][j];
                vst[i][j] = 0;
                ds[i][j] = inf;
                de[i][j] = inf;
                if(mp[i][j] == 'Y'){
                    sx = i; sy = j;
                }
                if(mp[i][j] == 'M'){
                    ex = i; ey = j;
                }
                if(mp[i][j] == '@'){
                    KCF.push_back(Point(i, j, 0));
                }
            }
        bfsS();
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                vst[i][j] = 0;
        bfsE();
        //for(int i = 0; i < n; ++i){
        //   for(int j = 0; j < m; ++j){
        //       printf("%12d", ds[i][j]);
        //   }
        //   printf("\n");
        //}
        //for(int i = 0; i < n; ++i){
        //   for(int j = 0; j < m; ++j){
        //       printf("%12d", de[i][j]);
        //   }
        //   printf("\n");
        //}
        int MIN = INT_MAX;
        for(int i = 0; i < KCF.size(); ++i)
            MIN = min(MIN, ds[KCF[i].x][KCF[i].y] + de[KCF[i].x][KCF[i].y]);
        cout<<MIN*11<<endl;
    }
    return 0;
}