#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

const int maxn = 1010;
int n;
double d;
int par[maxn];
int parr[maxn];//修复的计算机编号
int cot = 0;
int x[maxn];
int y[maxn];

double dis(int x1,int y1, int x2, int y2){
    return sqrt(double((double) (x1-x2)*(x1-x2) + (double)(y1-y2)*(y1-y2)  ));
}
int Find(int x){
    if(par[x] != x)
        par[x] = Find(par[x]);
    return par[x];
}
void Union(int x, int y){ par[Find(x)] = Find(y);  }

int main(){
    scanf("%d%lf", &n, &d);
    for(int i = 0; i <= n; ++i)
        par[i] = i;
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &x[i], &y[i]);
    }
    
    char ch[10];
    int p, q;
    while(~scanf("%s", ch)){
        switch(ch[0]){
            case 'O':
                scanf("%d", &p);
                parr[cot++] = --p;//编号从0开始
                for(int i = 0; i < cot; ++i){
                    if(parr[i] != p){
                        double distance = dis(x[parr[i]], y[parr[i]], x[p], y[p]);
                        if(distance <= (double)d)
                            Union(parr[i], p);
                    }
                }
                break;
            case 'S':
                scanf("%d%d", &p, &q);
                if( Find(--p) == Find(--q) )//编号从0开始
                    printf("SUCCESS\n");
                else{
                    printf("FAIL\n");
                }
                break;
        }
    }
    return 0;
}