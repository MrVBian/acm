#include <string>
#include <queue>
#include <cstdio>
#include <cstring>
#include <utility>
#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int, int> P;
#define N 55
#define M 1001
const int INF = 0x3f3f3f3f;
#define fi first
#define se second
//
//         1  2  3
//         4  5  6
//         7  8  9
//10 11 12 13 14 15 16 17 18 19 20 21
//22 23 24 25 26 27 28 29 30 31 32 33
//34 35 36 37 38 39 40 41 42 43 44 45
//         46 47 48
//         49 50 51
//         52 53 54
//
int cent[7] = {23, 26, 29, 32, 5, 50 };
int face[7][10] = {
    {10,11,12,22,23,24,34,35,36},
    {13,14,15,25,26,27,37,38,39},
    {16,17,18,28,29,30,40,41,42},
    {19,20,21,31,32,33,43,44,45},
    {1,2,3,4,5,6,7,8,9},
    {46,47,48,49,50,51,52,53,54}
};

int change[12][20] = {
                   {1,4,7,13,25,37,46,49,52,21,33,45,10,11,12,24,36,35,34,22},
                   {45,33,21,1,4,7,13,25,37,52,49,46,34,22,10,11,12,24,36,35},
                   {7,8,9,16,28,40,48,47,46,36,24,12,13,14,15,27,39,38,37,25},
                   {36,24,12,7,8,9,16,28,40,48,47,46,37,25,13,14,15,27,39,38},
                   {9,6,3,19,31,43,54,51,48,39,27,15,16,17,18,30,42,41,40,28},
                   {39,27,15,9,6,3,19,31,43,54,51,48,40,28,16,17,18,30,42,41},
                   {42,30,18,3,2,1,10,22,34,52,53,54,19,20,21,33,45,44,43,31},
                   {52,53,54,42,30,18,3,2,1,10,22,34,43,31,19,20,21,33,45,44},
                   {15,14,13,12,11,10,21,20,19,18,17,16,1,2,3,6,9,8,7,4},
                   {18,17,16,15,14,13,12,11,10,21,20,19,7,4,1,2,3,6,9,8},
                   {37,38,39,40,41,42,43,44,45,34,35,36,46,47,48,51,54,53,52,49},
                   {34,35,36,37,38,39,40,41,42,43,44,45,52,49,46,47,48,51,54,53}
                  };

char s[N];
int t, res;
int a[10], b[10];

char getch(){
    char c; while((c = getchar()) == ' ' || c == '\n');
    return c;
}

int geth(char * s){
    int mx = 0;
    for(int i = 0; i < 6; ++i)
        for(int j = 0; j < 9; ++j)
            if(s[face[i][j]] != s[cent[i]])
                mx++;
    return (mx + 11) / 12;
}

bool dfs(int deep){
    int t = geth(s);
    if(t + deep > res) return false;
    if(!t) return true;

    char tmp[N];
    memcpy(tmp, s, sizeof s);
    for(int i = 0; i < 12; ++i){
        for(int j = 0; j < 20; ++j)
            s[change[i][j]] = tmp[change[i^1][j]];

        a[deep] = i / 2;
        b[deep] = i & 1?-1:1;

        if(dfs(deep + 1)) return true;
        memcpy(s, tmp, sizeof tmp);
    }
    return false;
}

void ida(){
    res = geth(s);

    if(!res) {printf("0\n"); return;}
    res = 1;
    while(res <= 5){
        if(dfs(0)){
            printf("%d\n", res);
            for(int i = 0; i < res; ++i)
                printf("%d %d\n", a[i], b[i]);
            return;
        }
        res++;
    }
    printf("-1\n");
}

int main(){
    scanf("%d", &t);
    while(t--){
        for(int i = 1; i < N; ++i)
            s[i] = getch();
        ida();
    }

    return 0;
}