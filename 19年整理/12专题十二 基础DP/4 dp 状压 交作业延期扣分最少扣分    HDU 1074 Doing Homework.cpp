#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = (1<<15) + 100;
const int inf = 0x3f3f3f3f;

struct node{
    string name;
    int e, v;
}a[20];

int n;
int dp[maxn];
int pre[maxn];
int time[maxn];
vector<int> ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        memset(dp, 0, sizeof(dp));
        memset(pre, 0, sizeof(pre));
        memset(time, 0, sizeof(time));
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> a[i].name >> a[i].e >> a[i].v;
        int m = 1 << n;
        for(int i = 1; i < m; ++i){
            dp[i] = inf;
            for(int j = n-1; j >= 0; --j){// 字典序最小，从第一个作业开始dp
                int k = 1 << j;
                if( !(i & k) )  continue; // 该作业没有做
                int v = time[i-k] + a[j].v - a[j].e; // 扣分 = 在做j作业前用了的时间 + j作业需要的时间 - j作业截止时间
                v = v < 0 ? 0 : v;// 扣分为负，即按照规定完成了作业
                if(dp[i] > dp[i-k] + v){
                    dp[i] = dp[i-k] + v;
                    pre[i] = j;// 存下一位置
                    time[i] = time[i-k] + a[j].v;
                }
            }
        }
        cout << dp[m-1] << endl;
        int k = m-1;
        ans.clear();
        while(k){
            int tmp = 1 << pre[k];
            ans.push_back(pre[k]);
            k -= tmp;
        }
        int len = ans.size();
        for(int i = len-1; i >= 0; --i)
            cout << a[ ans[i] ].name << endl;
    }
    return 0;
}
