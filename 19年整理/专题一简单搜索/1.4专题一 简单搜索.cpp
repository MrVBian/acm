#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

typedef unsigned long long ULL;
const int maxn = 30;
int n;
int flag;
int a[maxn];

void dfs(ULL x, int len){
    if(!flag)
        return ;
    if(x % n == 0){
        flag = 0;
        printf("%lld\n", x);
        a[n] = x;
        return;
    }
    if(len >= 19)
        return ;
    dfs(x*10, len+1);
    dfs(x*10+1, len+1);
}

int main(){
    while(~scanf("%d", &n)){
        if(!n)
            return 0;
        flag = 1;
        dfs(1,1);
    }
    return 0;
}