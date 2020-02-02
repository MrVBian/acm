#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include <map>
using namespace std;

const int maxn = 40010;

struct Data{
    int x, y, v;
    char ch;
    Data(){}
    Data(int xx, int yy, int vv, char c):x(xx), y(yy), v(vv), ch(c){}
}data[maxn];

struct Query{
    int x, y, t, num;
    Query(){}
    Query(int xx, int yy, int tt, int nn):x(xx), y(yy), t(tt), num(nn){}
}query[maxn];

int cmp(Query q1, Query q2){
    return q1.t < q2.t;
}

int par[maxn],ew[maxn],ns[maxn];
int n, m, q;

int Find(int x){
    if(x!=par[x]){
        int tmp = par[x];
        par[x] = Find(par[x]);
        ew[x] += ew[tmp];
        ns[x] += ns[tmp];
    }
    return par[x];
}

void Union(int x, int y, int k, char ch){
    int xx = Find(x);
    int yy = Find(y);
    if(xx != yy){
        par[xx] = yy;
        if(ch == 'E' || ch == 'W'){
            if(ch == 'E')   ew[xx] = ew[y]-ew[x] + k;//东为正
            if(ch == 'W')   ew[xx] = ew[y]-ew[x] - k;
            ns[xx] = ns[y] - ns[x];//不增加,只更新
        }
        else{
            if(ch == 'N')   ns[xx] = ns[y]-ns[x] + k;//北为正
            if(ch == 'S')   ns[xx] = ns[y]-ns[x] - k;
            ew[xx] = ew[y] - ew[x];//不增加,只更新
        }

    }
}

map<int, int> mp;

int main(){
    for(int i = 0; i < maxn; ++i)
        par[i] = i;
    scanf("%d%d", &n, &m);
    int x, y, v;
    char ch[5];
    for(int i = 0; i < m; ++i){
        scanf("%d%d%d%s", &x, &y, &v, ch);
        data[i] = Data(x, y, v, ch[0]);
    }
    scanf("%d", &q);
    for(int i = 0; i < q; ++i){
        scanf("%d%d%d", &x, &y, &v);
        query[i] = Query(x, y, v, i);
    }

    sort(query, query+q, cmp);

    int time = 0;

    for(int i = 0; i < q; ++i){
        int t = query[i].t;
        while(time < t){
            Union(data[time].x, data[time].y, data[time].v, data[time].ch);
            time ++;
        }

        x = query[i].x;
        y = query[i].y;
        int xx, yy;
        xx = Find(x);
        yy = Find(y);

        if(xx != yy)
            v = -1;
        else
            v = abs(ew[x]-ew[y]) + abs(ns[x]-ns[y]);
        mp[query[i].num] = v;
    }

    for(int i = 0; i < q; ++i)
        printf("%d\n", mp[i]);

    return 0;
}
