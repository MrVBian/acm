#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;
int s, n, m;
int a[10];
int vst[maxn][maxn];

struct Point{
    int a[3], d;
    Point(int x, int y, int z, int dd){
        a[0] = x;
        a[1] = y;
        a[2] = z;
        d = dd;
    }
    Point(){}
};

void bfs(){
    queue<Point> q;
    q.push(Point(s, 0, 0, 0));
    vst[s][0] = 1;
    while(!q.empty()){
        Point p = q.front();
        q.pop();
        if( (p.a[0] == p.a[1] && !p.a[2]) || (p.a[1] == p.a[2] && !p.a[0]) || (p.a[0] == p.a[2] && !p.a[1]) ){
            printf("%d\n", p.d);
            return ;
        }
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j){
                if(i != j){
                    int b[3];
                    b[j] = p.a[i]+p.a[j]>=a[j] ? a[j] : p.a[i]+p.a[j];
                    b[i] = p.a[i]+p.a[j]>=a[j] ? p.a[i]-(a[j]-p.a[j]) : 0;
                    for(int k = 0; k < 3; ++k)
                        if(i != k && j != k)
                            b[k] = p.a[k];
                    if(!vst[b[0]][b[1]]){
                        vst[b[0]][b[1]] = 1;
                        q.push(Point(b[0], b[1], b[2], p.d+1));
                    }
                }
            }

    }
    printf("NO\n");
}

int main(){
    while(~scanf("%d%d%d", &s, &n, &m)){
        if(!s || !n || !m)
            return 0;
        for(int i = 0; i <= s; ++i)
            for(int j = 0; j <= s; ++j)
                vst[i][j] = 0;
        a[0] = s; a[1] = n; a[2] = m;
        bfs();
    }
    return 0;
}