#include<bits/stdc++.h>
#include<cstring>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    if(s.size()>= 5){
        string mo = s.substr(s.size()-6,s.size());
        int cot = 0;
        if(mo[0] != '1')
            cot ++;
        for(int i = 1; i <= 5; ++i)
            if(mo[i] != '0')
                cot ++;
        cout << "---------- " << mo << endl;
        cout << "---------- " << cot << endl;
        if(n < cot){
            cout << "no";
            return 0;
        }
        else{
            cout <<"yes";
            return 0;
        }
    }
    else{
        int cot = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '0')
                cot ++;
        }
        if(cot == s.size()){
            cout << "yes";
            return 0;
        }
        else{
            cout << "no";
            return 0;
        }
    }
    return 0;
}
