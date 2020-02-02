#include<map>
#include<iostream>
#include<cstdio>
using namespace std;
map<string,int> mp;
int main()
{
    int n;
    while(~scanf("%d",&n)){
        if(!n)
            return 0;
        int Max=0;
        string mo;
        string s;
        for(int i=0;i<n;i++){
            cin>>s;
            mp[s]++;
            if(mp[s]>Max){
                Max=mp[s];
                mo=s;
            }
        }
        cout<<mo<<endl;
    }
}
