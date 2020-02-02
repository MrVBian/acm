#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int dp[100005];
int a[100005];

int b1,e1;
int b2,e2;

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int m;
        cin>>m;
        int ans=-2000050000;
        for(int j=0;j<m;j++)
            cin>>a[j];
        dp[0]=a[0];
        b1=0;
        int tap1,tap2=tap1=1;
        for(int j=0;j<m;j++){
            if(dp[j-1]+a[j]>=a[j]&&j>0){
                dp[j]=dp[j-1]+a[j];
            }
            else{
                b1=j;
                dp[j]=a[j];
            }
            if(ans<dp[j]){
                ans=dp[j];
                b2=b1;
                e2=j;
            }
        }
        if(ans==0)
            e2=b2;
        printf("Case %d:\n",i);
        printf("%d %d %d\n",ans,b2+1,e2+1);
        if(i!=n)
            cout<<endl;
    }
}
//4 0 0 2 0
//6 2 7 -9 5 4 3
//4 0 0 -1 0
//7 -1 -2 -3 -2 -5 -1 -2
//6 -1 -2 -3 1 2 3
//5 -3 -2 -1 -2 -3
//4 0 0 2 0 —— 2 1 3
//6 2 7 -9 5 4 3 —— 12 1 6
//4 0 0 -1 0 —— 0 1 1
//7 -1 -2 -3 -2 -5 -1 -2 —— -1 1 1
//6 -1 -2 -3 1 2 3 —— 6 4 6
//----------------------------------------------------------------------------------
//增加一组测试数据：
//5 -3 -2 -1 -2 -3 —— -1 3 3
