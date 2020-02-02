#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 1e3+100;

struct node{
    int x, y, z;
    node(){}
    node(int xx, int yy, int zz){
        x = xx; y = yy; z = zz;
    }
}block[maxn];
int dp[maxn];
int x, y, z, n;

bool cmp(node a, node b){
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int main(){
    int t = 1;
    while(~scanf("%d", &n) && n){
        int k = 0;
        for(int i = 0; i < n; ++i){
            scanf("%d%d%d", &x, &y, &z);
            block[k++] = node(x, y, z);
            block[k++] = node(x, z, y);
            block[k++] = node(y, x, z);
            block[k++] = node(y, z, x);
            block[k++] = node(z, x, y);
            block[k++] = node(z, y, x);
        }
        sort(block, block+k, cmp);
        for(int i = 0; i < k; ++i)
            dp[i] = block[i].z;
        int ans = 0;
        for(int i = 0; i < k; ++i){
            for(int j = 0; j < i; ++j){
                if(block[i].x > block[j].x && block[i].y > block[j].y){
                    dp[i] = max(dp[i], dp[j] + block[i].z);
                }
            }
            ans = max(ans, dp[i]);
        }
        printf("Case %d: maximum height = %d\n", t++, ans);
    }
    return 0;
}
