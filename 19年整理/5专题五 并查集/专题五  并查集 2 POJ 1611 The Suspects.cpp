#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 30010;
int n, m;
int par[maxn];

int Find(int x){
    if(par[x] == x)
        return x;
    return par[x] = Find(par[x]);
}

void Union(int x, int y){
    par[Find(x)] = Find(y);
}

void init(){
    for(int i = 0; i <= n; ++i){
        par[i] = i;
    }
}

int arr[maxn];
int cot = 0;

int main(){
    while(~scanf("%d%d", &n, &m)){
        if(!n && !m)
            return 0;
        int ans = 0;
        int k;
        init();
        for(int i = 0; i < m; ++i){
            scanf("%d", &k);
            for(int j = 0; j < k; ++j){
                scanf("%d", &arr[cot++]);
                if(j){
                    // cout<<arr[cot-2]<<"        "<<arr[cot-1]<<endl;
                    Union(arr[cot-2], arr[cot-1]);//cot==arr.size()
                }
            }
        }
        int p = Find(0);
        sort(arr, arr+n);
        int res = unique(arr, arr+n) - arr;
        for(int i = 0; i < res; ++i){
            if(Find(arr[i]) == p){
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}