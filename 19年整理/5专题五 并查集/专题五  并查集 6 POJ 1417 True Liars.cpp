#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1010;
const int maxm = 610;

int par[maxn],Rank[maxn],p[maxn],vst[maxn];
int w0[maxn],w1[maxn];
int dp[maxm][maxm];
int n,p1,p2;

int Find(int x){
    if(x!=par[x]){
        int tmp = par[x];
        par[x] = Find(par[x]);
        Rank[x] = Rank[x]^Rank[tmp];
    }
    return par[x];
}

void Union(int x,int y,int k){
    int xx = Find(x);
    int yy = Find(y);
    if(xx!=yy){
        par[xx] = yy;
        Rank[xx]=Rank[x]^Rank[y]^k;
    }
}

int main(){
    while(scanf("%d%d%d",&n,&p1,&p2)){
        if(n+p1+p2 == 0)
            break;
        for(int i=1;i<=p1+p2;i++){
            par[i] = i;
            Rank[i] = 0;
            vst[i] = 0;
            w0[i] = w1[i] = 0;
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            int a,b;char ch[5];
            scanf("%d%d%s",&a,&b,ch);
            if(ch[0]=='y')
                Union(a,b,0);
            else
                Union(a,b,1);
        }
        int cnt = 1;//组数
        for(int i=1;i<=p1+p2;i++){
            if(!vst[i]){
                int xx = Find(i);
                for(int j=i;j<=p1+p2;j++){
                    if(Find(j) == xx && !vst[j]){
                        vst[j] = 1;
                        if(Rank[j] == 0)
                            w0[cnt]++;//第i组中与根同类的数量
                        else
                            w1[cnt]++;//第i组中与根异类的数量
                    }
                }
                p[cnt] = xx;//第i组的根为xx
                cnt++;
            }
        }

        dp[0][0]=1;
        for(int i=1; i < cnt; ++i){
            int Min=min(w0[i], w1[i]);
            for(int j = p1; j >= Min; --j){
                if(dp[i-1][j-w0[i]]){
                    dp[i][j]+=dp[i-1][j-w0[i]];
                }
                if(dp[i-1][j-w1[i]]){
                    dp[i][j]+=dp[i-1][j-w1[i]];
                }
            }
        }

        if(dp[cnt-1][p1]!=1){
            printf("no\n");
            continue;
        }
        int ans[maxn];
        int num = 0;
        int Mp = p1;//神圣人的数量
        for(int i=cnt-1;i>=1;i--){
            if(dp[i-1][Mp-w0[i]]==1){//w0存的全是权值为0的
                for(int j=1;j<=p1+p2;j++){
                    if(Find(j)==p[i]&&Rank[j]==0)
                        ans[num++]=j;
                }
                Mp-=w0[i];
            }
            else {//w1存的全是权值为1的
                for(int j=1;j<=p1+p2;j++){
                    if(Find(j)==p[i]&&Rank[j]==1)
                        ans[num++]=j;
                }
                Mp-=w1[i];
            }
        }
        sort(ans,ans+num);
        for(int i=0;i<num;i++)
            printf("%d\n",ans[i]);
        puts("end");
    }
    return 0;
}
