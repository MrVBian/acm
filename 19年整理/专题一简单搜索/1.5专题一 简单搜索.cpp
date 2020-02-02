#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <math.h>

using namespace std;

const int maxn = 1e5+10;

int t;
int n, m;
int d[maxn];
int vst[maxn];

bool isPrime(int x){
    for(int i = 2; i < sqrt(x)+1; ++i)
        if(x % i == 0)
            return false;
    return true;
}

int f(int a[], int x){
    int sum = 0;
    for(int k = 0; k < 4; ++k){
        sum *= 10;
        sum += a[k];
    }
    return sum;
}

void bfs(){
    queue<int> q;
    q.push(n);
    vst[n] = 1;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        if(p == m){
            printf("%d\n", d[p]);
            return;
        }
        int a[4];
        int tmp = p;
        for(int i = 0; i < 4; ++i){
            a[4-i-1] = tmp%10;
            tmp /= 10;
        }
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 10; ++j){
                if(!i && !j)
                    continue;
                tmp = a[i];
                a[i] = j;
                int next = f(a, 4);
                if(!vst[next] && isPrime(next)){
                    q.push(next);
                    vst[next] = 1;
                    d[next] = d[p] + 1;
                }
                a[i] = tmp;
            }
        }
    }
}

int main(){
    scanf("%d", &t);
    while(t--){
        memset(d, 0, sizeof(d));
        memset(vst, 0, sizeof(vst));
        scanf("%d%d", &n, &m);
        bfs();
    }
    return 0;
}