#include <bits/stdc++.h>
using namespace std;
#define clr(a) memset(a,0,sizeof(a))

const int N = 10100;
const int Mod = 256;

bool dp[N][257];
struct node{
    char op[4];
    int v, k;
}p[N];

bool check(int pos, int num){
    if(dp[pos][num]) return false;
    else return true;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        clr(p);
        memset(dp, false, sizeof(dp));
        int n;
        scanf("%d", &n);
        for(int i=1; i<=n; i++){
            scanf("%s", p[i].op);
            if(strcmp(p[i].op, "add") == 0) scanf("%d", &p[i].v);
            else scanf("%d%d",&p[i].v, &p[i].k);
        }
        int num = 0, pos = 1;
        bool flag = true;
        while(pos <= n && flag){
            flag = check(pos, num);
            if(!flag) continue;
            dp[pos][num] = true;
            if(strcmp(p[pos].op, "add") == 0){
                num = (num + p[pos].v) % Mod;
                pos ++;
            }
            else if(strcmp(p[pos].op, "beq") == 0){
                if(num == p[pos].v) pos = p[pos].k;
                else pos++;
            }
            else if(strcmp(p[pos].op, "bne") == 0){
                if(num != p[pos].v) pos = p[pos].k;
                else pos++;
            }
            else if(strcmp(p[pos].op, "blt") == 0) {
                if(num < p[pos].v) pos = p[pos].k;
                else pos ++;
            }
            else {
                if(num > p[pos].v) pos = p[pos].k;
                else pos ++;
            }
        }
        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}
