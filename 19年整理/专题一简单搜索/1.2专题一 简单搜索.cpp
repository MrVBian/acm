#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cstdio>

using namespace std;

const int maxn = 1e5+10;
int n, k;
int d[maxn];
int vst[maxn];

int bfs(){
    if(n == k)  //不能省略？
        return 0;
    queue<int> q;
    vst[n] = 1;
    q.push(n);
    while(!q.empty()){
        int p = q.front();
        q.pop();
        if(p == k){
            return d[p];
        }
        if(p+1 <= maxn && !vst[p+1]){
            q.push(p+1);
            vst[p+1] = 1;
            d[p+1] = d[p]+1;
        }
        if(p-1 >= 0 && !vst[p-1]){
            q.push(p-1);
            vst[p-1] = 1;
            d[p-1] = d[p]+1;
        }
        if(p*2 <= maxn && !vst[p*2]){
            q.push(p*2);
            vst[p*2] = 1;
            d[p*2] = d[p]+1;
        }
    }
}

int main(){
    scanf("%d%d", &n, &k);
    int ans = bfs();
    printf("%d", ans);
    return 0;
}