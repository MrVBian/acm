#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

const int maxn = 160;
const int inf = 0x3f3f3f3f;

int n, m;
int cot;
map<string,int> mp;
double G[maxn][maxn];
int vst[maxn];
double d[maxn];
int ans[maxn];

bool spfa(int s){
    for(int i = 0; i <= n; ++i){
        vst[i] = 0;
        d[i] = 0;
        ans[i] = 0;
    }
    vst[s] = 1;
    d[s] = 1;
    ans[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int k = q.front();
        q.pop();
        vst[k] = 0;
        for(int j = 0; j < n; ++j){
            if(d[j] < d[k]*G[k][j]){
                d[j] = d[k] * G[k][j];
                if(!vst[j]){
                    vst[j] = 1;
                    ans[j] ++;
                    q.push(j);
                    if(ans[j] > n)
                        return true;
                }
            }
        }
    }
    return false;
}

int main(){
    int res = 1;
    while(~scanf("%d", &n) && n){
        memset(G, 0, sizeof(G));
        mp.clear();
        string p, q;
        double v;
        cot = 0;
        for(int i = 0; i < n; ++i){
            cin >> p;
            mp[p] = cot++;
        }
        scanf("%d", &m);
        for(int i = 0; i < m; ++i){
            cin >> p >> v >> q;
            G[mp[p]][mp[q]] = v;
            //printf("%4d%4d%6.2lf", mp[p], mp[q], v);
        }
        /*
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                printf("%6.2lf",G[i][j]);
            }
            printf("\n");
        }
        */
        int tag = 0;
        for(int i = 0; i < n; ++i){
            if(spfa(i))
                tag = 1;
        }
        if(tag){
            cout<<"Case "<<res++<<": Yes"<<endl;
        }
        else{
            cout<<"Case "<<res++<<": No"<<endl;
        }
    }
    return 0;
}
