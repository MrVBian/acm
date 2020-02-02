#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const int maxn = 1010;
const int inf = 0x3f3f3f3f;
int n, a, b;
int G[maxn][maxn];
int d[maxn];
int vst[maxn];

void spfa(int s){
   queue<int> q;
   for(int i = 0; i <= n; ++i)
       d[i] = inf;
   d[s] = 0;
   memset(vst, 0, sizeof(vst));
   vst[s] = 1;
   q.push(s);
   while(!q.empty()){
       int k = q.front();
       vst[k] = 0;
       q.pop();
       for(int j = 1; j <= n; ++j){
           if(d[j] > d[k]+G[k][j]){
               d[j] = d[k] + G[k][j];
               if(!vst[j]){
                   vst[j] = 1;
                   q.push(j);
               }
           }
       }
   }
}
int main(){
    cin >> n >> a >> b;

    for(int i = 0; i <= n; ++i)
    for(int j = 0; j <= n; ++j){
        if(i == j)
            G[i][j] = 0;
        else
            G[i][j] = inf;
    }

    for(int i = 1; i <= n; ++i){
        int m, v;
        cin >> m;
        for(int j = 0; j < m; ++j){
            cin >> v;
            if(j)
                G[i][v] = 1;
            else
                G[i][v] = 0;
        }
    }

    spfa(a);
    if(d[b] >= inf)
        cout << -1;
    else
        cout << d[b];

    return 0;
}
