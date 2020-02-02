#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const ll MOD = (int)1e9 + 7;
const int maxn = (int)1e6 + 10;

int n, num;
int arr[40];

inline void RUN()
{
    int t;
    scanf("%d", &t);
    while (t--){
        int ans = 0;
        scanf("%d", &n);
        memset(arr, 0, sizeof arr);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &num);
            int cnt = 0;
            while (num)
            {
                printf("num: %d %d\n",num,cnt);
                cnt++;
                num >>= 1;
            }
            printf("cnt: %d\n",cnt);
            arr[cnt]++;
            ans = max(ans, arr[cnt]);
        }
        printf("%d\n", ans);
    }
}

#define LOCAL_JUDGE

int main()
{
#ifdef LOCAL_JUDGE
    freopen("Text.txt", "r", stdin);
#endif // LOCAL_JUDGE

    RUN();

#ifdef LOCAL_JUDGE
    fclose(stdin);
#endif // LOCAL_JUDGE
    return 0;
}
