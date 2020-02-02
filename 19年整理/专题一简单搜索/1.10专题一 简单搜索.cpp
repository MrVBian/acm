#include <iostream>
#include <queue>

using namespace std;

const int n = 5;
int step[][2]={{0,-1},{-1,0},{0,1},{1,0}};
int vst[100][100];
int mp[100][100];

bool check(int x,int y){
    if(x < 0 || x >= n || y < 0 || y >= n)
        return false;
    return true;
}

struct Point{
    int x, y;
    Point(int xx, int yy):x(xx), y(yy){}
    Point(){}
};


void bfs(){
    queue<Point> q;
    q.push(Point(0, 0));
    queue<string> qq;
    qq.push("00");
    while(!q.empty()){
        Point p = q.front();
        q.pop();
        string pp = qq.front();
        qq.pop();
        if(p.x == n-1 && p.y == n-1){
            for(int i = 0; i < pp.size(); i += 2){
                if(i)
                    cout<<endl;
                cout<<"("<<pp[i]<<", "<<pp[i+1]<<")";
            }
            return ;
        }
        for(int i = 0; i < 4; i++){
            int cur_x = p.x + step[i][0];
            int cur_y = p.y + step[i][1];
            if(check(cur_x,cur_y) && !vst[cur_x][cur_y] && !mp[cur_x][cur_y] ){
                vst[cur_x][cur_y] = 1;
                q.push(Point(cur_x, cur_y));
                string mo = pp + char(cur_x + '0') + char(cur_y + '0');
                qq.push(mo);
            }
        }
    }
}

int main(){
    for(int i = 0; i < n; i++)
        for(int j =0; j < n; j++){
            cin >> mp[i][j];
            vst[i][j] = 0;
        }
    vst[0][0] = 1;
    bfs();
}