#include <bits/stdc++.h>

using namespace std;

const int maxn = 10;
const int inf = 0x3f3f3f3f;
map<char, int> Hash;
char s[maxn][maxn];
int len[maxn], match[maxn];
int n, MAX, pd;
int cost[4], tp[4];
char ch[] = {'A', 'G', 'C', 'T'};

//统计每个序列里面四种序列值，并求得每种序列值的最长长度。将四种序列值加起来就是最长待匹配长度。
int calc(){
    for(int i = 0; i < 4; ++i)//4不是maxn
        cost[i] = tp[i] = 0;
    memset(cost, 0, sizeof(cost));
    memset(tp, 0, sizeof(tp));
    for(int i = 0; i < n; ++i){
        for(int j = match[i]; j < len[i]; ++j)//每种序列值的长度
            tp[ Hash[ s[i][j] ] ]++;
        for(int j = 0; j < 4; ++j){//每种序列值的最长长度
            cost[j] = max(cost[j], tp[j]);
            tp[j] = 0;
        }
    }
    int sum = 0;
    for(int i = 0; i < 4; ++i)
        sum += cost[i];
    return sum;
}

int dfs(int cot){
    int deep = calc();
    if(!deep){
        printf("%d\n", MAX);
        return 1;
    }
    if(deep + cot > MAX){
        pd = min(deep+cot, pd);
        return 0;
    }
    int old[maxn];
    memcpy(old, match, sizeof(old));
    for(int i = 0; i < 4; ++i){
        char c = ch[i];
        int flag = 0;
        for(int j = 0; j < n; ++j){
            if(match[j] < len[j] && s[j][match[j]] == c){
                flag = 1;
                ++match[j];
            }
        }
        if(flag && dfs(cot + 1))
            return 1;
        memcpy(match, old, sizeof(old));
    }
}

int main(){
    for(int i = 0; i < 4; ++i)
        Hash[ch[i]] = i;
    int t;
    scanf("%d", &t);
    while(t--){
        MAX = 0;
        memset(match, 0, sizeof(match));
        scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            scanf("%s", s[i]);
            len[i] = strlen(s[i]);
            MAX = max(MAX, len[i]);
        }
        while(1){
            pd = inf;
            if(dfs(0))
                break;
            MAX = pd;
        }
    }
    return 0;
}
