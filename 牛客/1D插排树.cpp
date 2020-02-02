#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int p[50001];

struct node{
    int e,c;
}k[50001];

int main()
{
    int n;
    ios::sync_with_stdio(false);
    cin>>n;

    int Max=0;
    for(int i=1;i<=n-1;i++){
        int a,b,c,dex,ans=0;
        cin>>a>>b>>c;
        p[a]=b;
        k[a].e=b;
        k[a].c=c;

        int t=a;
        while(p[t]>0){
            ans+= k[t].c ;
            t=k[t].e;
        }
        Max=max(ans,Max);
    }
    cout<<Max<<endl;
}
