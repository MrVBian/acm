#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

const int maxn = 20;
int n, m;
int mp[maxn][maxn];
int flip[maxn][maxn];
int ans[maxn][maxn];
int step[5][2] = {{0,1},{0,-1},{1,0},{-1,0},{0,0}};

bool check(int x,int y){
    if(x<0 || x>=n || y<0 || y>=m)
        return false;
    return true;
}

bool isFlip(int x, int y){
    int color = mp[x][y];
    for(int i = 0; i < 5; ++i){
        int cur_x = x+step[i][0];
        int cur_y = y+step[i][1];
        if(flip[cur_x][cur_y] && check(cur_x, cur_y))
            color++;
    }
    return color%2;
}

int getFlipNum(){
    int sum = 0;
    for(int i = 0; i < m; ++i)
        if(flip[0][i])
            sum++;
    for(int i = 1; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(isFlip(i-1, j)){
                flip[i][j] = 1;
                sum++;
            }
    for(int i = 0; i < m; ++i)
        if(isFlip(n-1, i))
            return -1;
    return sum;
}

int MIN = INT_MAX;

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            scanf("%d", &mp[i][j]);
    for(int i = 0; i < 1<<m; ++i){
        memset(flip, 0, sizeof(flip));
        for(int j = 0; j < m; ++j)
            flip[0][m-j-1] = i>>j&1;
        int cot = getFlipNum();
        if(cot == -1)
            continue;
        if(MIN > cot){
            MIN = cot;
            memcpy(ans, flip, sizeof(flip));
        }
    }
    if(MIN == INT_MAX)
        printf("IMPOSSIBLE");
    else{
        for(int i = 0; i < n; ++i){
            if(i)
                printf("\n");
            for(int j = 0; j < m; ++j){
                if(j)
                    printf(" ");
                printf("%d", ans[i][j]);
            }
        }
    }
    return 0;
}