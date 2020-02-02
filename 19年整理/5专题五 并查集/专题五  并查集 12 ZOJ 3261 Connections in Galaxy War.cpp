#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

const int maxn = 10010;//编号范围
const int maxm = 50010;//操作次数
const int maxg = 20010;//建边数量
const int Hash = 10000;

int m, n, q;
int par[maxn];
int val[maxn];
map<int, bool> mp;//存储破坏的边
pair<int, int> G[maxg];//存储边
int ans[maxm];

struct Data{
    char op;
    int x, y;
}data[maxm];

int Find(int x){
    if(par[x] == x)
        return x;
    return par[x] = Find(par[x]);
}

void Union(int x, int y){
    int xx = Find(x);
    int yy = Find(y);
    if(val[xx] > val[yy] || (val[xx] == val[yy] && xx < yy))
        par[yy] = xx;
    if(val[xx] < val[yy] || (val[xx] == val[yy] && yy < xx))
        par[xx] = yy;
}

void init(){
    mp.clear();
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i < maxn; ++i)
        par[i] = i;
}

int main(){
    bool flag = false;
    while(~scanf("%d", &n)){
        init();
        for(int i = 0; i < n; ++i){
            scanf("%d", &val[i]);
        }

        scanf("%d", &m);//m个边战前建立
        int x, y;
        for(int i = 0; i < m; ++i){
            scanf("%d%d", &x, &y);
            if(x > y)//与删除保持一致
                swap(x, y);
            G[i] = make_pair(x, y);
        }

        scanf("%d", &q);//操作次数
        char ch[10];
        for(int i = 0; i < q; ++i){
            scanf("%s", ch);
            if(ch[0] == 'q'){//查询
                scanf("%d", &x);
                data[i].op = 'q';
                data[i].x = x;
            }
            else{//删除
                scanf("%d%d", &x, &y);
                data[i].op = 'd';
                if(x > y)
                    swap(x, y);
                data[i].x = x;
                data[i].y = y;
                mp[ x * Hash + y ] = 1;
            }
        }

        for(int i = 0; i < m; ++i){
            if(!mp[ G[i].first * Hash + G[i].second ])
                Union(G[i].first, G[i].second);
            // else{
                // printf(" delete %4d%4d\n", G[i].first, G[i].second);
            // }
        }

        int cot = 0;

        for(int i = q-1; i >= 0; --i){
            if(data[i].op == 'q'){
                x = data[i].x;
                int xx = Find(x);
                if(val[xx] > val[x])//选择功率大的
                    ans[cot++] = xx;
                else
                    ans[cot++] = -1;
                // printf(" ans %4d%4d%4d%4d\n", i, x, xx, ans[i]);
            }
            else{
                Union(data[i].x, data[i].y);
            }
        }
        if(flag)
            printf("\n");
        else
            flag = true;
        for(int i = cot-1; i >= 0; --i)
            printf("%d\n", ans[i]);
    }
    return 0;
}
