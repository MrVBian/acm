#include<iostream>
#include<queue>
#include<math.h>
#include<algorithm>

using namespace std;

typedef  long long LL;
const int inf = 1<<30;
const LL maxn = 410;

int sx, sy, ex, ey;

struct Point {
    int x, y;
    Point(int xx, int yy) {
        x = xx, y = yy;
    }
    Point() {}
} e[maxn];

int k = 0;
double G[maxn][maxn];

double getDis(double x1, double y1, double x2, double y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double d[maxn];
typedef pair<double, int> P;
bool vst[maxn];

void Dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > q;
    fill(d, d+maxn, inf);
    d[s] = 0;
    q.push(P(d[s], s));
    while(!q.empty()) {
        P cur = q.top();
        q.pop();
        int i = cur.second;
        if(vst[i]) continue;
        vst[i] = true;
        for(int j = 1; j <= k; ++j) {
            if(d[i]+G[i][j] < d[j]) {
                d[j] = d[i]+G[i][j];
                q.push(P(d[j], j));
            }
        }
    }
}

int main() {
    double x, y;
    cin >> x >> y;
    e[++k] = Point(x, y);
    cin >> x >> y;
    e[++k] = Point(x, y);
    //1为起点, 2为终点
    int last= 2;
    while(cin >> x >> y) {
        //地铁建图
        if(x==-1.0 && y==-1.0) {
            for(int i = last+1; i < k; ++i) {
                double dis = getDis(e[i].x, e[i].y, e[i+1].x, e[i+1].y);
                G[i][i+1] = G[i+1][i] = dis/40000.0;
            }
            last = k;
            continue;
        }
        e[++k] = Point(x, y);
    }
    //步行补边
    for(int i = 1; i <= k; ++i)
        for(int j = i+1; j <= k; ++j)
            if(G[i][j] == 0)
                G[i][j] = G[j][i] = getDis(e[i].x, e[i].y, e[j].x, e[j].y)/10000.0;
    Dijkstra(1);
    cout << (int)(d[2]*60.0+0.5) << endl;
    return 0;
}