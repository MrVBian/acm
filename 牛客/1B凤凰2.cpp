#include<bits/stdc++.h>
using namespace std;
#define INF 0x7ffffffff
typedef long long LL;
const int maxn = 1e6+5;
const LL mod = 1e9+7;
int m,n;
int par[maxn];
int num[maxn];
int findl(int a){
    if(a==par[a]) return a;
    return par[a]=findl(par[a]);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        par[i]=i;
        num[i]=1;
    }
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a==1||b==1) continue;
        int f1=findl(a);
        int f2=findl(b);
        if(f1!=f2){
            par[f2]=f1;
            num[f1]+=num[f2];
        }
    }
    int ma=0;
    for(int i=2;i<=n;i++){
        ma=max(ma,num[i]);
    }
    printf("%d\n",ma);
    return 0;
}
