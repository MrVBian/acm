#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

const int maxn = 210;
const int inf = 0x3f3f3f3f;

int n,m,s;
double v;
pair<double,double> G[maxn][maxn];
int vst[maxn];
double d[maxn];
int cot[maxn];

int spfa(int s){
    for(int i = 0; i <= n; ++i){
        vst[i] = 0;
        d[i] = 0;
        cot[i] = 0;
    }
    vst[s] = 1;
    cot[s] = 1;
    d[s] = v;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int k = q.front();
        q.pop();
        vst[k] = 0;
        for(int j = 1; j <= n; ++j){
            if(d[j] < (d[k] - G[k][j].second) * G[k][j].first ){
                d[j] = (d[k] - G[k][j].second) * G[k][j].first;
                if(!vst[j]){
                    vst[j] = 1;
                    q.push(j);
                    cot[j] ++;
                    if(cot[j] > n)
                        return true;
                }
            }
        }
    }
    return false;
}

int main(){
    while(~scanf("%d%d%d%lf", &n,&m,&s,&v)){
        memset(G, 0, sizeof(G));
        int x, y;
        double p,q;
        for(int i = 0; i < m; ++i){
            scanf("%d%d",&x,&y);
            scanf("%lf%lf",&p,&q);
            G[x][y] = make_pair(p,q);
            scanf("%lf%lf",&p,&q);
            G[y][x] = make_pair(p,q);
        }
        if(spfa(s)){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
