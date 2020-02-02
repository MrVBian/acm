#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

const int maxn = 110;

int n, m;
char mp[maxn][maxn];
bool vst[maxn][maxn];
int ans = 0;
int step[9][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

bool check(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if(vst[x][y])
        return false;
    return true;
}

void dfs(int x, int y){
    for(int i = 0; i < 9; ++i){
        int cur_x = x + step[i][0];
        int cur_y = y + step[i][1];
        if(check(cur_x, cur_y) && mp[cur_x][cur_y] == '@'){
            vst[cur_x][cur_y] = 1;
            dfs(cur_x, cur_y);
        }
    }
}

int main(){
    while(~scanf("%d%d", &n, &m)){
        if(!n || !m)
            return 0;
        ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                cin >> mp[i][j];
                vst[i][j] = 0;
            }
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                if(mp[i][j] == '@' && !vst[i][j]){
                    dfs(i, j);
                    ans++;
                }
            }
        cout << ans << endl;
    }
    return 0;
}
