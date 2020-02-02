#include<bits/stdc++.h>

using namespace std;

int main(){
    while(1){
        string s;
        cin>>s;
        if(s.size()==1 && s[0]=='0'){
            return 0;
        }
        long long sum=0;
        for(int i=0;i<s.size();i++){
            sum+=s[i]-'0';
        }
        sum=(sum-1)%9+1;
        cout<<sum<<endl;
    }
}
